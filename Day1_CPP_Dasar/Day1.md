# Day 1 Tutorial C++ Dasar

## Link Penting 🔗

* **Compiler:**
    * [MinGW-w64 (Untuk Windows)](https://www.mingw-w64.org/)

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

**Contoh Penggunaan:**

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

### Keyword auto
**auto** adalah kata kunci di C++ yang fungsinya untuk menentukan tipe data sebuah variabel secara **otomatis**.

**Contoh Penggunaan auto:**

```cpp
#include <iostream>
#include <string> 

using namespace std;

int main() {
    // Deklarasi dan inisialisasi variabel
    auto nama = "Budi";
    auto umur = 20;
    auto kelas = 'D';
    auto ipk = 3.5;
    auto isStudent = true;

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
    
    cout << "Masukkan namamu: ";
    cin >> nama; // Mengambil satu baris input string
    
    cout << "Masukkan umurmu: ";
    cin >> umur; // Mengambil input integer dari keyboard

    cout << "Halo, " << nama << "! Kamu berumur " << umur << " tahun." << endl;

    return 0;
}
```

-----

## 5\. Operator dan Operasi Matematika

| Kategori | Operator | Contoh |
| :--- | :--- | :--- |
| **Aritmatika** | `+`, `-`, `*`, `/`, `%` (modulo) | `5 + 3` |
| **Penugasan** | `=`, `+=`, `-=`, `*=`, `/=`, `++`, `--` | `x += 5` |
| **Perbandingan**| `==`, `!=`, `>`, `<`, `>=`, `<=` | `jarak < 10` |
| **Logika** | `&&` (AND), `\|\|` (OR), `!` (NOT) | `true && false`|

**Contoh Kode Matematika:**

```cpp
#include <iostream>
#include <cmath> // Library untuk fungsi matematika kompleks (sqrt, pow, dll)

using namespace std;

int main() {
    double alas = 4.0;
    double tinggi = 5.0;
    double luasSegitiga = (alas * tinggi) / 2;

    cout << "Luas segitiga: " << luasSegitiga << endl;

    double sisiMiring = sqrt(pow(alas, 2) + pow(tinggi, 2));
    cout << "Sisi miring: " << sisiMiring << endl;
    
    return 0;
}
```

-----

## 6\. Percabangan (if, else if, else)

Digunakan untuk membuat keputusan dalam program. Kode di dalam blok `if` hanya akan dijalankan jika kondisinya bernilai `true`.

```cpp
#include <iostream>

using namespace std;

#include <iostream>

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

## 8\. Arrays & Vector

### a. Array

**Array** adalah struktur data fundamental yang menyimpan koleksi elemen dengan tipe data identik dalam blok memori yang **berurutan (kontinu)**. Ukuran array bersifat **tetap (statis)**, artinya jumlah elemennya ditentukan saat kompilasi dan tidak bisa diubah saat program berjalan.

**Karakteristik Utama:**

  * **Ukuran Tetap:** Jumlah elemen harus diketahui saat kode ditulis.
  * **Akses Cepat:** Akses ke elemen mana pun sangat cepat karena posisinya di memori bisa dihitung langsung menggunakan indeks.
  * **Manajemen Manual:** Tidak memiliki fitur bawaan untuk mengetahui ukurannya sendiri.

**Kapan Digunakan?**
Gunakan Array ketika kamu tahu persis jumlah elemen yang akan disimpan dan jumlah tersebut tidak akan pernah berubah. Contoh: menyimpan nama hari dalam seminggu (selalu ada 7).

**Contoh Kode:**

```cpp
#include <iostream>

using namespace std;

int main() {
    // Deklarasi array integer dengan 5 elemen
    int nilai[5] = {80, 95, 75, 88, 92};

    // Mengakses elemen (indeks dimulai dari 0)
    cout << "Nilai pertama: " << nilai[0] << endl; // Output: 80
    cout << "Nilai ketiga: " << nilai[2] << endl;  // Output: 75

    // Mengubah nilai elemen
    nilai[0] = 85;
    cout << "Nilai pertama setelah diubah: " << nilai[0] << endl; // Output: 85

    return 0;
}
```

-----

### b. Vector

**Vector** adalah struktur data dari *Standard Template Library* (STL) yang mirip dengan array, tetapi dengan keunggulan utama: ukurannya **dinamis**. Artinya, `vector` bisa tumbuh atau menyusut secara otomatis saat program berjalan.

**Karakteristik Utama:**

  * **Ukuran Dinamis:** Bisa menambah (`push_back`) atau mengurangi elemen kapan saja.
  * **Manajemen Otomatis:** Memiliki banyak fungsi bawaan yang berguna, seperti `.size()` untuk mengetahui jumlah elemen, `.empty()` untuk mengecek apakah kosong, dan lainnya.
  * **Sedikit *Overhead***: Karena sifatnya yang dinamis, `vector` memiliki sedikit *overhead* performa dibandingkan array C-style, namun perbedaannya seringkali tidak signifikan untuk sebagian besar aplikasi.

**Kapan Digunakan?**
Gunakan `vector` di hampir semua kasus, kecuali jika performa level mikro dan ukuran yang benar-benar statis adalah prioritas utama. Ini adalah pilihan yang lebih aman dan fleksibel untuk pemrograman C++ modern.

**Contoh Kode:**

```cpp
#include <iostream>
#include <vector> // Wajib menyertakan header vector
#include <string>

using namespace std;

int main() {
    // Deklarasi vector string
    vector<string> nama_buah;

    // Menambah elemen ke dalam vector
    nama_buah.push_back("Apel");
    nama_buah.push_back("Jeruk");
    nama_buah.push_back("Mangga");

    // Mengakses elemen (sama seperti array)
    cout << "Buah pertama: " << nama_buah[0] << endl;

    // Mengetahui jumlah elemen saat ini
    cout << "Jumlah buah di keranjang: " << nama_buah.size() << endl;

    return 0;
}
```

### Perbandingan Singkat

| Fitur | Array | Vector |
| :--- | :--- | :--- |
| **Ukuran** | Statis (Tetap) | Dinamis (Fleksibel) |
| **Manajemen Memori** | Manual | Otomatis |
| **Fungsi Bawaan** | Tidak ada | Banyak (`.size()`, `.push_back()`, dll.) |
| **Penggunaan** | Kasus spesifik dengan ukuran pasti | Pilihan utama dalam C++ modern |

-----

## 9\. Loop

Perulangan atau *loop* adalah struktur kontrol fundamental yang memungkinkan eksekusi blok kode secara berulang berdasarkan kondisi tertentu. Penggunaan loop sangat esensial untuk efisiensi, karena menghindari redundansi penulisan kode.

### a. For Loop

*For loop* adalah jenis perulangan terstruktur yang ideal digunakan ketika jumlah iterasi (putaran) **sudah diketahui secara pasti** sebelum loop dimulai.

**Karakteristik Utama:** Strukturnya terdiri dari tiga bagian utama: inisialisasi, kondisi, dan pembaruan (increment/decrement).

**Contoh Kode:**

```cpp
#include <iostream>

using namespace std;

int main() {
    // Loop akan berjalan sebanyak 5 kali
    for (int i = 1; i <= 5; i++) {
        cout << "Iterasi ke-" << i << endl;
    }
    return 0;
}
```

**Struktur dan Cara Kerja:**

1.  **Inisialisasi (`int i = 1`):** Dieksekusi **satu kali** di awal untuk mendeklarasikan dan menginisialisasi variabel kontrol.
2.  **Kondisi (`i <= 5`):** Dievaluasi **sebelum** setiap iterasi. Jika `true`, blok kode dieksekusi. Jika `false`, loop berhenti.
3.  **Pembaruan (`i++`):** Dieksekusi di **akhir** setiap iterasi untuk memodifikasi variabel kontrol.

-----

### b. For-Each Loop (Range-Based For)

*For-each loop* adalah sintaks modern yang dirancang untuk mengiterasi **setiap elemen** dalam sebuah rentang atau koleksi data (seperti array, vector, dll.) tanpa perlu mengelola indeks secara manual.

**Karakteristik Utama:** Menyederhanakan iterasi pada koleksi data dan membuat kode lebih mudah dibaca.

**Contoh Kode:**

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> buah = {"Apel", "Jeruk", "Mangga"};

    // Untuk setiap elemen 'item' dalam koleksi 'buah'
    for (auto item : buah) {
        cout << item << endl;
    }
    return 0;
}
```

**Cara Kerja:**
Loop ini secara otomatis mengambil setiap elemen dari `buah` satu per satu dan menyalinnya ke dalam variabel `item`. Penggunaan `auto` adalah praktik terbaik untuk efisiensi (menghindari penyalinan yang tidak perlu) dan keamanan (mencegah modifikasi elemen).

-----

### c. While Loop

*While loop* adalah perulangan yang akan terus berjalan **selama** sebuah kondisi prasyarat bernilai `true`. Jumlah iterasi tidak harus diketahui di awal.

**Karakteristik Utama:** Kondisi diperiksa **sebelum** blok kode dieksekusi. Jika kondisi awalnya sudah `false`, loop tidak akan pernah berjalan.

**Contoh Kode:**

```cpp
#include <iostream>

using namespace std;

int main() {
    int timer = 10;

    // Loop berjalan selama nilai timer lebih dari 0
    while (timer > 0) {
        cout << "Timer: " << timer << endl;
        timer--; // Kondisi harus bisa diubah di dalam loop
    }
    cout << "Waktu habis." << endl;
    return 0;
}
```

**Cara Kerja:**
Kondisi `timer > 0` dievaluasi sebelum setiap iterasi. Penting untuk memastikan bahwa variabel kondisi (dalam hal ini `timer`) dapat berubah di dalam loop untuk menghindari perulangan tak terbatas (*infinite loop*).

-----

### d. Do-While Loop

*Do-while loop* mirip dengan `while`, tetapi dengan satu perbedaan kunci: blok kode di dalamnya **dijamin berjalan minimal satu kali**.

**Karakteristik Utama:** Kondisi diperiksa **setelah** blok kode dieksekusi.

**Contoh Kode:**

```cpp
#include <iostream>

using namespace std;

int main() {
    char pilihan;

    do {
        cout << "Masukkan pilihan ('x' untuk keluar): ";
        cin >> pilihan;
    } while (pilihan != 'x');

    cout << "Program berakhir." << endl;
    return 0;
}
```

**Cara Kerja:**
Blok kode di dalam `do` dieksekusi terlebih dahulu. Kemudian, kondisi `pilihan != 'x'` dievaluasi. Jika `true`, loop akan berlanjut. Ini sangat berguna untuk skenario seperti validasi input, di mana program harus meminta input setidaknya sekali.

-----

## 10\. Functions (Fungsi)

**Fungsi** adalah blok kode yang bisa diberi nama dan dipanggil berulang kali untuk melakukan tugas spesifik. Ini membuat kodemu lebih rapi, terorganisir, dan mudah dikelola.

```cpp
#include <iostream>

using namespace std;

// Fungsi yang tidak mengembalikan nilai (void)
void cekJarak(int jarak) {
    if (jarak < 20) {
        cout << "Berhenti!" << endl;
    } else {
        cout << "Maju." << endl;
    }
}

// Fungsi yang mengembalikan nilai (return value)
int hitungLuas(int panjang, int lebar) {
    int hasil = panjang * lebar;
    return hasil;
}

int main() {
    // Memanggil fungsi void
    cekJarak(15); // Output: Berhenti!
    cekJarak(50); // Output: Maju.

    // Memanggil fungsi yang mengembalikan nilai
    int luasArea = hitungLuas(10, 5);
    cout << "Luas area: " << luasArea << endl; // Output: 50

    return 0;
}
```