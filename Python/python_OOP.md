# 💻 Python OOP

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
    * [W3Schools Python Tutorial](https://www.w3schools.com/python/python_oop.asp)
    * [Bro Code Python Playlist](https://youtube.com/playlist?list=PLZPZq0r_RZOOkUQbat8LyQii36cJf2SWT&si=wm8dP4nLr55oovpu)
    * [Kelas Terbuka Python OOP Playlist](https://youtube.com/playlist?list=PLZS-MHyEIRo7ab0-EveSvf4CLdyOECMm0&si=vrOG6N4KIf-T6OAE)

-----

## 🐍 Apa itu OOP pada bahasa pemrograman Python?

OOP adalah paradigma pemrograman yang berfokus pada penggunaan “objek” untuk merepresentasikan data dan fungsi-fungsi yang bekerja dengan data tersebut. Dalam pendekatan OOP, programmer memodelkan bagian-bagian program sebagai objek yang memiliki atribut (data/properti) dan method (fungsi).

**Sumber:** [Dicoding](https://www.dicoding.com/blog/mengenal-oop-konsep-dan-contoh/)

-----

## 1.\.🏭 Class & Object

<details>
<summary> Click to see more... </summary>

### 1. Class
Class adalah sebuah blueprint atau template untuk membuat objek. Di dalamnya (Class) didefinisikan attribut - attribut dan method - method yang akan objek miliki.

### Contoh Class Kosong:
```python
# Membuat Class (Cetakan)
class Robot:
    pass  # 'pass' artinya kosong dulu, belum ada isinya
```

### 2. Object
Object adalah sebuah variabel instance yang merupakan wujud dari class. Instance merupakan wujud dari sebuah kelas. Sebuah objek digambarkan dengan variable dan method.

### Contoh Object:
```python
# Membuat Class (Cetakan)
class Robot:
    pass  # 'pass' artinya kosong dulu, belum ada isinya

# Membuat Object (Barang jadi)
robot_1 = Robot()
ambatron = Robot()

print(robot_1)
```

-----
</details>

## 2.\.🏭 Attribut

<details>
<summary> Click to see more... </summary>
Atribut merupakan bagian dari sebuah kelas yang masih berhubungan erat dari kelas tersebut. Atribut bisa juga disebut sebagai properti atau properties dari sebuah class. Contohnya ketika terdapat sebuah class bernama Robot, maka Class tersebut dapat ditambahkan atribut seperti pin Ultrasonik, pin Motor, pin LED, dsb.

### Contoh attribut: 
```python
# Membuat Class (Cetakan)
class Robot:
    pinMotor # attribut untuk menyimpan angka pin Motor
    pinUltrasonik # attribut untuk menyimpan angka pin sensor Ultrasonik
    pinServo # attribut untuk menyimpan angka pin Servo
    pinKamera # attribut untuk menyimpan port/pin Kamera

# Membuat Object (Barang jadi)
robot_1 = Robot()
ambatron = Robot()

print(robot_1)
```
-----
</details>

## 3.\.🏭 Method

<details>
<summary> Click to see more... </summary>
Method merupakan bagian dari Class yang berperanmenjelaskan bagaimana suatu atribut beraksi. Peran yang dimaksud berupa tingkah laku (behavior) yang dapat digambarkan oleh suatu method. Misal Class Robot. Robot tentu memiliki method berupa bergerak maju, mundur, mengukur jarak, dsb.

### Contoh Method:
```python
# Membuat Class (Cetakan)
class Robot:
    pinMotor # attribut untuk menyimpan angka pin Motor
    pinUltrasonik # attribut untuk menyimpan angka pin sensor Ultrasonik
    pinServo # attribut untuk menyimpan angka pin Servo
    pinKamera # attribut untuk menyimpan port/pin Kamera

    # Method / behavior yang dimiliki oleh Class Robot
    def maju(): 
        print("Robot bergerak maju.....")

    def mundur():
        print("Robot bergerak mundur....")

    def bukaKamera():
        print("Kamera dinyalakan")

# Membuat Object (Barang jadi)
robot_1 = Robot()
ambatron = Robot()

ambatron.pinServo = 67

print(robot_1)
```

-----
</details>

## 4.\.🔧 Constructor

<details>
<summary> Click to see more... </summary>

Constructor adalah method spesial yang otomatis dijalankan saat objek pertama kali dibuat. Pada bahasa pemrograman Python, constructur memiliki nama/keyword `__init__`. Fungsinya untuk memberikan nilai awal pada atribut secara langsung, sehingga kita tidak perlu mengisinya satu per satu secara manual.

### Contoh Constructor:
```python
# Membuat Class (Cetakan)
class Robot:
    # Di Python, jika Class memiliki konstruktor, attribut didefinisikan langsung di dalam __init__

    def __init__(self, pinMotor, pinUltrasonik, pinServo, pinKamera):
        self.pinMotor = pinMotor # attribut untuk menyimpan angka pin Motor
        self.pinUltrasonik = pinUltrasonik # attribut untuk menyimpan angka pin sensor Ultrasonik
        self.pinServo = pinServo # attribut untuk menyimpan angka pin Servo
        self.pinKamera = pinKamera # attribut untuk menyimpan port/pin Kamera

    # Method / behavior yang dimiliki oleh Class Robot
    def maju(): 
        print("Robot bergerak maju.....")

    def mundur():
        print("Robot bergerak mundur....")

    def bukaKamera():
        print("Kamera dinyalakan")

# Pembuatan objek dengan memberi nilai awal untuk attribut melalui constructor
robot_1 = Robot(3, 5,  7, 8) 
ambatron = Robot(1, 4, 6, 9)

ambatron.pinServo = 67 # mengganti nilai pinServo menjadi 67

print(robot_1)
```

-----
</details>

## 5.\.🛡️ Encapsulasi

<details>
<summary> Click to see more... </summary>

Enkapsulasi adalah teknik "membungkus" data (atribut) dan method dalam satu unit untuk melindunginya agar tidak bisa diakses atau diubah sembarangan oleh pihak luar.

* **Jenis - jenis enkaspulasi di Python:**
    * Public (tanpa garis bawah `_`), attribut dan method dengan jenis enkapsulasi ini bisa dikases dari mana saja. Contohnya `self.pinServo`.
    * Protected (satu garis bawah `_`), attribut dan method dengan jenis enkapsulasi ini hanya bisa diakses oleh Class itu sendiri dan turunannya. Contohnya `self._pinServo`.
    * Private, (dua garis bawah `_`), attribut dan method dengan jenis enkapsulasi ini hanya bisa diakses dari dalam Class itu sendiri. Contonya `self.__pinServo`.

Untuk mengakses attribut yang memiliki enkapsulasi private diperlukan method setter dan getter yang bersifat public. Method getter digunakan untuk memperoleh nilai dari attribut sedangkan method setter digunakan untuk mengatur nilai dari attribut. Hal ini juga berlaku untuk attribut yang memiliki enkapsulasi protected jika diakses dari Class lain yang bukan turunan dari Class pemilik attribut tersebut.

### Contoh Enksapsulasi: 
```python
class Robot:
    # Di Python, jika Class memiliki konstruktor, attribut didefinisikan langsung di dalam __init__
 
    
    def __init__(self, pinMotor, pinUltrasonik, pinServo, pinKamera):
       self.pinMotor = pinMotor # attribut untuk menyimpan angka pin Motor
        self.pinUltrasonik = pinUltrasonik # attribut untuk menyimpan angka pin sensor Ultrasonik
        self._pinServo = pinServo # attribut untuk menyimpan angka pin Servo
        self._pinKamera = pinKamera # attribut untuk menyimpan port/pin Kamera

    # Method / behavior yang dimiliki oleh Class Robot
    def maju(): 
        print("Robot bergerak maju.....")

    def mundur():
        print("Robot bergerak mundur....")

    def bukaKamera():
        print("Kamera dinyalakan")
    
    #Method Getter dan Setter
    # Getter: Mengambil nilai
    def get_pinKamera(self):
        return self.__pinKamera

    # Setter: Mengubah nilai dengan validasi
    def set_pinKamera(self, pin_baru):
        self.__pinKamera = pin_baru
        print(f"Pin kamera berhasil diubah menjadi {self.__pinKamera}")

# Pembuatan objek dengan memberi nilai awal untuk attribut melalui constructor
robot_1 = Robot(3, 5,  7, 8) 
ambatron = Robot(1, 4, 6, 9)

ambatron._pinServo = 67 # mengganti nilai pinServo menjadi 67
ambatron.set_pinKamera(99) # mengganti pin kamera dengan setter
pinKamera = ambatron.get_pinKamera() # mangambil nilai attribut __pinKamera

print(robot_1.pinMotor) # Mengakses attribut public
```

-----
</details>

## 6.\.🧬 Inheritance (Pewarisan)

<details>
<summary> Click to see more... </summary>
Inheritance atau pewarisan adalah sebuah konsep fundamental di OOP yang mengizinkan Class baru untuk mewarisi attribut - attribut dan method - method yang dimiliki oleh Class yang sudah dulu ada (Class Induk).

### Contoh Inheritance:
```python
# Class Induk
class Robot:
    # Di Python, jika Class memiliki konstruktor, attribut didefinisikan langsung di dalam __init__
 
    
    def __init__(self, pinMotor, pinUltrasonik, pinServo, pinKamera):
       self.pinMotor = pinMotor # attribut untuk menyimpan angka pin Motor
        self.pinUltrasonik = pinUltrasonik # attribut untuk menyimpan angka pin sensor Ultrasonik
        self._pinServo = pinServo # attribut untuk menyimpan angka pin Servo
        self._pinKamera = pinKamera # attribut untuk menyimpan port/pin Kamera

    # Method / behavior yang dimiliki oleh Class Robot
    def maju(): 
        print("Robot bergerak maju.....")

    def mundur():
        print("Robot bergerak mundur....")

    def bukaKamera():
        print("Kamera dinyalakan")
    
    #Method Getter dan Setter
    # Getter: Mengambil nilai
    def get_pinKamera(self):
        return self.__pinKamera

    # Setter: Mengubah nilai dengan validasi
    def set_pinKamera(self, pin_baru):
        self.__pinKamera = pin_baru
        print(f"Pin kamera berhasil diubah menjadi {self.__pinKamera}")

# Class Anak (Mewarisi Robot)
Class RobotSAR(Robot):
    def menggerakkanCapit():
        print("Capi robot bergerak....")

# Pembuatan objek
robotSAR = RobotSAR(1, 4, 6, 9)
robotSAR.menggerakkanCapit()
robotSAR.maju()
```

-----
</details>

## 7.\.🎭 Polymorphism (Polimorfisme)

<details>
<summary> Click to see more... </summary>
Polimorfisme atau yang berarti 'banyak bentuk' adalah sebuah konse inti dari OOP yang mengizinkan object diperlakukan seperti objek dari kelas induknya (parent class), meskipun sebenarnya objek tersebut adalah bentuk dari kelas turunan (child class) yang berbeda. Dalam penerapannya, polimorfisme sering diterapkkan melali method Overriding dan method Overloading.

### 1. Method Overriding
Overridng adalah ituasi di mana sebuah Child Class (kelas anak) menyediakan implementasi ulang yang spesifik untuk sebuah method yang sebenarnya sudah didefinisikan di Parent Class (kelas induk). Secara harfiah, Overriding berarti "menimpa" atau "menggantikan".

### Contoh Overriding:
```python
class Robot:
    def serang(self):
        print("Menembakkan laser pew pew!")

class RobotBoss(Robot):
    def serang(self):
        # 1. Jalankan dulu serangan standar milik Parent
        super().serang() 
        
        # 2. Tambahkan serangan spesial Boss (Overriding dengan perluasan)
        print("Meluncurkan roket raksasa! BOOM!")

# --- Pengujian ---
boss = RobotBoss()
boss.serang()
```

### 2. Method Overloading
Overloading adalah sitausi dimana dibuat beberapa  method dengan nama yang **SAMA PERSIS** di dalam **SATU CLASS** yang sama, tetapi memiliki parameter yang BERBEDA.

Tujuannya adalah untuk menangani input yang berbeda-beda tanpa harus membuat nama method yang aneh-aneh (seperti hitung_luas_persegi, hitung_luas_segitiga, dsb). Cukup satu nama: hitung_luas, tatapi method dapat menyesuaikan diri.

Berbeda dengan beberapa bahasa pemrograman lain, Python tidak mendukung Overloading secara langsung. Untuk melalukan overloading, programmer dapat melakukan trik **Default Parameter**. Dengan adanya default paramter, paremater dari method tersebut menjadi opsional bisa diisi bisa tidak.

### Contoh Overloading:
```python
class MotorRobot:
    # Kita set 'durasi' menjadi None (kosong) jika user tidak mengisinya
    def jalan(self, kecepatan, durasi=None):
        if durasi is None:
            # Logika 1: Jika cuma ada kecepatan (Terus jalan sampai distop)
            print(f"Motor berputar terus dengan speed {kecepatan}...")
        else:
            # Logika 2: Jika ada kecepatan DAN durasi
            print(f"Motor berputar speed {kecepatan} selama {durasi} detik, lalu berhenti.")

# --- PENGUJIAN ---
dinamo = MotorRobot()

# Cara Pakai 1 (1 Parameter)
dinamo.jalan(255)  
# Output: Motor berputar terus dengan speed 255...

# Cara Pakai 2 (2 Parameter)
dinamo.jalan(150, 5) 
# Output: Motor berputar speed 150 selama 5 detik, lalu berhenti.
```

-----
</details>

## 🎯 Latihan
* [Codewars](https://www.codewars.com/?language=python)
* [Leetcode](https://leetcode.com/problemset/)
* [Hackerrank](https://www.hackerrank.com/domains/python)