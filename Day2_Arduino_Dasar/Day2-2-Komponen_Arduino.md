# Komponen Arduino

**1. Arduino Uno R3**

![Arduino Uno R3](https://cdn.pixabay.com/photo/2014/09/10/23/44/integrated-circuit-441289_1280.jpg)

Arduino merupakan sebuah perangkat kreas dan lunak yang bersifat open-source. Arduino sering digunakan untuk merancang dan membuat perangkat elektronik yang salah satunya robot. Pada robot, arduino berperan sebagai otak dari robot mengendalikan sensor, aktuator, serta proses logika yang dibutuhkan.

**2. Breadboard**

![Breadboard](https://cdn-shop.adafruit.com/970x728/4539-03.jpg)

Breadboard adalah komponen elekronika yang berbentuk seperti papan yang memiliki banyak lubang. Lubang-lubang tersebut berfungsi untuk menempatkan dan menyusun piranti atau komponen-komponen elektronika menjadi rangkaian elektronika tanpa penyolderan.

**3. Kabel Jumper**

![Kabel Jumper Male to Male](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEj0WwBXz4eA8hSjtPsSaFB5rT6FIj2NZbC1xKpTKa38czXK61tjwFuCH7xxdRUAdVzU8Uqx2_f9BHsmJzYNFdLtvG_JuLzjDNs95f0x2LE8T3P5SGU3-il_OntZb9eK-_LiZhD7Ro0V9AlLDKJjHsqhZlhX6NJNiAlNFA-vqe-NjQIMU2vGDYcI8-Jg/s500/male%20to%20male.jpg)

Kabel jumper adalah kabel elektrik yang mempunyai pin konektor disetiap ujungnya dan memungkinkan untuk menghubungkan dua komponen yang melibatkan Arduino tanpa memerlukan solder. Kabel jumper banyak jenisnya, yaitu kabel jumper male to male, male to female dan female to female.

**4. Resistor**

![Resistor](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEgYgswCAN-MaOYNtnACfDuSMjKNCeyH6V1QEZJrvkHbpe6d8Zo567COM2JRfeDg-v3jyGSDEOV1FQe4ipOsIp3nF7c4fCShcQuKymg_8M_2W7Zh-cTvPUmeXkWhkFV2DBnmymmJtcM_Bt0/w320-h224/Electronic-Axial-Lead-Resistors-Array+%2528FILEminimizer%2529.jpg)

Resistor adalah komponen elektronik yang memiliki dua pin dan didesain untuk mengatur tegangan listrik dan arus listrik, dengan resistansi tertentu (tahanan) dapat memproduksi tegangan listrik di antara kedua pin, nilai tegangan terhadap resistansi berbanding lurus dengan arus yang mengalir.

**5. Servo**

![Micro Servo 9g](https://planetheli.com/image/cache/catalog/Product/Servo/SG-90-SG90-9g-Mirco-Servos-For-Futaba-Hitec-RC-2-800x500-0.JPG)

Servo atau motor servo adalah perangkat atau aktuator putar (motor) yang dirancang dengan sistem kontrol feedback loop tertutup (close loop), sehingga dapat memastikan dan menentukan posisi sudut dari poros output motor. Daya yang dimiliki motor servo bervariasi, mulai beberapa watt sampai ratusan watt. Motor servo digunakan untuk berbagai keperluan seperti sistem pelacakan, peralatan mesin dan lain sebagainya. Motor servo dibagi menjadi dua, yaitu motor serco AC dan DC. 

**6. LCD I2C**

![LCD I2C](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEh0rOsbnPj25SIX2N0B25BVcKMiaDFOgfVN6aSN2wPXiSAXC7UiuJV2B8CDYTT4C2XsoGSTIs1xY2wpEgwu08uXUwh7OcUjtaGDTuh1JiXnBXP9IalmmxUf2Z68xSZrRjmg8tX72CD1GZ5o/s320/8119219_b2f5dd90-e31c-4945-b529-1b408c0f3142_640_572%2527%2527.jpg)

LCD I2C adalah salah satu media penampil yang digunakan sebagai interface anatara mikrokontroler dengan USernya. LCD (Liquid Crystal Display) ini sudah dilengkapi dengan interface I2C (Inter-Integrated Circuit) sehingga lebih mudah digunakan dari pada LCD biasa.

**7. Sensor Jarak HC-SR04**

![Sensor Jarak HC-SR04](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEh7FTK0RCMiMrBNrnh19Clw1AtqnYTH9Vbm-hK4e0lEVcwKkBpzK0Al0kFypdSzfpGphlkS1e_N7qKouM9pKzQeG744OCyoEyQUmp5sgK3lfP0SIfjxOHAzspNfH8tGry-qsGrFcW1Wbg0tnXrzKs3SJZkg6XVqy2ulMZ5ZVVPI5uPKKCUOCTC6bkKa/s16000/ultrasonic.jpg)

Sensor Jarak HC-SR04 merupakan sensor yang menggunakan gelombang ultrasonik. Gelombang ultrasonik yaitu gelombang yang umum digunakan untuk mendeteksi keberadaan suatu benda dengan memperkirakan jarak antara sensor dan benda tersebut.

---

# Penjelasan Komponen Arduino

**1. Arduino Uno R3**

![Arduino UNO R3](Images/arduino_edit.png)

* **Kotak Merah (Power Pin)**
    * Vin → Input tegangan eksternal (7–12V biasanya).
    * 3.3V → Output tegangan 3.3V.
    * 5V → Output tegangan 5V (banyak dipakai untuk modul).
    * GND → Ground (negatif), ada beberapa pin GND.
    * IOREF → Memberi referensi tegangan untuk mikrokontroler.
    * RESET → Untuk me-reset board (juga bisa disambungkan ke tombol reset eksternal).
* **Kotak Orange (Analog Pins (A0–A5))**
    * Digunakan untuk membaca input analog (sensor).
    * Resolusi ADC (Analog to Digital Converter) = 10-bit (nilai 0–1023).
    * Bisa juga digunakan sebagai digital pin jika dibutuhkan.
* **Kotak Kuning (Digital Pins (0–13))**
    * Pin 0 (RX) dan 1 (TX) → digunakan untuk komunikasi serial (UART).
    * Pin 2–13 → digital input/output.
    * Pin dengan tanda ~ (misalnya 3, 5, 6, 9, 10, 11) → mendukung PWM (Pulse Width Modulation).
* **Kotak Hijau (USB Port)**
     → untuk komunikasi dan suplai daya.
* **Kotak Biru (Jack Barrel)**
     → untuk suplai daya eksternal (7–12V).

**2. Breadboard**

![Breadboard](Images/Breadboard.png)

* **Tanda plus (+)**
    * Biasanya digunakan sebagai rail positif.
    * Jalur ini kemudian dihubungkan ke pin VCC Arduino (5V atau 3.3V).
    * Dengan begitu, jalur + di breadboard bisa dipakai untuk membagikan tegangan ke banyak sensor atau modul sekaligus, tanpa harus mencolok langsung ke pin VCC Arduino berkali-kali.
* **Tanda min (-)**
    * Biasanya digunakan sebagai rail negatif.
    * Jalur ini dihubungkan ke pin GND Arduino.
    * Dengan begitu, jalur – di breadboard bisa dipakai untuk membagikan ground ke banyak sensor atau modul sekaligus.


**3. LCD I2C**

![LCD I2C](Images/LCD_I2C.png)

* **Pin VCC → Untuk memberi daya (biasanya 5V dari Arduino).**
* **Pin GND → Ground (harus disambungkan ke GND Arduino).**
* **SDA (Serial Data) → Jalur data untuk komunikasi I²C dan dihubungkan ke pin A4 di Arduino.**
* **SCL (Serial Clock) → Jalur clock untuk komunikasi I²C dan dihubungkan ke pin A5 di Arduino.**

**4. Servo**

![Servo](Images/Servo.png)

* **Kabel Coklat / Hitam → GND (Ground)**
    * Kabel ini dihubungkan ke GND Arduino atau power supply.
    * Fungsinya sebagai jalur negatif / referensi tegangan.
* **Kabel Merah (VCC)**
    * Kabel ini dihubungkan ke VCC Arduino atau power supply.
    * Fungsinya sebagai jalur positif
* **Kabel Oren (Signal Pin)**
    * Kabel ini menerima sinyal PWM (Pulse Width Modulation) dari Arduino.
    * Pin ini dihubungkan ke digital pin Arduino (misalnya D9, D10, atau pin lain yang bisa output PWM).
    * Sinyal PWM ini yang menentukan sudut putaran servo.

**5. Ultrasonik HC-SR04**

![HC-SR04](Images/Ultrasonik-HC-SR04.png)

* **Pin VCC → Untuk memberi daya (biasanya 5V dari Arduino).**
* **Pin GND → Ground (harus disambungkan ke GND Arduino).**
* **TRIG**
    * Pin input dari Arduino.
    * Arduino memberi pulsa HIGH singkat (10 µs) ke pin ini untuk memicu sensor mengirim gelombang ultrasonik.
* **ECHO**
    * Pin output dari sensor ke Arduino.
    * Sensor akan memberi sinyal HIGH selama gelombang ultrasonik berjalan ke objek dan kembali lagi (pantulan).
    * Lama durasi HIGH inilah yang dipakai Arduino untuk menghitung jarak.