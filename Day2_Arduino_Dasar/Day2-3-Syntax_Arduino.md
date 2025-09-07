## Syntax Dasar Arduino

**Kode program yang akan tampil ketika baru membuka Arduino IDE:**
```cpp
    void setup() {
    // put your setup code here, to run once:

    }

    void loop() {
    // put your main code here, to run repeatedly:

    }
```

**Penjelasan Sintaks:**

* `void setup(){}`: merupakan tempat tempat inisialisasi yang hanya dijalankan satu kali ketika Arduino pertama kali dinyalakan atau setelah di-reset.
    * Menyetel mode pin (input/output) dengan pinMode().
    * Menginisialisasi komunikasi serial (Serial.begin()).
    * Menginisialisasi sensor, LCD, atau modul lainnya.
* `void loop(){}`: merupakan blok kode utama yang akan dijalankan berulang-ulang selama Arduino menyala. Fungsi ini mirip dengan “program utama” yang terus berjalan secara infinite loop. Biasanya digunakan untuk:
    * Membaca data sensor.
    * Memberikan logika perhitungan atau pengambilan keputusan.
    * Mengontrol aktuator seperti LED, motor, buzzer, dsb.
    * Mengirim/menampilkan data ke serial monitor atau LCD.

---
**Contoh projek menyalakan LED dengan arduino:**

* **Rangkaian Arduino**
![Rangkaian_LED_Arduino](Images/rangkaian_LED_Sederhana.png)

* **Komponen yang dibutuhkan:**
    * Lampu LED (3 buah)
    * Arduino UNO (1 buah)
    * Breadboard (1 buah)
    * Resistor 220 Ohm (3 buah)
    * Kabel jumper (Secukupnya)

* **Penjelasan rangkaian:**
    * 

* **Program menyalakan LED dengan arduino**
```cpp
    #define LED1 2
    #define LED2 3
    #define LED3 4

    void setup(){
        pinMode(LED1, OUTPUT);
        pinMode(LED2, OUTPUT);
        pinMode(LED3, OUTPUT);
        
        Serial.begin(9600);
    }

    void loop(){
        digitalWrite(LED1, HIGH);
        delay(500); 
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        delay(500); 
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, HIGH);
        delay(500);
        digitalWrite(LED3, LOW);
    }
```