## ESP32 Dasar

![ESP32 PIN Explanation](Images/ESP32-Pinout.webp)
---

## Penejelasan PIN ESP32 (30PIN)

Sumber: [Penjelasan Pin ESP32](https://lastminuteengineers.com/esp32-pinout-reference/)

**1. PIN GPIO**

![ESP32 GPIO PINS Explanation](Images/ESP32-GPIO-Pins.webp)

ESP32 memiliki 25 pin GPIO yang dapat diberi fungsi berbeda dengan memprogram register yang sesuai. Ada beberapa jenis GPIO: digital only, analog, sentuh kapasitif, dll. GPIO analog dan sentuh kapasitif dapat dikonfigurasi sebagai GPIO digital. Sebagian besar GPIO digital ini dapat dikonfigurasi dengan pull-up atau pull-down internal, atau diatur ke impedansi tinggi.

Meskipun ESP32 punya banyak pin dengan bermcam macam fungsi, beberapa diantaranya mungkin tidak bisa digunakan untuk projek. Tabel dibawah ini menunjukkan mana pin GPIO yang aman digunakan dan mana pin yang sebaiknya digunakan dengan hati- hati.

:white_check_mark: : Aman digunakan
:warning: : Gunakan saat perlu, tapi hati-hati saat booting
:x: : Direkomendasikan untuk tidak digunakan


| Label | GPIO | Aman digunakan? | Alasan |
| :--- | :--- | :--- | :--- |
| D0 | 0 | :warning: | harus bernilai HIGH saat boot dan LOW saat programming|
| TX0 | 1 | :x: | pin TX digunakan untuk flashing dan debugging |
| D2 | 2 | :warning: | harus bernilai LOW saat boot dan juga terhubing dengan LED pada board ESP |
| RX0 | 3 | :x: | pin RX digunkan untuk flashing dan debugging |
| D4 | 4 | :white_check_mark:| |
| D5 | 5 | :warning: | harus bernilai HIGH saat boot |
| D6 | 6 | :x: | terhubung dengan flash memory |
| D7 | 7 | :x: | terhubung dengan flash memory |
| D8 | 8 | :x: | terhubung dengan flash memory |
| D9 | 9 | :x: | terhubung dengan flash memory |
| D10 | 10 | :x: | terhubung dengan flash memory |
| D11 | 11 | :x: | terhubung dengan flash memory |
| D12 | 12 | :warning: | harus bernilai LOW saat boot |
| D13 | 13 | :white_check_mark:| |
| D14 | 14 | :white_check_mark:| |
| D15 | 15 | :warning: | harus bernilai HIGH saat boot, untuk mencegah , untuk mencegah terblokirnya proses startup |
| RX2 | 16 | :white_check_mark:| |
| TX2 | 17 | :white_check_mark:| |
| D18 | 18 | :white_check_mark:| |
| D19 | 19 | :white_check_mark:| |
| D21 | 21 | :white_check_mark:| |
| D22 | 22 | :white_check_mark:| |
| D23 | 23 | :white_check_mark:| |
| D25 | 25 | :white_check_mark:| |
| D26 | 26 | :white_check_mark:| |
| D27 | 27 | :white_check_mark:| |
| D32 | 32 | :white_check_mark:| |
| D33 | 33 | :white_check_mark:| |
| D34 | 34 | :warning:| Hanya bisa input, tidak bisa diubah menjadi ouput |
| D35 | 35 | :warning:| Hanya bisa input, tidak bisa diubah menjadi ouput |
| VP | 36 | :warning:| Hanya bisa input, tidak bisa diubah menjadi ouput |
| VN | 39 | :warning:| Hanya bisa input, tidak bisa diubah menjadi ouput |

**Pin GPIO Input Only**

Pin GPIO34, GPIO35, VP, VN Tidak dapat dikonfigurasi sebagai keluaran. Pin-pin ini dapat digunakan sebagai masukan digital atau analog, atau untuk tujuan lain. Pin-pin ini juga tidak memiliki resistor pull-up dan pull-down internal, tidak seperti pin GPIO lainnya.

**ESP32 Interrupt Pins**

Semua GPIO pin bisa dikonfigurasi sebagai interrupt. Interrupt adalah mekanisme di mana ESP32 langsung berhenti dari tugas yang sedang dikerjakan untuk merespon suatu kejadian penting pada pin tertentu. Setelah selesai, ESP32 akan kembali melanjutkan program utama.
---

**2. PIN ADC**

![ESP32 ADC PINS Explanation](Images/ESP32-ADC-Pins.webp)

Analog to Digital Converter (ADC) adalah fitur pada ESP32 yang bisa membaca sinyal analog (tegangan variabel) lalu mengubahnya menjadi data digital (angka). ADC ESP32 adalah ADC 12-bit, yang berarti dapat mendeteksi 4096 (2^12) level analog diskrit. Dengan kata lain, ADC ini akan mengonversi tegangan input mulai dari 0 hingga 3,3V (tegangan operasi) menjadi nilai integer mulai dari 0 hingga 4095. Hal ini menghasilkan resolusi 3,3 volt / 4096 unit, atau 0,0008 volt (0,8 mV) per unit.
---

**3. PIN DAC**

![ESP32 DAC PINS Explanation](Images/ESP32-DAC-Pins.webp)

Digital to Analog Converter (DAC) adalah fitur yang bisa membaca angka digital lalau mengubahnya menjadi teganagan analog. DAC ini memiliki resolusi 8-bit, yang berarti bahwa nilai dalam rentang 0 hingga 256 akan diubah ke tegangan analog dalam rentang 0 hingga 3,3V.
---

**4. PIN Touch**

![ESP32 TOUCH PINS Explanation](Images/ESP32-Touch-Pins.webp)

PIn Touch adalah fitur di ESP32 yang memungkinkan ESP32 mendeteksi sentuhan jari atau perubahan kapasitas pada permukaan konduktif yang terhubung ke pin tersebut. Fitur ini tidak memerlukan komponen tambahan (seperti IC touch sensor eksternal) karena sudah bawaan chip.

Pin touch ESP32 bekerja dengan prinsip kapasitansi. Saat jari (atau benda konduktif) menyentuh pad, kapasitansi berubah, dan ESP32 bisa membaca perubahan itu sebagai nilai angka.
Semakin kuat sentuhan maka semakin besar perubahan kapasitansinya.
---