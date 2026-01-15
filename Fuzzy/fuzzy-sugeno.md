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
Tahap input ditangani oleh fungsi `readUltrasonic(int trigPin, int echoPin)`. Robot membaca jarak dari 4 sensor ultrasonik (d1, d2, d3, d4). Hasilnya adalah angka pasti (crisp) dalam satuan centimeter, misalnya d1 = 15 cm. Sensor ultasonik mengirim sinyal ping, menghitung waktu pantul, dan mengonversinya menjadi jarak.

```cpp
    long readUltrasonic(int trigPin, int echoPin) {
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        long duration = pulseIn(echoPin, HIGH, 30000); // timeout ~5m
        if (duration == 0) return 100; // error → anggap sangat jauh

        long distance = duration * 0.034 / 2; // kecepatan suara ≈ 340 m/s
        return constrain(distance, 0, 100); // batasi range 0-100 cm
    }
```

### 2. Fuzzifikasi
Tahap ini mengubah nilai angka pasti (crisp) menjadi nilai linguistik (Fuzzy) menggunakan Fungsi Keanggotaan. Tahap ini ditangani oleh fungsi `fuzzifyDistance(long distance)` dan `trimf`. Ouput dari fungsi ini bukan lagi angka 15, melainkan derajat keanggotaan (0 sampai 1). Misalnya: very_close = 0.25 dan close = 0.4. Data ini disimpan dalam struct distanceSet.

```cpp
    // Mengubah jarak aktual (cm) menjadi nilai fuzzy (0~1)
    distanceSet fuzzifyDistance(long distance) {
        distanceSet ds;
        ds.very_close = trimf(distance, 0, 0, 20); // sangat dekat sekali
        ds.close = trimf(distance, 10, 30, 50); // dekat
        ds.medium = trimf(distance, 40, 60, 80); // sedang
        ds.far = trimf(distance, 70, 100, 100); // jauh
        return ds;
    }
```

```cpp
    // Fungsi keanggotaan segitiga (Triangular Membership Function)
    float trimf(float x, float a, float b, float c) {
        if (x <= a || x >= c) return 0.0;
        else if (x <= b) return (x - a) / (b - a); // naik
        else return (c - x) / (c - b); // turun
    }
```

### 3. Inferensi 
Tahap ini mengevaluasi aturan IF-THEN untuk menentukan seberapa kuat sebuah aksi harus dilakukan. Tahap ini ditangani oleh fungsi `fuzzyInference(d1, d2, d3, d4)`.

* Operator AND: Menggunakan fungsi fuzzyMin. Jika syaratnya "Jarak1 Jauh DAN Jarak2 Jauh", maka diambil nilai terkecil di antara keduanya.
* Operator OR: Menggunakan fungsi fuzzyMax

Output dari fungsi ini disebut α-predikat (nilai aktivasi). Nilai ini akan digunakan untuk menentukan nilai Z (titik tegas) pada setiap aturan.

```cpp
    FuzzyOutputPreference fuzzyInference(long d1, long d2, long d3, long d4) {
        distanceSet fdk = fuzzifyDistance(d1);
        distanceSet fdk_ = fuzzifyDistance(d2);
        distanceSet fsk = fuzzifyDistance(d3);
        distanceSet fsk_ = fuzzifyDistance(d4);

        FuzzyOutputPreference alpha;
        alpha.turn_left = 0.0; alpha.straight = 0.0; alpha.turn_right = 0.0; alpha.backward = 0.0;

        alpha.straight = fuzzyMax(alpha.straight, fuzzyMin(fdk.far, fdk_.far));
     
        alpha.turn_right = fuzzyMax(alpha.turn_right, fuzzyMin(fdk.close, fdk_.far));

        alpha.turn_left = fuzzyMax(alpha.turn_left, fuzzyMin(fdk_.close, fdk.far));
   
        alpha.straight = fuzzyMax(alpha.straight, fuzzyMax(fdk.very_close, fdk_.very_close));

        alpha.turn_left = fuzzyMax(alpha.turn_left, fuzzyMin(fuzzyMax(fdk.close, fdk_.close), fsk.far));
   
        alpha.turn_right = fuzzyMax(alpha.turn_right, fuzzyMin(fuzzyMax(fdk.close, fdk_.close), fsk_.far));

        alpha.straight = fuzzyMax(alpha.straight, fuzzyMin(fdk.close, fuzzyMin(fdk_.close, fuzzyMin(fsk.close, fsk_.close))));

        float a8 = fuzzyMax(fdk.very_close, fdk_.very_close);
        a8 = fuzzyMin(a8, fuzzyMin(fsk.very_close, fsk_.very_close));
        alpha.backward = fuzzyMax(alpha.backward, a8);

        return alpha;
    }
```

