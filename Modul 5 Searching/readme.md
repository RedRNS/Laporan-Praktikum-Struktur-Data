# <h1 align="center">Laporan Praktikum Modul 5 <br> Searching</h1>

<p align="center">Renisa Assyifa Putri - 103112400123</p>

## Dasar Teori - Searching

### 1. Pengertian Searching

Searching atau pencarian adalah operasi dasar dalam ilmu komputer yang bertujuan menemukan lokasi atau keberadaan elemen tertentu dalam kumpulan data. Operasi ini sangat penting dalam berbagai aplikasi seperti database management system, search engine, dan sistem informasi yang memproses data dalam jumlah besar.

Secara formal, searching adalah proses menemukan posisi atau index dari elemen dengan nilai kunci (key) tertentu dalam struktur data. Jika elemen ditemukan, algoritma mengembalikan posisinya; jika tidak ditemukan, algoritma memberikan informasi bahwa elemen tidak ada dalam struktur data.

### 2. Kompleksitas Algoritma Searching

Efisiensi algoritma searching diukur menggunakan notasi Big-O yang menganalisis time complexity dan space complexity:

**Time Complexity:**
- **Best Case**: Kondisi terbaik saat elemen ditemukan di posisi pertama
- **Average Case**: Rata-rata waktu yang dibutuhkan untuk berbagai kemungkinan posisi data
- **Worst Case**: Kondisi terburuk saat elemen berada di posisi terakhir atau tidak ada

**Space Complexity:**
Mengukur jumlah memori tambahan yang dibutuhkan algoritma untuk melakukan pencarian.

### 3. Sequential Search (Linear Search)

#### 3.1 Konsep Dasar Sequential Search

Sequential Search atau Linear Search adalah algoritma pencarian paling sederhana. Algoritma ini bekerja dengan memeriksa setiap elemen dalam struktur data secara berurutan dari awal sampai akhir, atau sampai elemen yang dicari ditemukan.

#### 3.2 Cara Kerja Sequential Search

Proses pencarian sequential mengikuti langkah berikut:

1. **Inisialisasi**: Mulai dari elemen pertama
2. **Komparasi**: Bandingkan nilai elemen saat ini dengan nilai yang dicari
3. **Kondisi Found**: Jika nilai cocok, kembalikan posisinya
4. **Iterasi**: Jika tidak cocok, lanjut ke elemen berikutnya
5. **Terminasi**: Proses berakhir saat elemen ditemukan atau semua data sudah diperiksa

#### 3.3 Karakteristik Sequential Search

**Kelebihan:**
- Implementasi sederhana dan mudah dipahami
- Dapat digunakan pada data yang tidak terurut
- Cocok untuk struktur data linked list
- Tidak perlu preprocessing atau pengurutan data
- Space complexity O(1) - efisien dalam penggunaan memori

**Kekurangan:**
- Time complexity O(n) - kurang efisien untuk dataset besar
- Pada worst case harus memeriksa semua elemen
- Performa menurun drastis untuk data yang banyak

#### 3.4 Analisis Kompleksitas Sequential Search

```
Time Complexity:
- Best Case: O(1)    - Elemen ditemukan di posisi pertama
- Average Case: O(n/2) ≈ O(n) - Elemen di tengah
- Worst Case: O(n)   - Elemen di posisi terakhir atau tidak ada

Space Complexity: O(1) - Hanya memerlukan variabel temporary
```

#### 3.5 Implementasi Sequential Search pada Linked List

Pada linked list, sequential search adalah satu-satunya metode pencarian yang praktis karena:
- Linked list tidak mendukung random access
- Setiap node hanya dapat diakses melalui pointer next
- Traversal harus dilakukan secara sekuensial dari head ke tail

### 4. Binary Search (Pencarian Biner)

#### 4.1 Konsep Dasar Binary Search

Binary Search adalah algoritma pencarian yang efisien menggunakan pendekatan divide and conquer. Algoritma ini membagi ruang pencarian menjadi dua bagian secara berulang, sehingga jumlah elemen yang perlu diperiksa berkurang secara eksponensial.

