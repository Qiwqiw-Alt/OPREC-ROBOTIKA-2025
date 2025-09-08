## Servo dan LCD

**Menggerakan servo dan menampilkan sudutnya di LCD**

* **Rangkaian Arduino**

![Rangkaian_LCD_Servo](Images/rangkaian_LCD_Servo2.png)

* **Komponen yang dibutuhkan:**
    * LCD I2C (1 buah)
    * Breadboard (1 buah)
    * Arduino UNO (1 buah)
    * Kabel jumper (Secukupnya)
    * Servo (1 buah)

* **Penjelasan rangkaian:**
    * GND Arduino dihubungkan ke jalur negatif di breadboard
    * 5V Arduino dihubungkan ke jalur positif di breadboard
    * Salah satu jalur negatif breadboard dihubungkan ke pin GND LCD
    * Salah satu jalur positif breadboard dihubungkan ke pin VCC LCD
    * A4 Arduino dihubungkan ke pin SDA LCD
    * A5 Arduino dihubungkan ke pin SCL LCD
    * Salah satu jalur negatif breadboard dihubungkan ke pin Ground Servo1 (kabel hitam)
    * Salah satu jalur positif breadboard dihubungkan ke pin Power Servo1 (kabel merah)
    * Digital pins 2 pada Arduino dihubungkan ke Signal Servo (kabel orange)

* **Program mengukur jarak dengan sensor ultrasonik dan Arduino**
```cpp
    #include <Wire.h>
    // mengimpor library komunikasi I2C, digunakan agar Arduino bisa berkomunikasi dengan modul I2C.
    #include <LiquidCrystal_I2C.h>
    // menggimpor library untuk mempermudah pengendalian LCD dengan modul I2C.
    #include <Servo.h> // mengimpor library bawaan Arduino untuk mengontrol motor servo
    LiquidCrystal_I2C lcd(0x27, 16, 2);
     /**
    membuat objek lcd dengan:
    - Alamat I2C = 0x27 (alamat bawaan modul I2C, bisa berbeda tergantung modul).
    - 16 kolom × 2 baris LCD.
    **/

    #define SERVO 2 // digunakan untuk memberi nama alias untuk pin digital 2 di Arduino
    Servo servo; // membuat sebuah objek bernama servo yang akan dipakai untuk mengendalikan servo


    void setup() {
        lcd.init(); // menginisialisasi LCD agar siap digunakan.
        lcd.backlight(); // menyalakan lampu latar LCD (supaya tulisan terlihat).

        servo.attach(SERVO); // menghubungkan objek servo dengan digital pin 2. Artinya, motor servo bisa dikontrol melalui pin itu.
    }

    void loop() {
        // loop pertama memutar servo dari sudut 0 derajat sampai 180 derajat
        for(int pos = 0; pos <= 180; pos++){
            servo.write(pos); // mengatur posisi servo ke sudut pos
            lcd.setCursor(0, 0); // tulis dibaris pertama
            lcd.print("Servo (derajat): ");  // tulis teks baris pertama
            lcd.setCursor(0, 1);
            lcd.print("     "); // hapus sisa angka sebelumnya  
            lcd.setCursor(0, 1); // tulis dibaris kedua
            lcd.print(pos);  // tampilkan sudut servo
            delay(10); // memberi delay selama 10 ms
        }
        
        delay(500); // memberi delay 500 ms
        
        // loop kedua memutar servo dari sudut 0 derajat sampai 180 derajat
        for(int pos = 180; pos >= 0; pos--){
            servo.write(pos); // mengatur posisi servo ke sudut pos
            lcd.setCursor(0, 0); // tulis dibaris pertama
            lcd.print("Servo (derajat): ");  // tulis teks baris pertama
            lcd.setCursor(0, 1);
            lcd.print("     "); // hapus sisa angka sebelumnya   
            lcd.setCursor(0, 1); // tulis dibaris kedua
            lcd.print(pos);  // tampilkan sudut servo
            delay(10); // memberi delay selama 10 ms
        }
    }
```