### 4. Defuzzifikasi
Tahap ini mengubah hasil inferensi (yang berupa nilai aktivasi atau α-predikat) menjadi satu angka pasti (Crisp Value). Berbeda dengan Mamdani yang mencari titik berat area, Tsukamoto menggunakan perhitungan rata-rata berbobot (Weighted Average).

Tahap ini ditangani oleh fungsi defuzzifySugeno(alpha). Program bekerja melalui dua langkah utama:
1. **Penggunaan Nilai Konstanta (Singleton)**: Untuk setiap aturan yang aktif, Sugeno tidak mencari titik pada kurva miring, melainkan langsung menggunakan nilai konstanta tetap yang sudah didefinisikan (misalnya: OUT_LEFT = -6.0, OUT_RIGHT = 6.0).
2. **Menghitung Rata-rata Berbobot**: Program menjumlahkan hasil perkalian antara nilai aktivasi (α) setiap aturan dengan nilai konstanta outputnya, kemudian membaginya dengan total seluruh nilai aktivasi.

Output dari fungsi ini menghasilkan satu nilai desimal tunggal yang sangat presisi (misalnya -5.42).

```cpp
    const float OUT_BACKWARD   = -12.5;   // nilai representatif mundur
    const float OUT_LEFT       = -6.0;    // nilai representatif belok kiri
    const float OUT_RIGHT      =  6.0;    // nilai representatif belok kanan
    const float OUT_STRAIGHT   =  0.0;    // nilai representatif lurus

    float defuzzifyTsukamoto(FuzzyOutputPreference alpha) {
        float numerator = 0.0;
        float denominator = 0.0;

        // Jika aturan mundur aktif, kontribusi = α × -12.5
        if (alpha.backward > 0) {
            numerator += alpha.backward * OUT_BACKWARD;
            denominator += alpha.backward;
        }

        // Jika aturan belok kiri aktif
        if (alpha.turn_left > 0) {
            numerator += alpha.turn_left * OUT_LEFT;
            denominator += alpha.turn_left;
        }

        // Jika aturan belok kanan aktif
        if (alpha.turn_right > 0) {
            numerator += alpha.turn_right * OUT_RIGHT;
            denominator += alpha.turn_right;
        }

         // Jika aturan lurus aktif = kontribusi 0
        if (alpha.straight > 0) {
            numerator += alpha.straight * OUT_STRAIGHT;
            denominator += alpha.straight;
        }

        if (denominator == 0) return 0.0;
        return numerator / denominator;
    }
```

### 5. Ouput (Crisp Ouput)
Tahap pengambilan keputusan akhir atau tindakan nyata oleh perangkat keras. Tahap ini terdapat di dalam `void loop()` melalui logika `if-else` untuk menentukan nilai variabel `final_value`.Karena robot perlu perintah sederhana (Mundur, Kiri, Kanan, Lurus), maka final_value hasil defuzzifikasi tadi dikategorikan kembali.

```cpp
    void loop() {
        long d1 = readUltrasonic(TRIG1, ECHO1);
        long d2 = readUltrasonic(TRIG2, ECHO2);
        long d3 = readUltrasonic(TRIG3, ECHO3);
        long d4 = readUltrasonic(TRIG4, ECHO4);

        FuzzyOutputPreference alpha = fuzzyInference(d1, d2, d3, d4);
        float final_value = defuzzifySugeno(alpha);

        enum DIRECTION {
             BACKWARD = 0, 
             LEFT = 1, 
             RIGHT = 2, 
             STRAIGHT_FORWARD = 3 
        };
        DIRECTION direction = STRAIGHT_FORWARD;

        if (final_value < -10.0) direction = BACKWARD;
        else if (final_value < -2.0) direction = LEFT;
        else if (final_value > 2.0) direction = RIGHT;
        else direction = STRAIGHT_FORWARD;

       Serial.println((int)direction);

        delay(200);
    }
```

