## Syntax Dasar Arduino

**Kode Program:**
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