# <h1 align="center">Laporan Praktikum Modul 5 <br> Searching</h1>

<p align="center">Renisa Assyifa Putri - 103112400123</p>

## Dasar Teori - Searching

Searching atau pencarian adalah salah satu operasi paling fundamental dalam struktur data. Tujuannya simpel: menemukan lokasi data tertentu di dalam sekumpulan data. Bayangin aja kamu lagi nyari satu buku spesifik di rak buku yang isinya puluhan buku. Nah, cara kamu nyarinya itu adalah algoritma searching.

Ada dua metode pencarian yang paling umum:
1. Sequential Search (Pencarian Berurutan): Ini metode paling dasar dan intuitif. Kamu bakal cek satu per satu data dari awal sampai akhir, sampai data yang kamu cari ketemu. Mirip kayak nyari buku di rak yang berantakan, kamu harus liat judulnya satu-satu dari ujung kiri ke ujung kanan. Metode ini gampang diimplementasikan tapi bisa jadi lambat banget kalau datanya banyak dan yang dicari ada di urutan terakhir. Semua kode di modul ini menggunakan pendekatan sequential search karena kita bekerja dengan linked list yang pada dasarnya harus ditelusuri satu per satu.
2. Binary Search (Pencarian Biner): Metode ini jauh lebih cepat dan efisien, tapi punya satu syarat mutlak: datanya harus sudah terurut. Cara kerjanya kayak nyari kata di kamus. Kamu nggak akan baca dari halaman pertama, kan? Kamu pasti langsung buka bagian tengah, liat katanya, terus tentuin apakah kata yang kamu cari ada di bagian sebelum atau sesudah halaman itu. Proses ini diulang terus, membagi dua sisa data setiap kali, sampai katanya ketemu. Karena efisiensinya ini, binary search jadi andalan di banyak aplikasi profesional untuk mengolah data dalam jumlah besar.

## Guided Modul

```cpp
#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* next;
};
Node* head = nullptr;

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// ========== INSERT DEPAN FUNCTION (Penambahan) ==========
void insertDepan(int data) {
    Node* newNode = createNode(data);
    // Logika Insert First: Node baru menunjuk ke head lama, lalu head menunjuk ke Node baru.
    newNode->next = head;
    head = newNode;
    cout << "Data " << data << " berhasil ditambahkan di depan.\n";
}

void insertBelakang(int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Data " << data << " berhasil ditambahkan di belakang.\n";
}

void insertSetelah(int target, int dataBaru) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Data " << target << " tidak ditemukan!\n";
    } else {
        Node* newNode = createNode(dataBaru);
        // Logika Insert After: Sambungkan newNode ke temp->next, lalu temp ke newNode
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Data " << dataBaru << " berhasil disisipkan setelah " << target << ".\n";
    }
}

// ========== DELETE FUNCTION ==========
void hapusNode(int data) {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // Jika data di node pertama (Delete First)
    if (temp != nullptr && temp->data == data) {
        head = temp->next;
        delete temp;
        cout << "Data " << data << " berhasil dihapus.\n";
        return;
    }

    // Cari node yang akan dihapus
    while (temp != nullptr && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // Jika data tidak ditemukan
    if (temp == nullptr) {
        cout << "Data " << data << " tidak ditemukan!\n";
        return;
    }

    // Putuskan tautan: prev melompati temp
    prev->next = temp->next;
    delete temp;
    cout << "Data " << data << " berhasil dihapus.\n";
}

// ========== UPDATE FUNCTION ==========
void updateNode(int dataLama, int dataBaru) {
    Node* temp = head;
    while (temp != nullptr && temp->data != dataLama) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Data " << dataLama << " tidak ditemukan!\n";
    } else {
        temp->data = dataBaru;
        cout << "Data " << dataLama << " berhasil diupdate menjadi " << dataBaru << ".\n";
    }
}

// ========== SEARCH FUNCTION  ==========
void searchData(int key) {
    Node *temp = head;
    int pos = 1;
    bool found = false;

    while (temp != nullptr) {
        // Cek apakah data di node saat ini sama dengan key
        if (temp->data == key) {
            cout << "Data " << key << " ditemukan pada posisi ke-" << pos << endl;
            found = true;
            break; // Hentikan perulangan jika sudah ditemukan
        }
        temp = temp->next; // Geser ke node berikutnya
        pos++;             // Tambah posisi
    }

    // PENTING: Menggunakan 'if (!found)' untuk mengoreksi kesalahan logika asli
    if (!found) { 
        cout << "Data " << key << " tidak ditemukan dalam linked list.\n";
    }
}


// ========== DISPLAY FUNCTION ==========
void tampilkanList() {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    }

    Node* temp = head;
    cout << "Isi Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


// ========== MAIN PROGRAM ==========
int main() {
    int pilihan, data, target, dataBaru;

    do {
        cout << "\n=== MENU SINGLE LINKED LIST ===\n";
        cout << "1. Insert Depan\n";
        cout << "2. Insert Belakang\n";
        cout << "3. Insert Setelah\n";
        cout << "4. Hapus Data\n";
        cout << "5. Update Data\n";
        cout << "6. Tampilkan List\n";
        cout << "7. Cari Data\n"; 
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        if (!(cin >> pilihan)) {
            // Menangani input non-integer
            cin.clear(); 
            cin.ignore(10000, '\n');
            pilihan = -1; // Set pilihan ke nilai default
        }

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                insertDepan(data); 
                break;
            case 2:
                cout << "Masukkan data: ";
                cin >> data;
                insertBelakang(data);
                break;
            case 3:
                cout << "Masukkan data target: ";
                cin >> target;
                cout << "Masukkan data baru: ";
                cin >> dataBaru;
                insertSetelah(target, dataBaru);
                break;
            case 4:
                cout << "Masukkan data yang ingin dihapus: ";
                cin >> data;
                hapusNode(data);
                break;
            case 5:
                cout << "Masukkan data lama: ";
                cin >> data;
                cout << "Masukkan data baru: ";
                cin >> dataBaru;
                updateNode(data, dataBaru);
                break;
            case 6:
                tampilkanList();
                break;
            case 7: // Case baru untuk Search
                cout << "Masukkan data yang dicari (key): ";
                cin >> data;
                searchData(data);
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
```
### Output Code

