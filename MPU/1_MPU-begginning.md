## MPU

## Link Penting 🔗

* **Webiste**
    * [MPU-9250 (TDK InvenSense)](https://invensense.tdk.com/products/motion-tracking/9-axis/mpu-9250/)
    * []
    
* **Video Penjelasan MPU**
    * []()
  

-----

## Apa itu MPU?
MPU (Motion Processing Unit) adalah chip yang berisi Accelerometer (pengukur percepatan/kemiringan) dan Gyroscope (pengukur kecepatan sudut/rotasi). Pada seri tertentu seperti MPU-9250, terdapat tambahan sensor Magnetometer (kompas digital). Chip ini bertugas memproses data mentah dari sensor-sensor tersebut menjadi informasi orientasi yang akurat.

## 9-Axis 
Istilah 9-Axis menunjukkan bahwa MPU memiliki 9 sumbu deteksi, yaitu
* 1. 3-Axis Accelerometer: Mendeteksi sumbu X, Y, dan Z untuk mengukur gaya gravitasi dan percepatan linier.
* 2. 3-Axis Accelerometer: Mendeteksi sumbu X, Y, dan Z untuk mengukur gaya gravitasi dan percepatan linier.
* 3. 3-Axis Magnetometer: Mendeteksi sumbu X, Y, dan Z terhadap medan magnet bumi untuk menentukan arah mata angin (Heading).

## Derajat Kebebasan
Dalam mekanika, 6-DoF (seperti MPU-6050) mencakup gerakan pitch, roll, dan yaw namun hanya berbasis kalkulasi inersia. Sedangkan 9-DoF (seperti MPU-9250) disebut memiliki derajat kebebasan yang lebih lengkap karena Magnetometer berfungsi sebagai referensi absolut untuk memperbaiki eror "drift" (pergeseran nilai) pada sumbu yaw (arah hadap).

## Pin-Pin MPU 9250
Umumnya MPU 9250 menggunakan komunikasi I2C untuk terhubung ke ESP32 atau Arduino. Berikut adalah penjelasan pin-pinnya:
* 1. VCC: Input daya (biasanya mendukung 3.3V - 5V tergantung modulnya).
* 2. GND: Ground (hubungkan ke GND ESP32/Arduino).
* 3. SCL (Serial Clock): Pin jam untuk komunikasi I2C.
* 4. SDA (Serial Data): Pin data untuk komunikasi I2C.
* 5. AD0: Pin untuk mengubah alamat I2C jika Anda menggunakan dua MPU sekaligus.
* 6. INT: Interrupt pin, memberikan sinyal ke microcontroller jika ada data baru yang siap dibaca.

## Cara Menggunakan MPU 9250 dengan Arduino

## Pengunaan MPU