## LCD I2C

**Mengukur jarak dengan sensor ultrasonik dan Arduino**

* **Rangkaian Arduino**

![Rangkaian_Sensor_ultrasonik](Images/rangkaian_Ultrasonik.png)

* **Komponen yang dibutuhkan:**
    * Sensor Ultrasonik HC-SR04 (1 buah)
    * Breadboard (1 buah)
    * Arduino UNO (1 buah)
    * Kabel jumper (Secukupnya)

* **Penjelasan rangkaian:**
    * GND Arduino dihubungkan ke jalur negatif di breadboard
    * 5V Arduino dihubungkan ke jalur positif di breadboard
    * Salah satu jalur negatif breadboard dihubungkan ke pin GND Sensor Ultrasonik
    * Salah satu jalur positif breadboard dihubungkan ke pin VCC Sensor Ultrasonik
    * pin 6 digital pin dihubungkan ke pin TRIG Sensor Ultrasonik
    * pin 7 digital pin dihubungkan ke pin ECHO Sensor Ultrasonik

* **Program mengukur jarak dengan sensor ultrasonik dan Arduino**
```cpp
    #define TRIG1 6 // digunakan untuk memberi nama alias untuk  digital pin 6 di Arduino
    #define ECHO1 7 // digunakan untuk memberi nama alias untuk  digital pin 7 di Arduino

    /**
        TRIG1 (pin 6 Arduino) → untuk mengirim sinyal ultrasonik
        ECHO1 (pin 7 Arduino) → untuk menerima pantulan sinyal ultrasonik
    **/

    void setup(){
        pinMode(TRIG1, OUTPUT);
        pinMode(ECHO1, INPUT);

        /**
        - pinMode(..., OUTPUT); digunakan untuk memberi tahu Arduino bahwa pin tersebut digunakan 
        untuk keluaran (output), dalam hal ini untuk menyalakan TRIG.
        - pinMode(..., INPUT); digunakan untuk memberi tahu Arduino bahwa pin tersebut digunakan 
        untuk keluaran (intput), dalam hal ini untuk menyalakan ECHO.
        **/
        
        Serial.begin(9600); // memulai komunikasi serial untuk menampilkan hasil di monitor serial
    }

    void loop(){
        digitalWrite(TRIG1, HIGH); // Sensor akan mengirim gelombang ultrasonik
        delayMicroseconds(10); // Memberi pulsa HIGH selama 10 mikrodetik ke pin TRIG 
        digitalWrite(TRIG1, LOW); // Sensor berhenti mengirim gelombang ultrasonik
    
        double selang = pulseIn(ECHO1, HIGH); 
        // mengukur lama waktu (dalam mikrodetik) pin ECHO menerima sinyal HIGH

        double jarak = (selang * 0.0343) / 2.0;
        /**
            - Kecepatan suara di udara ≈ 0,0343 cm/µs
            - selang * 0.0343 → menghitung jarak total tempuh suara (pergi + pulang)
            - Dibagi 2 → mendapatkan jarak sebenarnya ke objek (hanya satu arah)
        **/

        Serial.print("Jarak: "); Serial.print(jarak); Serial.println("cm");
        // Menampilkan hasil pengukuran di Serial Monitor dalam satuan cm

        delay(1000); // Memberikan delay 1000 ms sebelum melakukan pengukuran berikutnya
    }
```