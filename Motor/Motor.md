## Motor

## Link Penting 🔗

* **Webiste**
    * [Arduino - DC Motor](https://arduinogetstarted.com/tutorials/arduino-dc-motor#google_vignette)
    * [Pengertian dan Prinsip Kerja Motor DC](https://www.arduinoindonesia.id/2022/10/pengertian-dan-prinsip-kerja-motor-dc.html)

* **Video Penjelasan Motor**
  * [Control a DC Motor with Arduino](https://youtu.be/XrJ_zLWFGFw?si=bdzLXK3J5y59en3O)
  * [https://youtu.be/Da4HY7HZ6h0?si=nz-yWU4X8OU-icQ0](https://youtu.be/Da4HY7HZ6h0?si=nz-yWU4X8OU-icQ0)
  * [bts7960 motor driver FULL CODE](https://youtu.be/Jn3R5u4gDZc?si=3Sn4Pq_EVZFwLKi6)

* **Repository Github**
    * Belum mencari

-----

## Apa itu Motor?
Motor DC adalah perangkat yang dapat mengubah energi listrik menjadi energi kinetik atau gerakan. Motor DC memiliki dua terminal atau kabel, yaitu power dan ground (GND). Motor ini memerlukan tegangan DC agar dapat bergerak. Biasanya digunakan pada perangkat elektronik yang menggunakan sumber listrik DC seperti kipas pendingin komputer dan mobil remote control. Dalam proyek menggunakan ESP32 atau Arduino, motor digunakan untuk menggerakkan roda, lengan robot, atau baling-baling.

## Perbedaan Analog & Digital Write
Dalam pemrograman ESP32/Arduino, cara memberi perintah ke motor berbeda tergantung kebutuhan:
* Digital Write: Memberikan instruksi "Sangat Sederhana". Hanya ada dua kondisi: HIGH (nyala penuh) atau LOW (mati total). Ini tidak bisa digunakan untuk mengatur kecepatan.
* Analog Write: Memberikan instruksi "Sangat Sederhana". Hanya ada dua kondisi: HIGH (nyala penuh) atau LOW (mati total). Ini tidak bisa digunakan untuk mengatur kecepatan.

## Apa itu PWM?
PWM (Pulse Width Modulation) adalah teknik untuk mendapatkan hasil analog dengan sarana digital. Sinyal dikirimkan dalam gelombang kotak yang berpindah anatara ON dan OFF dengan sangat cepat. Persentase waktu "ON" dalam satu periode disebut *Duty Cycle*.
* Duty Cycle 10%: Motor berputar sangat lambat.
* Duty Cycle 100%: Motor berputar pada kecepatan maksimal.

## Penjelasan Driver Motor
ESP32 tidak bisa menggerakkan motor secara langsung karena pin ESP32 hanya mengeluarkan arus kecil (sekitar 12-40mA), sedangkan motor butuh arus besar (bisa >500mA). Driver Motor (seperti L298N atau L293D) berfungsi sebagai "jembatan" atau saklar elektronik yang mengambil daya dari baterai eksternal dan menyalurkannya ke motor berdasarkan instruksi sinyal kecil dari ESP32.

Secara prinsip, baik Arduino maupun ESP32 membutuhkan driver motor karena alasan yang sama: keterbatasan arus (current limiting). Namun, ada perbedaan pada level tegangan sinyalnya.

### 1. Tegangan Sinyal (Logic Level)
* Arduino Uno: Menggunakan logika 5V. Sinyal HIGH yang dikirim ke driver motor adalah 5V. Driver motor seperti L298N sangat stabil menerima sinyal ini.
* Arduino Uno: Menggunakan logika 5V. Sinyal HIGH yang dikirim ke driver motor adalah 5V. Driver motor seperti L298N sangat stabil menerima sinyal ini.

### 2. Pin PWM
* Pada Arduino Uno: Hanya pin tertentu yang bisa mengatur kecepatan motor (pin bertanda `tilde ~`, seperti 3, 5, 6, 9, 10, 11). Programmer cukup menggunakan fungsi `analogWrite(pin, nilai)`.
* Pada ESP32: Hampir semua pin GPIO bisa digunakan untuk PWM. Namun, ESP32 menggunakan fungsi yang sedikit berbeda (seperti `ledcWrite`) karena ia memiliki kontrol frekuensi yang lebih canggih daripada Arduino Uno.

-----
### Skema Koneksi Umum (Wiring)
Ringkasan Perbandingan koneksi menggunakan Driver L298N:
|Komponen |	Koneksi Arduino Uno	| Koneksi ESP32 | Fungsi |
| :--- | :--- | :--- | :--- |
***VCC (Driver)*** | Baterai (+) 7-12V | Baterai (+) 7-12V | Sumber tenaga motor |
***GND (Driver)*** | Sumber tenaga motor | GND Baterai & GND ESP32 | Ground bersama (wajib) |
***IN1 & IN2*** | Pin Digital (misal 2 & 3) | Pin GPIO (misal 12 & 13) | Arah Putar |
***ENA (PWM)***| Pin PWM (misal 9) | Pin GPIO (misal 14) | Kecepatan |

## LPWM dan RPWM
LPWM dan RPWM adalah pin input pada beberapa jenis motor driver (pengendali motor DC), khususnya modul berbasis BTS7960 (sering disebut IBT-2 atau modul high-current 43A).
* LPWM dan RPWM adalah pin input pada beberapa jenis motor driver (pengendali motor DC), khususnya modul berbasis BTS7960 (sering disebut IBT-2 atau modul high-current 43A).
* LPWM (Left Pulse Width Modulation): Pin untuk mengatur kecepatan putaran ke arah kiri (Counter-Clockwise). Dengan mengatur kombinasi sinyal pada kedua pin ini, kita bisa menentukan arah sekaligus kecepatan motor.

## Menghitung Kecepatan
Untuk menghitung kecepatan motor secara teknis, programmer dapat menggunakan satuan RPM (Revolutions Per Minute). Secara matematis, jika menggunakan sensor Encoder, rumusnya adalah:

$$
RPM = \frac{Jumlah\ Pulsa\ per\ Menit}{PPR\ (Pulsa\ Per\ Revolusi)}
$$

Sedangkan untuk kecepatan linier robot (v):

$$
v = \pi \cdot D \cdot \frac{RPM}{60}
$$  

Dimana D adalah diameter roda.

## Penjelasan Pin Motor Driver


## Kode Program Menggunakan Motor dengN L298N dan Arduino
