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

  * `#include <iostream>`: Perintah untuk menyertakan *library* standar `iostream` yang berisi fungsi untuk operasi input dan output.
  * `using namespace std;`: Perintah ini memberitahu kompiler bahwa kita akan menggunakan elemen dari *namespace* (ruang nama) `std`. Ini memungkinkan kita menulis `cout` dan `endl` secara langsung tanpa awalan `std::`.
  * `int main()`: Ini adalah **fungsi utama**. Eksekusi program C++ selalu dimulai dari sini.
  * `cout`: Digunakan untuk menampilkan output ke konsol.
  * `<<`: Operator *insertion*, digunakan untuk "memasukkan" data ke dalam `cout`.
  * `"Hello, World!"`: Teks (string) yang ingin kita tampilkan.
  * `endl`: Singkatan dari *end line*, fungsinya untuk membuat baris baru.
  * `return 0;`: Menandakan bahwa program telah selesai dieksekusi dengan sukses.
  * `;` (titik koma): Setiap pernyataan (statement) dalam C++ harus diakhiri dengan titik koma.

-----

## 2\. Penggunaan Komentar

Komentar adalah baris teks dalam kode yang tidak akan dieksekusi oleh *compiler*. Gunanya untuk memberi catatan atau penjelasan pada kodemu.

```cpp
// Ini adalah komentar satu baris. Semua setelah tanda // akan diabaikan.

/*
Ini adalah
komentar multi-baris.
Sangat berguna untuk penjelasan yang lebih panjang.
*/

int tegangan = 5; // Komentar juga bisa diletakkan di akhir baris kode.
```

-----

## 3\. Variabel, Tipe Data, dan String

**Variabel** adalah nama untuk lokasi penyimpanan di memori. Setiap variabel harus memiliki **tipe data** yang spesifik.

| Tipe Data | Deskripsi | Contoh |
| :--- | :--- | :--- |
| `int` | Bilangan bulat (integer) | `10`, `-15`, `0` |
| `double` | Bilangan desimal (presisi ganda) | `3.14`, `9.81` |
| `char` | Satu karakter | `'A'`, `'z'`, `'%'` |
| `bool` | Logika kebenaran (benar atau salah) | `true`, `false` |
| `string` | Kumpulan karakter (teks) | `"Robot Cerdas"` |

**Contoh Penggunaan:**

```cpp
#include <iostream>
#include <string> // Wajib disertakan untuk menggunakan string

using namespace std;

int main() {
    // Deklarasi dan inisialisasi variabel
    int jumlahRoda = 4;
    double kecepatanMaks = 2.5; // dalam m/s
    char mode = 'A'; // Mode 'A' untuk otomatis
    bool isAktif = true;
    string namaRobot = "Robo-C++";

    // Menampilkan nilai variabel
    cout << "Nama Robot: " << namaRobot << endl;
    cout << "Status Aktif: " << isAktif << endl;

    return 0;
}
```

-----

## 4\. Menerima Input dari User

Kamu bisa membuat program interaktif dengan meminta input dari pengguna menggunakan `cin`.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    int umur;
    string nama;
    
    cout << "Masukkan namamu: ";
    getline(cin, nama); // Mengambil satu baris input string
    
    cout << "Masukkan umurmu: ";
    cin >> umur; // Mengambil input integer dari keyboard

    cout << "Halo, " << nama << "! Kamu berumur " << umur << " tahun." << endl;

    return 0;
}
```

-----

## 5\. Operator dan Operasi Matematika

C++ mendukung berbagai operator untuk melakukan kalkulasi.

| Kategori | Operator | Contoh |
| :--- | :--- | :--- |
| **Aritmatika** | `+`, `-`, `*`, `/`, `%` (modulo) | `5 + 3` |
| **Penugasan** | `=`, `+=`, `-=`, `*=`, `/=`, `++`, `--` | `x += 5` |
| **Perbandingan**| `==`, `!=`, `>`, `<`, `>=`, `<=` | `jarak < 10` |
| **Logika** | `&&` (AND), `||` (OR), `!` (NOT) | `isReady && isSafe`|

**Contoh Kode Matematika:**

```cpp
#include <iostream>
#include <cmath> // Library untuk fungsi matematika kompleks (sqrt, pow, dll)

