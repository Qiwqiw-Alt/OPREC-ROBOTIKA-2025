## Invers Kinematik

## Link Penting 🔗

* **Repository Github Invers Kinematik**
    * [Jakob Leander Hexapod](https://github.com/JakobLeander/hexapod)

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
\theta_1 = atan2(y, x) \pm \beta
$$

di mana:

$$
\beta = acos\left( \frac{L_1^2 + r^2 - L_2^2}{2 L_1 r} \right)
$$

- $r = \sqrt{x^2 + y^2}$ (jarak dari origin ke end-effector)  
- $atan2(y, x)$ memberikan sudut utama vektor posisi  
- Tanda $\pm$ dipilih tergantung konfigurasi (elbow-up atau elbow-down)  
- $\beta$ adalah sudut koreksi agar link kedua mencapai target dengan benar

## Contoh Soal Invers Kinematik 2 DoF
Diketahui: 
- Panjang Paha ($L_1$) = 80 mm
- Panjang Betis ($L_2$) = 80 mm
- Target = x = 100 mm dan y = 50 mm

### 1. Cari jarak Total ($H$) dengan Pythagoras untuk mencari jarak lurus dari pangkal paha ke titik target.

$$H = \sqrt{x^2 + y^2} = \sqrt{100^2 + 50^2} = \sqrt{10000 + 2500} \approx \mathbf{111.8 \text{ mm}}$$

### 2.  Cari Sudut Siku/Betis ($\theta_2$) dengan menggunakan rumus Hukum Cosinus

$$\cos(\theta_2) = \frac{x^2 + y^2 - L_1^2 - L_2^2}{2 \cdot L_1 \cdot L_2}$$

$$\cos(\theta_2) = \frac{100^2 + 50^2 - 80^2 - 80^2}{2 \cdot 80 \cdot 80} = \frac{12500 - 6400 - 6400}{12800} = \frac{-300}{12800} \approx -0.023$$

$$\theta_2 = \arccos(-0.023) \approx \mathbf{91.3^\circ}$$

#### 3.  Cari Sudut Bahu/Paha ($\theta_1$)
Langka ini terdiri dari dua bagian sudut:
1. $\alpha$ (Alpha): Sudut kemiringan dari pangkal ke target.

    $$\alpha = atan2(y, x)$$

    $$\alpha = atan2(50, 100) \approx \mathbf{26.5^\circ}$$

2. $\beta$ (Beta): Sudut internal di dalam segitiga yang dibentuk oleh lengan.

    $$\cos(\beta) = \frac{L_1^2 + H^2 - L_2^2}{2 \cdot L_1 \cdot H}$$

    $$\cos(\beta) = \frac{80^2 + 111.8^2 - 80^2}{2 \cdot 80 \cdot 111.8}$$

    $$\beta = \arccos(0.698) \approx \mathbf{45.7^\circ}$$

3. Menghitung Sudut Akhir 

    $$\theta_1 = \alpha + \beta$$

    $$\theta_1 = 26.5^\circ + 45.7^\circ = \mathbf{72.2^\circ}$$

### 4. Hasil Akhir
Agar ujung kaki sampai di titik $(100, 50)$, robot harus mengatur servonya ke posisi:
- Sudut Bahu ($\theta_1$) = $72.2^\circ$
- Sudut Siku ($\theta_2$) = $91.3^\circ$

## Kode Program Invers Kinematik 2 DoF

```cpp
    #include <iostream>
    #include <cmath> // Library untuk fungsi matematika seperti sqrt, atan2, acos

    using namespace std;

    // Konstanta untuk mengonversi radian ke derajat
    const double RAD_TO_DEG = 180.0 / 3.14159265358979323846;

    void hitungIK(double x, double y) {
        // 1. Tentukan panjang link (ruas) robot sesuai contoh soal sebelumnya
        double L1 = 80.0; // Panjang paha/lengan atas (mm)
        double L2 = 80.0; // Panjang betis/lengan bawah (mm)

        // 2. Hitung jarak hipotenusa (H) menggunakan Teorema Pythagoras
        // H = sqrt(x^2 + y^2)
        double H = sqrt(x * x + y * y);

        // Cek apakah target berada di luar jangkauan robot
        if (H > (L1 + L2)) {
            cout << "Target di luar jangkauan!" << endl;
            return;
        }

        // 3. Hitung Sudut Siku (theta2) menggunakan Hukum Cosinus
        // Rumus: cos(theta2) = (x^2 + y^2 - L1^2 - L2^2) / (2 * L1 * L2)
        double cosTheta2 = (x * x + y * y - L1 * L1 - L2 * L2) / (2 * L1 * L2);
        double theta2 = acos(cosTheta2) * RAD_TO_DEG; // Hasil dalam derajat

        // 4. Hitung Sudut Bahu (theta1)
        // Langkah A: Cari sudut elevasi ke target (alpha)
        double alpha = atan2(y, x); // Menggunakan atan2 agar kuadran akurat

        // Langkah B: Cari sudut internal segitiga (beta) menggunakan Hukum Cosinus
        // cos(beta) = (L1^2 + H^2 - L2^2) / (2 * L1 * H)
        double cosBeta = (L1 * L1 + H * H - L2 * L2) / (2 * L1 * H);
        double beta = acos(cosBeta);

        // Gabungkan alpha dan beta untuk mendapatkan theta1
        double theta1 = (alpha + beta) * RAD_TO_DEG; // Hasil dalam derajat

        // Output hasil sudut untuk servo
        cout << "--- Hasil Invers Kinematik ---" << endl;
        cout << "Input Target X : " << x << " mm" << endl;
        cout << "Input Target Y : " << y << " mm" << endl;
        cout << "Sudut Bahu (theta1) : " << theta1 << " derajat" << endl;
        cout << "Sudut Siku (theta2) : " << theta2 << " derajat" << endl;
    }

    int main() {
        double targetX, targetY;

        cout << "Masukkan koordinat target X: ";
        cin >> targetX;
        cout << "Masukkan koordinat target Y: ";
        cin >> targetY;

        hitungIK(targetX, targetY);

        return 0;
    }
```

## Rumus Invers Kinematik 3 DoF
Pada Inversi Kinematik 3 DoF, dicari 3 sudut yaitu 
- Coxa (pinggul atau $\theta_{coxa}$): berputar ke kiri dan kanan (horizontal)
- Femur (paha atau $\theta_{femur}$): bergerak naik dan turun (vertikal)
- Tibia (betis atau $\theta_{tibia}$): bergerak menekuk dan lurus (verikal)

Untuk menghitung 3 sudut tersebut digunakan 4 rumus utama, yaitu

### 1. Fungsi ArcTangent2
Digunakan pertama kali untuk menentukan sudut coxa ($\theta_{coxa}$) atau rotasi horizontal kaki. Fungsi ini digunakan untuk menghitung sudut dari titik pusat robot ke target di lantai agar kaki menghadap ke arah yang benar.

$$
\theta_{coxa} = atan2(y, x)
$$

di mana:
- $x, y$ = koordinat target end-effector  

### 2. Rumus Pythagoras
Digunakan untuk menghitung jarak lurus (H) dalam dua tahap, yaitu
- Tahap 1: Mencari jarak horizontal total dari pusat ke target di lantai.
- Tahap 2: Mencari jarak lurus dari sendi bahu (femur) langsung ke ujung kaki (tibia) di udara.

$$ H = \sqrt{R^2 + Z^2} $$

di mana:
- $R$ = Jarak mendatar dari sendi paha (Femur) ke titik target di lantai. Ini didapat dari jarak total $X, Y$ dikurangi panjang Coxa.
- $Z$ = Ketinggian vertikal, Posisi target pada sumbu tegak (seberapa tinggi atau rendah ujung kaki dari titik sendi paha).
- $H$ = jarak target

### 3. Hukum Cosinus (Mencari sudut tibia atau $\theta_{tibia}$)
Digunakan untuk mencari besarnya tekukan sendi Tibia (lutut) berdasarkan panjang paha ($L_{femur}$), panjang betis ($L_{tibia}$), dan jarak lurus ke target ($H$).

$$
\cos(\theta_{tibia}) = \frac{H^2  - L_{femur}^2 - L_{tibia}^2}{2 L_{femur} L_{tibia}}
$$

di mana:
- $H$ = Jarak lurus dari sendi paha ke ujung kaki (hasil dari rumus Pythagoras) 
- $L_{femur}$ = panjang ruas paha link 2  
- $L_{tibia}$ = panjang  ruas betis link 3  
- $\theta_{tibia}$ = sudut tekukan pada sendi Tibia

### 4. Trigonometri Dasar (Mencari sudut Femur atau $\theta_{femur}$)
Digunakan untuk menentukan sudut angkat paha. Sudut ini tidak bisa berdiri sendiri, melainkan hasil gabungan dari dua sudut kecil: sudut kemiringan ke target ($\alpha$) dan sudut internal segitiga kaki ($\beta$).

$$\theta_{femur} = atan2(Z, R) + acos\left(\frac{L_{femur}^2 + H^2 - L_{tibia}^2}{2 \cdot L_{femur} \cdot H}\right)$$

di mana:
- $atan2(Z, R)$ = Sudut elevasi target berdasarkan ketinggian $Z$ dan jarak datar $R$.
- Bagian $acos$ = Sudut koreksi internal agar paha terangkat dengan tepat sehingga ujung kaki menyentuh target.
- $Z$ = Ketinggian vertikal target.
- $R$ = Jarak mendatar dari sendi paha ke target.

## Contoh Soal Invers Kinematik 3 DoF
Diketahui:
- Panjang Coxa ($L_1$) = 3 cm
- Panjang Femur ($L_2$) = 7 cm
- Panjang Tibia ($L_3$) = 10 cm
- Target Koordinat = X =10; Y = 10; Z = -5

### 1. Cari Sudut Coxa ($\theta_{coxa}$) dengan fungsi ArcTangent2 untuk menentukan arah hadap kaki pada bidang horizontal.

$$\theta_{coxa} = atan2(Y, X)$$

$$\theta_{coxa} = atan2(10, 10) = \mathbf{45^\circ}$$

### 2.  Cari Nilai R dan H (Transformasi 3D ke 2D)
Untuk melakukan perhitungan, koordinat perlu disederhanakan agar bisa dihitung dengan menggunakan rumus 2D.

1. Mencari Jarak Horizontal Total ($D$):

    $$D = \sqrt{X^2 + Y^2} = \sqrt{10^2 + 10^2} \approx 14.14 \text{ cm}$$

2.  Mencari Jarak Mendatar dari Paha ($R$) dengan mengurangi arak total dengan panjang Coxa ($L_1$) karena paha baru dimulai setelah ruas coxa.

    $$R = D - L_1 = 14.14 - 3 = \mathbf{11.14 \text{ cm}}$$

3. Mencari Jarak Hipotenusa ($H$) dengan menggunakan Teorema Pythagoras untuk mencari jarak lurus dari sendi paha ke ujung kaki.

    $$H = \sqrt{R^2 + Z^2}$$

    $$H = \sqrt{11.14^2 + (-5)^2} = \sqrt{124.1 + 25} = \sqrt{149.1} \approx \mathbf{12.21 \text{ cm}}$$

#### 3.  Cari Sudut Sudut Tibia ($\theta_{tibia}$) dengan menggunakan Hukum Cosinus untuk mencari tekukan lutut. 
 
$$\cos(\theta_{tibia}) = \frac{L_2^2 + L_3^2 - H^2}{2 \cdot L_2 \cdot L_3}$$

$$\cos(\theta_{tibia}) = \frac{7^2 + 10^2 - 12.21^2}{2 \cdot 7 \cdot 10}$$

$$\cos(\theta_{tibia}) = \frac{49 + 100 - 149.08}{140} = \frac{-0.08}{140} \approx 0$$

$$\theta_{tibia} = \arccos(0) = \mathbf{90^\circ}$$
   

### 4. Cari Sudut Femur ($\theta_{femur}$) dengan menggunakan Trigonometri Dasar untuk menggabungkan sudut elevasi ($\alpha$) dan sudut internal ($\beta$).

1. Sudut Elevasi ($\alpha$):

    $$\alpha = \operatorname{atan2}(Z, R) = \operatorname{atan2}(-5, 11.14) \approx \mathbf{-24.2^\circ}$$

2. Sudut Internal ($\beta$):

    $$\cos(\beta) = \frac{L_2^2 + H^2 - L_3^2}{2 \cdot L_2 \cdot H}$$

    $$\cos(\beta) = \frac{7^2 + 12.21^2 - 10^2}{2 \cdot 7 \cdot 12.21} = \frac{49 + 149.08 - 100}{170.94} \approx 0.579$$

    $$\beta = \arccos(0.579) \approx \mathbf{54.6^\circ}$$

3. Hasil akhir $\theta_{femur}$:

    $$\theta_{femur} = \alpha + \beta = -24.2^\circ + 54.6^\circ = \mathbf{30.4^\circ}$$

### 5. Hasil Akhir Perhitungan
Agar ujung kaki sampai di titik $(10, 10, -5)$, robot harus mengatur servonya ke posisi:
- Sudut Coxa: $45^\circ$
- Sudut Femur: $30.4^\circ$
- Sudut Tibia: $90^\circ$

## Kode Program Invers Kinematik 3 DoF

```cpp
    #include <iostream>
    #include <cmath> // Library untuk fungsi matematika

    using namespace std;

    // Konstanta untuk mengonversi radian ke derajat
    const double RAD_TO_DEG = 180.0 / 3.14159265358979323846;

    void hitungIK3DoF(double x, double y, double z) {
        // 1. Tentukan panjang link (ruas) kaki robot sesuai contoh soal
        double L1 = 3.0;  // Panjang Coxa (cm)
        double L2 = 7.0;  // Panjang Femur (cm)
        double L3 = 10.0; // Panjang Tibia (cm)

        // --- LANGKAH 1: MENCARI SUDUT COXA (HORIZONTAL) ---
        // Menggunakan fungsi ArcTangent2 untuk arah hadap
        double thetaCoxa = atan2(y, x) * RAD_TO_DEG;

        // --- LANGKAH 2: TRANSFORMASI 3D KE 2D ---
        // Cari jarak horizontal total di lantai
        double D = sqrt(x * x + y * y);
        
        // Cari jarak mendatar murni untuk paha dan betis (R)
        double R = D - L1;

        // Cari jarak tembak langsung (Hipotenusa H) dari paha ke ujung kaki
        double H = sqrt(R * R + z * z);

        // Proteksi: Cek apakah target berada di luar jangkauan mekanis
        if (H > (L2 + L3)) {
            cout << "Target di luar jangkauan kaki!" << endl;
            return;
        }

        // --- LANGKAH 3: MENCARI SUDUT TIBIA (LUTUT) ---
        // Menggunakan Hukum Cosinus
        double cosThetaTibia = (L2 * L2 + L3 * L3 - H * H) / (2 * L2 * L3);
        double thetaTibia = acos(cosThetaTibia) * RAD_TO_DEG;

        // --- LANGKAH 4: MENCARI SUDUT FEMUR (PAHA) ---
        // A. Sudut elevasi ke arah target (alpha)
        double alpha = atan2(z, R);
        
        // B. Sudut internal segitiga kaki (beta)
        double cosBeta = (L2 * L2 + H * H - L3 * L3) / (2 * L2 * H);
        double beta = acos(cosBeta);

        // Gabungkan alpha dan beta untuk mendapatkan sudut Femur akhir
        double thetaFemur = (alpha + beta) * RAD_TO_DEG;

        // Output hasil sudut untuk motor servo
        cout << "--- Hasil Invers Kinematik 3 DoF ---" << endl;
        cout << "Target Koordinat: (" << x << ", " << y << ", " << z << ")" << endl;
        cout << "1. Sudut Coxa  (Pinggul) : " << thetaCoxa << " derajat" << endl;
        cout << "2. Sudut Femur (Paha)    : " << thetaFemur << " derajat" << endl;
        cout << "3. Sudut Tibia (Betis)   : " << thetaTibia << " derajat" << endl;
    }

    int main() {
        double tx, ty, tz;

        cout << "=== Kalkulator IK Kaki Laba-Laba ===" << endl;
        cout << "Masukkan Target X: "; cin >> tx;
        cout << "Masukkan Target Y: "; cin >> ty;
        cout << "Masukkan Target Z: "; cin >> tz;

        hitungIK3DoF(tx, ty, tz);

        return 0;
    }
```