### Kode Lengkap (belum fix)
```cpp
    #define TRIG1 7
    #define ECHO1 6
    #define TRIG2 9
    #define ECHO2 8
    #define TRIG3 11
    #define ECHO3 10
    #define TRIG4 13
    #define ECHO4 12    

    struct distanceSet {
        float very_close;
        float close;
        float medium;
        float far;
    };

    struct FuzzyOutputPreference {
        float turn_left;
        float straight;
        float turn_right;
        float backward; 
    };

    float trimf(float x, float a, float b, float c) {
        if (x <= a || x >= c) return 0.0;
        else if (x <= b) return (x - a) / (b - a);
        else return (c - x) / (c - b);
    }

    distanceSet fuzzifyDistance(long distance) {
        distanceSet ds;
        ds.very_close = trimf(distance, 0, 0, 20);
        ds.close = trimf(distance, 10, 30, 50);
        ds.medium = trimf(distance, 40, 60, 80);
        ds.far = trimf(distance, 70, 100, 100);
        return ds;
    }

    long readUltrasonic(int trigPin, int echoPin) {
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        long duration = pulseIn(echoPin, HIGH, 30000);
        if (duration == 0) return 100;
        long distance = duration * 0.034 / 2;
        return constrain(distance, 0, 100);
    }

    float fuzzyMin(float a, float b) { return (a < b) ? a : b; }
    float fuzzyMax(float a, float b) { return (a > b) ? a : b; }

    FuzzyOutputPreference fuzzyInference(long d1, long d2, long d3, long d4) {
        distanceSet fdk = fuzzifyDistance(d1);
        distanceSet fdk_ = fuzzifyDistance(d2);
        distanceSet fsk = fuzzifyDistance(d3);
        distanceSet fsk_ = fuzzifyDistance(d4);

        FuzzyOutputPreference alpha;
        alpha.turn_left = 0.0; alpha.straight = 0.0; alpha.turn_right = 0.0; alpha.backward = 0.0;

        alpha.straight = fuzzyMax(alpha.straight, fuzzyMin(fdk.far, fdk_.far));
     
        alpha.turn_right = fuzzyMax(alpha.turn_right, fuzzyMin(fdk.close, fdk_.far));

        alpha.turn_left = fuzzyMax(alpha.turn_left, fuzzyMin(fdk_.close, fdk.far));
   
        alpha.straight = fuzzyMax(alpha.straight, fuzzyMax(fdk.very_close, fdk_.very_close));

        alpha.turn_left = fuzzyMax(alpha.turn_left, fuzzyMin(fuzzyMax(fdk.close, fdk_.close), fsk.far));
   
        alpha.turn_right = fuzzyMax(alpha.turn_right, fuzzyMin(fuzzyMax(fdk.close, fdk_.close), fsk_.far));

        alpha.straight = fuzzyMax(alpha.straight, fuzzyMin(fdk.close, fuzzyMin(fdk_.close, fuzzyMin(fsk.close, fsk_.close))));

        float a8 = fuzzyMax(fdk.very_close, fdk_.very_close);
        a8 = fuzzyMin(a8, fuzzyMin(fsk.very_close, fsk_.very_close));
        alpha.backward = fuzzyMax(alpha.backward, a8);

        return alpha;
    }

    const float OUT_BACKWARD = -12.5; 
    const float OUT_LEFT = -6.0;  
    const float OUT_RIGHT = 6.0;   
    const float OUT_STRAIGHT = 0.0;   

    float defuzzifyTsukamoto(FuzzyOutputPreference alpha) {
        float numerator = 0.0;
        float denominator = 0.0;

        if (alpha.backward > 0) {
            numerator += alpha.backward * OUT_BACKWARD;
            denominator += alpha.backward;
        }

        if (alpha.turn_left > 0) {
            numerator += alpha.turn_left * OUT_LEFT;
            denominator += alpha.turn_left;
        }

        if (alpha.turn_right > 0) {
            numerator += alpha.turn_right * OUT_RIGHT;
            denominator += alpha.turn_right;
        }

        if (alpha.straight > 0) {
            numerator += alpha.straight * OUT_STRAIGHT;
            denominator += alpha.straight;
        }

        if (denominator == 0) return 0.0;
        return numerator / denominator;
    }

    void setup() {
        Serial.begin(9600); 
        pinMode(TRIG1, OUTPUT); pinMode(ECHO1, INPUT);
        pinMode(TRIG2, OUTPUT); pinMode(ECHO2, INPUT);
        pinMode(TRIG3, OUTPUT); pinMode(ECHO3, INPUT);
        pinMode(TRIG4, OUTPUT); pinMode(ECHO4, INPUT);
    }

    void loop() {
        long d1 = readUltrasonic(TRIG1, ECHO1);
        long d2 = readUltrasonic(TRIG2, ECHO2);
        long d3 = readUltrasonic(TRIG3, ECHO3);
        long d4 = readUltrasonic(TRIG4, ECHO4);

        FuzzyOutputPreference alpha = fuzzyInference(d1, d2, d3, d4);
        float final_value = defuzzifySugeno(alpha);

        enum DIRECTION { 
            BACKWARD = 0, 
            LEFT = 1, 
            RIGHT = 2, 
            STRAIGHT_FORWARD = 3 
        };
        DIRECTION direction = STRAIGHT_FORWARD;

        if (final_value < -10.0) direction = BACKWARD;
        else if (final_value < -2.0) direction = LEFT;
        else if (final_value > 2.0) direction = RIGHT;
        else direction = STRAIGHT_FORWARD;

       Serial.println((int)direction);

        delay(200);
    }
```