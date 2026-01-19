## Algorima PID

## Link Penting 🔗

* **Repository Github PID**
     * [Arduino-PID-Library](https://github.com/br3ttb/Arduino-PID-Library)
     * [Arduino-FOC](https://github.com/simplefoc/Arduino-FOC)

* **Video Youtube PID:**
    * [Pengenalan Sistem Kontrol PID Bagian 1](https://youtu.be/SZK5BvsQjX0?si=CIx5UTrpg4aZcN-7)
    * [Pengenalaan Sistem PID Bagian 2](https://youtu.be/c3nMN0EGsxM?si=FmpOoXi_JqUqaLIa)
    * [What is a PID Controller? | Digikey](https://youtu.be/tFVAaUcOm4I?si=lJfyjK0PIer2ZwmT)

* **Web Belajar:**
    * [Kontroller PID](https://www.kmtech.id/post/kontroller-pid-prinsip-kerja-aplikasinya-dalam-pengendalian-proses-keuntungan-kontroller-pid)
    * [PID (Proportional-Integral-Derivative) Controller](hhttps://putraekapermana.wordpress.com/2013/11/21/pid/)
    * [PID Tuning Guide](https://tlk-energy.de/blog-en/practical-pid-tuning-guide)
   
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
Rumus PID: 
![Alur PID](img/pid-flow.png)

![Rumus PID](img/rumus_pid.png)

* u(t) : Output kendali (misal: tegangan/PWM motor)
* e(t) : Error ouput pada waktu ke-t (e(t) = Setpoint - Nilai Sensor)
* Kp : Konstanta Proporsional, menentukan seberapa keras sistem bereaksi terhadap error saat ini.(nilainya ditentukan saat tunning)
* Ki : Konstanta Integrator, menjumlahkan error dari waktu ke waktu. Gunanya untuk memastikan u(t) benar-benar sampai ke titik target tanpa ada sisa error sedikitpun. (nilainya ditentukan saat tunning setelah Kp)
* Kd : Konstanta Derivative, mengukur seberapa cepat error berubah. Gunanya sebagai "peredam" atau rem otomatis agar u(t) melewati batas target (nilainya ditentukan saat tunning setelah Ki)
* dt : Selang waktu antar perhitungan. Ini sangat krusial dalam program karena integral dan derivative sangat bergantung pada ketepatan waktu.

## Kode program PID Sederhana
```cpp
```

## Pre-processing Input


## Tuning PID
Sumber: 
* [How to Tune a PID COntroller for an Inverted Pendulum | Digikey](https://youtu.be/hRnofMxEf3Q?si=CoE0QymsUkQEJXRM)
 * [PID Tuning Guide](https://tlk-energy.de/blog-en/practical-pid-tuning-guide)