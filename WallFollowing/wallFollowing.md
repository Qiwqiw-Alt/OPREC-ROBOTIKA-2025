## Algoritma Wall Following

* **Repository Github Wall Following**
     * [Arduino-Wall-Follower](https://github.com/grubdragon/Arduino-Wall-Follower/blob/master/wall_follower.ino)
     * [Wall-Follower](https://github.com/Rajneesh04/Wall-follower)

-----

## Apa itu Algortima Wall Following?
Algoritma Wall Following adalah metode navigasi sederhana yang digunakan robot untuk menyusuri dinding atau penghalang dengan menjaga jarak konstan dari sisi tertentu (kiri atau kanan). Konsep dasarnya memungkinkan robot menelusuri labirin atau lintasan kompleks tanpa peta lengkap, hanya mengandalkan sensor jarak seperti ultrasonik atau infrared.

## Konsep Dasar Navigasi Robot
Robot tidak hanya bergerak maju, belok kanan, atau belok kiri, tetapi terus menerus memenatau jarak dan memperbarui nilai jarak tersebut. Hal tersebut biasa disebut Sistem Kendali Tertutup (Closed-Loop System). Nilai jarak yang terus-menerus diperbarui tersebut menjadi sebuah umpan balik yang memengaruhi gerakan robot. Dalam menentukan pergerakan, diperlukan set point yang dijadikan sebagai nilai penentu, misal jika senosr bagian kanan mendeteksi jarak kurang dari 15 cm sedangkan sensor bagian kiri mendeteksi jarak lebih dari 15 cm, maka robot akan bergerak ke kiri.

## Persepsi: Cara Robot "Melihat" Dinding
Robot membutuhkan sensor sebagai indra peraba jarak. Tanpa sensor yang akurat, algoritma navigasi sehebat apa pun tidak akan bisa bekerja karena data yang diproses salah.

### Cara Robot Mengukur Jarak
Salah satu cara robot mengukur jarak adalah menggunakan sensor Ultrasonik seperti HC-SR04. Sensor ini bekerja dengan prinsip Time of Flight (ToF), yaitu menghitung waktu pantulan suara untuk mendapatkan jarak.

Secara matematis, jarak ($s$) dihitung berdasarkan kecepatan suara ($v$) dan waktu tempuh ($t$):

$$s = \frac{v \times t}{2}$$

(Dibagi dua karena waktu tempuh dihitung sejak suara keluar hingga kembali lagi ke sensor).

### Kelemahan Sensor Ultrasonik
1. Sudut Pantul: Jika dinding terlalu miring, gelombang suara akan memantul ke arah lain dan tidak kembali ke sensor. Robot akan mengira tidak ada dinding di dekatnya.
2. Bahan Dinding: Bahan yang lunak (seperti kain atau busa) cenderung menyerap suara, sehingga pembacaan jarak menjadi tidak akurat.

### Alternatif Lain
Selain menggunakan sensor Ultrasonik, robot juga dapat menggunakan alat/teknologi lain, yaitu
1. Sensor Infrared (IR)
2. LiDAR (Light Detection and Ranging)

## Strategi Naviagasi
Dalam melakukan navigasi, robot memiliki beberapa prinsip, yaitu

1. Single Wall Following: Hanya mengikuti satu sisi (kiri atau kanan).
2. Maze Solving (Rule of Thumb): Hanya mengikuti satu dinding secara konsisten (misal: selalu kiri) sehingga robot bisa keluar dari labirin.
3. Corner Handling: Logika apa yang dilakukan robot saat menemui sudut dalam (belok tajam) atau sudut luar (dinding mendadak hilang).

## Algoritma Kontrol Gerakan
Dalam Wall Following terdapat beberapa jenis logika berbeda yang dapat digunakan, yaitu

1. Logika Bang-Bang (On-Off Control)
Merupakan metode paling sederhana dimana robot hanya memiliki dua kondisi eksterm yaitu "On" atau "Off".
    - Cara Kerja: Jika jarak lebih besar dari set point, robot kanan. Jika jarak kurang dari set point robot akan belok kiri.
    - Karakteristik: Robot akan bergerak secara kasar dan terlihat zig-zag (berosilasi) karena tidak ada perintah untuk bergerak halus. Robot akan selalu melewati batas Set Point (overshoot).

2. Logika Proportional (P)
Merupakan metode yang ditentukan bergantung pada besarnya error.
    - Cara Kerja: Semakin jauh robot melenceng dari dinding, semakin tajam ia berbelok. Sebaliknya, jika robot hanya melenceng sedikit, ia akan berbelok secara halus.
    - Rumus dasar: $Ouput = Kp x Error$
    - Karakteristik: Gerakan robot jauh lebih halus dibandingkan Bang-Bang. Namun, kontroler P saja seringkali menyisakan jarak kecil yang tetap (Steady State Error), di mana robot sejajar dengan dinding tapi tidak tepat di angka Set Point.

3. PID Control
Merupakan metode yang menggabungkan 3 perhitungan untuk menghasilkan gerakan yang mulus. 3 perhitungan tersebut adalah Proportional, Integral, dan Derivative (sudah dibahas di materi PID). 
    - Cara Kerja: Jika robot menjauh dari dinding, hasil perhitungan Proporsional (P) akan menariknya kembali. Hasil perhitungan Integral (I) berperan untuk mengurangi kesalahan kecil hingga mendekati nilai set point. Dan, hasil perhitungan Derivative (D) berperan sebagai rem. Jika robot bergerak terlalu cepat ke arah dinding, D akan memperlambat belokan agar robot tidak menabrak atau melewati batas
    - Rumus dasar: (Sudah ada dimateri PID)
    - Karakteristik: Sangat stabil, Halus, presisi tinggi. **Namun, perlu dilakukan tunning. Jika proses tunning asal-asalan, hasilnya tidak akan lebih baik dibanding dua metode sebelumnya awoawkoakwoaakwo :v**

## Kode Progaram Wall Following Biasa

```cpp
    // Konfigurasi Pin
    int trig_front=8; int echo_front=9;
    int trig_right=10; int echo_right=11;

    // Parameter Ambang Batas (Threshold)
    double dist_target = 15.0; // Set point
    double toleransi = 3.0;    // Toleransi error
    long distance_front, distance_right;

    // Pin Motor
    int leftWheelForward=5; int rightWheelForward=3;
    int leftWheelBackward=4; int rightWheelBackward=2;

    void setup() {
        // Inisialisasi Pin Motor sebagai OUTPUT
        pinMode(leftWheelForward, OUTPUT);
        pinMode(leftWheelBackward, OUTPUT);
        pinMode(rightWheelForward, OUTPUT);
        pinMode(rightWheelBackward, OUTPUT);

        // Inisialisasi Pin Sensor Ultrasonik
        pinMode(trig_front, OUTPUT); // Trigger mengirim suara (OUTPUT)
        pinMode(trig_right, OUTPUT); // Trigger mengirim suara (OUTPUT)
        
        pinMode(echo_front, INPUT);  // Echo menerima suara (INPUT) - INI YANG DIPERBAIKI
        pinMode(echo_right, INPUT);  // Echo menerima suara (INPUT) - INI YANG DIPERBAIKI

        Serial.begin(9600); 
        Serial.println("Test Komunikasi Serial");

        // Pastikan Motor Diam saat Baru Dinyalakan
        digitalWrite(leftWheelForward, LOW);
        digitalWrite(leftWheelBackward, LOW);
        digitalWrite(rightWheelForward, LOW);
        digitalWrite(rightWheelBackward, LOW);
    }

    void loop() {
        // 1. Baca Sensor 
        distance_front = readUltrasonic(trig_front, echo_front);
        distance_right = readUltrasonic(trig_right, echo_right);

        // 2. LOGIKA BANG-BANG (ON-OFF CONTROL)
        
        if (distance_front < 10) {
            stopRobot();
            turnLeft(); // Belok kiri tajam untuk menghindari tabrakan
        } 
        else {
            if (distance_right > (dist_target + toleransi)) {
                // KONDISI A: Terlalu Jauh dari dinding kanan (> 18cm)
                // AKSI: Belok Kanan agar mendekat ke dinding
                moveSlightRight(); 
            } 
            else if (distance_right < (dist_target - toleransi)) {
                // KONDISI B: Terlalu Dekat dengan dinding kanan (< 12cm)
                // AKSI: Belok Kiri agar menjauh dari dinding
                moveSlightLeft();
            } 
            else {
                // KONDISI C: Berada di area aman (12cm - 18cm)
                // AKSI: Jalan Lurus saja
                moveForward();
            }
        }
    }

    long readUltrasonic(int trigPin, int echoPin) {
        digitalWrite(trigPin, LOW); // Sensor berhenti mengirim gelombang ultrasonik
        delayMicroseconds(2); 
        digitalWrite(trigPin, HIGH); // Sensor akan mengirim gelombang ultrasonik
        delayMicroseconds(10); // Memberi pulsa HIGH selama 10 mikrodetik ke pin TRIG 
        digitalWrite(trigPin, LOW); // Sensor berhenti mengirim gelombang ultrasonik
        long duration = pulseIn(echoPin, HIGH, 30000); 
        // mengukur lama waktu (dalam mikrodetik) pin ECHO menerima sinyal HIGH
        long distance = duration * 0.034 / 2;
        /**
            - Kecepatan suara di udara ≈ 0,0343 cm/µs
            - selang * 0.0343 → menghitung jarak total tempuh suara (pergi + pulang)
            - Dibagi 2 → mendapatkan jarak sebenarnya ke objek (hanya satu arah)
        **/

        return distance;
    }


    // Fungsi Gerakan Sederhana (Full ON/OFF)
    void moveForward() {
        digitalWrite(leftWheelForward, HIGH);
        digitalWrite(rightWheelForward, HIGH);
    }

    void moveSlightLeft() {
        digitalWrite(leftWheelForward, LOW); // Motor kiri mati
        digitalWrite(rightWheelForward, HIGH); // Motor kanan jalan -> Robot belok kiri
    }

    void moveSlightRight() {
        digitalWrite(leftWheelForward, HIGH); // Motor kiri jalan
        digitalWrite(rightWheelForward, LOW); // Motor kanan mati -> Robot belok kanan
    }

    void stopRobot() {
        digitalWrite(leftWheelForward, LOW);
        digitalWrite(rightWheelForward, LOW);
    }
```

## Kode Program Wall Following + Proporsional ($P$)

## Kode Program Wall Following + PID