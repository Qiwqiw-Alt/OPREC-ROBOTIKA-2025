## Fuzzy Sugeno

## Sumber:
* [Fuzzy SUGENO alias TAKAGI-SUGENO-KANG | Sistem Inferensi Fuzzy | Studi Kasus Mesin Cuci Otomatis](https://youtu.be/RjyRTBNk3w8?si=wApoVoZ0tOUxGNqS)

## Contoh Kasus: Sensor Ultrasonik untuk mengatur arah pergerakan robot.
Sebuah robot memiliki 4 buah sensor ultrasonik di keempat sisinya untuk mengukur jarak pada masing- masing sisi. Spesifikasi dari pengkategorian jaraknya adalah:
1. **Sangat dekat (0 - 20 cm)**. Nilai kebenaran (derajat keanggotaan) maksimal (1.0) berada pada angka 0 cm. Semakin menjauh dari 0 cm, derajat keanggotaannya menurun hingga mencapai angka 0 (tidak dianggap sangat dekat lagi) tepat di 20 cm.
2. **Dekat (10 - 50 cm)**. Jarak mulai dianggap "Dekat" sejak 10 cm. Status "Dekat" mencapai nilai maksimal jika sensor membaca tepat 30 cm. Setelah melewati 30 cm, status "Dekat" mulai berkurang hingga hilang di angka 50 cm.
3. **Sedang (40 - 80 cm)**. Jarak mulai dianggap "Sedang" sejak 40 cm. Status "Sedang" mencapai nilai maksimal pada jarak 60 cm dan hilang pada jarak 80 cm.
4. **Jauh (70 - 100 cm atau lebih)**arak mulai dianggap "Jauh" sejak 70 cm. Status "Jauh" akan bernilai maksimal (1.0) jika jarak mencapai 100 cm atau lebih.

## Contoh Kasus: Sensor Ultrasonik untuk mengatur arah pergerakan robot.
Sebuah robot memiliki 4 buah sensor ultrasonik di keempat sisinya untuk mengukur jarak pada masing- masing sisi. Spesifikasi dari pengkategorian jaraknya adalah:
1. **Sangat dekat (0 - 20 cm)**. Nilai kebenaran (derajat keanggotaan) maksimal (1.0) berada pada angka 0 cm. Semakin menjauh dari 0 cm, derajat keanggotaannya menurun hingga mencapai angka 0 (tidak dianggap sangat dekat lagi) tepat di 20 cm.
2. **Dekat (10 - 50 cm)**. Jarak mulai dianggap "Dekat" sejak 10 cm. Status "Dekat" mencapai nilai maksimal jika sensor membaca tepat 30 cm. Setelah melewati 30 cm, status "Dekat" mulai berkurang hingga hilang di angka 50 cm.
3. **Sedang (40 - 80 cm)**. Jarak mulai dianggap "Sedang" sejak 40 cm. Status "Sedang" mencapai nilai maksimal pada jarak 60 cm dan hilang pada jarak 80 cm.
4. **Jauh (70 - 100 cm atau lebih)**arak mulai dianggap "Jauh" sejak 70 cm. Status "Jauh" akan bernilai maksimal (1.0) jika jarak mencapai 100 cm atau lebih.

Berdasarkan beberapa pengujian, diperoleh aturan sebagai berikut: (beberapa belum fix)
1. R1: Jika Depan Kiri Jauh dan Depan Kanan Jauh, **Jalan Lurus**
2. R2: Jika Depan Kiri Dekat dan Depan Kanan Jauh, **Belok Kanan**
3. R3: Jika Depan Kiri Jauh dan Depan Kanan Dekat, **Belok Kiri**
4. R4: Jika Depan Kiri Sangat Dekat atau Depan Kanan Sangat Dekat, **Jalan Lurus (belum fix)**
5. R5: Jika Depan (Kiri/Kanan) Dekat dan Samping Kiri Jauh, **Belok Kiri (belum fix)**
6. R6: Jika Depan (Kiri/Kanan) Dekat dan Samping Kanan Jauh, **Belok Kanan (belum fix)**
7. R7: Jika Semua Senosr berada pada jarak yang Dekat, **Jalan Lurus (belum fix)**
8. R8. Jika Semua Sensor berada pada jarak yang Sangat Dekat, **Mundur (belum fix)**

## Kode Program (Belum Fix)
### 1. Input (Crisp Input)
```cpp
```

### 2. Fuzzifikasi
```cpp
```

### 3. Inferensi 
```cpp
```

### 4. Defuzzifikasi
```cpp
```

### 5. Ouput (Crisp Ouput)
```cpp
```

### Kode Lengkap
```cpp
```