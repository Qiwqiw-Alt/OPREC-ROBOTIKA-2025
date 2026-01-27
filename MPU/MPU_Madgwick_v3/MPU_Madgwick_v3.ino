#include <MPU9250.h>
#include <MadgwickAHRS.h>
MPU9250 mpu;
Madgwick MadgwickFilter;

float yaw, pitch, roll;
float heading;

float declinationAngle = 7.0 * (57.0 / 60.0) * PI / 180.0; 

unsigned long timer;
int count = 0;

float ax, ay, az;
float gx, gy, gz;
float mx, my, mz;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("=== MPU9250 9 DOF ===");

  if (!mpu.setup(0x68)) {
    Serial.println("MPU9250 TIDAK TERDETEKSI");
    while (1);
  }
  Serial.println("MPU9250 TERDETEKSI");

  MadgwickFilter.begin(25); 
    
  timer = millis();
}

void loop() {
  if (mpu.update()) {

    ax = mpu.getAccX(); ay = mpu.getAccY(); az = mpu.getAccZ();
    gx = mpu.getGyroX(); gy = mpu.getGyroY(); gz = mpu.getGyroZ();
    mx = mpu.getMagX(); my = mpu.getMagY(); mz = mpu.getMagZ();

    MadgwickFilter.update(gx, gy, gz, ax, ay, az, mx, my, mz);

    heading = atan2(-my, -mx) + declinationAngle;

    if (heading < 0) heading += 2 * PI;
    if (heading > 2 * PI) heading -= 2 * PI;

    yaw = MadgwickFilter.getYaw();
    pitch = MadgwickFilter.getPitch();
    roll = MadgwickFilter.getRoll();

    unsigned long currentTimer = millis();
    count++;

    if (currentTimer - timer >= 100) {
        Serial.print("Heading: "); Serial.print((int)(heading * 180.0 / PI)); Serial.print("\n");
        Serial.print("Yaw: "); Serial.print(yaw); Serial.print("\n");
        Serial.print("Pitch: "); Serial.print(pitch); Serial.print("\n");
        Serial.print("Roll: "); Serial.print(roll); Serial.print("\n"); 
        Serial.print("Frekuensi: "); Serial.print(((float)count * 1000) / (float)(currentTimer - timer)); Serial.println("Hz\n");
        Serial.print("------------------------------------------------------");

        timer = currentTimer;
        count = 0;

      float Kp = 2.0, Ki = 0.01; kd = 0.5;

      float  p_error, p_lastError, p_integral, p_derivative;
      float r_error, r_lastError, r_integral, r_derivative;

      float setpoint = 0;

    }
  }
}