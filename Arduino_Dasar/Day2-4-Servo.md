## Servo/Motor Servo

**Menggerakan servo dengan Arduino**

* **Rangkaian Arduino**

![Rangkaian_Servo](Images/rangkaian_Servo.png)

* **Komponen yang dibutuhkan:**
    * Servo (1 buah)
    * Arduino UNO (1 buah)
    * Kabel jumper (Secukupnya)

* **Penjelasan rangkaian:**
    * GND Arduino dihubungkan ke pin Ground Servo (kabel hitam/coklat)
    * 5V Arduino dihubungkan ke pin Power Servo (kabel merah)
    * Digital pins 2 pada Arduino dihubungkan ke Signal Servo (kabel orange)

* **Program menyalakan Servo dengan Arduino**
```cpp
    #include <Servo.h> // mengimpor library bawaan Arduino untuk mengontrol motor servo
    Servo servo; // membuat sebuah objek bernama servo yang akan dipakai untuk mengendalikan servo

    #define SERVO1 2 // digunakan untuk memberi nama alias untuk digital pin 2 di Arduino

    void setup(){
        servo.attach(SERVO1); // menghubungkan objek servo dengan digital pin 2. Artinya, motor servo bisa dikontrol melalui pin itu.
        Serial.begin(9600); // memulai komunikasi serial
    }

    void loop(){
        // loop pertama memutar servo dari sudut 0 derajat sampai 180 derajat
        for(int pos = 0; pos <= 180; pos++){
            servo.write(pos); // mengatur posisi servo ke sudut pos
            delay(50); // memberi delay selama 50 ms
        }
    
        delay(500); // memberi delay 500 ms
        
        // loop kedua memutar servo dari sudut 180 derajat sampai 0 derajat
        for(int pos = 180; pos >= 0; pos--){
            servo.write(pos); // mengatur posisi servo ke sudut pos
            delay(50); // memberi delay selama 50 ms
        }
    }
```
