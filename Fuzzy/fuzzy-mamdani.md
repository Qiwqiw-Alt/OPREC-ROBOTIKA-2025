## Fuzzy Mamdani

## Sumber:
* [Fuzzy MAMDANI | Sistem Inferensi Fuzzy | Contoh Studi Kasus dan Langkah Penyelesaiannya](https://youtu.be/fKueNI4kY6A?si=PfTgy1NZoZpa8g0J)


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

Output dari fungsi ini menghasilkan Nilai Aktivasi untuk setiap aksi (pref_turn_left, pref_straight, dsb). Jika beberapa aturan menghasilkan aksi yang sama (misal ada dua aturan yang menyuruh belok kanan), maka diambil nilai yang paling kuat (fuzzyMax).

```cpp
    FuzzyOutputPreference fuzzyInference(long d1, long d2, long d3, long d4) {
        // Fuzzifikasi semua sensor
        distanceSet fdk = fuzzifyDistance(d1);
        distanceSet fdk_ = fuzzifyDistance(d2);
        distanceSet fsk = fuzzifyDistance(d3);
        distanceSet fsk_ = fuzzifyDistance(d4);

        // Inisialisasi nilai preferensi awal = 0
        float pref_turn_left = 0.0; 
        float pref_straight = 0.0;
        float pref_turn_right = 0.0;
        float pref_backward = 0.0;

        // 1. Jauh semua di depan = lurus
        float activation_rule1 = fuzzyMin(fdk.far, fdk_.far);
        pref_straight = fuzzyMax(pref_straight, activation_rule1);

        // 2. Kiri dekat, kanan jauh = belok kanan
        float activation_rule2 = fuzzyMin(fdk.close, fdk_.far);
        pref_turn_right = fuzzyMax(pref_turn_right, activation_rule2);

        // 3. Kanan dekat, kiri jauh = belok kiri
        float activation_rule3 = fuzzyMin(fdk_.close, fdk.far);
        pref_turn_left = fuzzyMax(pref_turn_left, activation_rule3);

        // 4. Ada yang sangat dekat di depan = lurus dulu (prioritas hindar belakang)
        float activation_rule4 = fuzzyMax(fdk.very_close, fdk_.very_close);
        pref_straight = fuzzyMax(pref_straight, activation_rule4);

        // 5. Ada yang dekat di depan + samping kiri jauh = cenderung belok kiri
        float activation_rule5 = fuzzyMin(fuzzyMax(fdk.close, fdk_.close), fsk.far);
        pref_turn_left = fuzzyMax(pref_turn_left, activation_rule5);

        // 6. Ada yang dekat di depan + samping kanan jauh → cenderung belok kanan
        float activation_rule6 = fuzzyMin(fuzzyMax(fdk.close, fdk_.close), fsk_.far);
        pref_turn_right = fuzzyMax(pref_turn_right, activation_rule6);

        // 7. Semua sisi depan & samping relatif dekat = tetep lurus pelan-pelan
        float activation_rule7 = fuzzyMin(fdk.close, fuzzyMin(fdk_.close, fuzzyMin(fsk.close, fsk_.close)));
        pref_straight = fuzzyMax(pref_straight, activation_rule7);

        // 8. Sangat dekat di depan DAN samping = mundur
        float activation_rule8 = fuzzyMax(fdk.very_close, fdk_.very_close);
        activation_rule8 = fuzzyMin(activation_rule8, fuzzyMin(fsk.very_close, fsk_.very_close));
        pref_backward = fuzzyMax(pref_backward, activation_rule8);

        FuzzyOutputPreference fo;
        fo.turn_left = pref_turn_left;
        fo.straight = pref_straight;
        fo.turn_right = pref_turn_right;
        fo.backward = pref_backward;

        return fo;
    }
```

### 4. Defuzzifikasi
Tahap mengubah hasil inferensi (yang masih berupa area/himpunan fuzzy) kembali menjadi satu angka pasti.  Tahap ini ditangani oleh fungsi `fuzzyInference(d1, d2, d3, d4)`. Metode yang digunakan pada fungsi ini adalah COG (Center Of Gravity). Program melakukan perulangan (for loop) pada "Semesta Pembicaraan" output (dari -15 sampai 10). Ia menghitung luas area gabungan dari semua aksi dan mencari di mana titik keseimbangannya. Output dari fungsi ini menghasilkan atu nilai desimal tunggal, misalnya -5.42.

```cpp
    // Defuzzifikasi metode Centre of Gravity (COG)
    float defuzzifyCOG(FuzzyOutputPreference output) {
        float numerator = 0.0;
        float denominator = 0.0;

        // Diskritisasi universe of discourse
        for (int i = 0; i < OUTPUT_UNIVERSE_SIZE; i++) {
            float x = OUTPUT_UNIVERSE_MIN + i * (OUTPUT_UNIVERSE_MAX - OUTPUT_UNIVERSE_MIN) / (OUTPUT_UNIVERSE_SIZE - 1);

            // Diskritisasi universe of discourse
            float combined = fuzzyMax(
                fuzzyMax3(
                    fuzzyMin(output.turn_left, mf_turn_left_out(x)),
                    fuzzyMin(output.straight, mf_straight_out(x)),
                    fuzzyMin(output.turn_right, mf_turn_right_out(x))
                ),
                fuzzyMin(output.backward, mf_backward_out(x)) 
            );

            numerator += x * combined;
            denominator += combined;
        }

        if (denominator == 0) return 0.0;
        return numerator / denominator;
    }
```

### 5. Ouput (Crisp Ouput)
Tahap pengambilan keputusan akhir atau tindakan nyata oleh perangkat keras. Tahap ini terdapat di dalam `void loop()` melalui logika `if-else` untuk menentukan nilai variabel `final_value`.Karena robot perlu perintah sederhana (Mundur, Kiri, Kanan, Lurus), maka final_value hasil defuzzifikasi tadi dikategorikan kembali.

```cpp
    void loop() {
        d1 = readUltrasonic(TRIG1, ECHO1);
        d2 = readUltrasonic(TRIG2, ECHO2);
        d3 = readUltrasonic(TRIG3, ECHO3);
        d4 = readUltrasonic(TRIG4, ECHO4);

        FuzzyOutputPreference result = fuzzyInference(d1, d2, d3, d4);
        float final_value = defuzzifyCOG(result);

        // Keputusan akhir (crisp value) = diubah menjadi arah diskrit
        enum DIRECTION {
            BACKWARD = 0,
            LEFT = 1,
            RIGHT = 2,
            STRAIGHT_FORWARD = 3
        };

        DIRECTION direction = STRAIGHT_FORWARD;
        if (final_value < -10.0) {
            direction = BACKWARD ;
        } else if (final_value < -2.0) {
            direction = LEFT;
        } else if (final_value > 2.0) {
            direction = RIGHT;
        } else {
            direction = STRAIGHT_FORWARD;
        }

        Serial.println((int)direction);  // Kirim ke serial untuk debugging/motor driver

        delay(200); // kontrol kecepatan loop ~5 kali per detik
    }
```

### Kode Lengkap
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

    float fuzzyMin(float a, float b) {
        return (a < b) ? a : b;
    }

    float fuzzyMax(float a, float b) {
        return (a > b) ? a : b;
    }

    float fuzzyMax3(float a, float b, float c) {
        return fuzzyMax(a, fuzzyMax(b, c));
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

    FuzzyOutputPreference fuzzyInference(long d1, long d2, long d3, long d4) {
        distanceSet fdk = fuzzifyDistance(d1);
        distanceSet fdk_ = fuzzifyDistance(d2);
        distanceSet fsk = fuzzifyDistance(d3);
        distanceSet fsk_ = fuzzifyDistance(d4);

        float pref_turn_left = 0.0;
        float pref_straight = 0.0;
        float pref_turn_right = 0.0;
        float pref_backward = 0.0;

        float activation_rule1 = fuzzyMin(fdk.far, fdk_.far);
        pref_straight = fuzzyMax(pref_straight, activation_rule1);

        float activation_rule2 = fuzzyMin(fdk.close, fdk_.far);
        pref_turn_right = fuzzyMax(pref_turn_right, activation_rule2);

        float activation_rule3 = fuzzyMin(fdk_.close, fdk.far);
        pref_turn_left = fuzzyMax(pref_turn_left, activation_rule3);

        float activation_rule4 = fuzzyMax(fdk.very_close, fdk_.very_close);
        pref_straight = fuzzyMax(pref_straight, activation_rule4);

        float activation_rule5 = fuzzyMin(fuzzyMax(fdk.close, fdk_.close), fsk.far);
        pref_turn_left = fuzzyMax(pref_turn_left, activation_rule5);

        float activation_rule6 = fuzzyMin(fuzzyMax(fdk.close, fdk_.close), fsk_.far);
        pref_turn_right = fuzzyMax(pref_turn_right, activation_rule6);

        float activation_rule7 = fuzzyMin(fdk.close, fuzzyMin(fdk_.close, fuzzyMin(fsk.close, fsk_.close)));
        pref_straight = fuzzyMax(pref_straight, activation_rule7);

        float activation_rule8 = fuzzyMax(fdk.very_close, fdk_.very_close);
        activation_rule8 = fuzzyMin(activation_rule8, fuzzyMin(fsk.very_close, fsk_.very_close));
        pref_backward = fuzzyMax(pref_backward, activation_rule8);

        FuzzyOutputPreference fo;
        fo.turn_left = pref_turn_left;
        fo.straight = pref_straight;
        fo.turn_right = pref_turn_right;
        fo.backward = pref_backward;

        return fo;
    }

    const int OUTPUT_UNIVERSE_SIZE = 21;
    const float OUTPUT_UNIVERSE_MIN = -15.0;
    const float OUTPUT_UNIVERSE_MAX = 10.0;

    float mf_turn_left_out(float x) {
        return trimf(x, -10, -9.999, 0);
    }
    float mf_straight_out(float x) {
        return trimf(x, -5, 0, 5);
    }
    float mf_turn_right_out(float x) {
        return trimf(x, 0, 10, 10);
    }

    float mf_backward_out(float x) {
        return trimf(x, -15, -12, -10); 
    }

    float defuzzifyCOG(FuzzyOutputPreference output) {
        float numerator = 0.0;
        float denominator = 0.0;

        for (int i = 0; i < OUTPUT_UNIVERSE_SIZE; i++) {
            float x = OUTPUT_UNIVERSE_MIN + i * (OUTPUT_UNIVERSE_MAX - OUTPUT_UNIVERSE_MIN) / (OUTPUT_UNIVERSE_SIZE - 1);

            float combined = fuzzyMax(
                fuzzyMax3(
                    fuzzyMin(output.turn_left, mf_turn_left_out(x)),
                    fuzzyMin(output.straight, mf_straight_out(x)),
                    fuzzyMin(output.turn_right, mf_turn_right_out(x))
                ),
                fuzzyMin(output.backward, mf_backward_out(x)) 
            );

            numerator += x * combined;
            denominator += combined;
        }

        if (denominator == 0) return 0.0;
        return numerator / denominator;
    }

    long d1, d2, d3, d4;

    void setup() {
        Serial.begin(9600);

        pinMode(TRIG1, OUTPUT); pinMode(ECHO1, INPUT);
        pinMode(TRIG2, OUTPUT); pinMode(ECHO2, INPUT);
        pinMode(TRIG3, OUTPUT); pinMode(ECHO3, INPUT);
        pinMode(TRIG4, OUTPUT); pinMode(ECHO4, INPUT);

    }

    void loop() {
        d1 = readUltrasonic(TRIG1, ECHO1);
        d2 = readUltrasonic(TRIG2, ECHO2);
        d3 = readUltrasonic(TRIG3, ECHO3);
        d4 = readUltrasonic(TRIG4, ECHO4);

        FuzzyOutputPreference result = fuzzyInference(d1, d2, d3, d4);
        float final_value = defuzzifyCOG(result);

        enum DIRECTION {
            BACKWARD = 0,
            LEFT = 1,
            RIGHT = 2,
            STRAIGHT_FORWARD = 3
        };

        DIRECTION direction = STRAIGHT_FORWARD;
        if (final_value < -10.0) {
            direction = BACKWARD ;
        } else if (final_value < -2.0) {
            direction = LEFT;
        } else if (final_value > 2.0) {
            direction = RIGHT;
        } else {
            direction = STRAIGHT_FORWARD;
        }

        Serial.println((int)direction); 

        delay(200);
    }
```