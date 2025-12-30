## Multihread Dasar

## Link Penting 🔗

* **Compiler:**
    * [Download Python](https://www.python.org/downloads/)
    * [Video Tutorial Install](https://youtu.be/1sKTa3r-SqE?si=-LiVcH28LvolAlRS)

* **Teks Editor / IDE:**
    * [Visual Studio Code](https://code.visualstudio.com/)
    * [Notepad++](https://notepad-plus-plus.org/downloads/)
    * [Vim](https://www.vim.org/download.php)

* **Online Compiler:**
    * [Programiz Python Compiler (Interpreter)](https://www.programiz.com/python-programming/online-compiler/)
    * [OnlineGDB Python Compiler (Interpreter)](https://www.onlinegdb.com/online_python_compiler)
    * [Oneline Python Compiler (Interpreter)](https://www.online-python.com/)

* **Sumber Belajar Tambahan:**
    * [Kevin Wood | Robotics & AI](https://youtu.be/Rm9Pic2rpAQ?si=UTYnkmdotUmo-14H)
    * [Bro Code Python MultiThreading](https://youtu.be/STEOavXqXkQ?si=fqD9VZsTFGXx7_qi)

-----

## Apa itu Multihread dalam pemrograman?
Multithread adalah teknik pemrograman yang memungkinkan suatu program menjalankan beberapa thread (alur eksekusi) secara bersamaan dalam suatu proses. Ini digunakan untuk meningkatkan kinerja dan responsifitas program, terutama saat menangani tugas-tugas yang bisa berjalan secara paralel, seperti membaca file sambil memproses data atau menjalankan beberapa tugas jaringan sekaligus.

## \.Manfaat
1. Pengelolaan tugas lebih baik
2. Responsif lebih baik
3. Pemanfaatan Maksimal CPU
4. Kinerja lebih cepat

## \.Source Code C++
```cpp
    #include <iostream>   // Library untuk input-output (seperti cout)
    #include <thread>     // Library utama untuk mendukung fungsi multi-threading
    #include <unistd.h>   // Library untuk fungsi sistem seperti sleep()

    using namespace std;

    // Fungsi yang akan dijalankan oleh thread pertama
    void thread1() {
        for(int i = 0; i < 5; i++){
            // Mencetak teks ke layar
            cout << "Ini loop 1" << endl;
            // Memberhentikan eksekusi selama 1 detik
            sleep(1);
        }
    }

    // Fungsi yang akan dijalankan oleh thread kedua dengan parameter input
    void thread2(int a) {
        for(int i = 0; i < 5; i++){
            // Mencetak teks beserta nilai parameter 'a'
            cout << "Ini loop " << a << endl;
            // Memberhentikan eksekusi selama 1 detik
            sleep(1);
        }
    }

    int main() {
        // Membuat objek thread 'th1' dan mulai menjalankan fungsi thread1
        thread th1(thread1);
        
        // Membuat objek thread 'th2' dan menjalankan fungsi thread2 dengan mengirim angka 2 sebagai argumen
        thread th2(thread2, 2);

        // .join() berfungsi untuk menunggu thread tersebut selesai bekerja 
        // sebelum program utama (main) ditutup.
        th1.join();
        th2.join();

        return 0;
    }
```

## \.Source Code Python
```python
    import threading  # Library untuk membuat dan mengelola thread
    import time       # Library untuk fungsi waktu seperti memberikan jeda (sleep)

    # Fungsi pertama yang menerima satu parameter 'a'
    def thread1(a):
        for i in range(5):
            # Mencetak teks dengan menggabungkan string dan nilai variabel 'a'
            print("Ini loop " + str(a))
            # Memberhentikan eksekusi thread ini selama 1 detik
            time.sleep(1)

    # Fungsi kedua tanpa parameter
    def thread2():
        for i in range(5):
            # Mencetak teks statis ke layar
            print("Ini loop 2")
            # Memberhentikan eksekusi thread ini selama 1 detik
            time.sleep(1)

    # Titik masuk utama program
    if __name__ == "__main__":
        # Membuat thread pertama (t1)
        # target: fungsi yang dijalankan, args: parameter yang dikirim (harus dalam bentuk tuple)
        t1 = threading.Thread(target=thread1, args=(1,))
        
        # Membuat thread kedua (t2)
        t2 = threading.Thread(target=thread2)

        # Menjalankan kedua thread secara bersamaan (paralel)
        t1.start()
        t2.start()

        # .join() memerintahkan program utama untuk menunggu sampai t1 dan t2 selesai
        # agar program tidak langsung tertutup sebelum proses loop selesai
        t1.join()
        t2.join()
```

## \.Multithread dengan ESP32
ES32 bisa menjalankan multithreading dengan menggunakan FreeRTOS, operasinya sama seperti operasi sebelumnya tetapi berbeda cara pemnggilannya. 

```cpp
// Fungsi untuk Task 1
void Task1(void *pvParameters) {
    while (1) { // Loop tak terbatas (mirip fungsi loop() utama)
        Serial.println("Ini Task 1");
        // Memberikan jeda 1000ms. portTICK_PERIOD_MS memastikan waktu akurat sesuai clock RTOS
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

// Fungsi untuk Task 2
    void Task2(void *pvParameters) {
        while (1) {
            Serial.println("  --> Ini Task 2");
            // Jeda 500ms (Task 2 berjalan lebih cepat dari Task 1)
            vTaskDelay(500 / portTICK_PERIOD_MS);
        }
    }

    void setup() {
        Serial.begin(115200);

        // Membuat Task 1 dan menguncinya di Core 0
        xTaskCreatePinnedToCore(
            Task1,               // Nama fungsi task
            "Task 1",            // Nama teks untuk identifikasi task
            1000,                // Ukuran Stack (memori yang dialokasikan untuk task ini)
            NULL,                // Parameter yang dikirim ke task
            1,                   // Prioritas task (makin tinggi angka, makin prioritas)
            NULL,                // Task handle
            0                    // ID Core (ESP32 punya Core 0 dan Core 1)
        );

        // Membuat Task 2 dan menguncinya di Core 1
        xTaskCreatePinnedToCore(Task2, "Task 2", 1000, NULL, 1, NULL, 1);
    }

    void loop() {
        // Dibiarkan kosong karena semua pekerjaan sudah diambil alih oleh Task 1 dan Task 2
    }
```

### Mengapa menggunakan RTOS di ESP32
    * 1 1. Paralelisme Sejati: ESP32 memiliki Dual-Core. Dengan xTaskCreatePinnedToCore, programmer bisa menyuruh Core 0 mengerjakan pembacaan sensor, sementara Core 1 fokus mengurus koneksi WiFi/HTTP. 
    * 2. Tidak Saling Menunggu: Di kode biasa, jika Anda menggunakan delay(1000), seluruh program berhenti. Di RTOS, saat Task 1 sedang vTaskDelay, prosesor tidak menganggur melainkan langsung mengerjakan Task 2.
    * 3. Manajemen Prioritas: Programmer bisa mengatur agar tugas yang kritis (seperti mematikan mesin jika ada bahaya) memiliki prioritas lebih tinggi daripada tugas sepele (seperti menyalakan lampu hias).


## \.Gimik Multithread dengan Arduino 
Operasinya berbeda dengan sebelumnya karena operasi ini sebenarnya bukan multithreading, melainkan meniru atau mengimplementasikan konsep multitasking (pseudomultithreading) di Arduino.

```cpp
    // Menyiapkan variabel untuk menyimpan waktu terakhir kali task dijalankan.
    // Gunakan 'unsigned long' karena nilai millis() bisa sangat besar dan tidak pernah negatif.
    unsigned long prevMillis1 = 0; 
    unsigned long prevMillis2 = 0;

    // Menentukan interval waktu (dalam milidetik) untuk masing-masing tugas.
    unsigned long interval1 = 1000; // Tugas 1 berjalan setiap 1 detik
    unsigned long interval2 = 1500; // Tugas 2 berjalan setiap 1.5 detik

    void setup() {
        // Memulai komunikasi serial dengan kecepatan 9600 bps
        Serial.begin(9600);
    }

    void loop() {
        // Fungsi millis() mengambil waktu (ms) sejak Arduino pertama kali dinyalakan.
        // Variabel ini diperbarui terus-menerus setiap kali loop berputar.
        unsigned long currentMillis = millis();

        // --- TASK 1 ---
        // Logika: Apakah (Waktu Sekarang - Waktu Terakhir) sudah lebih besar atau sama dengan Interval?
        if (currentMillis - prevMillis1 >= interval1) {
            // Simpan waktu sekarang sebagai 'Waktu Terakhir' untuk putaran berikutnya
            prevMillis1 = currentMillis; 
            
            // Kerjakan tugas di sini (Isinya)
            Serial.println("Halo dari Task 1"); 
        }

        // --- TASK 2 ---
        // Logika yang sama digunakan untuk tugas kedua dengan variabel waktu dan interval berbeda.
        if (currentMillis - prevMillis2 >= interval2) {
            // Update waktu terakhir khusus untuk Task 2
            prevMillis2 = currentMillis; 
            
            // Kerjakan tugas di sini (Isinya)
            Serial.println("Halo dari Task 2"); 
        }
        
        // Karena tidak ada delay(), loop ini bisa berputar ribuan kali per detik.
        // Ini memungkinkan Arduino mengecek kedua kondisi IF di atas hampir secara bersamaan.
    }
```

## \.Kekurangan Multithread
1. Overhead Sistem: Terlalu banyak thread bisa membebani CPU/Memori, malah menyebabkan penurunan performa
2. Ketergantungan pada Harware: Multithreading bakerja optimal pada sistem dengan multi-core CPU.
3. Masalah SInkronisasi
4. Debugging dan Testing Sulit: Bug yang muncul di lingkunganseringkali acak dan sulit direproduksi, karena hasil eksekusi bisa berbeda-beda tergantung urutan thread.

## \.Penggunaan Multithread pada Robotika
Dalam robotika, multithread dapat digunakan untuk berbagai aplikasi, yaitu
1. Pemisahan Kendali & Komunikasi: Satu thread fokus pada algoritma pergerakan (Inverse Kinematics), sementara thread lain mengurus pengiriman data ke aplikasi atau remote control.
2. Pembacaan Sensor Real-time: Membaca data sensor yang kritis (seperti IMU/Gyroscope atau Ultrasonic) tanpa terganggu oleh proses lain yang lambat (seperti menampilkan data ke layar LCD).
3. Keamanan (Failsafe): Membuat thread khusus yang terus memantau tombol darurat (emergency stop) atau mendeteksi tabrakan agar robot bisa langsung berhenti tanpa menunggu proses antrean kode utama selesai.