#### 4.2 Prasyarat Binary Search

**Syarat Mutlak:**
Data harus sudah terurut (sorted) secara ascending atau descending. Tanpa kondisi ini, binary search tidak akan bekerja dengan benar.

#### 4.3 Cara Kerja Binary Search

1. **Tentukan Batas**: Set indeks low = 0 dan high = n-1
2. **Hitung Middle**: Kalkulasi middle = (low + high) / 2
3. **Komparasi Middle**:
   - Jika array[middle] == key → elemen ditemukan
   - Jika array[middle] > key → cari di bagian kiri (high = middle - 1)
   - Jika array[middle] < key → cari di bagian kanan (low = middle + 1)
4. **Iterasi**: Ulangi langkah 2-3 hingga elemen ditemukan atau low > high

#### 4.4 Karakteristik Binary Search

**Kelebihan:**
- Time complexity O(log n) - sangat efisien untuk dataset besar
- Jumlah komparasi minimal dibanding sequential search
- Performa stabil dan dapat diprediksi

**Kekurangan:**
- Hanya bisa digunakan pada data terurut
- Memerlukan proses sorting jika data belum terurut
- Tidak cocok untuk linked list karena butuh random access
- Overhead sorting bisa memakan waktu untuk data dinamis

#### 4.5 Analisis Kompleksitas Binary Search

```
Time Complexity:
- Best Case: O(1)      - Elemen di posisi middle pertama
- Average Case: O(log n) - Rata-rata operasi
- Worst Case: O(log n)  - Pencarian hingga satu elemen tersisa

Space Complexity:
- Iterative: O(1)
- Recursive: O(log n) karena call stack
```

#### 4.6 Perbandingan Efisiensi

Untuk dataset dengan n = 1,000,000 elemen:
- **Sequential Search**: Worst case = 1,000,000 komparasi
- **Binary Search**: Worst case = log₂(1,000,000) ≈ 20 komparasi

Perbedaan ini menjadi sangat signifikan pada big data processing.

### 5. Variasi Algoritma Searching

#### 5.1 Jump Search

Algoritma yang melompati beberapa elemen dengan ukuran blok √n, kemudian melakukan linear search dalam blok tersebut.
- Time Complexity: O(√n)
- Cocok untuk data terurut dengan ukuran medium

#### 5.2 Interpolation Search

Menggunakan interpolasi matematis untuk memperkirakan posisi elemen yang dicari.
- Time Complexity: O(log log n) untuk uniform distribution
- Sangat efisien untuk data numerik yang terdistribusi merata

#### 5.3 Exponential Search

Mencari range dimana elemen mungkin berada dengan eksponensial, lalu gunakan binary search.
- Time Complexity: O(log n)
- Efektif untuk unbounded atau infinite arrays

### 6. Penerapan Searching dalam Praktik

#### 6.1 Database Systems
- B-Tree dan B+ Tree search untuk indexing
- Hash-based search untuk primary key lookup
- Full-text search menggunakan inverted index

#### 6.2 Search Engines
- Web crawling dan indexing
- Ranking algorithms (PageRank, TF-IDF)
- Query optimization menggunakan berbagai search strategies

#### 6.3 Artificial Intelligence
- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- A* Search Algorithm untuk pathfinding
- Minimax search dalam game theory

### 7. Trade-offs dalam Pemilihan Algoritma Searching

Pemilihan algoritma searching yang tepat bergantung pada beberapa faktor:

1. **Karakteristik Data**:
   - Sorted vs Unsorted
   - Static vs Dynamic
   - Ukuran dataset

2. **Struktur Data**:
   - Array/Vector → Binary search optimal untuk sorted data
   - Linked List → Sequential search sebagai pilihan utama
   - Hash Table → O(1) average case dengan proper hash function
   - Tree → Specialized tree search algorithms

3. **Frekuensi Operasi**:
   - Read-heavy: Investasi sorting untuk binary search worth it
   - Write-heavy: Sequential search lebih praktis

4. **Constraint Resources**:
   - Memory-limited: Prefer O(1) space algorithms
   - Time-critical: Prefer O(log n) atau better time complexity

