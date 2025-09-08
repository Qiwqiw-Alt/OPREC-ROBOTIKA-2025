# Day 1 Tutorial C++ Dasar

## Link Penting 🔗

* **Compiler:**
    * [MinGW-w64 (C/C++ Compiler)](https://www.mingw-w64.org/)
    * [Video Tutorial Install](https://youtu.be/A_M4KSQFx-Y?si=WMm6KPe4cCgS6fUp)

* **Teks Editor / IDE:**
    * [Visual Studio Code](https://code.visualstudio.com/)
    * [Notepad++](https://notepad-plus-plus.org/downloads/)

* **Online Compiler:**
    * [Programiz C++ Compiler](https://www.programiz.com/cpp-programming/online-compiler/)
    * [OnlineGDB C++ Compiler](https://www.onlinegdb.com/online_c++_compiler)
    * [OneCompiler C++ Compiler](https://onecompiler.com/cpp/)

* **Sumber Belajar Tambahan:**
    * [W3Schools C++ Tutorial](https://www.w3schools.com/cpp/)
    * [GeeksforGeeks C++](https://www.geeksforgeeks.org/c-plus-plus/)
    * [Learn C++](https://www.learncpp.com/)

---

## Kenapa Belajar C++ untuk Robotika?

Mempelajari C++ sangat penting untuk robotika karena bahasa ini menawarkan **performa dan kecepatan yang luar biasa**, memungkinkan robot merespons lingkungannya secara *real-time* tanpa jeda. C++ memberikan **kontrol tingkat rendah terhadap perangkat keras**, yang krusial untuk berinteraksi langsung dengan sensor, motor, dan mikrokontroler. Selain itu, C++ menjadi tulang punggung bagi banyak *framework* dan ekosistem robotika paling populer di industri, seperti **ROS (Robot Operating System)** dan **Arduino**, menjadikannya keahlian fundamental di bidang ini.

---

## 1. Program "Hello, World!"

**Kode Program (`main.cpp`):**
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
````

**Penjelasan Sintaks:**

  * `#include <iostream>`: *Library* standar `iostream` untuk input dan output.
  * `using namespace std;`: Untuk menulis `cout` dan `endl` secara langsung tanpa awalan `std::`.
  * `int main()`: **Fungsi utama**. Eksekusi program C++ selalu dimulai dari sini.
  * `cout <<`: Digunakan untuk menampilkan output.
  * `"Hello, World!"`: Teks (string) yang ingin kita tampilkan.
  * `endl`: Singkatan dari *end line*, fungsinya untuk membuat baris baru.
  * `return 0;`: Menandakan bahwa program telah selesai dieksekusi.

-----

## 2\. Penggunaan Komentar

Komentar adalah baris teks dalam kode yang tidak akan dieksekusi oleh *compiler*. Gunanya untuk memberi catatan atau penjelasan pada kode.

```cpp
// Ini adalah komentar satu baris. Semua setelah tanda // akan diabaikan.

/*
Ini adalah
komentar multi-baris.
Sangat berguna untuk penjelasan yang lebih panjang.
*/

int angka = 5; // Komentar juga bisa diletakkan di akhir baris kode.
```

-----

## 3\. Variabel, Tipe Data, dan String

**Variabel** adalah nama untuk lokasi penyimpanan di memori. Setiap variabel harus memiliki **tipe data** yang spesifik.

| Tipe Data | Deskripsi | Contoh |
| :--- | :--- | :--- |
| `int` | Bilangan bulat (integer) | `10`, `-15`, `0` |
| `double` | Bilangan desimal | `3.14`, `9.81` |
| `char` | Satu karakter | `'A'`, `'z'`, `'%'` |
| `bool` | Logika kebenaran (benar atau salah) | `true`, `false` |
| `string` | Kumpulan karakter (teks) | `"Robotika"` |

### Contoh Penggunaan:

```cpp
#include <iostream>
#include <string> // Wajib disertakan untuk menggunakan string
using namespace std;

int main() {
    // Deklarasi dan inisialisasi variabel
    string nama = "Budi";
    int umur = 20;
    char kelas = 'D';
    double ipk = 3.5;
    bool isStudent = true;

    // Menampilkan nilai variabel
    cout << "Nama: " << nama << endl;
    cout << "Umur: " << umur << endl;
    cout << "Kelas: " << kelas << endl;

    return 0;
}
```

-----

## 4\. Menerima Input dari User

Program interaktif dengan meminta input dari pengguna menggunakan `cin`.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int umur;
    string nama;
    
    cout << "Masukkan nama: ";
    cin >> nama; // Mengambil satu baris input string
    
    cout << "Masukkan umur: ";
    cin >> umur; // Mengambil input integer dari keyboard

    cout << "Halo, " << nama << "! Kamu berumur " << umur << " tahun." << endl;

    return 0;
}
```

-----

## 5. Operator dan Operasi Matematika

Operator adalah simbol khusus yang digunakan untuk melakukan operasi pada variabel dan nilai, mulai dari perhitungan matematika dasar hingga logika yang kompleks.

| Kategori | Operator / Fungsi | Contoh |
| :--- | :--- | :--- |
| **Arithmetic** | `+`, `-`, `*`, `/`, `%` (modulo) | `5 + 3` |
| **Assigment** | `=`, `+=`, `-=`, `++`, `--` | `x += 5` |
| **Comparison**| `==`, `!=`, `>`, `<`, `>=`, `<=` | `jarak < 10` |
| **Logical** | `&&` (AND), `\|\|` (OR), `!` (NOT) | `isReady && isSafe`|
| **Math (`cmath`)** | `sqrt()`, `pow()`, `sin()`, `cos()` | `sqrt(25)`|

-----

#### a. Arithmetic

Digunakan untuk operasi matematika dasar seperti penjumlahan, pengurangan, perkalian, dan pembagian.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 3;
    int c = a + b;
    int d = a * b;
    int e = a % b;

    cout << "a + b = " << c << endl; // Penjumlahan: 13
    cout << "a * b = " << d << endl; // Perkalian: 30
    cout << "a % b = " << e << endl; // Modulo (sisa bagi): 1
    return 0;
}
```

#### b. Assignment

Digunakan untuk memberikan atau memperbarui nilai sebuah variabel.

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    x += 5; // Sama dengan x = x + 5
    cout << "Nilai x setelah 'x += 5' adalah: " << x << endl; // Output: 15

    x++; // Sama dengan x = x + 1
    cout << "Nilai x setelah 'x++' adalah: " << x << endl; // Output: 16
    return 0;
}
```

#### c. Comparison

Digunakan untuk membandingkan dua nilai. Hasil dari operasi ini selalu berupa nilai boolean (`true` atau `false`).

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int y = 3;

    cout << (x > y) << endl; // Output 1 (true)
    cout << (x == y) << endl; // Output 0 (false)
    return 0;
}
```

#### d. Logical

Digunakan untuk menggabungkan beberapa kondisi boolean.

```cpp
#include <iostream>
using namespace std;

int main() {
    bool x = true;
    bool y = false;

    // Logika AND (&&): keduanya harus true agar hasilnya true
    bool and = x && y; 
    cout << and << endl; // Output 0 (false)

    // Logika OR (||): minimal satu harus true agar hasilnya true
    bool or = x || y;
    cout << or << endl; // Output 1 (true)
    return 0;
}
```

#### e. Fungsi Matematika (`<cmath>`)

Library `<cmath>` menyediakan fungsi-fungsi matematika yang lebih kompleks.

```cpp
#include <iostream>
#include <cmath> // Library untuk fungsi matematika
using namespace std;

int main() {
    // Menghitung akar kuadrat
    cout << "Akar kuadrat dari 25 adalah: " << sqrt(25) << endl; // Output: 5

    // Menghitung pangkat
    cout << "2 pangkat 3 adalah: " << pow(2, 3) << endl; // Output: 8
    return 0;
}
```

-----

## 6\. Percabangan (if, else if, else)

Digunakan untuk membuat keputusan dalam program. Kode di dalam blok `if` hanya akan dijalankan jika kondisinya bernilai `true`.

### Sintaks Dasar:
```cpp
if (kondisi_1) {
    // Blok kode ini dijalankan jika kondisi_1 benar (true).
} 
else if (kondisi_2) {
    // Blok ini dijalankan jika kondisi_1 salah,
    // DAN kondisi_2 benar.
} 
else {
    // Blok ini dijalankan jika semua kondisi di atas salah.
}
```
### Contoh:

```cpp
#include <iostream>
using namespace std;

int main() {
    int suhu;
    cout << "Suhu: ";
    cin >> suhu;

    if (suhu <= 20) {
        cout << "Kondisi: Dingin." << endl;
    } 
    else if (suhu > 20 && suhu <= 30) {
        cout << "Kondisi: Normal." << endl;
    } 
    else {
        cout << "Kondisi: Panas." << endl;
    }

    return 0;
}
```

-----

## 7\. Percabangan (switch case)

Alternatif dari `if-else if` yang lebih rapi jika digunakan untuk memeriksa satu variabel dengan banyak kemungkinan nilai.

### Sintaks Dasar:
```cpp
switch (variabel) {
    case nilai_1:
        // Blok kode yang dijalankan jika variabel == nilai_1
        break;
    case nilai_2:
        // Blok kode yang dijalankan jika variabel == nilai_2
        break;
    // ... bisa ada banyak case lain
    default:
        // Blok kode yang dijalankan jika tidak ada case yang cocok
        break;
}
```

### Contoh: 

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int nomorHari = 3;
    string namaHari;

    // Struktur switch-case dimulai di sini
    switch (nomorHari) {
        case 1:
            namaHari = "Senin";
            break; // Wajib ada agar tidak lanjut ke case berikutnya
        case 2:
            namaHari = "Selasa";
            break;
        case 3:
            namaHari = "Rabu";
            break;
        case 4:
            namaHari = "Kamis";
            break;
        case 5:
            namaHari = "Jumat";
            break;
        case 6:
            namaHari = "Sabtu";
            break;
        case 7:
            namaHari = "Minggu";
            break;
        default:
            // Blok ini dijalankan jika tidak ada case yang cocok
            namaHari = "Tidak valid";
            break;
    }

    cout << "Nomor hari: " << nomorHari << endl;
    cout << "Nama hari: " << namaHari << endl;

    return 0;
}
```

-----

## 8. Array & Vector

Untuk menyimpan banyak data sejenis, C++ punya dua "wadah" utama: **Array** yang statis dan **Vector** yang dinamis.

-----

### a. Array (Ukuran Tetap)

**Array** adalah kumpulan data sejenis dengan **ukuran yang sudah ditetapkan** dan tidak bisa diubah.

**Kelebihan & Kekurangan:**

  * ✅ **Cepat:** Akses data lewat nomor indeks (urutan) sangat cepat.
  * ❌ **Kaku:** Ukurannya tidak bisa diubah setelah dibuat.

**Kapan Digunakan?** Saat jumlah data **sudah pasti** dan tidak akan pernah berubah, misalnya menyimpan 7 nama hari.

**Contoh Kode:**

```cpp
#include <iostream>
using namespace std;

int main() {
    // Array 'nilai' hanya bisa menampung 5 angka.
    int nilai[5] = {80, 95, 75, 88, 92};

    // Mengakses data di "lubang" ke-0 (indeks pertama)
    cout << "Nilai pertama: " << nilai[0] << endl; 
    
    return 0;
}
```

-----

### b. Vector (Ukuran Fleksibel)

**Vector** adalah versi "pintar" dari array. Ukurannya **dinamis**, artinya bisa ditambah atau dikurangi kapan saja.

**Kelebihan & Kekurangan:**

  * ✅ **Fleksibel:** Ukuran bisa berubah sesuai kebutuhan.
  * ✅ **Banyak Fitur:** Punya fungsi bawaan seperti `.size()` untuk cek ukuran dan lainnya.
  * ⚠️ **Sedikit *Overhead***: Sedikit lebih lambat dari array karena fleksibilitasnya.

**Kapan Digunakan?** Di **hampir semua kasus**. Ini adalah pilihan standar yang lebih aman dan modern di C++.

**Contoh Kode:**

```cpp
#include <iostream>
#include <vector> // Wajib menyertakan header vector
#include <string>
using namespace std;

int main() {
    // Vector 'buah' awalnya kosong.
    vector<string> buah;

    // Menambah data ke dalam daftar
    buah.push_back("Apel");
    buah.push_back("Jeruk");

    cout << "Buah pertama: " << buah[0] << endl;
    cout << "Jumlah buah sekarang: " << buah.size() << endl;

    return 0;
}
```

-----

### Array vs Vector

| Fitur | Array | Vector |
| :--- | :--- | :--- |
| **Ukuran** | Statis (Tetap) | Dinamis (Fleksibel) |
| **Pilihan Terbaik** | Untuk data yang jumlahnya absolut tetap. | Pilihan utama untuk hampir semua kebutuhan. |
-----

## 9. Perulangan (Loops) 🔁

Loop digunakan untuk menjalankan blok kode secara berulang agar lebih efisien dan ringkas.

-----

### a. For Loop
For loop digunakan ketika jumlah perulangan sudah diketahui secara pasti dari awal.

Sintaks Dasar:

```C++
for (inisialisasi; kondisi; pembaruan) {
    // Blok kode yang diulang
}
```
Contoh Kode:

```C++
#include <iostream>
using namespace std;

int main() {
    // Ulangi dari i=1 sampai i<=5, naikkan i setiap putaran
    for (int i = 1; i <= 5; i++) {
        cout << "Iterasi ke-" << i << endl;
    }
    return 0;
}
```

Cara Kerja: Loop ini memulai i dari 1, berjalan selama i kurang dari atau sama dengan 5, dan menaikkan i setiap kali selesai satu putaran.

-----

### b. While Loop
While loop digunakan untuk mengulang kode selama sebuah kondisi tertentu masih terpenuhi (true). Jumlah perulangannya tidak harus diketahui di awal.

Sintaks Dasar:

```C++
while (kondisi) {
    // Blok kode yang diulang
}
```
Contoh Kode:

```C++
#include <iostream>
using namespace std;

int main() {
    int timer = 3;

    // Loop berjalan selama nilai timer lebih besar dari 0
    while (timer > 0) {
        cout << "Timer: " << timer << endl;
        timer--; // Pastikan kondisi diubah agar loop bisa berhenti
    }
    cout << "Waktu habis!" << endl;
    return 0;
}
```

Cara Kerja: Loop akan terus memeriksa apakah timer > 0. Jika ya, kode di dalamnya dijalankan dan nilai timer dikurangi. Proses ini berhenti saat timer mencapai 0.

-----

### For vs. While
Meskipun keduanya untuk perulangan, penggunaannya berbeda tergantung situasi.

|Fitur |	For Loop	| While Loop |
| :--- | :--- | :--- |
***Penggunaan Utama*** |	Ketika jumlah perulangan diketahui di awal. |	Ketika jumlah perulangan tidak diketahui dan bergantung pada kondisi.|
***Struktur Kontrol*** |	Inisialisasi, kondisi, dan pembaruan didefinisikan di satu tempat. |	Inisialisasi di luar, kondisi di while, pembaruan di dalam loop. |
***Analogi*** |	"Ulangi 10 kali." | "Ulangi selama masih ada sisa." |
***Risiko Kesalahan***| Lebih terstruktur, risiko infinite loop lebih kecil.	|Rentan terjadi infinite loop jika lupa memperbarui variabel kondisi. |

-----

## 10\. Functions (Fungsi)

**Fungsi** adalah blok kode yang bisa diberi nama dan dipanggil berulang kali untuk melakukan tugas spesifik. Ini membuat kodemu lebih rapi, terorganisir, dan mudah dikelola.

### Sintaks Fungsi dalam C++

Sebuah fungsi dalam C++ mengikuti format umum berikut:

```cpp
return_type function_name(parameter_list) {
    // code
}
```

Setiap bagian memiliki peran spesifik:

  * **Return type:** Menentukan jenis nilai yang akan dikembalikan oleh fungsi (**`int`, `bool`, `string`**). Gunakan kata kunci **`void`** jika fungsi tersebut tidak mengembalikan nilai apa pun.

  * **Function name:** Nama unik yang akan digunakan untuk memanggil (menjalankan) fungsi tersebut.

  * **Parameter list:** Masukan (input) yang diterima oleh fungsi untuk diolah. Bagian ini bisa dikosongkan jika fungsi tidak memerlukan masukan apa pun.

  * **Function Body:** Blok kode di dalam kurung kurawal `{}` yang berisi serangkaian perintah. Kode inilah yang akan dijalankan ketika fungsi dipanggil.

### Contoh

```cpp
#include <iostream>

using namespace std;


void halo() {
    cout << "Halo" << endl;
}

int main() {

    halo();

    return 0;
}
```
### Contoh lainnya

```cpp
void (string nama){
    cout << "Halo " << nama;
}

int kali(a, b){
    return a * b;
}
```

## Tambahan (Belum di update)
* Penggunaa `#include <bits/stdc++.h>` untuk include semua library
* Tipe data memakai `auto`
* `#define` 