![Output](output/guided_Modul5_latihanSoalLab_1.png)
![Output](output/guided_Modul5_latihanSoalLab_2.png)

Program ini merupakan pengembangan dari implementasi Singly Linked List dari modul sebelumnya, dengan penambahan fungsionalitas utama yaitu pencarian data.

- Struktur & Operasi Dasar: Program ini masih menggunakan struct Node yang sama dan memiliki fungsi-fungsi dasar CRUD (Create, Read, Update, Delete) seperti insertDepan, hapusNode, dan updateNode.
- Fungsi searchData(int key): Ini adalah inti dari modul ini. Fungsi ini mengimplementasikan algoritma Sequential Search. Ia bekerja dengan cara menelusuri (traverse) list dari head satu per satu. Di setiap Node, ia membandingkan data yang tersimpan dengan key yang dicari. Sebuah variabel pos digunakan untuk melacak posisi node saat ini. Jika data ditemukan, fungsi akan mencetak posisinya dan berhenti. Jika sampai akhir list (temp == nullptr) data tidak ditemukan, sebuah flag found memastikan pesan "tidak ditemukan" akan ditampilkan.

## Guided Latihan Soal di Lab

```cpp
#include <iostream>
#include <string>

using namespace std;

struct infotype {
    string isbn;
    string judul;
    string penulis;
};

typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype data) {
    address P = new elmlist;
    P->info.isbn = data.isbn;
    P->info.judul = data.judul;
    P->info.penulis = data.penulis;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

address cariBuku(List L, string isbn) {
    address P = L.first;
    while (P != NULL) {
        if (P->info.isbn == isbn) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void tambahBuku(List &L, infotype data) {
    address P = alokasi(data);
    if (L.first == NULL) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
    cout << "\n[INFO] Buku '" << data.judul << "' berhasil ditambahkan." << endl;
}

void hapusBuku(List &L, string isbn) {
    address P = cariBuku(L, isbn);

    if (P == NULL) {
        cout << "\n[ERROR] Buku dengan ISBN " << isbn << " tidak ditemukan." << endl;
        return;
    }

    if (P == L.first) {
        L.first = P->next;
    } else {
        address prev = L.first;
        while (prev->next != P) {
            prev = prev->next;
        }
        prev->next = P->next;
    }
    
    cout << "\n[INFO] Buku '" << P->info.judul << "' berhasil dihapus." << endl;
    dealokasi(P);
}

void updateBuku(List &L, string isbn) {
    address P = cariBuku(L, isbn);
    if (P != NULL) {
        cout << "\nData Buku Ditemukan:" << endl;
        cout << "Judul Lama: " << P->info.judul << endl;
        cout << "Penulis Lama: " << P->info.penulis << endl;
        
        cout << "\nMasukkan Judul Baru: ";
        cin.ignore();
        getline(cin, P->info.judul);
        
        cout << "Masukkan Penulis Baru: ";
        getline(cin, P->info.penulis);
        
        cout << "\n[INFO] Data buku berhasil diperbarui." << endl;
    } else {
        cout << "\n[ERROR] Buku dengan ISBN " << isbn << " tidak ditemukan." << endl;
    }
}

void lihatBuku(List L) {
    cout << "\n================ DAFTAR BUKU ================" << endl;
    if (L.first == NULL) {
        cout << "          (Tidak ada buku di daftar)" << endl;
    } else {
        address P = L.first;
        int i = 1;
        while (P != NULL) {
            cout << i << ". ISBN    : " << P->info.isbn << endl;
            cout << "   Judul   : " << P->info.judul << endl;
            cout << "   Penulis : " << P->info.penulis << endl;
            cout << "-------------------------------------------" << endl;
            P = P->next;
            i++;
        }
    }
    cout << "===========================================" << endl;
}

int main() {
    List daftar_buku;
    createList(daftar_buku);
    int pilihan;
    string isbn;
    infotype dataBuku;

    do {
        cout << "\n===== SISTEM MANAJEMEN BUKU =====" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Hapus Buku" << endl;
        cout << "3. Perbarui Buku" << endl;
        cout << "4. Lihat Semua Buku" << endl;
        cout << "5. Keluar" << endl;
        cout << "=================================" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\n--- Tambah Buku Baru ---" << endl;
                cout << "Masukkan ISBN: ";
                cin >> dataBuku.isbn;
                cout << "Masukkan Judul: ";
                cin.ignore(); 
                getline(cin, dataBuku.judul);
                cout << "Masukkan Penulis: ";
                getline(cin, dataBuku.penulis);
                tambahBuku(daftar_buku, dataBuku);
                break;
            case 2:
                cout << "\n--- Hapus Buku ---" << endl;
                cout << "Masukkan ISBN buku yang akan dihapus: ";
                cin >> isbn;
                hapusBuku(daftar_buku, isbn);
                break;
            case 3:
                cout << "\n--- Perbarui Data Buku ---" << endl;
                cout << "Masukkan ISBN buku yang akan diperbarui: ";
                cin >> isbn;
                updateBuku(daftar_buku, isbn);
                break;
            case 4:
                lihatBuku(daftar_buku);
                break;
            case 5:
                cout << "\nTerima kasih! Program selesai." << endl;
                break;
            default:
                cout << "\n[ERROR] Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan != 5);

    return 0;
}
```
### Output Code