### 8. Implementasi Searching pada Modul Ini

Semua program dalam modul ini mengimplementasikan **Sequential Search** karena bekerja dengan **Singly Linked List** sebagai struktur data utama. Linked list bersifat sequential access, sehingga:

- Setiap node harus diakses melalui traversal dari head
- Tidak ada mekanisme untuk langsung "melompat" ke middle element
- Binary search secara teknis tidak applicable
- Sequential search menjadi pilihan natural dan efisien

Pendekatan ini mencerminkan realitas implementation dimana pemilihan algoritma sangat bergantung pada karakteristik struktur data yang digunakan.

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

Program ini adalah pengembangan dari Singly Linked List modul sebelumnya dengan penambahan fitur pencarian data.

- Struktur & Operasi Dasar: Program menggunakan struct Node dan fungsi-fungsi dasar CRUD seperti insertDepan, hapusNode, dan updateNode.
- Fungsi searchData(int key): Ini adalah fungsi utama yang mengimplementasikan Sequential Search. Fungsi ini menelusuri list dari head satu per satu dan membandingkan data di setiap Node dengan key yang dicari. Variabel pos digunakan untuk melacak posisi node. Jika data ditemukan, fungsi mencetak posisinya dan berhenti. Jika sampai akhir list data tidak ditemukan, flag found memastikan pesan "tidak ditemukan" ditampilkan.

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

Program ini adalah implementasi Singly Linked List untuk sistem manajemen data buku.

- Struktur Data: Menggunakan struct infotype untuk data buku (ISBN, judul, penulis) dan struct elmlist sebagai node linked list. Pendekatan ini lebih terstruktur dan umum digunakan dalam pengembangan software.
- Fungsi cariBuku(List L, string isbn): Fungsi ini menjadi dasar untuk operasi lain dengan melakukan Sequential Search berdasarkan ISBN. Fungsi mengembalikan pointer (address) ke node yang ditemukan, yang kemudian digunakan langsung oleh fungsi hapusBuku dan updateBuku untuk memodifikasi data tanpa perlu pencarian ulang.

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

Program ini adalah modifikasi dari program antrian pembeli modul 4 dengan penambahan fitur pencarian.

- Sistem Antrian (FIFO): Program mempertahankan logika First-In, First-Out menggunakan pointer head dan tail untuk operasi tambahAntrian dan layaniAntrian.
- Fungsi cariPembeli(): Fitur ini mengimplementasikan Sequential Search untuk mencari pembeli berdasarkan nama. Fungsi menggunakan string::find yang memungkinkan pencarian substring, sehingga pencarian "Ren" akan menemukan "Renisa". Hal ini membuat pencarian lebih fleksibel karena pengguna tidak perlu mengetik nama lengkap.

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

Program ini merupakan pengembangan dari latihan manajemen buku dengan fitur pencarian yang lebih lengkap dan interaktif.

- Pemisahan Fungsi Pencarian: Program memisahkan dua jenis pencarian. cariBukuByISBN untuk pencarian internal yang membutuhkan pointer (untuk operasi hapus & update), dan cariDanTampilkanBuku untuk interaksi dengan pengguna.
- Fungsi cariDanTampilkanBuku(List L): Fungsi ini memberikan pilihan pencarian berdasarkan Judul, Penulis, atau ISBN. Fungsi melakukan Sequential Search ke seluruh list. Untuk Judul dan Penulis menggunakan string::find untuk pencocokan parsial, sedangkan ISBN menggunakan perbandingan eksak. Pendekatan ini mencerminkan implementasi pencarian di aplikasi nyata dimana pengguna diberikan berbagai opsi filter.

## Kesimpulan

Modul 5 tentang Searching memberikan pemahaman tentang algoritma pencarian dan implementasinya pada struktur data linked list. Berikut adalah kesimpulan dari pembelajaran modul ini:

### 1. Searching sebagai Operasi Dasar

Searching merupakan operasi fundamental dalam sistem informasi modern. Kemampuan menemukan data dengan cepat dan efisien menentukan performa aplikasi. Pemahaman tentang algoritma searching penting tidak hanya untuk implementasi teknis, tetapi juga untuk membuat keputusan arsitektural dalam software design.

