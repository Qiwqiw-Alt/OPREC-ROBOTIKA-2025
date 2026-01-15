## Library Logika Fuzzy
Selain dengan membuat kode program sendiri, dapat juga dengan menggunkan library yang sudah disediakan untuk bisa menggunakan logika fuzzy.
* **Arduino**: Untuk Arduino dapat menggunakan library eFLL (Embedded Fuzzy Logic Library) oleh Alvicenteno.
* **ESP32**: Untuk ESP32 dapat menggunakan library eFLL (Embedded Fuzzy Logic Library) oleh Alvicenteno juga.

## Contoh Kode Program Logika Fuzzy (belum fix)
```cpp
    #include <Fuzzy.h>

    // 1. Inisialisasi objek Fuzzy
    Fuzzy *fuzzy = new Fuzzy();

    void setup() {
        Serial.begin(9600);

        // 2. Definisi Input (Jarak)
        FuzzyInput *jarak = new FuzzyInput(1); 
        FuzzySet *dekat = new FuzzySet(0, 0, 10, 20);      // Trapesium (a, b, c, d)
        FuzzySet *aman = new FuzzySet(15, 30, 30, 50);    // Segitiga
        FuzzySet *jauh = new FuzzySet(40, 60, 100, 100);  // Trapesium
        jarak->addFuzzySet(dekat);
        jarak->addFuzzySet(aman);
        jarak->addFuzzySet(jauh);
        fuzzy->addFuzzyInput(jarak);

        // 3. Definisi Output (Kecepatan PWM)
        FuzzyOutput *kecepatan = new FuzzyOutput(1);
        FuzzySet *lambat = new FuzzySet(0, 0, 50, 100);
        FuzzySet *cepat = new FuzzySet(80, 150, 255, 255);
        kecepatan->addFuzzySet(lambat);
        kecepatan->addFuzzySet(cepat);
        fuzzy->addFuzzyOutput(kecepatan);

        // 4. Definisi Aturan (Rule)
        // IF jarak IS dekat THEN kecepatan IS lambat
        FuzzyRuleAnticedent *ifJarakDekat = new FuzzyRuleAnticedent();
        ifJarakDekat->addInput(dekat);
        FuzzyRuleConsequent *thenLambat = new FuzzyRuleConsequent();
        thenLambat->addOutput(lambat);
        FuzzyRule *rule1 = new FuzzyRule(1, ifJarakDekat, thenLambat);
        fuzzy->addFuzzyRule(rule1);
    }

    void loop() {
        int inputJarak = 12; // Simulasi input dari sensor
        
        fuzzy->setInput(1, inputJarak); // Masukkan nilai ke input 1
        fuzzy->fuzzify();               // Proses Fuzzifikasi & Inferensi
        float output = fuzzy->defuzzify(1); // Proses Defuzzifikasi Output 1

        Serial.print("Jarak: "); Serial.print(inputJarak);
        Serial.print(" => PWM Motor: "); Serial.println(output);
        delay(500);
    }
```