![Output](output/guided_Modul5.png)

Program ini adalah contoh praktis penerapan Singly Linked List untuk mengelola data buku dalam sebuah sistem manajemen sederhana.

- Struktur Data: Menggunakan struct infotype untuk membungkus data buku (ISBN, judul, penulis) dan struct elmlist sebagai node dari linked list. Ini adalah pendekatan yang lebih terstruktur dan umum dipakai dalam pengembangan software.
- Fungsi cariBuku(List L, string isbn): Fungsi ini menjadi tulang punggung untuk operasi lain. Ia melakukan Sequential Search untuk menemukan sebuah buku berdasarkan ISBN-nya yang unik. Fungsi ini sangat efisien untuk tugas internal karena ia langsung mengembalikan pointer (address) ke node yang ditemukan. Pointer ini kemudian digunakan secara langsung oleh fungsi hapusBuku dan updateBuku untuk memodifikasi data tanpa perlu melakukan pencarian ulang.

## Unguided

## Soal Latihan Modul 5

### Soal 1

1. Buatlah searcing untuk mencari nama pembeli pada unguided sebelumnya!

```cpp
#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk menyimpan data pembeli
struct Node {
    string nama;
    string pesanan;
    Node* next;
};

// Pointer depan (head) dan belakang (tail) antrian
Node* head = nullptr;
Node* tail = nullptr;

void tambahAntrian(string nama, string pesanan) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->pesanan = pesanan;
    newNode->next = nullptr;

    if (head == nullptr) { // Jika antrian kosong
        head = tail = newNode;
    } else { // Jika sudah ada antrian
        tail->next = newNode;
        tail = newNode;
    }
    cout << "Pembeli atas nama " << nama << " telah masuk ke antrian.\n";
}

void layaniAntrian() {
    if (head == nullptr) {
        cout << "Antrian kosong! Tidak ada yang dilayani.\n";
        return;
    }

    Node* temp = head;
    cout << "Melayani pembeli: " << temp->nama << " (Pesanan: " << temp->pesanan << ")\n";

    head = head->next;
    delete temp;

    if (head == nullptr) {
        tail = nullptr; // Jika antrian jadi kosong
    }
}

void tampilkanAntrian() {
    if (head == nullptr) {
        cout << "Antrian kosong!\n";
        return;
    }

    Node* temp = head;
    cout << "\n=== Daftar Antrian Pembeli ===\n";
    int nomor = 1;
    while (temp != nullptr) {
        cout << nomor << ". " << temp->nama << " - Pesanan: " << temp->pesanan << endl;
        temp = temp->next;
        nomor++;
    }
    cout << "==============================\n";
}


// PENAMBAHAN FUNGSI BARU: Fungsi untuk mencari nama pembeli

void cariPembeli() {
    if (head == nullptr) {
        cout << "Antrian kosong! Tidak ada yang bisa dicari.\n";
        return;
    }

    string namaDicari;
    cout << "Masukkan nama pembeli yang dicari: ";
    getline(cin, namaDicari);

    Node* temp = head;
    bool ditemukan = false;
    int posisi = 1;

    cout << "\n===== Hasil Pencarian untuk '" << namaDicari << "' =====\n";
    while (temp != nullptr) {
        if (temp->nama.find(namaDicari) != string::npos) {
            cout << "Ditemukan pada antrian ke-" << posisi << ":\n";
            cout << "  -> Nama    : " << temp->nama << "\n";
            cout << "  -> Pesanan : " << temp->pesanan << "\n\n";
            ditemukan = true;
        }
        temp = temp->next;
        posisi++;
    }

    if (!ditemukan) {
        cout << "Pembeli dengan nama yang mengandung kata '" << namaDicari << "' tidak ditemukan.\n";
    }
    cout << "=======================================\n";
}


int main() {
    int pilihan;
    string nama, pesanan;

    do {
        cout << "\n=== MENU ANTRIAN PEMBELI ===\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Layani Antrian\n";
        cout << "3. Tampilkan Antrian\n";

        // PERUBAHAN 1: Menambahkan opsi menu baru
        cout << "4. Cari Pembeli\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        
        // Menangani jika input bukan angka
        if (cin.fail()) {
            cout << "\n[ERROR] Input harus berupa angka.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            pilihan = -1;
            continue;
        }
        cin.ignore(); 

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama pembeli: ";
                getline(cin, nama);
                cout << "Masukkan pesanan: ";
                getline(cin, pesanan);
                tambahAntrian(nama, pesanan);
                break;
            case 2:
                layaniAntrian();
                break;
            case 3:
                tampilkanAntrian();
                break;

            // PERUBAHAN 2: Menambahkan case untuk menu baru
            case 4:
                cariPembeli();
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
```
### Output Code
![Output](output/unguided1_Modul5.png)

