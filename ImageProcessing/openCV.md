## OpenCV Dasar

## Link Penting 🔗

* **Compiler:**
    * [Download Python](https://www.python.org/downloads/)
    * [Video Tutorial Install](https://youtu.be/1sKTa3r-SqE?si=-LiVcH28LvolAlRS)
    * [Video Tutorial Install OpenCV](https://youtu.be/j3V17t0a0fw?si=BxqlMxDWAy4nku9M)

* **Teks Editor / IDE:**
    * [Visual Studio Code](https://code.visualstudio.com/)
    * [Notepad++](https://notepad-plus-plus.org/downloads/)
    * [Vim](https://www.vim.org/download.php)

* **Online Compiler:**
    * [Programiz Python Compiler (Interpreter)](https://www.programiz.com/python-programming/online-compiler/)
    * [OnlineGDB Python Compiler (Interpreter)](https://www.onlinegdb.com/online_python_compiler)
    * [Oneline Python Compiler (Interpreter)](https://www.online-python.com/)

* **Sumber Belajar Tambahan:**
    * [freeCodeCamp OpenCV](https://youtu.be/oXlwWbU8l2o?si=o5RrbjgFlKuIftN3)
    * [Tech With Tim Playlist](https://youtube.com/playlist?list=PLzMcBGfZo4-lUA8uGjeXhBUUzPYc6vZRn&si=8Y7farwouZjbSy_1)
    * [OpenCV with C++ Playlist](https://youtube.com/playlist?list=PLUTbi0GOQwghR9db9p6yHqwvzc989q_mu&si=cwnKAAP2Wss1JTNO)
    * [OpenCV Official Website](https://opencv.org/)

-----

## OpenCV
OpenCV (Open Source Computer Vision Library) adalah library open source terbesar untuk computer vision dan machine learning, dengan lebih dari 2500 algoritma teroptimasi. Library ini dirancang untuk aplikasi real-time, mendukung berbagai bahasa pemrograman seperti C++, Python, Java, dan platform Windows, Linux, macOS, Android, serta iOS. OpenCV dapat diunduh secara gratis di [OpenCV Official Website](https://opencv.org/).

## NumPy
NumPy (Numerical Python) adalah library fundamental dalam Python untuk komputasi numerik. Library ini menyediakan objek array multidimensi (ndarray) yang efisien serta berbagai fungsi matematika untuk operasi pada array tersebut. NumPy sangat penting untuk pemrosesan data, operasi matriks, pemrosesan citra, dan menjadi dasar bagi banyak library ilmiah lainnya seperti Pandas, SciPy, dan OpenCV.

### Menampilkan Gambar Layar
```python
    import cv2 # Mengimpor library OpenCV untuk pemrosesan video dan citra

    # Membaca citra dari file
    citra = cv2.imread("image/ambasing.png")

    # Memeriksa apakah citra berhasil dibaca
    if citra is not None:
        cv2.imshow("Image", citra) # Menampilkan citra di jendela berjudul "Image"
        cv2.waitKey(0) # Menunggu sampai ada tombol keyboard yang ditekan (0 = tunggu selamanya)
        cv2.destroyAllWindows() # Menutup semua jendela setelah tombol ditekan
    else:
        print("Gagal membaca citra! Periksa path file atau apakah file benar-benar ada.")
```

### Membuat Persgi/Persegi Panjang
```python
    import cv2 # Mengimpor library OpenCV untuk pemrosesan video dan citra
    import numpy as np  # Mengimpor NumPy untuk membuat array dan operasi numerik

    # Membuat citra kosong berukuran 500x500 piksel, berwarna PUTIH (nilai 255)
    # np.ones((tinggi, lebar), tipe_data) → menghasilkan array dengan semua elemen = 1
    # Dikali 255 → semua piksel menjadi 255 (putih pada skala grayscale 0-255)
    # np.uint8 → tipe data 8-bit unsigned integer (0-255, standar untuk citra)
    citra = 255 * np.ones((500, 500), np.uint8)

    # Menggambar persegi PANJANG PERTAMA:
    # cv2.rectangle(citra, pt1, pt2, warna_BGR, ketebalan_garis)
    # pt1 = (64, 64) → koordinat pojok kiri atas
    # pt2 = (128, 128) → koordinat pojok kanan bawah
    # warna = (123, 34, 99) → format BGR (Blue=123, Green=34, Red=99) → warna ungu/magenta
    # ketebalan = 10 → garis tebal 10 piksel
    cv2.rectangle(citra, (64, 64), (128, 128), (123, 34, 99), 10)

    # Menggambar persegi PANJANG KEDUA (di atas persegi pertama):
    # pt1 = (32, 64) → lebih lebar, mulai dari x=32
    # pt2 = (256, 128) → lebih besar, sampai x=256
    # warna = (0, 0, 0) → HITAM
    # cv2.FILLED → mengisi seluruh area persegi (bukan hanya garis tepi)
    cv2.rectangle(citra, (32, 64), (256, 128), (0, 0, 0), cv2.FILLED)

    cv2.imshow("Citra", citra)   # Menampilkan citra hasil gambar di jendela berjudul "Citra"
    cv2.waitKey(0) # Menunggu sampai ada tombol keyboard yang ditekan (0 = tunggu selamanya)
    cv2.destroyAllWindows() # Menutup semua jendela setelah tombol ditekan
```

## GrayScale 
```python
    import cv2 # Mengimpor library OpenCV untuk pemrosesan video dan citra

    # Membaca citra dari file dengan skala ke abu abuan
    citra = cv2.imread("img/goldhill.jpg", 0)

    if citra is not None:
        cv2.imshow("Image", citra) # Menampilkan citra di jendela berjudul "Image"
        cv2.waitKey(0) # Menunggu sampai ada tombol keyboard yang ditekan (0 = tunggu selamanya)
        cv2.destroyAllWindows() # Menutup semua jendela setelah tombol ditekan
    else:
        print("Gagal membaca citra! Periksa path file atau apakah file benar-benar ada.")
```

## Thersholding
```python
    import cv2  # Mengimpor library OpenCV untuk pemrosesan citra

    # Membaca citra "goldhill.jpg" dalam mode grayscale (abu-abu)
    # Parameter 0 = cv2.IMREAD_GRAYSCALE → langsung jadi citra satu channel (0-255)
    # Pastikan file berada di folder "img/goldhill.jpg" relatif terhadap script
    citra = cv2.imread("img/goldhill.jpg", 0)

    # Memeriksa apakah citra berhasil dibaca (penting untuk menghindari error)
    if citra is None:
        print("Error: File 'img/goldhill.jpg' tidak ditemukan atau gagal dibaca!")
        exit()

    # Mengecilkan citra menjadi 1/4 ukuran asli (lebar dan tinggi dibagi 4)
    # citra.shape[0] = tinggi (baris), citra.shape[1] = lebar (kolom)
    # Hasil: citra_kecil memiliki ukuran 1/4 dari aslinya (misal 512x512 → 128x128)
    citra_kecil = cv2.resize(citra, (citra.shape[1] // 4, citra.shape[0] // 4))

    # Melakukan thresholding dengan nilai ambang 128
    # cv2.threshold(src, thresh, maxval, type)
    # - thresh = 128 → piksel ≤128 jadi 0, >128 jadi 255
    # - maxval = 255 → nilai maksimum yang diberikan
    # - cv2.THRESH_BINARY → tipe thresholding standar (hitam-putih biasa)
    # Return: ambang (nilai ambang yang digunakan), binerA (citra hasil biner)
    ambang, binerA = cv2.threshold(citra_kecil, 128, 255, cv2.THRESH_BINARY)

    # Thresholding yang sama, tapi tipe INVERSE
    # cv2.THRESH_BINARY_INV → kebalikan dari BINARY:
    #   piksel ≤128 jadi 255 (putih), >128 jadi 0 (hitam)
    ambang, binerB = cv2.threshold(citra_kecil, 128, 255, cv2.THRESH_BINARY_INV)

    # Menampilkan tiga jendela:
    # 1. Citra asli yang sudah dikecilkan (grayscale)
    cv2.imshow("Aseli:", citra_kecil)          # Judul jendela diperbaiki (spasi dan tanda titik)

    # 2. Hasil thresholding BINARY (objek terang = putih, latar gelap = hitam)
    cv2.imshow("THRESH_BINARY:", binerA)

    # 3. Hasil thresholding BINARY INVERSE (objek terang = hitam, latar gelap = putih)
    cv2.imshow("THRESH_BINARY_INV:", binerB)

    # Menunggu sampai ada tombol keyboard yang ditekan (0 = tunggu selamanya)
    cv2.waitKey(0)

    # Menutup semua jendela yang dibuka oleh OpenCV
    cv2.destroyAllWindows()
```

## Kontur
```python
    import cv2          # Mengimpor OpenCV untuk pemrosesan citra dan kontur
    import numpy as np  # Mengimpor NumPy untuk membuat array dan operasi matriks

    # Membaca citra dalam mode grayscale (abu-abu)
    # File harus berada di folder "citra-biner/img/hello2.png"
    # Parameter 0 = cv2.IMREAD_GRAYSCALE → citra jadi 1 channel (0-255)
    citra = cv2.imread("citra-biner/img/hello2.png", 0)

    # (Opsional tapi sangat disarankan) Cek apakah citra berhasil dibaca
    if citra is None:
        print("Error: File 'citra-biner/img/hello2.png' tidak ditemukan atau gagal dibaca!")
        exit()

    # Membuat canvas kosong berwarna HITAM dengan ukuran sama persis seperti citra asli
    # Ukuran: (tinggi, lebar, 3 channel) → untuk citra berwarna (BGR)
    # np.uint8 → tipe data 8-bit (0-255), semua nilai awal = 0 (hitam)
    citraKontur = np.zeros((citra.shape[0], citra.shape[1], 3), np.uint8)

    # Mencari kontur pada citra biner/grayscale
    # cv2.RETR_EXTERNAL → hanya ambil kontur paling luar (tidak termasuk kontur dalam/lubang)
    # cv2.CHAIN_APPROX_NONE → simpan SEMUA titik kontur (paling detail, tanpa kompresi)
    # Return: kontur (list kontur), hierarki (hubungan antar kontur)
    kontur, hierarki = cv2.findContours(citra, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

    # Menggambar semua kontur yang ditemukan ke canvas hitam (citraKontur)
    # kontur      → list semua kontur
    # -1          → gambar SEMUA kontur (bukan hanya indeks tertentu)
    # (0, 255, 0) → warna HIJAU dalam format BGR
    # 2           → ketebalan garis kontur = 2 piksel
    cv2.drawContours(citraKontur, kontur, -1, (0, 255, 0), 2)

    # Mengubah citra grayscale (1 channel) menjadi citra berwarna (3 channel) dengan cara menduplikasi channel
    # Hasil: citraRGB tetap terlihat abu-abu, tapi sekarang formatnya BGR (bisa digabung dengan citraKontur)
    citraRGB = cv2.merge((citra, citra, citra))

    # Menggabungkan dua citra secara horizontal (side-by-side)
    # np.hstack() → horizontal stack: citraRGB di kiri, citraKontur di kanan
    # Kedua citra harus memiliki tinggi yang sama (sudah pasti karena ukuran sama)
    hasil = np.hstack((citraRGB, citraKontur))

    # Menampilkan hasil gabungan dalam satu jendela
    # Kiri: citra asli grayscale (tapi ditampilkan sebagai RGB)
    # Kanan: canvas hitam dengan garis kontur berwarna hijau
    cv2.imshow("Hasil", hasil)

    # Menunggu sampai user menekan tombol apa saja
    cv2.waitKey(0)

    # Menutup semua jendela OpenCV
    cv2.destroyAllWindows()
```


### Bounding Box
```python
    import cv2 # Mengimpor OpenCV untuk pemrosesan citra dan kontur
    import numpy as np # Mengimpor NumPy untuk operasi array dan konversi data

    # Membaca citra dalam mode grayscale (0 = IMREAD_GRAYSCALE)
    citra = cv2.imread("citra-biner/img/ghost.png", 0)

    # Mengubah citra grayscale menjadi citra berwarna (RGB 3 channel)
    # Karena OpenCV pakai BGR, kita duplikat channel grayscale menjadi 3 channel
    citraBerwarna = cv2.merge((citra, citra, citra))

    # Mencari kontur pada citra biner/grayscale
    # cv2.RETR_EXTERNAL → hanya ambil kontur paling luar (external contours)
    # cv2.CHAIN_APPROX_NONE → simpan semua titik kontur (tanpa aproksimasi)
    kontur, hireariki = cv2.findContours(citra, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

    # Mengambil bounding box tegak (axis-aligned, persegi panjang biasa)
    # cv2.boundingRect() mengembalikan: x, y (pojok kiri atas), lebar, tinggi
    x, y, lebar, tinggi = cv2.boundingRect(kontur[0])

    # Menggambar persegi panjang tegak (warna kuning cyan dalam BGR: (255,255,0), tebal 2 px)
    cv2.rectangle(citraBerwarna, (x, y), (x + lebar, y + tinggi), (255, 255, 0), 2)

    # Mengambil bounding box rotasi (minimum area rectangle) yang mengikuti kemiringan objek
    # cv2.minAreaRect() mengembalikan: (center_x, center_y), (width, height), angle_rotasi
    persegiPanjang = cv2.minAreaRect(kontur[0])
    kotak = cv2.boxPoints(persegiPanjang) # Mengubah hasil minAreaRect menjadi 4 titik pojok kotak (dalam float) 
    kotak = np.int32(kotak) # Konversi titik-titik ke integer (diperlukan untuk cv2.drawContours)
    # Menggambar kotak rotasi (bounding box miring) dengan warna abu-abu (128,128,128), tebal 2 px
    cv2.drawContours(citraBerwarna, [kotak], 0, (128, 128, 128), 2)

    cv2.imshow("Hasil", citraBerwarna) # Menampilkan hasil akhir: citra berwarna dengan dua bounding box
    cv2.waitKey(0) # Menunggu sampai ada tombol keyboard yang ditekan (0 = tunggu selamanya)
    cv2.destroyAllWindows() # Menutup semua jendela setelah tombol ditekan
```

## Mengakses Kamera Eksternal dengan OpenCV
```python
   import cv2  # Mengimpor library OpenCV untuk pemrosesan video dan citra

    # Membuka akses ke kamera default (biasanya webcam built-in)
    # Angka 0 berarti kamera pertama yang terdeteksi oleh sistem
    kameraVideo = cv2.VideoCapture(0)

    # Memeriksa apakah kamera berhasil dibuka
    if not kameraVideo.isOpened():
        print("Kamera tidak bisa diakses")  # Tampilkan pesan error jika gagal
        exit()  # Keluar dari program

    # Loop utama: terus membaca frame dari kamera sampai user menekan tombol 'q'
    while(True):
        # Membaca satu frame dari kamera
        # ret = True/False (berhasil atau tidak membaca frame)
        # kerangkaAsal = gambar/frame yang berhasil dibaca (dalam bentuk array NumPy)
        ret, kerangkaAsal = kameraVideo.read()

        # Jika gagal membaca frame (misalnya kamera terputus), hentikan loop
        if not ret:
            print("Gagal membaca frame dari kamera")
            break

        # Menampilkan frame yang baru saja dibaca di jendela berjudul "Kamera"
        cv2.imshow("Kamera", kerangkaAsal)

        # cv2.waitKey(1) menunggu input keyboard selama 1 ms
        # & 0xFF digunakan untuk kompatibilitas di sistem 64-bit
        # ord('q') mengembalikan kode ASCII huruf 'q'
        # Jika user menekan tombol 'q', maka loop akan berhenti
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # Setelah loop selesai (user tekan 'q' atau error), lepaskan resource kamera
    kameraVideo.release()

    # Menutup semua jendela yang dibuat oleh OpenCV
    cv2.destroyAllWindows()
```

Pada bagian `cv2.VideoCapture(0)` angka 0 bisa diganti menjadi angka lain seperti 1, 2, dst jika terdapat lebih dari 1 kamera yang terhubung ke komputer. Jika diset dengan angka 0, kamera yang digunakan adalah kamera pertama (default). Jika di set dengan angka 1, kamera yang digunakan adalah kamera kedua dan seterusnya. Urutan angka ini tergantung sistem operasi dan driver kamera. Kadang urutannya tidak selalu sesuai ekspektasi, jadi kalau ingin mencoba kamera lain tapi tidak berhasil dengan angka tertentu, coba secara berurutan dari 0, 1, 2, dst sampai menemukan yang benar.

Selain angka, kamu juga bisa membuka file video dengan memberikan path file, contoh:

```python
    kameraVideo = cv2.VideoCapture("video.mp4")  # membuka file video
```

### Deteksi Wajah dengan Haar Cascades
```python
    import cv2 # Mengimpor library OpenCV untuk pemrosesan video dan citra
    import numpy as np # Mengimpor NumPy untuk operasi array dan konversi data

    # Memuat model Haar Cascade yang sudah dilatih untuk mendeteksi wajah depan (frontal face)
    pengklasifikasiwajah = cv2.CascadeClassifier("pengenalan-wajah/model/haarcascade_frontalface_default.xml")

    # Membuka kamera default laptop/komputer (0 = kamera utama)
    kameraLaptop = cv2.VideoCapture(0)

    # Memeriksa apakah kamera berhasil dibuka
    if not kameraLaptop.isOpened():
        print("Kamera tidak bisa diakses") # Tampilkan pesan error jika kamera gagal dibuka
        exit() # Keluar dari program

    tombolQDitekan = False # Variabel untuk mengontrol loop: program berhenti jika tombol 'q' ditekan

    # Loop utama: terus membaca frame dari kamera sampai tombol 'q' ditekan
    while(tombolQDitekan == False):
        # Membaca satu frame dari kamera
        # ret = True jika berhasil membaca, False jika gagal (misalnya kamera terputus)
        # frame = citra/frame dalam format BGR
        ret, frame = kameraLaptop.read()

        # Membalik frame secara horizontal (mirror effect) agar seperti melihat cermin
        # Angka 1 = flip horizontal, 0 = vertical, -1 = keduanya
        frame = cv2.flip(frame, 1)

        # Hanya proses jika frame berhasil dibaca
        if ret == True:
            # Mengubah frame berwarna (BGR) menjadi grayscale
            # Haar Cascade bekerja lebih baik dan lebih cepat pada citra abu-abu
            abuAbu = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

            # Mendeteksi wajah pada citra grayscale
            # scaleFactor=1.3   → seberapa besar skala pencarian dikecilkan tiap langkah (semakin kecil semakin akurat tapi lambat)
            # minNeighbors=2    → berapa banyak tetangga yang harus mendeteksi agar dianggap valid (mengurangi false positive)
            # Hasil: dafWajah berupa list tuple (x, y, w, h) → koordinat dan ukuran wajah
            dafWajah = pengklasifikasiwajah.detectMultiScale(abuAbu, scaleFactor= 1.3, minNeighbors= 2)

            # Mengambil nilai FPS (Frame Per Second) dari properti kamera
            fps = kameraLaptop.get(cv2.CAP_PROP_FPS)
            fps_txt = f"FPS: {fps:.2f}"

            # Menampilkan teks FPS di pojok kiri atas frame
            # Posisi (10,30), font sederhana, ukuran 1, warna hijau terang (0,255,0), tebal garis default
            cv2.putText(frame, fps_txt, (10, 30), cv2.FONT_HERSHEY_PLAIN, 1, (0, 255, 9))

            # Loop untuk setiap wajah yang terdeteksi
            for (x, y, w, h) in dafWajah:
                # Menggambar persegi panjang biru tebal di sekitar wajah
                # (x,y) = pojok kiri atas, (x+w, y+h) = pojok kanan bawah
                # Warna (255,0,0) = Biru dalam format BGR
                # Tebal garis = 5 piksel
                cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 5)
            
            # Menampilkan frame hasil (dengan kotak wajah dan teks FPS) di jendela
            cv2.imshow("Hasil", frame)

            # Menunggu 1 ms untuk input keyboard
            # Jika tombol 'q' ditekan, ubah variabel menjadi True agar loop berhenti
            if cv2.waitKey(1) & 0xFF == ord('q'):
                tombolQDitekan = True
                break
        else:
            # Jika gagal membaca frame (misalnya kamera terputus), keluar dari loop
            break

    # Setelah loop selesai: lepaskan resource kamera
    kameraLaptop.release()
    # Tutup semua jendela yang dibuat oleh OpenCV
    cv2.destroyAllWindows()
```