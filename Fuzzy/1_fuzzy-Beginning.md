## Logika Fuzzy Dasar

## Link Penting 🔗

* **Webiste**
    * [Penjelasan Lengkap Mengenai Logika Fuzzy (Fuzzy Logic)](https://bif.telkomuniversity.ac.id/mengenal-logika-fuzzy-ketika-komputer-tidak-lagi-hanya-benar-atau-salah/)
    * [Pengantar Logika Fuzzy](https://informatika.stei.itb.ac.id/~rinaldi.munir/MetNum/2011-2012/Pengantar%20Logika%20Fuzzy.pdf)
    * [Logika Fuzzzy](https://tita.lecturer.pens.ac.id/AI_SDT/11.%20Logika%20Fuzzy%202/Bab%207%20Logika%20Fuzzy.pdf)
    * [Penjelasan Lengkap Mengenai Logika Fuzzy (Fuzzy Logic)](https://www.trivusi.web.id/2022/05/pengertian-fuzzy-logic.html)

* **Penjelasan Logika Fuzzy**
    * [Pengenalan Logika Fuzzy | Konsep, Contoh Aplikasi, Fungsi Keanggotaan hingga Sistem Inferensi](https://youtu.be/6szqrV9u9k8?si=EBT30VTiWYddchnO)
    * [Fuzzy TSUKAMOTO | Sistem Inferensi Fuzzy | Contoh Studi Kasus dan Langkah Penyelesaiannya](https://youtu.be/aAjSFo0SXhg?si=4hd1i2qBCkTECz4D)
    * [Fuzzy MAMDANI | Sistem Inferensi Fuzzy | Contoh Studi Kasus dan Langkah Penyelesaiannya](https://youtu.be/fKueNI4kY6A?si=PfTgy1NZoZpa8g0J)
    * [Fuzzy SUGENO alias TAKAGI-SUGENO-KANG | Sistem Inferensi Fuzzy | Studi Kasus Mesin Cuci Otomatis](https://youtu.be/RjyRTBNk3w8?si=wApoVoZ0tOUxGNqS)
    * [Konsep Dasar Fuzzy Logic](https://youtu.be/riDIpLmpFuk?si=r38BFUGXSIFPgohi)

-----

## Apa itu Logika Fuzzy?
Logika Fuzzy adalah metode komputasi yang dirancang khusus untuk merepresentasikan dan memanipulasi data atau informasi yang bersifat tidak pasti (uncertain), kabur (vague), atau kualitatif (seperti "agak panas", "cukup tinggi", atau "lumayan mahal"). Berbeda dengan logika klasik (Boolean) yang hanya mengenal nilai benar (1) atau salah (0), logika fuzzy memungkinkan nilai kebenaran dalam rentang kontinu antara 0 dan 1. Logika ini sangat berguna ketika suatu sistem perlu mengambil keputusan berdasarkan informasi yang tidak eksak, karena mampu meniru cara manusia berpikir dalam situasi dunia nyata yang penuh ketidakpastian.

## Teori Dasar Logika Fuzzy
* **Variabel Fuzzy** : variabel yang akan dibahas dalam suatu sistem . Contoh: kecepatan, jarak, dll.
* **Himpunan Fuzzy** : kelompok yang mewakili suatu keadaan tertentu dalam variabel fuzzy. Atribut himpunan fuzzy dapat berupa linguistik (bahasa alami) atau numerik (angka).
* **Semesta Pembicaraan** : keseluruhan nilai yang diperbolehkan untuk dioperasikan dengan variabel fuzzy. Contoh: semesta pembicaraan variabel jarak adalah [0, ∞].
* **Domain himpunan Fuzzy** : yaitu seluruh nilai yang diijinkan dalam semesta pembicaraan dan boleh dioperasikan dalam suatu himpunan fuzzy.

## Fungsi Keangotaan
* **Fungsi Keanggotaan** : merupakan grafik yang mewakili besar dari derajat keanggotaan masing-masing variabel input yang berada dalam interval antara 0 dan 1.
* **Derajat keanggotaan** : fungsi keanggotaan dari sebuah variabel (x) biasanya dilambangkan dengan simbol μ(x).
* **Jenis FUngsi keanggotaan** : Kurva linear, kurva segitiga, kurva trapesium, kurva bahu, kurva s (sigmoid), dan kurva lonceng.

## Operasi Himpunan Fuzzy
* Operasi himpunan diperlukan untuk proses penalaran atau **inferensi**
* Operasi himpunan melibatkan operasi terhadap **derajat keanggotaan**
* Derajat keanggotaan hasil operasi dua buah himpunan fuzzy disebut dengan α-predikat.
* Jenis-jenis operasi himpunan fuzzy : operasi gabungan (union), operasi irisan (intersection), operasi komplemen (complement).

## Sistem Inferensi Fuzzy
Sistem inferensi fuzzy adalah cara memetakan ruang input menuju ruang output menggunakan logika fuzzy.
### Tahapan Logika Fuzzy
1. Input (crips)
2. Fuzzifikasi
3. Inferensi
4. Defuzzifikasi
5. Ouput (crips)

* Fuzzifikasi merupakan prosses mengubah input sistem yang mempunyai nilai tegas (crips) menjadi variabel linguistik (fuzzy) menggunakan fungsi keanggotaan yang disimpan pada basis pengetahuan.
* Inferensi merupakan proses mengubah input fuzzy menjadi output fuzzy dengan cara mengikuti aturan-aturan (if-then) yang telah ditetapkan pada basis pengetahuan fuzzy.
* Defuzzifikasi merupakan proses mengubah hasil dari tahap inferensi menjadi output yang bernilai tagas (crips) menggunakan fungsi keanggotaan yang telah ditetapkan.
* Basis Pengetahuan/Peraturan merupakan kumpulan aturan dalam bentuk pernyataan if-then yang telah dibuat.

## Contoh sederhana Logika Fuzzy
* Input (Crisp): Sensor Jarak membaca 10 cm.
* Fuzzifikasi: 10 cm diterjemahkan menjadi himpunan "SANGAT DEKAT" dengan derajat 0.8.
* Rule (Inferensi): IF Jarak "SANGAT DEKAT", THEN Kecepatan Motor "SANGAT LAMBAT".
* Defuzzifikasi: Motor bergerak pada PWM 50 (dari rentang 0-255).