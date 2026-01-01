#!/usr/bin/env python3
from math import inf as infinity
from random import choice
import platform
import time
from os import system

# Konstanta untuk pemain
HUMAN = -1   # Manusia direpresentasikan dengan nilai -1
COMP = +1    # Komputer (AI) direpresentasikan dengan nilai +1

# Papan permainan 3x3, 0 berarti kosong
board = [
    [0, 0, 0],
    [0, 0, 0],
    [0, 0, 0],
]

# ===================================================================
# 1. Fungsi evaluate(state)
# ===================================================================
def evaluate(state):
    """
    Mengevaluasi kondisi akhir permainan (hanya dipanggil saat game over atau papan penuh)
    Mengembalikan skor dari sudut pandang komputer:
        +1 → Komputer menang
        -1 → Manusia menang
         0 → Seri
    """
    if wins(state, COMP):       # Jika komputer menang
        score = +1
    elif wins(state, HUMAN):    # Jika manusia menang
        score = -1
    else:                       # Tidak ada pemenang (seri)
        score = 0
    return score

# ===================================================================
# 2. Fungsi wins(state, player)
# ===================================================================
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

# ===================================================================
# 3. Fungsi game_over(state)
# ===================================================================
def game_over(state):
    """
    Memeriksa apakah permainan sudah selesai (ada yang menang)
    """
    return wins(state, HUMAN) or wins(state, COMP)

# ===================================================================
# 4. Fungsi empty_cells(state)
# ===================================================================
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

# ===================================================================
# 5. Fungsi valid_move(x, y)
# ===================================================================
def valid_move(x, y):
    """
    Memeriksa apakah langkah ke posisi (x, y) diperbolehkan (masih kosong)
    """
    if [x, y] in empty_cells(board):       # Cek apakah ada di daftar sel kosong
        return True
    else:
        return False

# ===================================================================
# 6. Fungsi set_move(x, y, player)
# ===================================================================
def set_move(x, y, player):
    """
    Menempatkan tanda pemain (COMP atau HUMAN) di posisi (x, y)
    Mengembalikan True jika berhasil, False jika tidak valid
    """
    if valid_move(x, y):
        board[x][y] = player   # Tempatkan tanda
        return True
    else:
        return False

# ===================================================================
# 7. Fungsi minimax(state, depth, player) ← INI INTI AI!
# ===================================================================
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

    return best                            # Kembalikan langkah terbaik

# ===================================================================
# 8. Fungsi clean()
# ===================================================================
def clean():
    """
    Membersihkan layar konsol (Windows: cls, Linux/Mac: clear)
    """
    os_name = platform.system().lower()
    if 'windows' in os_name:
        system('cls')
    else:
        system('clear')

# ===================================================================
# 9. Fungsi render(state, c_choice, h_choice)
# ===================================================================
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

# ===================================================================
# 10. Fungsi ai_turn(c_choice, h_choice)
# ===================================================================
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

# ===================================================================
# 11. Fungsi human_turn(c_choice, h_choice)
# ===================================================================
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

# ===================================================================
# 12. Fungsi main()
# ===================================================================
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