### 2. Sequential Search: Kesederhanaan dengan Trade-offs

Sequential search membuktikan bahwa algoritma sederhana tetap memiliki tempat penting dalam computer science. Dengan time complexity O(n), algoritma ini memiliki beberapa keunggulan praktis:

- **Universal applicability**: Dapat digunakan pada data sorted maupun unsorted
- **Minimal overhead**: Tidak perlu preprocessing atau struktur data khusus
- **Natural fit untuk linked list**: Sesuai dengan karakteristik sequential access
- **Implementation simplicity**: Mudah dipahami dan di-maintain

Pembelajaran ini menunjukkan bahwa "optimal" tidak selalu berarti "fastest algorithm", tetapi algoritma yang paling sesuai dengan kebutuhan sistem.

### 3. Struktur Data Menentukan Pilihan Algoritma

Pemilihan algoritma sangat bergantung pada struktur data yang digunakan. Linked list dengan karakteristik sequential access membuat sequential search menjadi pilihan yang tepat:

- **No random access**: Linked list tidak mendukung direct indexing
- **Pointer-based traversal**: Akses node hanya melalui pointer next
- **Binary search impracticality**: Binary search tidak efisien pada linked list karena mencari middle element memerlukan O(n/2) traversal

Hal ini menunjukkan pentingnya memahami karakteristik struktur data sebelum memilih algoritma.

### 4. Time Complexity sebagai Performance Metric

Modul ini memperkuat pemahaman tentang analisis kompleksitas algoritma:

**Sequential Search Analysis:**
- Best case O(1): Data di posisi pertama
- Average case O(n/2) \u2248 O(n): Data di tengah
- Worst case O(n): Data di akhir atau tidak ada

**Binary Search Comparison:**
- O(log n) untuk sorted array dengan random access
- Menunjukkan perbedaan dramatis untuk large datasets
- n = 1,000,000: Sequential = 1M komparasi vs Binary = ~20 komparasi

Pemahaman ini krusial untuk membuat informed decisions tentang kapan optimization diperlukan.

### 5. Implementasi Praktis dalam Aplikasi Nyata

Implementasi dalam modul ini mendemonstrasikan bagaimana searching terintegrasi dalam aplikasi:

- **Search as enabling operation**: Pencarian memungkinkan operasi update dan delete
- **User experience**: Fungsi pencarian menunjukkan pentingnya UX dalam search interface
- **Multiple search criteria**: Pencarian berdasarkan ISBN, judul, dan penulis mencerminkan kebutuhan nyata
- **Partial matching**: Penggunaan string::find untuk pencarian fleksibel

### 6. Error Handling dan Robustness

Program menunjukkan pentingnya defensive programming:

- **Input validation**: Pengecekan cin.fail() untuk menangani input tidak valid
- **Null checking**: Validasi list kosong sebelum operasi
- **Clear user feedback**: Pesan informatif untuk kondisi found/not found
- **Graceful degradation**: Program tidak crash ketika data tidak ditemukan

### 7. Sequential Search untuk Linked List

Modul ini membuktikan sequential search cocok untuk linked list:

- **Single traversal**: Efisien karena setiap node hanya dikunjungi sekali
- **Early termination**: Break statement mengoptimalkan average case
- **Memory efficient**: O(1) space complexity
- **Simplicity in implementation**: Logika straightforward mengurangi potensi bug

### 8. Trade-offs dalam Software Engineering

Pemahaman tentang engineering trade-offs:

**Time vs Space:**
- Sequential search: O(n) time, O(1) space
- Advanced search: Better time dengan kebutuhan space tambahan

**Simplicity vs Performance:**
- Sequential: Mudah implement dan maintain
- Complex algorithms: Performa lebih baik dengan kompleksitas lebih tinggi

**Flexibility vs Efficiency:**
- Unsorted data: Fleksibel dengan sequential search
- Sorted data: Efisien dengan binary search namun kurang fleksibel

### 9. Foundation untuk Advanced Searching

