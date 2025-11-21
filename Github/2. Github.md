## 1. Membuat Akun GitHub

1. Buka [github.com](https://github.com).
2. Klik tombol **Sign Up** di pojok kanan atas.
3. Masukkan email aktif, buat password, dan pilih username. 
4. Selesaikan verifikasi.
5. **Penting:** Cek email dan klik link verifikasi agar akun bisa dipakai sepenuhnya.


## 2. Membuat Repository (Repo)
Repository adalah "folder proyek" di awan (cloud). Satu proyek = satu repo.

1. Login ke GitHub.
2. Klik tombol **+** di pojok kanan atas, pilih **New repository**.
3. Isi detail berikut:
   - **Repository name:** Nama proyek.
   - **Description:** (Opsional) Penjelasan singkat tentang proyek ini.
   - **Public/Private:**
     - *Public:* Semua orang bisa lihat (cocok untuk portofolio/open source).
     - *Private:* Hanya diri sendiri dan tim yang bisa lihat.
   - **Initialize this repository with:** Centang **Add a README file**.
     *(Ini penting agar bisa langsung meng-upload file dari web).*
4. Klik **Create repository**.

## 3. Upload File (Cara Manual)
Sebenarnya cara terbaik upload adalah menggunakan Terminal (Git), tapi GitHub menyediakan cara cepat untuk pemula.

1. Buka Repository yang sudah kamu buat.
2. Klik tombol **Add file** > **Upload files**.
3. *Drag and drop* file kodinganmu ke area yang disediakan, atau klik "choose your files".
4. **Commit changes:**
   - Di kotak "Commit message", tulis apa yang kamu lakukan (misal: "Upload file latihan code pertama").
5. Klik tombol hijau **Commit changes**.

## 4. Collaboration (Mengundang Teman)

1. Masuk ke Repository.
2. Klik tab **Settings** di menu atas.
3. Di menu kiri, pilih **Collaborators**.
4. Klik **Add people**.
5. Masukkan username GitHub atau email temanmu.
6. Klik **Add to this repository**.
7. Temanmu akan menerima email undangan dan harus meng-kliknya ("Accept Invitation") agar bisa mulai mengedit repo tersebut.

## 5. Mengenal Pull Request (PR)
*Pull Request* adalah jantung kolaborasi di GitHub. Ini adalah cara sopan untuk berkata: *"Hei, aku sudah memperbaiki kode ini, tolong dicek dan gabungkan ke kode utama dong."*

Meskipun biasanya dilakukan setelah `git push`, prosesnya terjadi di website:

1. Tab **Pull requests** ada di setiap repository.
2. Jika ada perubahan dari *branch* lain, akan muncul tombol **Compare & pull request**.
3. Kamu bisa melihat perbedaan kode (warna hijau = penambahan, merah = penghapusan).
4. Jika setuju dengan perubahannya, pemilik repo akan menekan tombol **Merge pull request**.

## 🎓 Bonus: GitHub Student Developer Pack
Fasilitas gratis senilai ribuan dollar khusus untuk pelajar/mahasiswa!

**Manfaat:**
- **GitHub Copilot Gratis:** AI yang bantu nulis coding (sangat powerful!).
- **Domain Gratis:** (biasanya .me atau .tech) selama setahun.
- **Canva Pro** (terkadang tersedia), lisensi JetBrains, dll.

**Cara Daftar:**
1. Siapkan bukti status pelajar (Email kampus `.ac.id`, Kartu Tanda Mahasiswa, atau Surat Keterangan Aktif).
2. Buka [education.github.com/pack](https://education.github.com/pack).
3. Klik **Sign up for Student Developer Pack**.
4. Upload foto bukti pelajar dan tunggu verifikasi (biasanya 1-3 hari, tapi bisa lebih cepat).

---