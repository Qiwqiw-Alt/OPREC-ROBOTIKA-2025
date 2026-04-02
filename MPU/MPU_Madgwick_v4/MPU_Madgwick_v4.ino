#include <MadgwickAHRS.h>
#include <MPU9250_WE.h>
#include <Wire.h>
#include <PID_v1.h>

MPU9250_WE myMPU = MPU9250_WE();
Madgwick madgwickFilter;


float yaw, pitch, roll = 0.0f;
float trueHeading = 0.0f;                     
const float DECLINATION_DEG = 0.6f;   
float magXOffset = 0.0f, magYOffset = 0.0f, magZOffset = 0.0f;

unsigned long lastUpdate = 0;
const int sampleInterval = 10;
unsigned long lastPrint = 0;
int count = 0;

xyzFloat accRaw;
xyzFloat accCorr;
xyzFloat gyr;
xyzFloat mag;
// float temp;

//Yaw
double setpointYaw = 0.0;
double inputYaw = 0.0;
double outputYaw = 0.0;
double KpYaw = 1.8, KiYaw = 0.1, KdYaw = 0.8;
PID pidYaw(&inputYaw, &outputYaw, &setpointYaw, KpYaw, KiYaw, KdYaw, DIRECT);

//Pitch
double setpointPitch = 0.0;
double inputPitch = 0.0;
double outputPitch = 0.0;
double KpPitch = 3.0, KiPitch = 0.2, KdPitch = 1.5;
PID pidPitch(&inputPitch, &outputPitch, &setpointPitch, KpPitch, KiPitch, KdPitch, DIRECT);

//Roll
double setpointRoll = 0.0;
double inputRoll = 0.0;
double outputRoll = 0.0;
double KpRoll = 2.5, KiRoll = 0.15, KdRoll = 1.2;
PID pidRoll(&inputRoll, &outputRoll, &setpointRoll, KpRoll, KiRoll, KdRoll, DIRECT);

void setup() {
  Serial.begin(115200);
  while(!Serial){}

  Wire.begin();
  Wire.setClock(400000);

  if(!myMPU.init()) {
    Serial.println("MPU9250 does not respond");
    while(1) {}
  }

  Serial.println("Calibarating MPU 9250");
  myMPU.autoOffsets();
  myMPU.enableAcc();
  myMPU.enableGyr();
  myMPU.enableMag();

  myMPU.setMagOpMode(AK8963_CONT_MODE_100HZ);

  madgwickFilter.begin(100.0f); 

  pidPitch.SetMode(AUTOMATIC);
  pidRoll.SetMode(AUTOMATIC);
  pidYaw.SetMode(AUTOMATIC);     // Matikan kalau yaw tidak perlu PID: pidYaw.SetMode(MANUAL);

  pidPitch.SetOutputLimits(-30, 30);
  pidRoll.SetOutputLimits(-30, 30);
  pidYaw.SetOutputLimits(-60, 60);

  pidPitch.SetSampleTime(sampleInterval);
  pidRoll.SetSampleTime(sampleInterval);
  pidYaw.SetSampleTime(sampleInterval);
    
  lastUpdate = millis();
  lastPrint = millis();
  // delay(100);
}

void loop() {
  unsigned long currentTimer = millis();

  if (currentTimer - lastUpdate >= sampleInterval) {
      accRaw = myMPU.getAccRawValues();
      accCorr = myMPU.getCorrectedAccRawValues();
      gyr = myMPU.getGyrValues();
      mag = myMPU.getMagValues();
      // temp = myMPU.getTemperature();

      madgwickFilter.update(gyr.x, gyr.y, gyr.z, accCorr.x, accCorr.y, accCorr.z, mag.x, mag.y, mag.z);

      yaw = MadgwickFilter.getYaw();
      pitch = MadgwickFilter.getPitch();
      roll = MadgwickFilter.getRoll();

      trueHeading = yaw + DECLANATION_DEG;
      if (trueHeading < 0.0f) trueHeading += 360.0f;
      if (trueHeading >= 360.0f) trueHeading -= 360.0f;

      inputPitch = pitch;
      inputRoll = roll;

      double yawError = setpointYaw - trueHeading;
      if (yawError >  180.0) yawError -= 360.0;
      if (yawError < -180.0) yawError += 360.0;
      inputYaw = trueHeading; 

      pidPitch.Compute();
      pidRoll.Compute();
      pidYaw.Compute();

      count++;
      lastUpdate = currentTimer;
  }

  if (currentTimer - lastPrint >= 500) {
    Serial.println("Accelerometer (corrected, g): ");
    Serial.print("ax = "); Serial.print(accCorr.x, 3);
    Serial.print("  ay = "); Serial.print(accCorr.y, 3);
    Serial.print("  az = "); Serial.println(accCorr.z, 3);

    Serial.println("Gyroscope (dps):");
    Serial.print("gx = "); Serial.print(gyr.x, 2);
    Serial.print("  gy = "); Serial.print(gyr.y, 2);
    Serial.print("  gz = "); Serial.println(gyr.z, 2);

    Serial.print("Magnetometer (µT):  mx = "); Serial.print(mag.x, 1);
    Serial.print("  my = "); Serial.print(mag.y, 1);
    Serial.print("  mz = "); Serial.println(mag.z, 1);

    // Serial.print("Temperature: "); Serial.print(temp); Serial.println(" °C");

    Serial.print("True Heading : "); Serial.print(trueHeading, 1); Serial.print("°\n");
    Serial.print("Yaw   (mag)  : "); Serial.print(inputYaw, 1); Serial.print("°\n");
    Serial.print("Pitch        : "); Serial.print(inputPitch, 1); Serial.print("°\n");
    Serial.print("Roll         : "); Serial.print(inputRoll, 1); Serial.print("°\n");
    Serial.print("PID Yaw Out  : "); Serial.print(outputYaw, 1); Serial.print("\n");
    Serial.print("PID Pitch Out: "); Serial.print(outputPitch, 1); Serial.print("\n");
    Serial.print("PID Roll Out : "); Serial.print(outputRoll, 1); Serial.print("\n");
    Serial.print("Frekuensi    : "); Serial.print(((float)count * 1000) / (float)(currentTimer - lastPrint)); Serial.println(" Hz");
    Serial.println("------------------------------------------------------");
    lastPrint = currentTimer;
    count = 0;
  }
}
