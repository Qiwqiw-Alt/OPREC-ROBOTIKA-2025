## Algorima Minimax

## Link Penting 🔗

* **PPT DFS Dasar:**
    * [Breadth/Depth First Search(BFS/DFS) Bagian 1](https://informatika.stei.itb.ac.id/~rinaldi.munir/Stmik/2020-2021/BFS-DFS-2021-Bag1.pdf)
    * [Breadth/Depth First Search(BFS/DFS) Bagian 2](https://informatika.stei.itb.ac.id/~rinaldi.munir/Stmik/2020-2021/BFS-DFS-2021-Bag2.pdf)

* **Repository Github**
    * [Tic-Tac-Toe Minimax (Python dan JS)](https://github.com/Cledersonbc/tic-tac-toe-minimax?tab=readme-ov-file)
    * [Tic-Tac-Toe Minimax (JS)](https://github.com/viandwi24/tictactoe-minimax)

* **Video Youtube:**
    * [Algorithms Explained – minimax and alpha-beta pruning](https://youtu.be/l-hh51ncgDI?si=QZRiFOcbjMMKbSdI)
    * [Minimax: How Computers Play Games](https://youtu.be/SLgZhpDsrfc?si=a66pzM_EImtURJ4w)
    * [Coding Challenge 154: Minimax Algorithm for Tic Tac Toe](https://youtu.be/trKjYdBASyQ?si=9P3qBj5pdivTKQ4V)

* **Web Belajar:**
    * [Minimax Algorithm in Game Theory | Set 1 (Introduction)](https://www.geeksforgeeks.org/dsa/minimax-algorithm-in-game-theory-set-1-introduction/)
   
-----

## Game State & Tree
Permainan Tic-Tac-Toe dapat dipetakan ke dalam bentuk Pohon Keputusan (Decision Tree), di mana setiap posisi atau konfigurasi bidak di papan permainan mewakili sebuah node atau simpul dalam pohon tersebut. Setiap langkah yang mungkin diambil oleh pemain, seperti menempatkan simbol X atau O di kotak kosong, menjadi cabang atau edge yang menghubungkan node satu dengan yang lain, membentuk struktur hierarkis yang merepresentasikan semua kemungkinan jalannya permainan. Dengan pendekatan ini, komputer dapat memvisualisasikan dan mengeksplorasi semua kemungkinan masa depan dari posisi saat ini, memungkinkan analisis strategi optimal dengan mempertimbangkan hasil akhir seperti menang, kalah, atau seri.

## Algoritma Depth-First Search (DFS)
Algoritma DFS adalah algoritma penulusuran yang bekerja menelusuri satu jalur cabang sedalam mungkin hingga mencapai titik paling ujung atau Leaf Node (kondisi permainan berakhir), sebelum mencoba cabang lainnya. Analogi yang paling tepat adalah seperti seseorang yang sedang mencari jalan keluar di dalam sebuah labirin; ia akan terus berjalan menyusuri satu lorong hingga menemui jalan buntu, lalu melakukan Backtracking atau mundur kembali ke persimpangan terakhir untuk mencoba lorong yang berbeda. Dalam Tic-Tac-Toe, DFS memungkinkan komputer "mensimulasikan" satu rangkaian permainan sampai tuntas, mencatat hasilnya, lalu mundur untuk mengevaluasi rangkaian langkah alternatif lainnya guna menemukan strategi yang paling optimal.

## Logika Pemerograman
Papan permainan biasanya disimpan menggunakan array atau list 2D berukuran 3x3, di mana setiap sel diinisialisasi dengan simbol kosong seperti "-" atau spasi, memungkinkan representasi visual grid yang mudah diakses dan dimodifikasi. Fungsi pengecekan kondisi menang dilakukan dengan memeriksa semua baris, kolom, dan diagonal apakah ketiga selnya identik (misalnya semua 'X' atau 'O'), sementara kondisi seri dicek ketika papan penuh tanpa pemenang. Input pemain manusia dihandle melalui loop yang meminta koordinat baris dan kolom (1-3), validasi posisi kosong, dan ganti giliran antar pemain 'X' dan 'O' hingga permainan berakhir.

## Implementasi DFS ke Minimax
Setelah aturan main terbentuk, algoritma Minimax diterapkan sebagai pengembangan dari DFS untuk memberikan kemampuan berpikir pada komputer. Dalam Tic-Tac-Toe, DFS murni hanya akan menelusuri langkah tanpa tujuan, sehingga kita perlu memberikan bobot atau skor pada setiap kondisi akhir permainan di ujung cabang (Leaf Node). Secara standar, kondisi menang bagi AI diberi skor +1, kalah diberi skor -1, dan seri diberi skor 0. Algoritma ini bekerja dengan dua prinsip utama:
* Maximizing, di mana Komputer akan memilih langkah yang memaksimalkan skornya sendiri
* Minimizing, di mana AI berasumsi bahwa lawan adalah pemain optimal yang akan memilih langkah untuk menekan skor AI hingga sekecil mungkin.
Dengan menelusuri seluruh pohon keputusan secara mendalam, Komputer dapat memprediksi hasil akhir dari setiap langkah yang mungkin diambil dan selalu memilih jalur yang memberikan hasil terbaik, terlepas dari apa pun respon yang diberikan oleh pemain lawan.