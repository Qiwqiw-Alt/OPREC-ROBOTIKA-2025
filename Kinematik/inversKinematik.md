## Invers Kinematik

## Link Penting 🔗

* **Repository Github Invers Kinematik**
    * []()

* **Video Youtube Invers Kinematik:**
    * [Coding Challenge #64.3: Inverse Kinematics - Fixed Point](https://youtu.be/RTc6i-7N3ms?si=L6iEj5FAcCngYW-b)
    * [Coding Challenge #64.2: Inverse Kinematics](https://youtu.be/hbgDqyy8bIw?si=C2o0OQYByqSJ1E1Z)
    * [Master Inverse Kinematics for Arduino Robots – Easy Math, Full Code, Real Results](https://youtu.be/WAsMAeKDc4U?si=G7N2-ImwLdytCBRC)
    * [Build a Walking Arduino Hexapod (Full DIY Guide!)](https://youtu.be/iLIIuMj-77w?si=-ASI_DjX2pX6vOPk)

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

## Perbedaan dengan Forward Kinematik (FK)
* Forward Kinematik adalah proses menggerakan sudut bahu sebanyak 30 derajat, lalu gerakan sudut diku 45 derajat sehingga hasilnya sampai di suatu titik.
* Invers Kinematik adalah proses memberikan titik koordinat tujuan sehingga sudut-sudutnya seperti bahu dan siku bergerak untuk mencapai titik tujuan tersebut.

## Rumus Invers Kinematik 2 DoF
Pada Inversi Kinematik 2 DoF, dicari 2 sudut yaitu $\theta_1$ (sudut bahu) dan $\theta_2$ (sudut siku). Jika diibaratkan dengan lengan manusia, $\theta_1$ adalah sudut yang menghubungkan bahu dengan lengan atas manusia. Sedangkan, $\theta_2$ adalah sudut yang menghubungkan lengan atas dengan lengan bawah.

Untuk menghitung 2 sudut tersebut digunakan 3 rumus utama, yaitu

### 1. Rumus Pythagoras
Digunakan untuk menghitung jarak lurus (H) dari pangkal bahu ke titik target (x, y).
Rumus hipotenusa:

$$ H = \sqrt{x^2 + y^2} $$

di mana:
- $x, y$ = koordinat target end-effector  
- $H$ = jarak target

### 2. Hukum Cosinus (Mencari sudut siku atau $\theta_2$)
Digunakan untuk mencari besarnya tekukan siku berdasarkan panjang lengan atas (L1), lengan bawah (L2), dan jarak target (H).

$$
\cos(\theta_2) = \frac{x^2 + y^2 - L_1^2 - L_2^2}{2 L_1 L_2}
$$

di mana:
- $x, y$ = koordinat target end-effector  
- $L_1$ = panjang link 1  
- $L_2$ = panjang link 2  
- $\theta_2$ = sudut relatif antara link 1 dan link 2

### 3. Fungsi ArcTan/Atan2 (Mencari sudut bahu atau $\theta_1$)
Digunakan untuk menentukan arah elevasi atau kemiringan lengan terhadap garis horizontal.

$$
\theta_1 = \operatorname{atan2}(y, x) \pm \beta
$$

di mana:

$$
\beta = \acos\left( \frac{L_1^2 + r^2 - L_2^2}{2 L_1 r} \right)
$$

- $r = \sqrt{x^2 + y^2}$ (jarak dari origin ke end-effector)  
- $\operatorname{atan2}(y, x)$ memberikan sudut utama vektor posisi  
- Tanda $\pm$ dipilih tergantung konfigurasi (elbow-up atau elbow-down)  
- $\beta$ adalah sudut koreksi agar link kedua mencapai target dengan benar

## Contoh Soal Invers Kinematik 2 DoF

## Kode Program Invers Kinematik 2 DoF

## Rumus Invers Kinematik 3 DoF

## Contoh Soal Invers Kinematik 3 DoF

## Kode Program Invers Kinematik 3 DoF