Program ini merupakan modifikasi dari program antrian pembeli di modul 4 dengan menambahkan fitur pencarian.

- Sistem Antrian (FIFO): Program tetap mempertahankan logika First-In, First-Out menggunakan pointer head dan tail untuk operasi tambahAntrian (menambah di belakang) dan layaniAntrian (menghapus dari depan).
- Fungsi cariPembeli(): Fitur baru ini mengimplementasikan Sequential Search untuk mencari pembeli berdasarkan nama. Uniknya, fungsi ini menggunakan string::find yang memungkinkan pencarian substring (pencocokan sebagian kata). Artinya, jika kita mencari "Ren", maka pembeli dengan nama "Renisa" akan ditemukan. Ini membuat fitur pencarian menjadi lebih fleksibel dan user-friendly, karena pengguna tidak perlu mengetik nama lengkap secara persis.

### Soal 2

2. Gunakan latihan pada pertemuan minggu ini dan tambahkan searching untuk mencari buku berdasarkan judul, penulis, dan ISBN!

```cpp
#include <iostream>
#include <string>

using namespace std;

struct infotype {
    string isbn;
    string judul;
    string penulis;
};

typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype data) {
    address P = new elmlist;
    P->info.isbn = data.isbn;
    P->info.judul = data.judul;
    P->info.penulis = data.penulis;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

// PERUBAHAN 1: Nama fungsi diubah agar lebih spesifik
// Fungsi ini hanya mencari berdasarkan ISBN dan mengembalikan address
// karena dibutuhkan oleh fungsi hapus dan update.

address cariBukuByISBN(List L, string isbn) {
    address P = L.first;
    while (P != NULL) {
        if (P->info.isbn == isbn) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}


// PENAMBAHAN FUNGSI BARU: Fungsi untuk mencari buku
// Fungsi ini akan menampilkan semua buku yang cocok dengan kriteria
// pencarian (Judul, Penulis, atau ISBN).

void cariDanTampilkanBuku(List L) {
    if (L.first == NULL) {
        cout << "\n[INFO] Daftar buku masih kosong, tidak ada yang bisa dicari." << endl;
        return;
    }

    int pilihanCari;
    cout << "\n--- Cari Buku Berdasarkan ---" << endl;
    cout << "1. Judul" << endl;
    cout << "2. Penulis" << endl;
    cout << "3. ISBN" << endl;
    cout << "Pilihan Anda: ";
    cin >> pilihanCari;

    if (cin.fail() || pilihanCari < 1 || pilihanCari > 3) {
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cout << "\n[ERROR] Pilihan tidak valid." << endl;
        return;
    }

    string keyword;
    cout << "Masukkan kata kunci pencarian: ";
    cin.ignore(); 
    getline(cin, keyword);

    address P = L.first;
    bool ditemukan = false;
    int i = 1;

    cout << "\n================ HASIL PENCARIAN ================" << endl;
    while (P != NULL) {
        bool cocok = false;
        // Pilihan 1: Cari berdasarkan judul (bisa sebagian kata)
        if (pilihanCari == 1 && P->info.judul.find(keyword) != string::npos) {
            cocok = true;
        // Pilihan 2: Cari berdasarkan penulis (bisa sebagian kata)
        } else if (pilihanCari == 2 && P->info.penulis.find(keyword) != string::npos) {
            cocok = true;
        // Pilihan 3: Cari berdasarkan ISBN (harus sama persis)
        } else if (pilihanCari == 3 && P->info.isbn == keyword) {
            cocok = true;
        }

        if (cocok) {
            cout << i << ". ISBN    : " << P->info.isbn << endl;
            cout << "   Judul   : " << P->info.judul << endl;
            cout << "   Penulis : " << P->info.penulis << endl;
            cout << "-------------------------------------------" << endl;
            ditemukan = true;
            i++;
        }
        P = P->next;
    }

    if (!ditemukan) {
        cout << "   (Buku dengan kata kunci '" << keyword << "' tidak ditemukan)" << endl;
    }
    cout << "===========================================" << endl;
}


void tambahBuku(List &L, infotype data) {
    address P = alokasi(data);
    if (L.first == NULL) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
    cout << "\n[INFO] Buku '" << data.judul << "' berhasil ditambahkan." << endl;
}

void hapusBuku(List &L, string isbn) {
    // PERUBAHAN 2: Memanggil fungsi cariBukuByISBN
    address P = cariBukuByISBN(L, isbn);

    if (P == NULL) {
        cout << "\n[ERROR] Buku dengan ISBN " << isbn << " tidak ditemukan." << endl;
        return;
    }

    if (P == L.first) {
        L.first = P->next;
    } else {
        address prev = L.first;
        while (prev->next != P) {
            prev = prev->next;
        }
        prev->next = P->next;
    }

    cout << "\n[INFO] Buku '" << P->info.judul << "' berhasil dihapus." << endl;
    dealokasi(P);
}

void updateBuku(List &L, string isbn) {
    // PERUBAHAN 3: Memanggil fungsi cariBukuByISBN
    address P = cariBukuByISBN(L, isbn);
    if (P != NULL) {
        cout << "\nData Buku Ditemukan:" << endl;
        cout << "Judul Lama: " << P->info.judul << endl;
        cout << "Penulis Lama: " << P->info.penulis << endl;

        cout << "\nMasukkan Judul Baru: ";
        cin.ignore();
        getline(cin, P->info.judul);

        cout << "Masukkan Penulis Baru: ";
        getline(cin, P->info.penulis);

        cout << "\n[INFO] Data buku berhasil diperbarui." << endl;
    } else {
        cout << "\n[ERROR] Buku dengan ISBN " << isbn << " tidak ditemukan." << endl;
    }
}

void lihatBuku(List L) {
    cout << "\n================ DAFTAR BUKU ================" << endl;
    if (L.first == NULL) {
        cout << "               (Tidak ada buku di daftar)" << endl;
    } else {
        address P = L.first;
        int i = 1;
        while (P != NULL) {
            cout << i << ". ISBN    : " << P->info.isbn << endl;
            cout << "   Judul   : " << P->info.judul << endl;
            cout << "   Penulis : " << P->info.penulis << endl;
            cout << "-------------------------------------------" << endl;
            P = P->next;
            i++;
        }
    }
    cout << "===========================================" << endl;
}

int main() {
    List daftar_buku;
    createList(daftar_buku);
    int pilihan;
    string isbn;
    infotype dataBuku;

    do {
        cout << "\n===== SISTEM MANAJEMEN BUKU =====" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Hapus Buku" << endl;
        cout << "3. Perbarui Buku" << endl;
        cout << "4. Lihat Semua Buku" << endl;

        // PERUBAHAN 4: Menambahkan opsi menu baru
        cout << "5. Cari Buku" << endl;
        cout << "6. Keluar" << endl;
        cout << "=================================" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        
        // Menangani jika input bukan angka
        if (cin.fail()) {
            cout << "\n[ERROR] Input harus berupa angka." << endl;
            cin.clear();
            cin.ignore(10000, '\n'); 
            pilihan = 0; 
            continue; 
        }


        switch (pilihan) {
            case 1:
                cout << "\n--- Tambah Buku Baru ---" << endl;
                cout << "Masukkan ISBN: ";
                cin >> dataBuku.isbn;
                cout << "Masukkan Judul: ";
                cin.ignore();
                getline(cin, dataBuku.judul);
                cout << "Masukkan Penulis: ";
                getline(cin, dataBuku.penulis);
                tambahBuku(daftar_buku, dataBuku);
                break;
            case 2:
                cout << "\n--- Hapus Buku ---" << endl;
                cout << "Masukkan ISBN buku yang akan dihapus: ";
                cin >> isbn;
                hapusBuku(daftar_buku, isbn);
                break;
            case 3:
                cout << "\n--- Perbarui Data Buku ---" << endl;
                cout << "Masukkan ISBN buku yang akan diperbarui: ";
                cin >> isbn;
                updateBuku(daftar_buku, isbn);
                break;
            case 4:
                lihatBuku(daftar_buku);
                break;

            // PERUBAHAN 5: Menambahkan case untuk menu baru
            case 5:
                cariDanTampilkanBuku(daftar_buku);
                break;
            case 6:
                cout << "\nTerima kasih! Program selesai." << endl;
                break;
            default:
                cout << "\n[ERROR] Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }

    // PERUBAHAN 6: Kondisi loop diubah karena opsi keluar jadi nomor 6
    } while (pilihan != 6);

    return 0;
}
```
### Output Code
![Output](output/unguided2_Modul5_1.png)
![Output](output/unguided2_Modul5_2.png)

