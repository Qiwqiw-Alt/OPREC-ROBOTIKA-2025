## Task ESP32

## Apa itu FreeRTOS?
FreeRTOS adalah sebuah sistem operasi yang dirancang khusus untuk mikrokontroller, contohnya ESP32. Pada ESP32, FreeRTOS sudah ada secara default sehingga user tidak perlu menginstal sendiri. Pada ESP32, FreeRTOS berfungsi untuk mengatur jadwal ekseskusi kode. Tanpa FreeRTOS, ESP32 hanya bisa melakukan satu pekerjaan dalam satu waktu secara berurutan (sequential). Dengan FreeRTOS, user bisa membuat ESP32 seolah-olah mampu melakukan banyak hal sekaligus secara paralel.

## Apa itu Task?
Task adalah unit terkecil dari sebuah program yang dijalankan oleh FreeRTOS. Setiap Task di FreeRTOS memiliki:
* Function: fungsi yang dijalankan dalam task tersebut
* Name: nama bebas yang digunakan untuk mengidentifikasi task
* Stack Size: besar ukuran memori (RAM) yang dialokasikan untuk task tersebut
* Parameter: Data yang mau dikirim ke task (biasanya NULL)
* Priority: menentukan task mana yang harus didahulukan
* Task Handle: Untuk mengontrol task dari luar (bisa NULL)
* CoreID: 0 atau 1 (jika menngunakan xTaskCreatePinnedToCore)

### Contoh Task dengan xTaskCreatePinnedToCore
```cpp
    xTaskCreatePinnedToCore(
        Task1Function,   // Fungsi task
        "Task_Satu",     // Nama task
        2048,            // Stack size
        NULL,            // Parameter
        1,               // Prioritas
        NULL,            // Task handle
        0                // Jalankan di Core 0
    );
```

#### COntoh Task dengan xTaskCreate
```cpp
    xTaskCreate(
        TaskLampu,    // Fungsi task
        "BlinkTask",  // task
        2048,         // Stack size 
        NULL,         // Parameter 
        1,            // Prioritas
        NULL          // Task Handle (untuk hapus/pause task nanti)
    );
```


## Perbedaan Task dengan Thread pada Multihtead biasa
Secara konsep, keduanya bertujuan sama yaitu menjalankan unit kode secara paralel. Namun, cara Task dan Thread bekerja sangat berbeda. Berikut perbedaannya:
### 1. Penjadwalan
* Thread (Desktop): Menggunakan Time-Slicing. OS memberikan jatah waktu yang adil (misal 10ms) untuk tiap thread. Jika waktunya habis, thread diputus paksa untuk memberi giliran yang lain.
* Task (FreeRTOS): Menggunakan Priority-Based Preemptive Scheduling. Task dengan prioritas tertinggi akan terus menguasai CPU sampai dia selesai atau sengaja memilih untuk "tidur" (vTaskDelay). Ini disebut Deterministic, di mana kita bisa memprediksi kapan sebuah tugas akan selesai.

### 2. Manajeman Memori
* Thread (Desktop): Memiliki akses ke RAM yang sangat besar (Virtual Memory). Jika thread butuh memori tambahan, OS bisa mengalokasikannya secara dinamis dengan mudah.
* Task (FreeRTOS): RAM sangat terbatas. Saat membuat Task, kamu harus menentukan Stack Size secara manual di awal (misal 2048 byte). Jika kode kamu memakan memori lebih dari itu, sistem akan langsung crash (Stack Overflow).

### 3. Mekanisme Switching
* Thread (Desktop): Proses berpindah antar thread (Context Switch) sangat berat karena OS harus mengurus banyak hal seperti izin akses file, memori virtual, dan proteksi antar proses.
* Task (FreeRTOS): Didesain sangat ringan. Perpindahan antar task hanya memakan waktu beberapa microsecond karena FreeRTOS hanya perlu menyimpan isi register CPU ke dalam stack task tersebut.

## Contoh Source Code
```cpp
    void setup() {
        Serial.begin(115200);
        
        // Membuat Task untuk LED di Core 1
        xTaskCreatePinnedToCore(
            TaskBlink, 
            "Blink", 
            1024, 
            NULL, 
            1, 
            NULL, 
            1
        );
        
        // Membuat Task untuk Sensor di Core 0
       xTaskCreatePinnedToCore(
            TaskSensor,   
            "BacaSensor",  
            2048,             
            NULL,             
            2,                
            NULL,             
            0                 
        );
    }

    void loop() {} // loop() dikosongkan karena sudah pakai Task

    void TaskBlink(void *pv) {
        pinMode(2, OUTPUT); // Menjadikan Pin 2 sebagai OUTPUT berupa LED
        for(;;) { // Infinit Loop
            digitalWrite(2, !digitalRead(2));
            vTaskDelay(500 / portTICK_PERIOD_MS);
        }
    }

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
```

## Penjelasan Task Pada Source Code
### 1. Inisialisasi Fungsi Task
Sebelum program dijalankan, dibuat dua fungsi mandiri yaitu TaskBlink dan TaskSensor.
* TaskBlink: Berfungsi untuk membolak-balik logika (ON/OFF) LED.
* TaskSensor: Berfungsi untuk menghitung jarak menggunakan sensor ultrasonik.
Keduanya menggunakan struktur for(;;) agar terus berjalan selamanya tanpa berhenti.

### 2. Registrasi pada `void setup()`
Di dalam `setup()`, kedua fungsi tadi didaftarkan ke sistem FreeRTOS menggunakan perintah `xTaskCreatePinnedToCore`.
* Pada tahap ini, kita memberikan "bekal" kepada masing-masing task berupa jatah RAM (Stack), tingkat prioritas, dan instruksi harus berjalan di Core 0 atau Core 1.
* Setelah didaftarkan, FreeRTOS akan langsung mengambil alih dan menjalankan keduanya secara paralel.

### 3. Mengapa `void loop` kosong?
Pada pemrograman Arduino biasa, semua logika ditaruh di `loop()`. Namun di FreeRTOS, sudah terbuat looping sendiri dalam setiap task. Jadi, `void loop()` dibiarkan kosong karena tugasnya sudah digantikan oleh task-task yang sudah dibuat tadi.

### Penjalasan Bagian tiap Kode
| Bagian Kode | Penjelasan |
| :--- | :--- |
| `xTaskCreatePinnedToCore(...)` | Perintah untuk membuat task baru dan menguncinya di core tertentu agar tidak berpindah-pindah. |
| `2048 & 1024` | Kapasitas (RAM) untuk task tersebut. Task Sensor diberi lebih besar karena melakukan perhitungan matematika. |
| `Priority` | Task Sensor diberi prioritas 2 (lebih tinggi) agar pembacaan jarak lebih akurat dan tidak terhambat oleh kedipan LED. |
| `CoreID` | Menentukan lokasi eksekusi. Task Sensor di Core 0 dan Task Blink di Core 1. |
| `vTaskDelay(...)` | Perintah jeda pada task. Perintah ini wajib ada supata task lain punya kesempatan menggunakan CPU. Jika tidaka adam ESP32 bisa crash |

## Contoh Program lain

## Vide Demo Contoh Program lain