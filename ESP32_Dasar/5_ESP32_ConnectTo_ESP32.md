## ESP32 - ESP32 Communication dengan ESPNOW

**Menghubungkan ESP32 dengan ESP32 dengan ESPNOW**

## Link Penting 🔗

* **Web Belajar**
    * [Cara Komunikasi ESPNOW di ESP32](https://www.robotikindonesia.com/2023/06/cara-komunikasi-espnow-di-esp32.html)
    * [Cara Komunikasi Dua Arah ESPNOW di ESP32](https://www.robotikindonesia.com/2023/07/cara-komunikasi-dua-arah-espnow-di-esp32.html)

* **Tutorial Video ESPNOW**
    * [Cara Komunikasi ESPNOW di ESP32](https://youtu.be/7Ojdo3lveB4?si=pYaobtHhPraZFkrM)
    * [Cara Mudah Komunikasi Dua Arah ESPNOW di ESP32](https://youtu.be/7OXLOJMt4TU?si=J3jBkWHphtvC46Oy)
    * [ESP-NOW - Peer to Peer ESP32 Network](https://youtu.be/bEKjCDDUPaU?si=nhjNfssQyhi4vUhg)
    * [Forget WiFi! This Wireless Method is WAY Better? (ESP-NOW)](https://youtu.be/sLW_r0OVyok?si=qdnsjBf9jXncibJM)

-----

## Pengantar ESPNOW
ESPNOW adalah protokol komunikasi nirkabel connectionless yang dikembangkan oleh Espressif, memungkinkan perangkat ESP8266, ESP32, dan seri turunannya (seperti ESP32-S/C) berkomunikasi secara langsung peer-to-peer tanpa memerlukan router atau koneksi Wi-Fi tradisional. Protokol ini berbasis data-link layer (MAC layer) dengan latensi rendah, konsumsi daya rendah, dan kecepatan tinggi, mendukung mode unicast, broadcast, one-to-many, serta many-to-many, dengan enkripsi opsional (CCMP/AES-128).

## MAC Address
Dalam ekosistem ESP32 dan ESP8226, MAC Address (Media Access Control) adalah identitas unik yang dimiliki setiap perangkat. MAC Address berfungsi sebagai almat tujuan, identitas pengirim, dan keamanan.

## Mendapatkan MAC Address
Untuk mengetahui alamat MAC pada ESP32, dapat menggunakan libarary `WiFi.h` sperti contoh kode berikut

```cpp
    #include "WiFi.h"

    void setup(){
        // Inisialisasi komunikasi serial dengan baud rate 115200
        // Ini adalah kecepatan standar yang paling umum digunakan di ESP32
        Serial.begin(115200);

        // Mengatur ESP32 ke mode Station (WIFI_STA)
        // Mode ini WAJIB digunakan untuk hampir semua aplikasi ESP-NOW, scan WiFi, atau koneksi client
        // Mode lainnya: WIFI_MODE_AP (Access Point), WIFI_MODE_APSTA (keduanya sekaligus)
        WiFi.mode(WIFI_MODE_STA);

        // Mencetak alamat MAC Address dari ESP32 dalam mode Station
        Serial.print("MAC Address ESP32: ");
        Serial.println(WiFi.macAddress());
    }

    void loop(){}
```

## Komunikasi 1 Arah
Pada komunikasi 1 arah dari 2 buah ESP32, 1 ESP32 berperan sebagai pengirim dan 1 ESP32 berperan sebagai penerima. Berikut contoh kode programnya:

### Kode Master/Pengirim
```cpp
    #include <esp_now.h>       // Library utama untuk menggunakan fitur ESP-NOW
    #include <WiFi.h>          // Library WiFi (hanya pakai mode station, tidak konek ke router)

    // MAC Address tujuan (perangkat yang akan menerima data)
    // Untuk broadcast ke semua perangkat ser bisa pakai FF:FF:FF:FF:FF:FF
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
                    "Pengiriman Sukses" : 
                    "Pengiriman Gagal");
    }

    void setup() {
        Serial.begin(115200);
        Serial.println("\n\nESP-NOW - Pengirim (Master)");
        delay(100);

        // Set WiFi ke mode Station (penting untuk ESP-NOW)
        // Tidak perlu koneksi ke Access Point
        WiFi.mode(WIFI_STA);

        // Inisialisasi protokol ESP-NOW
        if (esp_now_init() != ESP_OK) {
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
        if (esp_now_add_peer(&peerInfo) != ESP_OK) {
            Serial.println("Error: Gagal menambahkan peer");
            while(true);
        }
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

### Kode Slave/Penerima
```cpp
    #include <esp_now.h>      // Library utama untuk protokol ESP-NOW
    #include <WiFi.h>         // Library WiFi, hanya pakai mode Station (tidak konek ke router)

    // Struktur data yang akan diterima
    // STRUKTUR INI HARUS SAMA PERSIS dengan yang ada di pengirim
    typedef struct struct_message {
        char a[32];       // Array char untuk menyimpan string (max 31 karakter + null)
        int b;            // Integer
        float c;          // Bilangan desimal
        bool d;           // Nilai boolean (true/false)
    } struct_message;

    // Variabel global untuk menyimpan data yang diterima
    struct_message data_ku;

    // Fungsi callback yang akan dipanggil OTOMATIS setiap kali ada data masuk
    // Parameter:
    //   mac_addr     → alamat MAC pengirim
    //   dataDiterima → pointer ke data yang diterima (raw bytes)
    //   panjang      → jumlah byte yang diterima
    void cb_terima(const uint8_t *mac_addr, const uint8_t *dataDiterima, int panjang) {
        // Salin data yang diterima ke dalam struktur 
        // Penting: ukuran data yang disalin harus sama dengan struktur
        memcpy(&data_ku, dataDiterima, sizeof(data_ku));

        // Tampilkan informasi ke Serial Monitor
        Serial.print("Bytes diterima: ");
        Serial.println(panjang);

        // Tampilkan isi data sesuai tipe
        Serial.print("Char  : ");
        Serial.println(data_ku.a); // akan menampilkan string

        Serial.print("Int   : ");
        Serial.println(data_ku.b);

        Serial.print("Float : ");
        Serial.println(data_ku.c, 3); // tampilkan 3 angka di belakang koma

        Serial.print("Bool  : ");
        Serial.println(data_ku.d ? "true" : "false");

        // Tampilkan alamat MAC pengirim (opsional, untuk debugging)
        Serial.print("Dari MAC: ");
        for (int i = 0; i < 6; i++) {
            Serial.print(mac_addr[i], HEX);
            if (i < 5) Serial.print(":");
        }
        Serial.println();

        Serial.println("---------------------------");
    }

    void setup() {
        Serial.begin(115200);
        Serial.println("\nESP-NOW RECEIVER");
        Serial.println("Menunggu data...\n");
        delay(100);

        // Set WiFi ke mode Station (WAJIB untuk ESP-NOW)
        WiFi.mode(WIFI_STA);

        // Inisialisasi ESP-NOW
        if (esp_now_init() != ESP_OK) {
            Serial.println("Error: Gagal menginisialisasi ESP-NOW");
            while (true);   // Berhenti selamanya jika gagal
        }

        // Daftarkan fungsi callback untuk menerima data
        // Setelah ini, setiap ada data masuk → cb_terima() akan dipanggil otomatis
        esp_now_register_recv_cb(cb_terima);

        Serial.println("ESP-NOW Receiver sudah siap!");
        Serial.println("=============================\n");
    }


    void loop() {
        delay(500);   // opsional: agar tidak terlalu cepat refresh serial
    }
```

## Komunikasi 2 Arah
Pada komunikasi 2 arah dari 2 buah ESP32, Kedua ESP32 berperan sebagai pengirim penerima. Berikut contoh kode programnya:

### Kode Master
```cpp
    #include <WiFi.h>         // Library untuk mengatur mode WiFi
    #include <esp_now.h>      // Library utama protokol ESP-NOW

    // MAC Address perangkat TUJUAN (yang akan menerima data)
    // Ganti dengan MAC Address ESP yang benar-benar jadi receiver
    uint8_t mac_addr_tujuan[] = {0xA4, 0xCF, 0x12, 0x05, 0xD5, 0x98};

    // Definisi struktur data yang akan dikirim & diterima
    // STRUKTUR INI HARUS SAMA di kedua perangkat
    typedef struct struct_message {
        unsigned long waktu;    // Menyimpan nilai millis() saat pengiriman
    } struct_message;

    // Variabel global untuk menyimpan data yang akan dikirim/diterima
    struct_message data_ku;

    // Variabel untuk menyimpan informasi peer (tujuan)
    esp_now_peer_info_t peerInfo;

    // Callback: dipanggil setelah ESP-NOW mencoba mengirim data
    void cb_kirim(const uint8_t *mac_addr, esp_now_send_status_t status) {
        Serial.print("Status Pengiriman: ");
        if (status == ESP_NOW_SEND_SUCCESS) {
            Serial.println("Sukses");
        } else {
            Serial.println("Gagal");
        }
    }

    // Callback: dipanggil OTOMATIS setiap kali menerima data via ESP-NOW
    void cb_terima(const uint8_t *mac_addr, const uint8_t *dataDiterima, int panjang) {
        // Salin data yang diterima ke struktur
        memcpy(&data_ku, dataDiterima, sizeof(data_ku));

        // Tampilkan informasi untuk debug
        Serial.print("Bytes diterima: ");
        Serial.println(panjang);

        Serial.print("Waktu Dikirim  : ");
        Serial.print(data_ku.waktu);
        Serial.println(" ms");

        Serial.print("Waktu Diterima : ");
        Serial.print(millis());
        Serial.println(" ms");

        // Hitung selisih waktu (latency) dalam milidetik
        unsigned long latency = millis() - data_ku.waktu;
        Serial.print("Latency (bolak-balik): ");
        Serial.print(latency);
        Serial.println(" ms");

        Serial.println("-----------------------------");
    }


    void setup() {
        Serial.begin(115200);
        Serial.println("\nESP-NOW - Bidirectional Test");
        Serial.println("============================\n");
        delay(100);

        // Set mode WiFi ke Station (WAJIB untuk ESP-NOW)
        WiFi.mode(WIFI_STA);

        // Inisialisasi ESP-NOW
        if (esp_now_init() != ESP_OK) 
        {
            Serial.println("Error: Gagal inisialisasi ESP-NOW");
            while (true);   // Berhenti selamanya jika gagal
        }

        // Daftarkan callback untuk status pengiriman
        esp_now_register_send_cb(cb_kirim);

        // --- Konfigurasi Peer (hanya diperlukan jika akan mengirim) ---
        memcpy(peerInfo.peer_addr, mac_addr_tujuan, 6);   // Salin MAC tujuan
        peerInfo.channel = 0;           // 0 = ikut channel WiFi saat ini
        peerInfo.encrypt = false;       // Tanpa enkripsi

        // Tambahkan peer ke daftar
        if (esp_now_add_peer(&peerInfo) != ESP_OK) 
        {
            Serial.println("Error: Gagal menambahkan peer");
            while (true);
        }

        // Daftarkan callback untuk menerima data
        esp_now_register_recv_cb(cb_terima);

        Serial.println("ESP-NOW siap!");
    }


    void loop() {
        // Isi data yang akan dikirim
        data_ku.waktu = millis();   // Catat waktu saat ini

        // Kirim data ke MAC tujuan yang sudah didaftarkan
        esp_err_t result = esp_now_send(mac_addr_tujuan, 
                                    (uint8_t *) &data_ku, 
                                    sizeof(data_ku));

        // (Opsional) Cek status antrian pengiriman
        if (result == ESP_OK) {
            Serial.println("Data masuk antrian pengiriman");
        } else {
            Serial.println("Gagal memasukkan ke antrian!");
        }

        delay(2000);   // Kirim setiap 2 detik
    }
```

### Kode Slave
```cpp
    #include <WiFi.h>
    #include <esp_now.h>

    // MAC Address tujuan akhir (ke mana data akan diforward/dikirim ulang)
    uint8_t mac_addr_tujuan[] = {0xF0, 0x08, 0xD1, 0x62, 0xD6, 0xE8};

    // Struktur data yang sama harus digunakan di semua perangkat
    typedef struct struct_message {
        unsigned long waktu;    // waktu pengiriman (biasanya millis())
    } struct_message;

    // Variabel untuk menyimpan data yang diterima / akan dikirim
    struct_message data_ku;

    // Struktur informasi peer (untuk pengiriman)
    esp_now_peer_info_t peerInfo;


    // Callback: dipanggil setelah ESP-NOW mencoba mengirim data
    void cb_kirim(const uint8_t *mac_addr, esp_now_send_status_t status) 
    {
        Serial.print("Status Pengiriman: ");
        if (status == ESP_NOW_SEND_SUCCESS) {
            Serial.println("Sukses ✓");
        } else {
            Serial.println("Gagal ✗");
        }
    }


    // Callback: dipanggil setiap kali menerima data via ESP-NOW
    void cb_terima(const uint8_t *mac_addr, const uint8_t *dataDiterima, int panjang) {
        // 1. Salin data yang diterima ke struktur 
        memcpy(&data_ku, dataDiterima, sizeof(data_ku));

        // 2. Langsung kirim ulang data yang baru diterima ke tujuan
        esp_err_t result = esp_now_send(mac_addr_tujuan, 
                                    (uint8_t *) &data_ku, 
                                    sizeof(data_ku));

        // 3. Tampilkan informasi untuk debugging
        Serial.print("Bytes diterima: ");
        Serial.println(panjang);

        Serial.print("Waktu yang diteruskan: ");
        Serial.print(data_ku.waktu);
        Serial.println(" ms");

        // Opsional: Tampilkan status pengiriman ulang langsung di sini
        Serial.print("Forward status: ");
        if (result == ESP_OK) {
            Serial.println("Masuk antrian");
        } else {
            Serial.println("Gagal masuk antrian");
        }

        Serial.println("-----------------------------");
    }

    void setup() {
        Serial.begin(115200);
        delay(100);
        Serial.println("\nESP-NOW REPEATER / FORWARDER");
        Serial.println("============================\n");

        // Set mode WiFi ke Station → WAJIB untuk ESP-NOW
        WiFi.mode(WIFI_STA);

        // Inisialisasi ESP-NOW
        if (esp_now_init() != ESP_OK) 
        {
            Serial.println("Error: Gagal inisialisasi ESP-NOW");
            while (true);
        }

        // Daftarkan callback status pengiriman
        esp_now_register_send_cb(cb_kirim);

        // --- Konfigurasi peer tujuan (ke mana kita akan forward) ---
        memcpy(peerInfo.peer_addr, mac_addr_tujuan, 6);
        peerInfo.channel = 0;       // 0 = pakai channel otomatis
        peerInfo.encrypt = false;

        // Tambahkan peer
        if (esp_now_add_peer(&peerInfo) != ESP_OK) 
        {
            Serial.println("Error: Gagal menambahkan peer tujuan");
            while (true);
        }

        // Daftarkan callback penerimaan data
        esp_now_register_recv_cb(cb_terima);

        Serial.println("ESP-NOW Repeater sudah aktif!");
        Serial.println("Menunggu data untuk diteruskan ke:");
        Serial.printf("MAC: %02X:%02X:%02X:%02X:%02X:%02X\n\n",
                    mac_addr_tujuan[0], mac_addr_tujuan[1], mac_addr_tujuan[2],
                    mac_addr_tujuan[3], mac_addr_tujuan[4], mac_addr_tujuan[5]);
    }

    void loop() {
        
    }
```