## MPU

## Link Penting 🔗

* **Webiste**
    * [MPU-9250 (TDK InvenSense)](https://invensense.tdk.com/products/motion-tracking/9-axis/mpu-9250/)
    * [Getting real-time position using MPU9250](https://projecthub.arduino.cc/tmekinyan/getting-real-time-position-using-mpu9250-5d1808)
    * [Interfacing MPU-9250 9-DOF Sensor with Arduino](https://www.flyrobo.in/blog/mpu9250-arduino?srsltid=AfmBOooI8KXwhjuLa6DpF14Kj69VVZxdSqO8BMjogrLKU0eD1jCCHVnA)
    
* **Video Penjelasan MPU**
    * [MPU9250 module with Arduino Tutorials -Accelerometer, gyroscope and Magnetometer sensor](https://youtu.be/wazPfdGBeZA?si=GFAcRKJf_vR6LsSn)
    * [MPU9250 IMU with ROS2 on Raspberry Pi for Rviz IMU Data Visualization](https://youtu.be/xgNka0DJZ4Y?si=Fdb7Wehenmqjy-FV)
  
-----

## Apa itu MPU?
MPU (Motion Processing Unit) adalah chip yang berisi Accelerometer (pengukur percepatan/kemiringan) dan Gyroscope (pengukur kecepatan sudut/rotasi). Pada seri tertentu seperti MPU-9250, terdapat tambahan sensor Magnetometer (kompas digital). Chip ini bertugas memproses data mentah dari sensor-sensor tersebut menjadi informasi orientasi yang akurat.

## 9-Axis 
Istilah 9-Axis menunjukkan bahwa MPU memiliki 9 sumbu deteksi, yaitu
* 3-Axis Accelerometer: Mendeteksi sumbu X, Y, dan Z untuk mengukur gaya gravitasi dan percepatan linier. Satuannya g atau m/s^2.
* 3-Axis Gyroscope: Mengukur kecepatan sudut atau rotasi pada sumbu X, Y, Z. Satuannya deg/s.
* 3-Axis Magnetometer: Mendeteksi sumbu X, Y, dan Z terhadap medan magnet bumi untuk menentukan arah mata angin (Heading). Satuannya μT.

## Derajat Kebebasan
Dalam mekanika, 6-DoF (seperti MPU-6050) mencakup gerakan pitch, roll, dan yaw namun hanya berbasis kalkulasi inersia. Sedangkan 9-DoF (seperti MPU-9250) disebut memiliki derajat kebebasan yang lebih lengkap karena Magnetometer berfungsi sebagai referensi absolut untuk memperbaiki eror "drift" (pergeseran nilai) pada sumbu yaw (arah hadap).

## Pin-Pin MPU 9250
Umumnya MPU 9250 menggunakan komunikasi I2C untuk terhubung ke ESP32 atau Arduino. Berikut adalah penjelasan pin-pinnya:
* VCC: Input daya (biasanya mendukung 3.3V - 5V tergantung modulnya).
* GND: Ground (hubungkan ke GND ESP32/Arduino).
* SCL (Serial Clock): Pin jam untuk komunikasi I2C.
* SDA (Serial Data): Pin data untuk komunikasi I2C.
* AD0: Pin untuk mengubah alamat I2C jika Anda menggunakan dua MPU sekaligus.
* INT: Interrupt pin, memberikan sinyal ke microcontroller jika ada data baru yang siap dibaca.

## Cara Menggunakan MPU 9250 dengan Arduino

### Dengan library `MPU9250`
```cpp
    #include "MPU9250.h"

    // Membuat objek MPU9250 dengan protokol I2C dan alamat 0x68
    MPU9250 IMU(Wire, 0x68);
    int status;

    void setup() {
    Serial.begin(115200);
    while(!Serial) {}

    // Memulai komunikasi dengan sensor
    status = IMU.begin();
    if (status < 0) {
        Serial.println("Sensor gagal diinisialisasi");
        Serial.print("Status: ");
        Serial.println(status);
        while(1) {}
    }

    // Melakukan kalibrasi (sensor harus diam saat ini)
    Serial.println("Kalibrasi Accelerometer dan Gyroscope...");
    IMU.calibrateAccel();
    IMU.calibrateGyro();
    
    Serial.println("Kalibrasi Magnetometer (Putar sensor ke segala arah)...");
    IMU.calibrateMag();
    
    Serial.println("Selesai!");
    }

    void loop() {
    // Membaca data dari sensor
    IMU.readSensor();

    // Menampilkan data Accelerometer (m/s^2)
    Serial.print("Accel X: "); Serial.print(IMU.getAccelX_mss(), 2);
    Serial.print(" Y: "); Serial.print(IMU.getAccelY_mss(), 2);
    Serial.print(" Z: "); Serial.println(IMU.getAccelZ_mss(), 2);

    // Menampilkan data Gyroscope (rad/s)
    Serial.print("Gyro X: "); Serial.println(IMU.getGyroX_rads(), 2);

    // Menampilkan data Magnetometer (uT)
    Serial.print("Mag X: "); Serial.println(IMU.getMagX_uT(), 2);

    delay(100);
    }
```

### Dengan library `MPU9250_asukiaa`
```cpp
    #include <MPU9250_asukiaaa.h>
    MPU9250_asukiaaa mySensor;

    void setup() {
    Serial.begin(115200);
    Wire.begin();

    mySensor.setWire(&Wire);
    
    // Mengaktifkan masing-masing bagian sensor
    mySensor.beginAccel();
    mySensor.beginGyro();
    mySensor.beginMag();

    // Anda juga bisa mengatur sensitivitas (opsional)
    // mySensor.setAccelRange(ACCEL_RANGE_4G);
    }

    void loop() {
    // Update data dari semua sensor
    mySensor.accelUpdate();
    mySensor.gyroUpdate();
    mySensor.magUpdate();

    // Tampilkan data Accelerometer
    Serial.print("Accel: ");
    Serial.print(mySensor.accelX()); Serial.print(", ");
    Serial.print(mySensor.accelY()); Serial.print(", ");
    Serial.println(mySensor.accelZ());

    // Tampilkan data Gyroscope
    Serial.print("Gyro: ");
    Serial.print(mySensor.gyroX()); Serial.print(", ");
    Serial.print(mySensor.gyroY()); Serial.print(", ");
    Serial.println(mySensor.gyroZ());

    // Tampilkan data Magnetometer
    Serial.print("Mag: ");
    Serial.print(mySensor.magX()); Serial.print(", ");
    Serial.print(mySensor.magY()); Serial.print(", ");
    Serial.println(mySensor.magZ());

    Serial.println("--------------------");
    delay(500);
    }
```

## Pengunaan MPU
Secara teknis, MPU berfungsi mendeteksi perubahan posisi dan rotasi. Berikut adalah kegunaannya:

1. Menjaga Keseimbangan (Self-Balancing)
da robot self-balancing (seperti Segway mini), MPU mendeteksi sudut kemiringan robot secara real-time. Jika robot miring ke depan, data dari MPU akan memerintahkan motor untuk bergerak ke depan agar robot tidak jatuh.
2. Navigasi dan Estimasi Posisi
MPU membantu robot mengetahui ke mana ia menghadap (Heading). Tanpa MPU, robot yang diperintahkan jalan lurus mungkin akan berbelok sedikit karena perbedaan gesekan roda. MPU membantu mengoreksi arah tersebut agar tetap lurus sesuai target.
3. Pendeteksi Jatuh atau Benturan
MPU dapat mendeteksi lonjakan percepatan mendadak. Jika robot terjatuh atau menabrak dinding, sensor ini bisa memicu protokol keamanan, seperti mematikan semua motor atau mengirim sinyal darurat.