#include <MadgwickAHRS.h>
#include <MPU9250_asukiaaa.h>
MPU9250_asukiaaa mySensor;
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
    Wire.begin();

    mySensor.setWire(&Wire);

    mySensor.beginAccel();
    mySensor.beginGyro();
    mySensor.beginMag();

    MadgwickFilter.begin(25); 
    
    timer = millis();
}

void loop() {
    mySensor.accelUpdate();
    mySensor.gyroUpdate();
    mySensor.magUpdate();

    ax = mySensor.accelX(); ay = mySensor.accelY(); az = mySensor.accelZ();
    gx = mySensor.gyroX();  gy = mySensor.gyroY();  gz = mySensor.gyroZ();
    mx = mySensor.magX();   my = mySensor.magY();   mz = mySensor.magZ();

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

    delay(500);
}