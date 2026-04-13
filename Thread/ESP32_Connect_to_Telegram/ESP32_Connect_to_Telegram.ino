#include <UniversalTelegramBot.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

// Konfigurasi WiFi dengan ESP32
const char* ssid = "Ambaspot";
const char* password = "altiano29";

// Bot Telegram
#define BOTtoken "123456789:ABCDefghIJKLmnopQRSTuv" 
#define CHAT_ID "987654321"

//WiFIClientSecure
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

const int trigPin = 5;
const int echoPin = 18;
float jarakTerakhir = 0;

void setup() {
    Serial.begin(115200);

    WiFi.begin(ssid, password);
    client.setInsecure();

    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }

    Serial.println("");                 // Mencetak baris baru
    Serial.println("WiFi connected.");  // Mencetak status koneksi berhasil
    Serial.println("IP address: ");     // Mencetak label alamat IP
    Serial.println(WiFi.localIP());     // Mencetak alamat IP yang didapatkan oleh ESP32

        
    // Membuat Task untuk Sensor di Core 0
    xTaskCreatePinnedToCore(
          TaskSensor,   
          "BacaSensor",  
          2048,             
          NULL,             
          1,                
          NULL,             
          0                 
      );

      xTaskCreatePinnedToCore(
        TaskTele,
        "KirimPesan",
        8192,
        NULL,
        2,
        NULL,
        1
      );
  }

  void loop() {} // loop() dikosongkan karena sudah pakai Task

  void TaskSensor(void *pv) {
      pinMode(5, OUTPUT);
      pinMode(18, INPUT);

      for(;;) { // Infinit Loop 
        // Logika HC-SR04
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
            
        long duration = pulseIn(echoPin, HIGH);
        jarakTerakhir = duration * 0.034 / 2;

        Serial.printf("[Sensor] Jarak terdeteksi: %.2f cm\n", jarakTerakhir);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
  }  

  void TaskTele(void *pv) {
      for(;;) {
        if (jarakTerakhir < 20 && jarakTerakhir > 0) {
            String message = "Objek dekat! di jarak: " + String(jarakTerakhir) + " cm";

          Serial.println("Mengirim pesan ke Telegram...");

          if (bot.sendMessage(CHAT_ID, message, "")) {
            Serial.println("Pesan tekirim kayaknya?");
          }

          vTaskDelay(10000 / portTICK_PERIOD_MS);
        }

      vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
  }
    