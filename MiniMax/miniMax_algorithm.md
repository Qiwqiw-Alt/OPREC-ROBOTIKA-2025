## Algorima Minimax

## Link Penting 🔗

* **PPT DFS Dasar:**
    * [Breadth/Depth First Search(BFS/DFS) Bagian 1](https://informatika.stei.itb.ac.id/~rinaldi.munir/Stmik/2020-2021/BFS-DFS-2021-Bag1.pdf)
    * [Breadth/Depth First Search(BFS/DFS) Bagian 2](https://informatika.stei.itb.ac.id/~rinaldi.munir/Stmik/2020-2021/BFS-DFS-2021-Bag2.pdf)

* **Repository Github Minimax**
    * [Tic-Tac-Toe Minimax (Python dan JS)](https://github.com/Cledersonbc/tic-tac-toe-minimax?tab=readme-ov-file)
    * [Tic-Tac-Toe Minimax (JS)](https://github.com/viandwi24/tictactoe-minimax)

* **Video Youtube DFS:**
    * [Depth First Search (DFS) Explained: Algorithm, Examples, and Code](https://youtu.be/PMMc4VsIacU?si=wqhET14lt0l3aTte)
    * [Learn Depth First Search in 7 minutes ⬇️](https://youtu.be/by93qH4ACxo?si=0OrD3jsBDgZqA5X5)
    * [Teknik Blind Search (BFS, DFS, dan UCS) pada Kecerdasan Buatan - Kuliah AI #03](https://youtu.be/kS7eHbgmCZQ?si=am1d9VAcnrzFPyJs)

* **Video Youtube Minimax:**
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

## Kode Program DFS dengan Rekursif
<details>
<summary> Click to see more... </summary>

```python
    # Representasi pohon (atau graf berarah) menggunakan dictionary
    # Key adalah node, value adalah list anak-anaknya (cabang yang keluar dari node tersebut)
    graph = {
        'A': ['B', 'C'],    # Node A memiliki dua anak: B dan C
        'B': ['D', 'E'],    # Node B memiliki dua anak: D dan E
        'C': ['F'],         # Node C memiliki satu anak: F
        'D': [],            # Node D adalah daun (leaf), tidak punya anak
        'E': [],            # Node E adalah daun (leaf), tidak punya anak
        'F': []             # Node F adalah daun (leaf), tidak punya anak
    }

    # Definisi fungsi DFS secara rekursif
    def dfs_rekursif(node, visited=None):
        # Jika ini pemanggilan pertama, buat set kosong untuk menyimpan node yang sudah dikunjungi
        if visited is None:
            visited = set()
        
        # Proses node saat ini: cetak node (ini adalah saat node "ditemukan" dan diproses)
        print(node, end=" ")  
        
        # Tandai node ini sebagai sudah dikunjungi agar tidak diproses ulang
        visited.add(node)
        
        # Loop melalui semua tetangga (anak) dari node saat ini
        for tetangga in graph[node]:
            # Jika tetangga belum pernah dikunjungi, lakukan DFS rekursif ke sana
            if tetangga not in visited:
                dfs_rekursif(tetangga, visited)
                # Setelah rekursi kembali (backtracking), lanjut ke tetangga berikutnya

    print("DFS Rekursif:")

    # Jalankan DFS mulai dari node root 'A'
    dfs_rekursif('A')

    # Output yang dihasilkan: A B D E C F
    # Artinya: mulai dari A → masuk ke B → masuk ke D (daun) → kembali → masuk ke E (daun) → kembali → kembali ke A → masuk ke C → masuk ke F (daun) → selesai
```
</details>

## Kode Program DFS dengan Stack
<details>
<summary> Click to see more... </summary>

```python
    # Representasi pohon (atau graf berarah) menggunakan dictionary
    # Key adalah node, value adalah list anak-anaknya (cabang yang keluar dari node tersebut)
    graph = {
        'A': ['B', 'C'],    # Node A memiliki dua anak: B dan C
        'B': ['D', 'E'],    # Node B memiliki dua anak: D dan E
        'C': ['F'],         # Node C memiliki satu anak: F
        'D': [],            # Node D adalah daun (leaf), tidak punya anak
        'E': [],            # Node E adalah daun (leaf), tidak punya anak
        'F': []             # Node F adalah daun (leaf), tidak punya anak
    }

    # Definisi fungsi DFS menggunakan stack secara manual (iteratif, bukan rekursif)
    def dfs_stack(start_node):
        # Set untuk menyimpan node yang sudah dikunjungi, mencegah pengulangan
        visited = set()
        
        # Stack awal hanya berisi node mulai (root), menggunakan list sebagai stack
        stack = [start_node]
        
        # Loop utama: selama stack tidak kosong, terus proses
        while stack:
            # Ambil node dari ujung stack (pop() mengambil elemen terakhir → LIFO: Last In First Out)
            node = stack.pop()
            
            # Jika node belum pernah dikunjungi, proses sekarang
            if node not in visited:
                # Cetak node saat ini (ini adalah saat node "diproses")
                print(node, end=" ")
                
                # Tandai node ini sebagai sudah dikunjungi
                visited.add(node)
                
                # Tambahkan semua anak node ini ke stack
                # Gunakan reversed() agar urutan pemrosesan anak sama dengan versi rekursif
                # Tanpa reversed, urutan akan terbalik (misal: E lalu D, bukan D lalu E)
                stack.extend(reversed(graph[node]))
                # extend() menambahkan semua elemen list ke stack satu per satu

    print("\nDFS Stack Manual:")

    # Jalankan DFS  mulai dari node 'A'
    dfs_stack('A')

    # Output yang dihasilkan: A B D E C F 
```
</details>

## Kode Program Minimax Tic-Tac-Toe dengan DFS
<details>
<summary> Click to see more... </summary>

Sumber:   [Tic-Tac-Toe Minimax (Python dan JS)](https://github.com/Cledersonbc/tic-tac-toe-minimax?tab=readme-ov-file)

### 1. Inisialisasi dan Variabel Global
Bagian ini digunakan untuk mengatur status awal permainan dan simbol pemain.

```python
    HUMAN = -1  # Simbol untuk pemain manusia (diwakili angka -1)
    COMP = +1   # Simbol untuk AI (diwakili angka +1)
    board = [   # Papan permainan 3x3 diinisialisasi dengan angka 0 (kosong)
        [0, 0, 0],
        [0, 0, 0],
        [0, 0, 0],
    ]
```

### 2. Fungsi Pengecekan
Fungsi ini digunakan untuk memeriksa kondisi papan untuk menentukan pemenang atau langkah yang tersedia.

```python
    def evaluate(state):
        """
        Mengevaluasi kondisi akhir permainan (hanya dipanggil saat game over atau papan penuh)
        Mengembalikan skor dari sudut pandang komputer:
            +1 → Komputer menang
            -1 → Manusia menang
            0 → Seri
        """
        if wins(state, COMP): # Jika komputer menang
            score = +1
        elif wins(state, HUMAN): # Jika manusia menang
            score = -1
        else: # Tidak ada pemenang (seri)
            score = 0

        return score
```

```python
    def wins(state, player):
        """
        Memeriksa apakah pemain tertentu (COMP atau HUMAN) sudah menang
        Memeriksa 8 kemungkinan kemenangan: 3 baris, 3 kolom, 2 diagonal
        """
        # Daftar semua kombinasi kemenangan
        win_state = [
            [state[0][0], state[0][1], state[0][2]],  # Baris atas
            [state[1][0], state[1][1], state[1][2]],  # Baris tengah
            [state[2][0], state[2][1], state[2][2]],  # Baris bawah
            [state[0][0], state[1][0], state[2][0]],  # Kolom kiri
            [state[0][1], state[1][1], state[2][1]],  # Kolom tengah
            [state[0][2], state[1][2], state[2][2]],  # Kolom kanan
            [state[0][0], state[1][1], state[2][2]],  # Diagonal utama
            [state[2][0], state[1][1], state[0][2]],  # Diagonal sekunder
        ]
        # Jika ada satu kombinasi yang semuanya milik player, maka menang
        if [player, player, player] in win_state:
            return True
        else:
            return False
```

```python
    def empty_cells(state):
    """
    Mengembalikan daftar koordinat [x, y] semua sel yang masih kosong (nilai 0)
    """
    cells = []
    for x, row in enumerate(state):        # Looping baris (0-2)
        for y, cell in enumerate(row):     # Looping kolom dalam baris (0-2)
            if cell == 0:                  # Jika sel kosong
                cells.append([x, y])       # Tambahkan koordinatnya
    return cells
```

```python
    def game_over(state):
        """
        Memeriksa apakah permainan sudah selesai (ada yang menang)
        """
        return wins(state, HUMAN) or wins(state, COMP)
```
### 3. Fungsi Pengecekan dan Eksekus Gerakan
Fungsi `valid_move(x, y)` digunakan untuk memastikan pemain (baik manusia maupun AI) tidak "menindih" kotak yang sudah terisi

```python
    def valid_move(x, y):
        """
        Memeriksa apakah langkah ke posisi (x, y) diperbolehkan (masih kosong)
        """
        if [x, y] in empty_cells(board):       # Cek apakah ada di daftar sel kosong
            return True
        else:
            return False
```
Sedangkan, fungsi `set_move(x, y, player)` digunakan untuk mengubah data pada papan (`board`)

```python
    def set_move(x, y, player):
        """
        Menempatkan tanda pemain (COMP atau HUMAN) di posisi (x, y)
        Mengembalikan True jika berhasil, False jika tidak valid
        """
        if valid_move(x, y):
            board[x][y] = player   # Tempatkan tanda
            return True
        else:
            return Fals
```

### 4. Fungsi Minimax
Fungsi ini merupakan bagian utama yang digunakan untuk memprediksi kemungkinan terbaik dengan menggunakan DFS Rekursif.

```python
    def minimax(state, depth, player):
        """
        Algoritma Minimax rekursif dengan backtracking
        Mencari langkah terbaik untuk komputer dengan memprediksi semua kemungkinan
        Mengembalikan [best_row, best_col, best_score]
        """
        # Inisialisasi nilai terbaik tergantung giliran pemain
        if player == COMP:                     # Komputer ingin skor maksimal
            best = [-1, -1, -infinity]
        else:                                  # Manusia ingin skor minimal
            best = [-1, -1, +infinity]

        # Kondisi berhenti: papan penuh (depth=0) atau ada pemenang
        if depth == 0 or game_over(state):
            score = evaluate(state)            # Beri skor sesuai hasil akhir
            return [-1, -1, score]             # Koordinat tidak penting, hanya skor

        # Telusuri semua sel kosong
        for cell in empty_cells(state):
            x, y = cell[0], cell[1]
            state[x][y] = player               # Coba langkah sementara
            # Rekursi: giliran lawan, kedalaman berkurang
            score = minimax(state, depth - 1, -player)
            state[x][y] = 0                    # Batalkan langkah (backtracking)
            score[0], score[1] = x, y           # Simpan koordinat langkah ini

            # Update nilai terbaik
            if player == COMP:                 # Maximizing player (komputer)
                if score[2] > best[2]:
                    best = score               # Pilih yang skornya lebih tinggi
            else:                              # Minimizing player (manusia)
                if score[2] < best[2]:
                    best = score               # Pilih yang skornya lebih rendah

        return best
```

### 5. Fungsi User Interface
Tugas utama fungsi-fungsi ini adalah mengelola apa yang dilihat oleh pengguna di layar. Fungsi `clean()` berfungsi untuk Menghapus semua teks yang sudah ada di konsol agar tampilan papan yang baru selalu berada di posisi atas.

```python
    def clean():
        """
        Membersihkan layar konsol (Windows: cls, Linux/Mac: clear)
        """
        os_name = platform.system().lower()
        if 'windows' in os_name:
            system('cls')
        else:
            system('clear')
```

Fungsi `render(state, c_choice, h_choice)` digunakan untuk menampilkan kondisi papan terbaru ke layar.

```python
    def render(state, c_choice, h_choice):
    """
    Menampilkan papan permainan di layar dengan simbol X/O dan garis pemisah
    """
    chars = {
        -1: h_choice,   # Simbol manusia
        +1: c_choice,   # Simbol komputer
        0: ' '          # Kosong → spasi
    }
    str_line = '---------------'
    print('\n' + str_line)
    for row in state:
        for cell in row:
            symbol = chars[cell]
            print(f'| {symbol} |', end='')
        print('\n' + str_line)
```

### 6. Fungsi Pengatur Giliran
Fungsi `ai_turn(c_choice, h_choice)` digunakan untk mengambil keputusan terbaik dari "otak" AI, menampilkannya ke layar, dan mengeksekusi langkah tersebut di papan.

```python
    def ai_turn(c_choice, h_choice):
        """
        Giliran komputer: pilih langkah terbaik menggunakan Minimax
        Jika papan masih kosong total (awal permainan), pilih acak
        """
        depth = len(empty_cells(board))
        if depth == 0 or game_over(board):      # Permainan sudah selesai
            return

        clean()
        print(f'Computer turn [{c_choice}]')
        render(board, c_choice, h_choice)

        if depth == 9:                         # Papan masih kosong semua (langkah pertama)
            x = choice([0, 1, 2])               # Pilih acak baris
            y = choice([0, 1, 2])               # Pilih acak kolom
        else:
            move = minimax(board, depth, COMP)  # Hitung langkah terbaik
            x, y = move[0], move[1]

        set_move(x, y, COMP)                   # Lakukan langkah
        time.sleep(1)                          # Jeda sedikit agar terasa natural
```

Fungsi `human_turn(c_choice, h_choice)` digunakan untuk memetakan angka tombol (numpad 1-9) menjadi koordinat matriks [x, y]. 
```python
def human_turn(c_choice, h_choice):
    """
    Giliran manusia: input menggunakan numpad 1-9
    Validasi input dan tolak jika posisi sudah terisi
    """
    depth = len(empty_cells(board))
    if depth == 0 or game_over(board):
        return

    # Mapping numpad ke koordinat papan
    moves = {
        1: [0, 0], 2: [0, 1], 3: [0, 2],
        4: [1, 0], 5: [1, 1], 6: [1, 2],
        7: [2, 0], 8: [2, 1], 9: [2, 2],
    }

    move = -1
    clean()
    print(f'Human turn [{h_choice}]')
    render(board, c_choice, h_choice)

    while move < 1 or move > 9:
        try:
            move = int(input('Use numpad (1..9): '))
            coord = moves[move]
            can_move = set_move(coord[0], coord[1], HUMAN)
            if not can_move:
                print('Bad move')
                move = -1                              # Ulangi input
        except (EOFError, KeyboardInterrupt):
            print('Bye')
            exit()
        except (KeyError, ValueError):
            print('Bad choice')
```

### 7. Fungsi Utama (Main Entry Point)
```python
    def main():
        """
        Fungsi utama: mengatur alur permainan dari awal hingga akhir
        """
        clean()
        h_choice = ''  # Pilihan manusia (X atau O)
        c_choice = ''  # Pilihan komputer
        first = ''     # Siapa yang mulai

        # Pilih simbol
        while h_choice != 'O' and h_choice != 'X':
            try:
                h_choice = input('Choose X or O\nChosen: ').upper()
            except (EOFError, KeyboardInterrupt):
                print('Bye')
                exit()

        # Komputer otomatis ambil simbol lawan
        if h_choice == 'X':
            c_choice = 'O'
        else:
            c_choice = 'X'

        # Tentukan siapa mulai
        clean()
        while first != 'Y' and first != 'N':
            try:
                first = input('First to start?[y/n]: ').upper()
            except (EOFError, KeyboardInterrupt):
                print('Bye')
                exit()

        # Loop utama permainan
        while len(empty_cells(board)) > 0 and not game_over(board):
            if first == 'N':               # Jika komputer mulai duluan
                ai_turn(c_choice, h_choice)
                first = ''                 # Setelah sekali, giliran normal
            human_turn(c_choice, h_choice)
            ai_turn(c_choice, h_choice)

        # Tampilkan hasil akhir
        if wins(board, HUMAN):
            clean()
            print(f'Human turn [{h_choice}]')
            render(board, c_choice, h_choice)
            print('YOU WIN!')
        elif wins(board, COMP):
            clean()
            print(f'Computer turn [{c_choice}]')
            render(board, c_choice, h_choice)
            print('YOU LOSE!')
        else:
            clean()
            render(board, c_choice, h_choice)
            print('DRAW!')

    if __name__ == '__main__':
        main()
```
</details>