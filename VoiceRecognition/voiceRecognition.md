## VOice Recognition

## Link Penting 🔗

* **Repository Github PID**
   
* **Video Youtube Voice Recognition:**

* **Web Belajar:**
   
-----

## Apa itu Voice Recognition?
Voice Recognition adalah proses pengubahan sinyal suara (gelombang akustik) menjadi data digital yang kemudian dianalisis oleh algoritma untuk mencari kecocokan dengan pola yang sudah dipelajari. Dengan Voice Recognition, robot dapat mendengarkan, mengenali, dan menjalankan perintah berdasarkan suara manusia atau mendeteksi pola suara tertentu (seperti ketukan musik).

Dalam proyek Robot Tari, teknologi ini bisa digunakan dalam dua cara:
* 1. Voice Recognition adalah teknologi yang memungkinkan robot untuk mendengarkan, mengenali, dan menjalankan perintah berdasarkan suara manusia atau mendeteksi pola suara tertentu (seperti ketukan musik).
* 2. Beat Detection (Analisis Musik): Robot tidak mengenali kata, melainkan mendeteksi frekuensi dan ketukan (beat) musik agar gerakannya selaras dengan irama.

## Komponen Elekronik untuk Voice Recognition
Agar robot bisa melakukan voice recognition, diperlukan beberapa komponen, yaitu
### 1. Mikrofon (Sensor Suara)
Ada dua jenis mikrofon yang umum digunakan:

- **Mikrofon Analog**  
  **Contoh:** KY-038, MAX9814  
  Menghasilkan tegangan yang berubah-ubah sesuai kerasnya suara. Sangat mudah digunakan di Arduino Uno untuk deteksi ketukan musik sederhana.

- **Mikrofon Digital**  
  **Contoh:** INMP441 (I2S)  
  Mengirimkan data digital yang sangat bersih. Sangat cocok untuk ESP32 guna memproses suara yang lebih kompleks (seperti mengenali kata).

### 2. Mikrokontroler
- **Arduino**
    Cocok untuk deteksi suara sederhana (seperti sensor tepuk tangan atau deteksi keras-lemahnya suara/amplitudo).
- **ESP32**
    Memiliki kecepatan proses yang tinggi, sehingga mampu menjalankan algoritma FFT (Fast Fourier Transform). FFT digunakan untuk memecah suara menjadi frekuensi (Bass, Mid, Treble) agar gerakan robot lebih presisi mengikuti alunan musik.
- **Modul Suara Khusus**
    **Contoh:** VR Module V3
    Jika mikrokontroler tidak cukup kuat, RObot bisa menggunakan modul tambahan yang sudah memiliki chip pengenal suara sendiri di dalamnya.


    