Konsep dalam modul ini menjadi dasar untuk algoritma searching yang lebih advanced:

- **Hash-based search**: O(1) average case dengan hash tables
- **Tree-based search**: Binary Search Tree, AVL Tree, B-Tree
- **Graph search algorithms**: BFS, DFS, Dijkstra, A*
- **String searching**: KMP, Rabin-Karp, Boyer-Moore

### 10. Integrasi dengan Operasi CRUD

Modul ini menunjukkan integrasi searching dengan operasi CRUD:

- **Update operation**: Memerlukan search untuk menemukan node
- **Delete operation**: Search menentukan node yang akan dihapus
- **Read operation**: Search adalah bentuk operasi read
- **Create validation**: Search dapat mencegah duplikasi data

Hal ini menunjukkan searching bukan operasi terpisah, tetapi operasi pendukung untuk operasi data lainnya.

### 11. Code Quality dan Best Practices

Implementasi dalam modul ini mendemonstrasikan best practices:

- **Modular functions**: Setiap fungsi memiliki tanggung jawab tunggal
- **Descriptive naming**: Nama variabel dan fungsi yang jelas
- **Comments dan documentation**: Komentar menjelaskan logika kompleks
- **Consistent style**: Indentasi dan formatting konsisten
- **User-friendly interface**: Menu dengan instruksi yang jelas

### 12. Aplikabilitas Sequential Search

Sequential search dapat diaplikasikan pada berbagai skenario:

- **Small datasets**: Overhead sorting tidak efisien untuk data kecil
- **Dynamic data**: Data yang sering berubah sulit maintain sorted order
- **One-time search**: Sorting overhead lebih besar dari sequential search
- **Linked list structures**: Pilihan natural untuk struktur berbasis pointer

### 13. Strategi Optimasi

Beberapa strategi optimasi untuk sequential search:

- **Early termination**: Break segera setelah data ditemukan
- **Move-to-front heuristic**: Menempatkan data yang sering diakses di depan
- **Caching results**: Untuk pencarian berulang pada data statis

### 14. Pentingnya Testing

Modul ini menekankan pentingnya testing:

- **Compilation success**: Memastikan kode syntactically correct
- **Functional testing**: Verifikasi semua operasi berjalan benar
- **Edge case handling**: Test dengan list kosong, single element, dll
- **Performance measurement**: Awareness tentang execution time

### 15. Menjembatani Teori dan Praktik

Modul ini berhasil menghubungkan teori algoritma dengan implementasi praktis. Mahasiswa tidak hanya mempelajari "apa itu sequential search", tetapi juga:

- **Kapan menggunakannya**: Konteks dan skenario yang tepat
- **Bagaimana mengimplementasikannya**: Practical coding skills
- **Mengapa memilihnya**: Understanding trade-offs dan pengambilan keputusan
- **Apa limitasinya**: Awareness tentang batasan dan alternatif

Pemahaman ini adalah fondasi untuk menjadi software engineer yang mampu membuat keputusan arsitektural berdasarkan pemahaman mendalam tentang algoritma dan struktur data dalam aplikasi nyata.

Modul Searching ini bukan hanya tentang menemukan data dalam linked list, tetapi tentang mengembangkan computational thinking, memahami analisis kompleksitas, dan menghargai kesederhanaan algoritma yang dirancang dengan baik. Kemampuan ini akan sangat berguna untuk mempelajari advanced data structures dan algorithms di modul selanjutnya seperti sorting, tree structures, dan graph algorithms.

## Referensi

1. Vimal P.Parmar. (2015). "Comparing Linear Search and Binary Search Algorithms to Search an Element from a Linear List Implemented through Static Array, Dynamic Array and Linked List ". International Journal of Computer Applications, 121(3), 15-18. https://research.ijcaonline.org/volume121/number3/pxc3904495.pdf
2. Prof.Mrs. Tejaswini.A. Puranik. (2025). "Performance Analysis of Sorting and Searching Algorithms". International Journal of Innovations & Advancement in Computer Science, 6(11), 368-372. https://www.researchgate.net/publication/394971225_Performance_Analysis_of_Sorting_and_Searching_Algorithms