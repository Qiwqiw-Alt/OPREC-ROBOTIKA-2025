## Algorima PID

## Link Penting 🔗

* **Repository Github PID**
     * [Arduino-PID-Library](https://github.com/br3ttb/Arduino-PID-Library)
     * [Arduino-FOC](https://github.com/simplefoc/Arduino-FOC)

* **Video Youtube PID:**
    * [Understanding PID Control](https://youtube.com/playlist?list=PLn8PRpmsu08pQBgjxYFXSsODEF3Jqmm-y&si=QZzJHKuHqNP3KZEs)

* **Web Belajar:**
    * [Kontroller PID](https://www.kmtech.id/post/kontroller-pid-prinsip-kerja-aplikasinya-dalam-pengendalian-proses-keuntungan-kontroller-pid)
    * [Algoritma PID: Jantung Pengendali Gerak pada Robot Modern](https://bce-sby.telkomuniversity.ac.id/algoritma-pid-jantung-pengendali-gerak-pada-robot-modern/)
    * []()
   
-----

## Apa itu Algoritma PID
PID adalah singkatan dari Proportional – Integral – Derivative, yaitu algoritma kontrol yang menghitung nilai keluaran (output) berdasarkan error (selisih antara nilai aktual/sensor dengan nilai yang diinginkan atau Setpoint).

## Komponen PID
Algoritma ini terdiri dari tiga komponen utama yang bekerja bersama, yaitu
* P (Proportional): Mengoreksi error saat ini. Semakin besar error, semakin kuat koreksinya.
* I (Integral): Mengakumulasi error dari waktu ke waktu. Gunanya untuk menghilangkan error kecil yang menetap yang tidak bisa diselesaikan oleh P saja.
* D (Derivative): Memprediksi error di masa depan berdasarkan tren saat ini. Ini berfungsi sebagai "rem" agar sistem tidak kebablasan (overshoot) saat mendekati setpoint.

## PID untuk MPU 9250
Sensor MPU 9250 memberikan data sudut (kemiringan). Jika robot miring ke depan 5 derajat, PID akan menghitung seberapa cepat motor harus berputar ke depan untuk mengembalikan robot ke posisi 0 derajat secara halus, tanpa membuat robot jatuh atau bergetar hebat.

## Istilah Penting dalam PID
* Setpoint: Target nilai yang diinginkan (Contoh: Sudut 0 derajat).
* Input/Process Variable: Nilai yang terbaca sensor saat ini (Contoh: MPU membaca miring 10 derajat).
* Tuning: Proses mencari nilai konstanta Kp, Ki, dan Kd yang pas agar robot stabil.

## Rumus PID (Sederhana)

## Kode program PID