using namespace std;

int main() {
    double alas = 4.0;
    double tinggi = 5.0;
    double luasSegitiga = (alas * tinggi) / 2;

    cout << "Luas segitiga: " << luasSegitiga << endl; // Output: 10

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

int main() {
    int jarakSensor = 25; // dalam cm

    if (jarakSensor < 20) {
        cout << "Bahaya! Ada halangan, robot berhenti." << endl;
    } else if (jarakSensor < 100) {
        cout << "Aman, robot maju perlahan." << endl;
    } else {
        cout << "Jalur bebas, robot maju dengan kecepatan normal." << endl;
    }

    return 0;
}
```

-----

## 7\. Percabangan (switch case)

Alternatif dari `if-else if` yang lebih rapi jika digunakan untuk memeriksa satu variabel dengan banyak kemungkinan nilai.

```cpp
#include <iostream>

using namespace std;

int main() {
    char mode = 'B'; // Mode operasi robot

    switch (mode) {
        case 'A':
            cout << "Mode Otomatis Aktif." << endl;
            break; // Wajib ada untuk keluar dari switch
        case 'M':
            cout << "Mode Manual Aktif." << endl;
            break;
        case 'S':
            cout << "Mode Siaga (Standby)." << endl;
            break;
        default:
            cout << "Mode tidak dikenali." << endl;
            break;
    }

    return 0;
}
```

-----

## 8\. Perulangan (for & while)

Digunakan untuk mengeksekusi blok kode yang sama berulang kali.

### For Loop

Digunakan ketika kamu tahu persis berapa kali perulangan akan terjadi.

```cpp
#include <iostream>

using namespace std;

int main() {
    // Perulangan dari 0 sampai 4
    for (int i = 0; i < 5; i++) {
        cout << "Motor berputar, langkah ke-" << i + 1 << endl;
    }
    return 0;
}
```

### While Loop

Digunakan ketika perulangan terus berjalan selama suatu kondisi bernilai `true`.

```cpp
#include <iostream>

using namespace std;

int main() {
    int baterai = 10; // Persentase baterai

    while (baterai > 0) {
        cout << "Robot berjalan. Sisa baterai: " << baterai << "%" << endl;
        baterai--; // Mengurangi nilai baterai setiap iterasi
    }
    
    cout << "Baterai habis, robot berhenti." << endl;
    return 0;
}
```

### Break dan Continue

  * `break`: Menghentikan paksa seluruh proses perulangan.
  * `continue`: Menghentikan iterasi saat ini dan langsung loncat ke iterasi berikutnya.

<!-- end list -->

```cpp
#include <iostream>

using namespace std;

int main() {
    for (int i = 1; i <= 10; i++) {
        if (i % 2 != 0) {
            continue; // Lewati angka ganjil, lanjut ke iterasi berikutnya
        }
        if (i > 8) {
            break; // Hentikan loop jika angka lebih dari 8
        }
        cout << i << endl; // Hanya akan mencetak 2, 4, 6, 8
    }
    return 0;
}
```

-----

## 9\. Arrays

**Array** adalah kumpulan data dengan tipe yang sama yang disimpan dalam satu variabel.

```cpp
#include <iostream>

using namespace std;

int main() {
    // Array untuk menyimpan 5 data sensor jarak
    double dataSensor[5] = {10.2, 11.5, 9.8, 12.0, 10.5};

    // Mengakses elemen array (indeks dimulai dari 0)
    cout << "Data sensor pertama: " << dataSensor[0] << endl;
    cout << "Data sensor ketiga: " << dataSensor[2] << endl;
    
    // Mengubah nilai elemen array
    dataSensor[4] = 10.7;

    // Menampilkan semua data sensor menggunakan loop
    for (int i = 0; i < 5; i++) {
        cout << "Data ke-" << i << ": " << dataSensor[i] << endl;
    }
    
    return 0;
}
```

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