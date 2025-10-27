## LCD I2C

**Menampilkan teks pada LCD I2C dengan Arduino**

* **Rangkaian Arduino**

![Rangkaian_LCD_I2C](Images/rangkaian_LCD_I2C.png)

* **Komponen yang dibutuhkan:**
    * LCD I2C (1 buah)
    * Arduino UNO (1 buah)
    * Kabel jumper (Secukupnya)

* **Penjelasan rangkaian:**
    * GND Arduino dihubungkan ke pin GND LCD
    * 5V Arduino dihubungkan ke pin VCC LCD
    * A4 Arduino dihubungkan ke pin SDA LCD
    * A5 Arduino dihubungkan ke pin SCL LCD

* **Program menampilkan teks pada LCD I2C dengan Arduino**
```cpp
    #include <Wire.h> 
    #include <LiquidCrystal_I2C.h>
    LiquidCrystal_I2C lcd(0x27, 16, 2);  

    void setup(){
        lcd.init(); 
        lcd.backlight();
        lcd.setCursor(4, 0); 
        lcd.print(" OPREC"); 
        lcd.setCursor(2, 1); 
        lcd.print("ROBOTIKA UNS"); 
    }

    void loop(){
        /**
         loop kosong artinya LCD hanya menampilkan tulisan sekali di awal (setup()), lalu tidak ada perubahan setelah itu
        **/
    }
```