Program ini adalah upgrade dari latihan manajemen buku, di mana fitur pencariannya dibuat lebih komprehensif dan interaktif.

- Pemisahan Fungsi Pencarian: Program ini cerdas dalam memisahkan dua jenis pencarian. cariBukuByISBN tetap ada untuk pencarian internal yang butuh pointer (untuk hapus & update). Sementara itu, fungsi baru cariDanTampilkanBuku dibuat khusus untuk interaksi dengan pengguna.
- Fungsi cariDanTampilkanBuku(List L): Fungsi ini memberikan pilihan kepada pengguna untuk mencari berdasarkan Judul, Penulis, atau ISBN. Berdasarkan pilihan tersebut, fungsi ini melakukan Sequential Search ke seluruh list. Untuk pencarian Judul dan Penulis, ia menggunakan string::find untuk pencocokan parsial, sedangkan untuk ISBN ia menggunakan perbandingan == untuk pencocokan yang eksak. Pendekatan ini adalah cerminan dari implementasi fitur pencarian di dunia nyata, di mana pengguna diberikan berbagai filter untuk menemukan data yang mereka inginkan.

## Referensi

1. Vimal P.Parmar. (2015). "Comparing Linear Search and Binary Search Algorithms to Search an Element from a Linear List Implemented through Static Array, Dynamic Array and Linked List ". International Journal of Computer Applications, 121(3), 15-18. https://research.ijcaonline.org/volume121/number3/pxc3904495.pdf
2. Prof.Mrs. Tejaswini.A. Puranik. (2025). "Performance Analysis of Sorting and Searching Algorithms". International Journal of Innovations & Advancement in Computer Science, 6(11), 368-372. https://www.researchgate.net/publication/394971225_Performance_Analysis_of_Sorting_and_Searching_Algorithms