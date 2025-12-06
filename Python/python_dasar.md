# 💻 Python Dasar

## Link Penting 🔗

* **Compiler:**
    * [Download Python](https://www.python.org/downloads/)
    * [Video Tutorial Install](https://youtu.be/1sKTa3r-SqE?si=-LiVcH28LvolAlRS)

* **Teks Editor / IDE:**
    * [Visual Studio Code](https://code.visualstudio.com/)
    * [Notepad++](https://notepad-plus-plus.org/downloads/)
    * [Vim](https://www.vim.org/download.php)

* **Online Compiler:**
    * [Programiz Python Compiler (Interpreter)](https://www.programiz.com/python-programming/online-compiler/)
    * [OnlineGDB Python Compiler (Interpreter)](https://www.onlinegdb.com/online_python_compiler)
    * [Oneline Python Compiler (Interpreter)](https://www.online-python.com/)

* **Sumber Belajar Tambahan:**
    * [W3Schools Python Tutorial](https://www.w3schools.com/python/)
    * [Bro Code Python Playlist](https://youtube.com/playlist?list=PLZPZq0r_RZOOkUQbat8LyQii36cJf2SWT&si=wm8dP4nLr55oovpu)
    * [Kelas Terbuka Python Playlist](https://youtube.com/playlist?list=PLZS-MHyEIRo59lUBwU-XHH7Ymmb04ffOY&si=KUA7AjvWAuf-qPVn)

-----

## 🐍 Kenapa Belajar Python untuk Robotika?

Dalam dunia robotika, python digunakan dalam berbagai hal seperti image processing dan memprogram mikrokontroller seperti Arduino hingga mini PC seperti Rasberry Pi. Keunggulan utamanya terlihat jelas dalam penerapan image processing dan computer vision, di mana Python memanfaatkan library seperti OpenCV untuk memberikan kemampuan visual pada robot, memungkinkannya mendeteksi objek dan merespons lingkungan secara cerdas. Hal ini menjadikan Python pilihan ideal untuk membangun sistem robot yang tidak hanya mampu bergerak secara mekanis, tetapi juga memiliki kemampuan kognitif visual yang tinggi tanpa kerumitan kode yang berlebihan.

-----

## 1\. 👋 Program "Hello, World!"

<details>
<summary> Click to see more... </summary>

**Kode Program (`main.py`):**
```python
print("Hello World!")
```

**Penjelasan Sintaks:**

  * `print()`: Digunakan untuk menampilkan output.
  * `"Hello, World!"`: Teks (string) yang ingin kita tampilkan.

-----
</details>

## 2\. 📝 Penggunaan Komentar

<details>
<summary> Click to see more... </summary>

Komentar adalah baris teks dalam kode yang tidak akan dieksekusi oleh *Interpreter*. Gunanya untuk memberi catatan atau penjelasan pada kode.

```python
# Ini adalah komentar satu baris. Gunakan tanda pagar

"""
Ini adalah komentar multi-baris (Docstring).
Biasanya digunakan untuk dokumentasi fungsi atau
penjelasan panjang. Diapit oleh tiga tanda kutip.
"""

angka = 5 # Komentar juga bisa diletakkan di akhir baris kode.
```
-----
</details>

## 3\. 📦 Variabel, Tipe Data, dan String

<details>
<summary> Click to see more... </summary>

**Variabel** adalah nama untuk lokasi penyimpanan di memori. Setiap variabel harus memiliki **tipe data** yang spesifik. Python menggunakan Dynamic Typing, artinya Anda tidak perlu mendeklarasikan tipe data secara eksplisit. Python akan otomatis tahu tipe datanya berdasarkan nilai yang user masukkan.

| Tipe Data | Deskripsi | Contoh |
| :--- | :--- | :--- |
| `int` | Bilangan bulat (integer) | `10`, `-15`, `0` |
| `float` | Bilangan desimal | `3.14`, `9.81` |
| `str` | Teks (String) | `"Robotika"`, `"Robot"` |
| `bool` | Logika kebenaran (benar atau salah) | `true`, `false` |
| `list` | Kumpulan data (mirip array) | `[1, 2, 3]` |

### Contoh Penggunaan:

```python
# Deklarasi variabel (langsung isi nilainya)
nama = "Budi"       # String
umur = 20           # Integer
tinggi = 170.5      # Float
is_student = True   # Boolean (Huruf awal Besar)

# Menampilkan nilai (menggunakan f-string agar mudah)
print(f"Nama: {nama}")
print(f"Umur: {umur}")
print(f"Status Mahasiswa: {is_student}")
```
-----
</details>

## 4\. ⌨️ Menerima Input dari User

<details>
<summary> Click to see more... </summary>

Gunakan fungsi input(). **PENTING**: input() di Python selalu menghasilkan String. Jika butuh angka, harus dikonversi (casting).

```python
# Menerima input string
nama = input("Masukkan nama: ")

# Menerima input angka (harus di-convert/cast ke int)
umur = int(input("Masukkan umur: "))

print(f"Halo, {nama}! Kamu berumur {umur} tahun.")

```
**Jika ingin input desimal, gunakan float()**:

```python
#include <iostream>
#include <string>
ipk = float(input("Masukkan IPK: "))
```
-----
</details>

## 5\. ⚙️ Konstanta & Import Library

<details>
<summary> Click to see more... </summary>

#### 1. Import Library

`import` mirip dengan `#include` di C++, keyword ini digunakan untuk memuat modul atau library eksternal ke dalam program agar kita bisa menggunakan fungsi, kelas, atau variabel yang tersedia di dalamnya tanpa harus menulis ulang kodenya dari nol.

```python
import math  # Mengimpor modul matematika

print(math.sqrt(25)) # Menggunakan fungsi akar dari modul math
```

#### 2. Mendefinisikan Konstanta

Python tidak memiliki keyword `const` yang membatasi perubahan nilai secara ketat, tapi banyak programmer sepakat bahwa variabel kapital tidak boleh diubah.

```python
PI = 3.14159  # Dianggap sebagai konstanta
GRAVITY = 9.8

jari_jari = 5
keliling = 2 * PI * jari_jari

print(f"Keliling: {keliling}")
```

-----
</details>

## 6\. 🧮 Operator dan Operasi Matematika

<details>
<summary> Click to see more... </summary>

Operator adalah simbol khusus yang digunakan untuk melakukan operasi pada variabel dan nilai, mulai dari perhitungan matematika dasar hingga logika yang kompleks.

| Kategori | Operator / Fungsi | Contoh |
| :--- | :--- | :--- |
| **Arithmetic** | `+`, `-`, `*`, `/`, `%`, `**`, `//` | `5 + 3` |
| **Assigment** | `=`, `+=`, `-=`, `*=`, `/=` | `x += 5` |
| **Comparison**| `==`, `!=`, `>`, `<`, `>=`, `<=` | `jarak < 10` |
| **Logical** | `and`, `or`, `not` | `isReady and isSafe`|
| **Math (`import math`)** | `math.sqrt()`, `math.pow()` | `math.sqrt(25)`|

-----

#### a. Arithmetic ➕

Digunakan untuk operasi matematika dasar seperti penjumlahan, pengurangan, perkalian, pembagian, perpangkatan dan pembagian bulat.

```python
a = 10
b = 3

print(a / b)   # Hasil desimal: 3.333...
print(a // b)  # Hasil bulat: 3
print(a ** b)  # 10 pangkat 3: 1000
```

#### b. Assignment ✏️

Digunakan untuk memberikan atau memperbarui nilai sebuah variabel.

```python
x = 10
x += 5  # Sama dengan x = x + 5 (Hasil: 15)

x += 1  # Cara menaikkan nilai sebanyak 1 (pengganti x++)
```

#### c. Comparison ⚖️

Digunakan untuk membandingkan dua nilai. Hasil dari operasi ini selalu berupa nilai boolean (`true` atau `false`).

```python
x = 5
y = 3

print(x > y) # Output True
print(x == y) # Output False
```

#### d. Logical 🧠

Digunakan untuk menggabungkan beberapa kondisi boolean.

```python
x = True
y = False

print(x and y) # False
print(x or y)  # True
print(not x)       # False
```

#### e. Fungsi Matematika (`import math`) 📐

Library `math` menyediakan fungsi-fungsi matematika yang lebih kompleks.

```python
import math
# Menghitung akar kuadrat
print(math.sqrt(25))

# Menghitung pangkat
print(math.pow(2, 3)) 
```

-----
</details>

## 7\. 🤔 Percabangan (if, else if, else)

<details>
<summary> Click to see more... </summary>

Digunakan untuk membuat keputusan dalam program. Kode di dalam blok `if` hanya akan dijalankan jika kondisinya bernilai `true`.

### Sintaks Dasar:
```python
if kondisi_1:
    # Kode dijalankan jika kondisi_1 True (perhatikan indentasi!)
elif kondisi_2:
    # Kode dijalankan jika kondisi_1 False dan kondisi_2 True
else:
    # Dijalankan jika semua salah
```
### Contoh:

```python
suhu = int(input("Suhu: "))

if suhu <= 20:
    print("Kondisi: Dingin.")
elif suhu > 20 and suhu <= 30:
    print("Kondisi: Normal.")
else:
    print("Kondisi: Panas.")
```
-----
</details>

## 8\. 🗃️ List (Pengganti Array & Vector)

<details>
<summary> Click to see more... </summary>

Di Python, struktur data utama adalah **List**. List di Python sangat fleksibel (mirip std::vector di C++), bisa menampung berbagai tipe data sekaligus, dan ukurannya dinamis.

-----

**Contoh Kode:**

```python
# Membuat list kosong
buah = []

# Membuat list dengan isi
nilai = [80, 90, 75, 100]

# Menambah data (push_back)
buah.append("Apel")
buah.append("Jeruk")

# Mengakses data (Indeks mulai dari 0)
print(f"Buah pertama: {buah[0]}")

# Slicing (Fitur Keren Python: Mengambil sebagian list)
print(nilai[0:2]) # Mengambil indeks 0 sampai 1 (80, 90)

# Cek panjang list
print(f"Jumlah buah: {len(buah)}")
```

-----
</details>

## 9\. 🔁 Perulangan (Loops) 

<details>
<summary> Click to see more... </summary>

Loop digunakan untuk menjalankan blok kode secara berulang agar lebih efisien dan ringkas.

-----

### a. For Loop 🔢
For loop digunakan ketika jumlah perulangan sudah diketahui secara pasti dari awal. Loop di Python lebih sederhana dan sering disebut "for-each" loop.

Contoh Kode:

```python
# Mengulang 5 kali (0, 1, 2, 3, 4)
for i in range(5):
    print(f"Iterasi ke-{i}")

# Mengulang dari 1 sampai 5
for i in range(1, 6):
    print(f"Angka: {i}")
```

Iterasi list:
```python
items = ["Sensor", "Motor", "Baterai"]

for item in items:
    print(f"Komponen: {item}")
```

-----

### b. While Loop ⏳
While loop digunakan untuk mengulang kode selama sebuah kondisi tertentu masih terpenuhi (true). Jumlah perulangannya tidak harus diketahui di awal.

Contoh kode:

```python
timer = 3

while timer > 0:
    print(f"Timer: {timer}")
    timer -= 1  # Jangan lupa kurangi agar tidak infinite loop!

print("Waktu habis!")
```

Cara Kerja: Loop akan terus memeriksa apakah timer > 0. Jika ya, kode di dalamnya dijalankan dan nilai timer dikurangi. Proses ini berhenti saat timer mencapai 0.

-----

### For vs. While
Meskipun keduanya untuk perulangan, penggunaannya berbeda tergantung situasi.

|Fitur |	For Loop	| While Loop |
| :--- | :--- | :--- |
***Penggunaan Utama*** |	Ketika jumlah perulangan diketahui di awal. |	Ketika jumlah perulangan tidak diketahui dan bergantung pada kondisi.|
***Struktur Kontrol*** |	Otomatis. Variabel langsung mengambil isi dari urutan (sequence). Tidak ada i++. |	Manual. Inisialisasi di luar, cek kondisi, dan wajib update variabel di dalam loop. |
***Analogi*** |	"Ulangi 10 kali." | "Ulangi selama masih ada sisa." |
***Risiko Kesalahan***| Risiko infinite loop lebih kecil.	|Rentan terjadi infinite loop jika lupa memperbarui variabel kondisi. |

-----
</details>

## 10\. 🧩 Functions (Fungsi)

<details>
<summary> Click to see more... </summary>

**Fungsi** adalah blok kode yang bisa diberi nama dan dipanggil berulang kali untuk melakukan tugas spesifik. Ini membuat kodemu lebih rapi, terorganisir, dan mudah dikelola.

### Sintaks Fungsi dalam Python

Sebuah fungsi dalam C++ mengikuti format umum berikut:

```python
def function_name(parameter):
    # blok kode
    return nilai  # Opsional
```

Setiap bagian memiliki peran spesifik:

  * **`def`':** merupakan keyword di bahasa python yang digunakan untuk mendeklarasikan function.

  * **Function name:** Nama unik yang akan digunakan untuk memanggil (menjalankan) fungsi tersebut.

  * **Parameter list:** Masukan (input) yang diterima oleh fungsi untuk diolah. Bagian ini bisa dikosongkan jika fungsi tidak memerlukan masukan apa pun.

  * **Function Body:** Blok kode di dalam kurung kurawal `{}` yang berisi serangkaian perintah. Kode inilah yang akan dijalankan ketika fungsi dipanggil.

  * **`return` :** merupakan keyword di bahasa python yang digunakan untuk mengembalikan nilai dari sebuah fungsi. Keyword ini Bbrsifat opsional. Jika tidak ditulis, fungsi akan tetap berjalan sampai selesai dan secara otomatis mengembalikan nilai None (kosong).

### Contoh

```python
def hello() {
    print("Hello World!")
}

# --- Program Utama ---
hello() 
```
### Contoh lainnya

```python
# Fungsi tanpa return
def sapa(nama):
    print(f"Halo, {nama}!")

# Fungsi dengan return
def tambah(a, b):
    return a + b

# Fungsi untuk cek ganjil (return Boolean)
def is_ganjil(angka):
    return angka % 2 == 1

# --- Program Utama ---
sapa("Andi")

hasil = tambah(5, 10)
print(f"Hasil penjumlahan: {hasil}")

if is_ganjil(3):
    print("3 adalah ganjil")
```

-----
</details>

## 🎯 Latihan
* [Codewars](https://www.codewars.com/?language=python)
* [Leetcode](https://leetcode.com/problemset/)
* [Hackerrank](https://www.hackerrank.com/domains/python)