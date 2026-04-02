/* ============================================================================
 * UPDATE LOG / CHANGELOG
 * ============================================================================
 * 1. Memory Optimization (SRAM) : Applied F() macro to all static strings in 
 * Serial.print() and Serial.println(). SRAM usage reduced from ~57% to ~38%.
 *
 * 2. Bug Fix (Compilation Error): Removed myMPU.enableAcc(), enableGyr(), and 
 * enableMag() as they do not exist in the MPU9250_WE library. myMPU.init() 
 * already handles sensor activation.
 *
 * 3. Syntax & Typo Fixes: Corrected case sensitivity for 'madgwickFilter' 
 * calls in the loop and fixed the 'DECLINATION_DEG' variable typo.
 *
 * 4. Character Encoding: Replaced special characters (degree, micro symbols) 
 * with standard ASCII ('deg', 'u') to prevent CLI console output issues.
 *
 * 5. Math Optimization: Changed frequency calculation to use '1000.0' to 
 * process floating-point math more cleanly. *
 * ============================================================================
 */

#include <MadgwickAHRS.h>
#include <MPU9250_WE.h>
#include <Wire.h>
#include <PID_v1.h>

// Global instances for sensor and filter
MPU9250_WE myMPU = MPU9250_WE();
Madgwick madgwickFilter;

// Orientation variables
float yaw, pitch, roll = 0.0f;
float trueHeading = 0.0f;                      
const float DECLINATION_DEG = 0.6f;   // Magnetic declination for Surakarta/current location
float magXOffset = 0.0f, magYOffset = 0.0f, magZOffset = 0.0f;

// Timing and frequency variables
unsigned long lastUpdate = 0;
const int sampleInterval = 10;        // 10ms = 100Hz
unsigned long lastPrint = 0;
int count = 0;

// Sensor data structures
xyzFloat accRaw;
xyzFloat accCorr;
xyzFloat gyr;
xyzFloat mag;

// PID Controller for Yaw
double setpointYaw = 0.0;
double inputYaw = 0.0;
double outputYaw = 0.0;
double KpYaw = 1.8, KiYaw = 0.1, KdYaw = 0.8;
PID pidYaw(&inputYaw, &outputYaw, &setpointYaw, KpYaw, KiYaw, KdYaw, DIRECT);

// PID Controller for Pitch
double setpointPitch = 0.0;
double inputPitch = 0.0;
double outputPitch = 0.0;
double KpPitch = 3.0, KiPitch = 0.2, KdPitch = 1.5;
PID pidPitch(&inputPitch, &outputPitch, &setpointPitch, KpPitch, KiPitch, KdPitch, DIRECT);

// PID Controller for Roll
double setpointRoll = 0.0;
double inputRoll = 0.0;
double outputRoll = 0.0;
double KpRoll = 2.5, KiRoll = 0.15, KdRoll = 1.2;
PID pidRoll(&inputRoll, &outputRoll, &setpointRoll, KpRoll, KiRoll, KdRoll, DIRECT);

void setup() {
  Serial.begin(115200);
  while(!Serial){}

  Wire.begin();
  Wire.setClock(400000); // 400kHz I2C clock

  // Initialize MPU9250
  if(!myMPU.init()) {
    Serial.println(F("MPU9250 does not respond"));
    while(1) {}
  }

  Serial.println(F("Calibrating MPU 9250"));
  myMPU.autoOffsets();

  // Set magnetometer to continuous 100Hz mode
  myMPU.setMagOpMode(AK8963_CONT_MODE_100HZ);

  // Initialize Madgwick filter at 100Hz
  madgwickFilter.begin(100.0f); 

  // Initialize PID Controllers
  pidPitch.SetMode(AUTOMATIC);
  pidRoll.SetMode(AUTOMATIC);
  pidYaw.SetMode(AUTOMATIC);     

  pidPitch.SetOutputLimits(-30, 30);
  pidRoll.SetOutputLimits(-30, 30);
  pidYaw.SetOutputLimits(-60, 60);

  pidPitch.SetSampleTime(sampleInterval);
  pidRoll.SetSampleTime(sampleInterval);
  pidYaw.SetSampleTime(sampleInterval);
    
  lastUpdate = millis();
  lastPrint = millis();
}

void loop() {
  unsigned long currentTimer = millis();

  // Primary Update Loop (100Hz)
  if (currentTimer - lastUpdate >= sampleInterval) {
      // Get data from sensor
      accRaw = myMPU.getAccRawValues();
      accCorr = myMPU.getCorrectedAccRawValues();
      gyr = myMPU.getGyrValues();
      mag = myMPU.getMagValues();

      // Update AHRS filter
      madgwickFilter.update(gyr.x, gyr.y, gyr.z, accCorr.x, accCorr.y, accCorr.z, mag.x, mag.y, mag.z);

      // Get Euler angles
      yaw = madgwickFilter.getYaw();
      pitch = madgwickFilter.getPitch();
      roll = madgwickFilter.getRoll();

      // Compensate for magnetic declination
      trueHeading = yaw + DECLINATION_DEG;
      if (trueHeading < 0.0f) trueHeading += 360.0f;
      if (trueHeading >= 360.0f) trueHeading -= 360.0f;

      // Assign PID inputs
      inputPitch = pitch;
      inputRoll = roll;
      inputYaw = trueHeading; 

      // Execute PID calculations
      pidPitch.Compute();
      pidRoll.Compute();
      pidYaw.Compute();

      count++;
      lastUpdate = currentTimer;
  }

  // Debug/Print Loop (Every 500ms)
  if (currentTimer - lastPrint >= 500) {
    Serial.println(F("Accelerometer (corrected, g): "));
    Serial.print(F("ax = ")); Serial.print(accCorr.x, 3);
    Serial.print(F("  ay = ")); Serial.print(accCorr.y, 3);
    Serial.print(F("  az = ")); Serial.println(accCorr.z, 3);

    Serial.println(F("Gyroscope (dps):"));
    Serial.print(F("gx = ")); Serial.print(gyr.x, 2);
    Serial.print(F("  gy = ")); Serial.print(gyr.y, 2);
    Serial.print(F("  gz = ")); Serial.println(gyr.z, 2);

    Serial.print(F("Magnetometer (uT):  mx = ")); Serial.print(mag.x, 1);
    Serial.print(F("  my = ")); Serial.print(mag.y, 1);
    Serial.print(F("  mz = ")); Serial.println(mag.z, 1);

    Serial.print(F("True Heading : ")); Serial.print(trueHeading, 1); Serial.print(F(" deg\n"));
    Serial.print(F("Yaw   (mag)  : ")); Serial.print(inputYaw, 1); Serial.print(F(" deg\n"));
    Serial.print(F("Pitch        : ")); Serial.print(inputPitch, 1); Serial.print(F(" deg\n"));
    Serial.print(F("Roll         : ")); Serial.print(inputRoll, 1); Serial.print(F(" deg\n"));
    Serial.print(F("PID Yaw Out  : ")); Serial.print(outputYaw, 1); Serial.print(F("\n"));
    Serial.print(F("PID Pitch Out: ")); Serial.print(outputPitch, 1); Serial.print(F("\n"));
    Serial.print(F("PID Roll Out : ")); Serial.print(outputRoll, 1); Serial.print(F("\n"));
    
    // Frequency calculation to monitor loop performance
    Serial.print(F("Frekuensi    : ")); Serial.print((1000.0 * count) / (currentTimer - lastPrint)); Serial.println(F(" Hz"));
    Serial.println(F("------------------------------------------------------"));
    
    lastPrint = currentTimer;
    count = 0;
  }
}
