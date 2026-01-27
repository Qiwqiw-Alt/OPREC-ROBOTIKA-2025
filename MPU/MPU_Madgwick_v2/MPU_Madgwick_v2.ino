#include <MadgwickAHRS.h>
#include <mpu9250.h>
bfs::Mpu9250 imu(&SPI, 10);
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
  while(!Serial) {}

  SPI.begin();

  if(!imu.Begin()) {
    Serial.println("Error initializing communication with imu");
    while(1) {}
  }

  if (!imu.ConfigSrd(19)) {
    Serial.println("Error configured SRD");
    while(1) {}
  }

  MadgwickFilter.begin(25); 
    
  timer = millis();
}

void loop() {
  if(imu.Read()) {
    // Serial.print(imu.new_imu_data());
    // Serial.print("\t");
    // Serial.print(imu.new_mag_data());
    // Serial.print("\t");
    // Serial.print(imu.accel_x_mps2());
    // Serial.print("\t")
    // Serial.print(imu.accel_y_mp2());
    // Serial.print("\t");
    // Serial.print(imu.accel_z_mp2())
    // Serial.print("\t");
    // Serial.print(imu.gyro_x_mps2());
    // Serial.print("\t")
    // Serial.print(imu.gyro_y_mp2());
    // Serial.print("\t");
    // Serial.print(imu.gyro_z_mp2());
    // Serial.print("\t");
    // Serial.print(imu.mag_x_mps2());
    // Serial.print("\t")
    // Serial.print(imu.mag_y_mp2());
    // Serial.print("\t");
    // Serial.print(imu.mag_z_mp2());
    // Serial.print("\t");
    // Serial.print(imu.die_temp_c());
    // Serial.print("\n");

    ax = imu.accel_x_mps2(); ay =imu.accel_y_mp2(); az = imu.accel_z_mp2();
    gx = imu.gyro_x_mps2();  gy = imu.gyro_y_mps2(); gz = imu.gyro_z_mps2();
    mx = imu.mag_x_mps2();   my = imu.mag_y_mps2(); mz =imu.mag_z_mps2();

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
    }

  }

  delay(500);
}
