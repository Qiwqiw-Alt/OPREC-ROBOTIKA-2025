# 💻 Day 1 Tutorial C++ Dasar

## Link Penting 🔗

* **Compiler:**
    * [MinGW-w64 (C/C++ Compiler)](https://www.mingw-w64.org/)
    * [Video Tutorial Install](https://youtu.be/A_M4KSQFx-Y?si=WMm6KPe4cCgS6fUp)

* **Teks Editor / IDE:**
    * [Visual Studio Code](https://code.visualstudio.com/)
    * [Notepad++](https://notepad-plus-plus.org/downloads/)
    * [Vim](https://www.vim.org/download.php)

* **Online Compiler:**
    * [Programiz C++ Compiler](https://www.programiz.com/cpp-programming/online-compiler/)
    * [OnlineGDB C++ Compiler](https://www.onlinegdb.com/online_c++_compiler)
    * [OneCompiler C++ Compiler](https://onecompiler.com/cpp/)

* **Sumber Belajar Tambahan:**
    * [W3Schools C++ Tutorial](https://www.w3schools.com/cpp/)
    * [TLX TOKI C++ Dasar](https://tlx.toki.id/courses)
    * [Bro Code C++ Full Course](https://youtu.be/-TkoO8Z07hI?si=oc2I1NqUG3xTgEID)

-----

## 🤖 Kenapa Belajar C++ untuk Robotika?

C++ adalah bahasa inti yang digunakan untuk memprogram mikrokontroler populer seperti **Arduino** dan **ESP32**. Bahasa ini menjadi pilihan utama karena kemampuannya memberikan **performa tinggi** dan **kontrol perangkat keras secara langsung**. Saat membangun proyek robotika, kamu perlu membaca data dari sensor, mengendalikan pergerakan motor, dan mengatur pin GPIO dengan presisi dan kecepatan. C++ memungkinkanmu melakukan semua itu secara efisien, "berbicara" langsung dengan *chip* mikrokontroler tanpa perantara yang memperlambat sistem, menjadikannya fondasi yang sangat kuat dan esensial di dunia *embedded systems*.

-----

## 1\. 👋 Program "Hello, World!"

<details>
<summary> Click to see more... </summary>

**Kode Program (`main.cpp`):**
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
```

**Penjelasan Sintaks:**

  * `#include <iostream>`: *Library* standar `iostream` untuk input dan output.
  * `using namespace std;`: Untuk menulis `cout` dan `endl` secara langsung tanpa awalan `std::`.
  * `int main()`: **Fungsi utama**. Eksekusi program C++ selalu dimulai dari sini.
  * `cout <<`: Digunakan untuk menampilkan output.
  * `"Hello, World!"`: Teks (string) yang ingin kita tampilkan.
  * `endl`: Singkatan dari *end line*, fungsinya untuk membuat baris baru.
  * `return 0;`: Menandakan bahwa program telah selesai dieksekusi.

**Cara Compile lewat Command Prompt/Terminal**
```bash
g++ main.cpp -o main
```
-----
</details>

## 2\. 📝 Penggunaan Komentar

<details>
<summary> Click to see more... </summary>

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
</details>

## 3\. 📦 Variabel, Tipe Data, dan String

<details>
<summary> Click to see more... </summary>

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
</details>

## 4\. ⌨️ Menerima Input dari User

<details>
<summary> Click to see more... </summary>

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
**Catatan Penting:** `cin` berhenti membaca pada spasi pertama. Jika ingin membaca nama lengkap (termasuk spasi), gunakan fungsi `getline()`.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string namaLengkap;
    
    cout << "Masukkan nama lengkap: ";
    getline(cin, namaLengkap); // Membaca seluruh baris input
    
    cout << "Halo, " << namaLengkap << "!" << endl;

    return 0;
}
```
-----
</details>

## 5\. ⚙️ `#define` (Preprocessor Macro)

<details>
<summary> Click to see more... </summary>

`#define` adalah sebuah **arahan *preprocessor*** yang menginstruksikan *compiler* untuk melakukan **penggantian teks** secara sederhana. Proses ini terjadi sebelum kompilasi dimulai, di mana setiap kemunculan makro yang didefinisikan akan diganti dengan teks yang ditentukan.

###  Penggunaan Umum:

#### 1. Membuat Alias Tipe Data

Ini adalah penggunaan yang populer, terutama untuk mempersingkat penulisan kode dalam kompetisi.

```cpp
#include <iostream>
using namespace std;

// Mengganti setiap kemunculan 'll' dengan 'long long'
#define ll long long

int main() {
    ll populasi = 8000000000;
    cout << "Populasi Dunia: " << populasi << endl;
    return 0;
}
```

**Catatan:** Praktik ini dianggap usang. Alternatif modern yang **lebih aman dan direkomendasikan** adalah `using`.

```cpp
// Cara modern dan lebih baik:
using ll = long long;
```

#### 2. Mendefinisikan Konstanta

Digunakan untuk memberikan nama pada nilai konstanta.

```cpp
#include <iostream>
using namespace std;

// Mendefinisikan konstanta PI
#define PI 3.14159

int main() {
    double jariJari = 5.0;
    double keliling = 2 * PI * jariJari;
    cout << "Keliling lingkaran: " << keliling << endl;
    return 0;
}
```

**Catatan:** Untuk konstanta, cara yang lebih aman adalah menggunakan `const` atau `constexpr`.

```cpp
// Cara modern dan lebih baik:
const double PI = 3.14159;
```

-----
</details>

## 6\. 🧮 Operator dan Operasi Matematika

<details>
<summary> Click to see more... </summary>

Operator adalah simbol khusus yang digunakan untuk melakukan operasi pada variabel dan nilai, mulai dari perhitungan matematika dasar hingga logika yang kompleks.

| Kategori | Operator / Fungsi | Contoh |
| :--- | :--- | :--- |
| **Arithmetic** | `+`, `-`, `*`, `/`, `%` (modulo) | `5 + 3` |
| **Assigment** | `=`, `+=`, `-=`, `++`, `--` | `x += 5` |
| **Comparison**| `==`, `!=`, `>`, `<`, `>=`, `<=` | `jarak < 10` |
| **Logical** | `&&` (AND), `\|\|` (OR), `!` (NOT) | `isReady && isSafe`|
| **Math (`cmath`)** | `sqrt()`, `pow()`, `sin()`, `cos()` | `sqrt(25)`|

-----

#### a. Arithmetic ➕

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

#### b. Assignment ✏️

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

#### c. Comparison ⚖️

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

#### d. Logical 🧠

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

#### e. Fungsi Matematika (`<cmath>`) 📐

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
</details>

## 7\. 🤔 Percabangan (if, else if, else)

<details>
<summary> Click to see more... </summary>

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
</details>

## 8\. 🗃️ Array & Vector

<details>
<summary> Click to see more... </summary>

Untuk menyimpan banyak data sejenis, C++ punya dua "wadah" utama: **Array** yang statis dan **Vector** yang dinamis.

-----

### a. Array (Ukuran Tetap) 🔒

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

### b. Vector (Ukuran Fleksibel) ⛓️

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
</details>

## 9\. Perulangan (Loops) 🔁

<details>
<summary> Click to see more... </summary>

Loop digunakan untuk menjalankan blok kode secara berulang agar lebih efisien dan ringkas.

-----

### a. For Loop 🔢
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

### b. While Loop ⏳
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
</details>

## 10\. 🧩 Functions (Fungsi)

<details>
<summary> Click to see more... </summary>

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

void hello() {
    cout << "Hello World" << endl;
}

int main() {

    hello();

    return 0;
}
```
### Contoh lainnya

```cpp
void sapa(string nama){
    cout << "Halo " << nama;
}

int kali(int a, int b){
    return a * b;
}

double pythagoras(double a, double b){
    int hasil = sqrt(pow(a, 2) + pow(b, 2));
    return hasil;
}

bool isGanjil(int a){
    return a % 2 == 1;
}
```

-----
</details>

## 🎯 Latihan
* [TLX Toki](https://tlx.toki.id/courses/basic-cpp)
* [Leetcode](https://leetcode.com/problemset/)
* [Hackerrank](https://www.hackerrank.com/domains/cpp)
