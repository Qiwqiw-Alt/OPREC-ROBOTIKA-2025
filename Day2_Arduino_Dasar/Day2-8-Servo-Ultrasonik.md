## Servo dan Ultrasonik

**Menggerakan servo berdasarkan ultrasonik**

* **Rangkaian Arduino**

![Rangkaian_Ultrasonik_Servo](Images/rangkaian_Ultrasonik_2servo.png)

* **Komponen yang dibutuhkan:**
    * Sensor Ultrasonik HC-SR04 (1 buah)
    * Breadboard (1 buah)
    * Arduino UNO (1 buah)
    * Kabel jumper (Secukupnya)
    * Servo (2 buah)

* **Penjelasan rangkaian:**
    * GND Arduino dihubungkan ke jalur negatif di breadboard
    * 5V Arduino dihubungkan ke jalur positif di breadboard
    * Salah satu jalur negatif breadboard dihubungkan ke pin GND Sensor Ultrasonik
    * Salah satu jalur positif breadboard dihubungkan ke pin VCC Sensor Ultrasonik
    * pin 6 digital pin dihubungkan ke pin TRIG Sensor Ultrasonik
    * pin 7 digital pin dihubungkan ke pin ECHO Sensor Ultrasonik
    * Salah satu jalur negatif breadboard dihubungkan ke pin Ground Servo1 (kabel hitam)
    * Salah satu jalur positif breadboard dihubungkan ke pin Power Servo1 (kabel merah)
    * Digital pins 2 pada Arduino dihubungkan ke Signal Servo (kabel orange)
    * Salah satu jalur negatif breadboard dihubungkan ke pin Ground Servo2 (kabel hitam)
    * Salah satu jalur positif breadboard dihubungkan ke pin Power Servo2 (kabel merah)
    * Digital pins 3 pada Arduino dihubungkan ke Signal Servo (kabel orange)

* **Program mengukur jarak dengan sensor ultrasonik dan Arduino**
```cpp
    #include <Servo.h> 
    #define SERVO1 2 
    #define SERVO2 3 
    #define TRIG 6 
    #define ECHO 7 

    Servo myServo1; 
    Servo myServo2; 

    long readUltrasonic(int trigPin, int echoPin) {
        digitalWrite(trigPin, LOW); 
        delayMicroseconds(2); 
        digitalWrite(trigPin, HIGH); 
        delayMicroseconds(10); 
        digitalWrite(trigPin, LOW); 
        long duration = pulseIn(echoPin, HIGH, 30000); 
        long distance = duration * 0.034 / 2;

        return distance;
    }

    void setup() {
        pinMode(TRIG, OUTPUT);
        pinMode(ECHO, INPUT);

        myServo1.attach(SERVO1);  
        myServo2.attach(SERVO2); 
        Serial.begin(9600);
    }

    void loop() {
        long jarak = readUltrasonic(TRIG, ECHO); 
        if(jarak < 50) {
            for(int pos = 0; pos < 180; pos++){
                myServo1.write(pos); 
                myServo2.write(pos); 
                delay(50); 
            }
            
            delay(5000);

            for(int pos = 180; pos <= 0; pos--){
                myServo1.write(pos);  
                myServo2.write(pos);  
                delay(50);  
            }
        }
    }
```