## ESP32 - ESP32 Communication dengan ESPNOW

**Menghubungkan ESP32 dengan ESP32 dengan ESPNOW**

## Link Penting 🔗

* **Web Belajar**
    * [Cara Komunikasi ESPNOW di ESP32](https://www.robotikindonesia.com/2023/06/cara-komunikasi-espnow-di-esp32.html)
    * 

* **Tutorial Video ESPNOW**
    * [Cara Komunikasi ESPNOW di ESP32](https://youtu.be/7Ojdo3lveB4?si=pYaobtHhPraZFkrM)
    * [Cara Mudah Komunikasi Dua Arah ESPNOW di ESP32](https://youtu.be/7OXLOJMt4TU?si=J3jBkWHphtvC46Oy)
    * [ESP-NOW - Peer to Peer ESP32 Network](https://youtu.be/bEKjCDDUPaU?si=nhjNfssQyhi4vUhg)
    * [Forget WiFi! This Wireless Method is WAY Better? (ESP-NOW)](https://youtu.be/sLW_r0OVyok?si=qdnsjBf9jXncibJM)

-----

**Pengantar ESPNOW**
ESPNOW adalah protokol komunikasi nirkabel connectionless yang dikembangkan oleh Espressif, memungkinkan perangkat ESP8266, ESP32, dan seri turunannya (seperti ESP32-S/C) berkomunikasi secara langsung peer-to-peer tanpa memerlukan router atau koneksi Wi-Fi tradisional. Protokol ini berbasis data-link layer (MAC layer) dengan latensi rendah, konsumsi daya rendah, dan kecepatan tinggi, mendukung mode unicast, broadcast, one-to-many, serta many-to-many, dengan enkripsi opsional (CCMP/AES-128).

**MAC Address**
Dalam ekosistem ESP32 dan ESP8226, MAC Address (Media Access Control) adalah identitas unik yang dimiliki setiap perangkat. MAC Address berfungsi sebagai almat tujuan, identitas pengirim, dan keamanan.

**Mendapatkan MAC Address**
Untuk mengetahui alamat MAC pada ESP32, dapat menggunakan libarary `WiFi.h` sperti contoh kode berikut

```cpp
    #include "WiFi.h"

    void setup(){
    Serial.begin(115200);
    WiFi.mode(WIFI_MODE_STA);
    Serial.print("MAC Address ESP32 Anda: ");
    Serial.println(WiFi.macAddress());
    }

    void loop(){}
```

**Komunikasi 1 Arah**
Pada komunikasi 1 arah dari 2 buah ESP32, 1 ESP32 berperan sebagai Pengirim dan 1 ESP32 berperan sebagai penerima. beikur contoh kode programnya:

***Kode Master/Pengirim***
```cpp
    #include <esp_now.h>       // Library utama untuk menggunakan fitur ESP-NOW
    #include <WiFi.h>          // Library WiFi (kita hanya pakai mode station, tidak konek ke router)

    // MAC Address tujuan (perangkat yang akan menerima data)
    // Untuk broadcast ke semua perangkat sekitar bisa pakai FF:FF:FF:FF:FF:FF
    uint8_t mac_addr_tujuan[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    // Contoh kalau mau kirim ke 1 ESP tertentu:
    // uint8_t mac_addr_tujuan[] = {0x24, 0x0A, 0xC4, 0x12, 0x34, 0x56};

    // Definisi struktur data yang akan dikirim
    // Struktur ini HARUS SAMA persis di pengirim dan penerima
    typedef struct struct_message {
        char a[32];         // String maksimal 31 karakter + null terminator
        int b;              // Bilangan bulat
        float c;            // Bilangan desimal
        bool d;             // Nilai true/false
    } struct_message;

    // Buat variabel dengan tipe data struktur di atas
    struct_message data_ku;

    // Variabel untuk menyimpan informasi peer (tujuan)
    esp_now_peer_info_t peerInfo;

    // Fungsi callback yang dipanggil OTOMATIS setelah pengiriman selesai
    // Parameter:
    //   mac_addr → alamat MAC tujuan yang baru saja dikirimi
    //   status   → ESP_NOW_SEND_SUCCESS atau gagal
    void cb_terkirim(const uint8_t *mac_addr, esp_now_send_status_t status) {
        Serial.print("\r\nStatus Pengiriman Paket Terakhir → ");
        // Operator ternary (if singkat)
        Serial.println(status == ESP_NOW_SEND_SUCCESS ? 
                    "Pengiriman Sukses ✓" : 
                    "Pengiriman Gagal ✗");
    }

    void setup() {
        Serial.begin(115200);
        Serial.println("\n\nESP-NOW - Pengirim (Master)");
        delay(100);

        // Set WiFi ke mode Station (penting untuk ESP-NOW)
        // Tidak perlu koneksi ke Access Point
        WiFi.mode(WIFI_STA);

        // Inisialisasi protokol ESP-NOW
        if (esp_now_init() != ESP_OK) 
        {
            Serial.println("Error: Gagal menginisialisasi ESP-NOW");
            while(true);    // berhenti selamanya (loop tak berujung)
        }

        // Daftarkan fungsi callback untuk mengetahui hasil pengiriman
        esp_now_register_send_cb(cb_terkirim);

        // --- Persiapan Peer (tujuan) ---
        
        // Salin alamat MAC tujuan ke struktur peerInfo
        memcpy(peerInfo.peer_addr, mac_addr_tujuan, 6);
        
        peerInfo.channel = 0;       // 0 = pakai channel yang sama dengan WiFi saat ini
        peerInfo.encrypt = false;   // true = pakai enkripsi (harus set key juga)

        // Tambahkan peer ke daftar
        if (esp_now_add_peer(&peerInfo) != ESP_OK) 
        {
            Serial.println("Error: Gagal menambahkan peer");
            while(true);
        }

        Serial.println("ESP-NOW siap! Mulai mengirim data setiap 2 detik...");
    }

    void loop() {
        // Isi data yang mau dikirim
        strcpy(data_ku.a, "Dari Master");      // copy string ke field a
        data_ku.b = random(1, 21);             // random 1 sampai 20
        data_ku.c = 3.14 + random(0, 100)/100.0; // contoh: 3.14 ~ 3.99
        data_ku.d = !data_ku.d;                // toggle true/false setiap pengiriman

        Serial.printf("Mengirim → %s | %d | %.2f | %s\n",
                    data_ku.a, data_ku.b, data_ku.c, data_ku.d ? "true" : "false");

        // Kirim data sebenarnya
        // Parameter: alamat tujuan, pointer data, ukuran data dalam byte
        esp_err_t result = esp_now_send(mac_addr_tujuan, 
                                    (uint8_t *) &data_ku, 
                                    sizeof(data_ku));

        // Cek hasil pengiriman (ini hanya status queue, bukan status sampai tujuan)
        if (result == ESP_OK) {
            Serial.println("  → Data masuk ke queue pengiriman");
        } else {
            Serial.println("  → Gagal masuk queue!");
        }

        // Tunggu 2 detik sebelum kirim lagi
        delay(2000);
    }
```

**Komunikasi 2 Arah**