## Invers Kinematik

## Link Penting 🔗

* **Repository Github Invers Kinematik**
    * []()

* **Video Youtube Invers Kinematik:**
    * [Coding Challenge #64.3: Inverse Kinematics - Fixed Point](https://youtu.be/RTc6i-7N3ms?si=L6iEj5FAcCngYW-b)
    * [Coding Challenge #64.2: Inverse Kinematics](https://youtu.be/hbgDqyy8bIw?si=C2o0OQYByqSJ1E1Z)
    * [Inverse Kinematics of Robots | Robotics 101](https://youtu.be/1-FJhmey7vk?si=OPkc01EL7FgPdLQ7)
    * [Inverse Kinematics (with solved example) | Planar RRP robot | Robotics 101](https://youtu.be/EzZDRwmk8Nw?si=6OU9hy040xKr6-GG)

* **Web Belajar:**
    * [Inverse Kinematics Basics Tutorial](https://oscarliang.com/inverse-kinematics-and-trigonometry-basics/)
    * [Inverse Kinematics for Hexapod and Quadruped Robots](https://oscarliang.com/inverse-kinematics-implementation-hexapod-robots//)
    * [Arduino Hexapod Robot, IK Algorithm and Source code](https://oscarliang.com/arduino-hexapod-robot/)
   
-----

## Apa itu Invers Kinematik
Invers kinematika adalah metode analisis yang digunakan untuk mengubah koordinat Kartesius menjadi nilai-nilai pada ruang sendi (joint space). Melalui persamaan invers kinematika, dapat ditenemukan hubungan antara geometri sendi robot dengan koordinat posisi yang umum dipakai untuk mendeskripsikan letak suatu objek. Dengan pendekatan ini, pergerakan robot dapat ditentukan hanya berdasarkan posisi koordinat end-effector (misalnya ujung kaki saat berjalan), sehingga tidak lagi diperlukan penentuan manual sudut putar untuk setiap motor servo secara terpisah. Oleh karena itu, metode invers kinematika dapat dianggap sebagai kebalikan dari pendekatan trial-and-error yang biasanya memerlukan pengaturan berulang untuk mencapai posisi yang diinginkan.

### Mengapa Invers Kinematik Penting?
* Dari Koordinat ke Sudut: IK adalah rumus matematika yang mengubah titik lokasi (koordinat X, Y, Z) menjadi angka derajat motor. Programmer cukup menentukan di mana ujung kaki harus mendarat, dan rumus ini akan otomatis menghitung posisi semua motornya.
* Fokus pada Ujung Kaki (End Effector): Dalam IK, tidak perlu lagi memikirkan satu per satu motor servo. Cukup fokus pada End Effector (titik paling ujung kaki robot). Selama mengetahui koordinat tujuan ujung kaki tersebut, robot akan bergerak secara presisi ke tujuan.
* Kebalikan dari Tebak-tebakan: Jika trial-error adalah mencoba-coba sudut sampai posisi ujung kakinya pas, maka Invers Kinematik adalah menentukan posisi ujung kakinya dulu, baru kemudian angka sudut yang pasti akan didapatkan lewat perhitungan.

## Rumus Invers Kinematik

## Kode Program Invers Kinematik 3 DoF