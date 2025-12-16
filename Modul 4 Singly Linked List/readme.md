# <h1 align="center">Laporan Praktikum Modul 4 <br> Singly Linked List</h1>

<p align="center">Renisa Assyifa Putri - 103112400123</p>

## Dasar Teori

### 1. Pengertian Singly Linked List

**Singly Linked List** adalah struktur data linier yang terdiri dari sekumpulan node yang saling terhubung secara berurutan. Setiap node memiliki dua komponen utama:
1. **Data**: Menyimpan nilai atau informasi
2. **Pointer Next**: Menyimpan alamat node berikutnya

**Visualisasi Singly Linked List:**
```
[Data|Next] -> [Data|Next] -> [Data|Next] -> NULL
   Node 1         Node 2         Node 3
```

**Analogi:** Singly Linked List dapat dianalogikan sebagai rangkaian gerbong kereta yang terhubung. Setiap gerbong (node) memiliki satu sambungan (pointer) yang menunjuk ke gerbong berikutnya.

### 2. Komponen Singly Linked List

**a. Node (Simpul)**

Node adalah unit dasar dari linked list yang berisi data dan pointer:
```cpp
struct Node {
    int data;        // Data yang disimpan
    Node* next;      // Pointer ke node berikutnya
};
```

**b. Head (Kepala)**

Head adalah pointer yang menunjuk ke node pertama dalam linked list. Head adalah entry point untuk mengakses seluruh linked list.
```cpp
Node* head = nullptr;  // Awalnya list kosong
```

**c. Tail (Ekor)**

Tail adalah node terakhir dalam linked list. Karakteristik tail:
- Pointer `next` nya menunjuk ke `nullptr` (NULL)
- Menandakan akhir dari linked list

**Ilustrasi:**
```
head -> [10|•] -> [20|•] -> [30|NULL] <- tail
```

### 3. Operasi Dasar Singly Linked List

**a. Insert (Penyisipan)**

**1) Insert di Depan (Insert at Beginning):**
```cpp
void insertDepan(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;  // Node baru menunjuk ke head lama
    head = newNode;         // Head sekarang menunjuk ke node baru
}
```

**Visualisasi:**
```
Sebelum: head -> [20|•] -> [30|NULL]
Sesudah: head -> [10|•] -> [20|•] -> [30|NULL]
                  ↑ node baru
```

**Kompleksitas Waktu:** O(1) - Sangat efisien

**2) Insert di Belakang (Insert at End):**
```cpp
void insertBelakang(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;  // Jika list kosong
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;  // Traverse sampai tail
        }
        temp->next = newNode;  // Sambungkan ke node baru
    }
}
```

**Visualisasi:**
```
Sebelum: head -> [10|•] -> [20|NULL]
Sesudah: head -> [10|•] -> [20|•] -> [30|NULL]
                                      ↑ node baru
```

**Kompleksitas Waktu:** O(n) - Harus traverse ke akhir

**3) Insert Setelah Node Tertentu:**
```cpp
void insertSetelah(int target, int dataBaru) {
    Node* temp = head;
    // Cari node dengan data target
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        Node* newNode = new Node();
        newNode->data = dataBaru;
        newNode->next = temp->next;  // Node baru menunjuk ke node setelah target
        temp->next = newNode;         // Target menunjuk ke node baru
    }
}
```

**Visualisasi:**
```
Sebelum: head -> [10|•] -> [20|•] -> [30|NULL]
                            ↓ target
Sesudah: head -> [10|•] -> [20|•] -> [25|•] -> [30|NULL]
                                      ↑ node baru
```

**b. Delete (Penghapusan)**

```cpp
void hapusNode(int data) {
    if (head == nullptr) return;  // List kosong
    
    // Jika node yang dihapus adalah head
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    // Cari node sebelum node yang akan dihapus
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != data) {
        temp = temp->next;
    }
    
    if (temp->next != nullptr) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;  // Bypass node yang dihapus
        delete nodeToDelete;
    }
}
```

**Visualisasi:**
```
Sebelum: head -> [10|•] -> [20|•] -> [30|NULL]
                            ↓ hapus
Sesudah: head -> [10|•] ---------> [30|NULL]
                    [20] (deleted)
```

**c. Update (Pembaruan)**

```cpp
void updateNode(int dataLama, int dataBaru) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == dataLama) {
            temp->data = dataBaru;
            return;
        }
        temp = temp->next;
    }
}
```

**d. Traverse (Penelusuran)**

```cpp
void tampilkanList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
```

**e. Search (Pencarian)**

```cpp
bool cariData(int data) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == data) {
            return true;  // Data ditemukan
        }
        temp = temp->next;
    }
    return false;  // Data tidak ditemukan
}
```

### 4. Perbandingan Array vs Singly Linked List

| Aspek | Array | Singly Linked List |
|-------|-------|--------------------|
| **Alokasi Memori** | Kontinu (berurutan) | Non-kontinu (tersebar) |
| **Ukuran** | Fixed (statis) | Dynamic (fleksibel) |
| **Akses Elemen** | O(1) - Random access | O(n) - Sequential access |
| **Insert di Awal** | O(n) - Harus shift | O(1) - Sangat cepat |
| **Insert di Akhir** | O(1) jika ada space | O(n) - Traverse dulu |
| **Delete** | O(n) - Harus shift | O(n) - Cari dulu |
| **Memory Overhead** | Minimal | Extra (pointer) |
| **Cache Locality** | Baik | Buruk |

### 5. Kelebihan Singly Linked List

1. **Dynamic Size**: Ukuran dapat berubah sesuai kebutuhan tanpa waste memory
2. **Easy Insert/Delete**: Operasi insert dan delete di awal sangat efisien O(1)
3. **No Memory Waste**: Tidak ada pre-alokasi memori seperti array
4. **Flexible**: Mudah untuk grow dan shrink

### 6. Kekurangan Singly Linked List

1. **Sequential Access**: Tidak bisa langsung akses elemen ke-n, harus traverse dari head
2. **Extra Memory**: Setiap node memerlukan memory tambahan untuk pointer
3. **No Backward Traversal**: Hanya bisa traverse ke depan (singly direction)
4. **Cache Unfriendly**: Node tersebar di memory, tidak cache-efficient

### 7. Aplikasi Singly Linked List

**a. Queue (Antrian):**
- Menggunakan FIFO (First In First Out)
- Insert di tail, delete di head
- Contoh: Print queue, task scheduling

**b. Stack:**
- Menggunakan LIFO (Last In First Out)  
- Insert dan delete di head
- Contoh: Undo mechanism, browser history

**c. Polynomial Representation:**
```
5x³ + 3x² + 2x + 7
Dapat direpresentasikan sebagai linked list:
[5,3] -> [3,2] -> [2,1] -> [7,0] -> NULL
```

**d. Sparse Matrix:**
Matriks dengan banyak nilai 0 dapat direpresentasikan efisien dengan linked list.

### 8. Memory Management

**Alokasi Dinamis:**
```cpp
Node* newNode = new Node();  // Alokasi memori di heap
```

**Dealokasi:**
```cpp
delete nodeToDelete;  // Bebaskan memori
```

**⚠️ Memory Leak:**
Jika tidak melakukan `delete` pada node yang dihapus, akan terjadi memory leak.

**Best Practice:**
```cpp
// Selalu hapus semua node saat program selesai
void clearList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
```

### 9. Kompleksitas Waktu Operasi

| Operasi | Time Complexity | Space Complexity |
|---------|----------------|------------------|
| Insert di Awal | O(1) | O(1) |
| Insert di Akhir | O(n) | O(1) |
| Insert di Tengah | O(n) | O(1) |
| Delete di Awal | O(1) | O(1) |
| Delete di Akhir | O(n) | O(1) |
| Delete di Tengah | O(n) | O(1) |
| Search | O(n) | O(1) |
| Access by Index | O(n) | O(1) |
| Traverse | O(n) | O(1) |

### 10. ADT (Abstract Data Type) Linked List

Ketika membuat struct Node dan fungsi-fungsi seperti insert, delete, dan traverse, kita sedang membangun ADT Linked List:

**Interface (Operasi Publik):**
- insertDepan(), insertBelakang(), insertSetelah()
- hapusNode(), updateNode()
- tampilkanList(), cariData()

**Implementation (Detail Internal):**
- Pointer manipulation
- Memory allocation/deallocation
- Traversal logic

**Prinsip Encapsulation:**
Pengguna tidak perlu tahu bagaimana pointer bekerja, mereka hanya perlu tahu operasi apa yang tersedia.

## Guided

```cpp
#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* next;
};

// Pointer awal
Node* head = nullptr;

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// ========== INSERT DEPAN ==========
void insertDepan(int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    cout << "Data " << data << " berhasil ditambahkan di depan.\n";
}

// ========== INSERT BELAKANG ==========
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

// ========== INSERT SETELAH ==========
void insertSetelah(int target, int dataBaru) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Data " << target << " tidak ditemukan!\n";
    } else {
        Node* newNode = createNode(dataBaru);
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

    // Jika data di node pertama
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
        temp = temp->next; //
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
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

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

![Output](output/Output-Guided1.1-Modul4.png)
![Output](output/Output-Guided1.2-Modul4.png)

Program ini adalah implementasi lengkap untuk mengelola singly linked list.

Struktur Dasar: Dimulai dengan struct Node yang punya dua komponen: data (untuk menyimpan nilai) dan next (pointer ke node selanjutnya). Ada juga pointer global head yang selalu menunjuk ke node pertama.

Operasi Penambahan: Terdapat tiga fungsi untuk menambah data:
insertDepan(): Menambah node baru di awal dan menjadikannya head yang baru.
insertBelakang(): Menelusuri list sampai akhir, lalu menyambungkan node baru di sana.
insertSetelah(): Mencari node dengan data tertentu, lalu menyisipkan node baru setelahnya.

Operasi Modifikasi & Penghapusan:
hapusNode(): Mencari node yang akan dihapus, lalu menyambungkan node sebelumnya dengan node sesudahnya, effectively "melepas" node target dari rantai sebelum menghapusnya.
updateNode(): Mencari node dengan data lama, lalu langsung mengganti nilainya dengan data baru.
Operasi Tampilan: tampilkanList() bekerja dengan cara berjalan dari head sampai NULL sambil mencetak data setiap node yang dilewati.
Program Utama: Fungsi main() menyediakan menu interaktif agar pengguna bisa memilih dan menjalankan semua operasi linked list yang sudah dibuat.

## Unguided

## Soal Latihan Modul 4

### Soal 1

1. Buatlah single linked list untuk Antrian yang menyimpan data pembeli( nama dan pesanan). program memiliki beberapa menu seperti tambah antrian,  layani antrian(hapus), dan tampilkan antrian. \*antrian pertama harus yang pertama dilayani

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

// Program utama
int main() {
    int pilihan;
    string nama, pesanan;

    do {
        cout << "\n=== MENU ANTRIAN PEMBELI ===\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Layani Antrian\n";
        cout << "3. Tampilkan Antrian\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
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
![Output](output/Output-Unguided1-Modul4.png)

Program ini adalah simulasi sistem antrian yang menerapkan prinsip First-In, First-Out (FIFO) menggunakan singly linked list.
- Struktur Data: Setiap Node menyimpan data nama dan pesanan pembeli. Program menggunakan dua pointer utama: head (untuk menunjuk antrian terdepan) dan tail (untuk menunjuk antrian terakhir).
- tambahAntrian(): Fungsi ini menambahkan pembeli baru di ujung belakang antrian. Node baru disambungkan setelah tail, dan tail kemudian diperbarui untuk menunjuk ke node baru tersebut. Ini memastikan penambahan data selalu efisien.
- layaniAntrian(): Fungsi ini melayani pembeli di urutan paling depan. Data pembeli di head ditampilkan, lalu node head dihapus dari list, dan head digeser ke node berikutnya. Ini adalah implementasi dari prinsip "yang pertama datang, yang pertama dilayani".
- tampilkanAntrian(): Menampilkan seluruh pembeli yang sedang mengantri dari head hingga tail.

### Soal 2

2. buatlah program kode untuk membalik (reverse) singly linked list (1-2-3 menjadi 3-2-1)

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Pointer awal
Node* head = nullptr;

void insertBelakang(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void tampilkanList() {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void reverseList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;  // simpan node berikutnya
        current->next = prev;  // balik arah pointer
        prev = current;        // geser prev ke current
        current = next;        // pindah ke node berikutnya
    }
    head = prev; // ubah head ke node terakhir
    cout << "Linked list berhasil dibalik!\n";
}
// Program utama
int main() {
    int n, data;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Masukkan data ke-" << i + 1 << ": ";
        cin >> data;
        insertBelakang(data);
    }
    cout << "\nLinked list sebelum dibalik:\n";
    tampilkanList();
    reverseList();
    cout << "\nLinked list setelah dibalik:\n";
    tampilkanList();
    return 0;
}
```
### Output Code
![Output](output/Output-Unguided2-Modul4.png)
Program ini berfungsi untuk membalik urutan sebuah singly linked list. Proses pembalikan dilakukan dalam fungsi reverseList() dengan sebuah algoritma iteratif yang cerdas menggunakan tiga pointer: prev, current, dan next.
Logikanya seperti ini:
1. prev awalnya NULL, akan menjadi node baru yang ditunjuk.
2. current dimulai dari head, node yang sedang diproses.
3. next digunakan untuk menyimpan sementara node selanjutnya agar kita tidak kehilangan sisa rantai.
Dalam setiap iterasi, pointer next dari current dibalik arahnya untuk menunjuk ke prev. Setelah itu, prev dan current digeser satu langkah ke depan. Proses ini diulang sampai seluruh node selesai dibalik. Pada akhirnya, head di-update untuk menunjuk ke prev, yang kini menjadi elemen pertama dari list yang sudah terbalik.

## Kesimpulan

Praktikum Modul 4 tentang Singly Linked List telah memberikan pemahaman mendalam tentang struktur data dinamis yang fundamental dalam pemrograman. Beberapa kesimpulan penting yang dapat diambil:

1. **Konsep Singly Linked List**: Singly Linked List adalah struktur data linier yang terdiri dari node-node yang saling terhubung melalui pointer. Setiap node memiliki dua komponen: data untuk menyimpan nilai, dan pointer `next` untuk menunjuk ke node berikutnya. Struktur ini memungkinkan organisasi data yang fleksibel dan dinamis.

2. **Komponen Fundamental**: Pemahaman tentang tiga komponen utama sangat penting:
   - **Node**: Unit dasar yang menyimpan data dan pointer
   - **Head**: Pointer ke node pertama sebagai entry point
   - **Tail**: Node terakhir dengan pointer next = nullptr
   
   Ketiga komponen ini bekerja sama untuk membentuk struktur linked list yang fungsional.

3. **Operasi Insert yang Efisien**: Singly Linked List memiliki keunggulan signifikan dalam operasi insert, terutama di awal list dengan kompleksitas O(1). Tiga jenis insert yang dipelajari:
   - **Insert di Depan**: Sangat cepat O(1), cocok untuk implementasi Stack
   - **Insert di Belakang**: Memerlukan traversal O(n), cocok untuk Queue
   - **Insert Setelah Node**: Fleksibel untuk penyisipan di posisi tertentu

4. **Memory Management yang Tepat**: Penggunaan alokasi dinamis (`new`) dan dealokasi (`delete`) sangat penting untuk mencegah memory leak. Setiap node yang tidak digunakan harus di-dealokasi dengan benar. Ini mengajarkan pentingnya manual memory management dalam bahasa seperti C++.

5. **Traversal dan Sequential Access**: Berbeda dengan array yang memiliki random access O(1), linked list menggunakan sequential access O(n). Untuk mengakses elemen tertentu, kita harus traverse dari head satu per satu. Ini adalah trade-off yang harus dipahami saat memilih struktur data.

6. **Pointer Manipulation**: Praktikum ini mengasah kemampuan manipulasi pointer yang sangat penting dalam pemrograman tingkat lanjut. Memahami bagaimana mengubah arah pointer, mem-bypass node, dan menghubungkan node adalah skill fundamental untuk struktur data yang lebih kompleks.

7. **Implementasi Queue dengan FIFO**: Unguided 1 mendemonstrasikan implementasi praktis queue (antrian) dengan prinsip First-In-First-Out. Penggunaan dua pointer (head dan tail) membuat operasi enqueue dan dequeue lebih efisien. Aplikasi ini sangat relevan untuk:
   - Sistem antrian pelanggan
   - Task scheduling
   - Buffer management
   - Print queue

8. **Algoritma Reverse List**: Unguided 2 mengajarkan algoritma iteratif yang elegant untuk membalik linked list menggunakan tiga pointer (prev, current, next). Algoritma ini menunjukkan:
   - Pentingnya temporary variable untuk tidak kehilangan referensi
   - Teknik pointer reversal yang efisien O(n) dengan space O(1)
   - Logika iteratif yang sistematis

9. **Perbandingan dengan Array**: Linked list memiliki kelebihan dan kekurangan dibandingkan array:
   
   **Kelebihan:**
   - Dynamic size tanpa waste memory
   - Insert/delete di awal sangat efisien O(1)
   - Tidak perlu shifting elemen
   - Mudah grow dan shrink
   
   **Kekurangan:**
   - No random access, harus sequential O(n)
   - Extra memory untuk pointer
   - Cache unfriendly (node tersebar di memory)
   - Tidak bisa traverse mundur (dalam singly linked list)

10. **ADT Linked List**: Implementasi linked list dengan fungsi-fungsi terpisah (insert, delete, update, display) adalah contoh penerapan Abstract Data Type. Interface yang jelas memisahkan "apa yang bisa dilakukan" dari "bagaimana cara melakukannya", menerapkan prinsip encapsulation.

11. **Kompleksitas Algoritma**: Pemahaman tentang kompleksitas waktu setiap operasi sangat penting untuk memilih algoritma yang tepat:
   - Insert di awal: O(1) - Sangat efisien
   - Insert di akhir: O(n) - Perlu traversal
   - Delete: O(n) - Perlu pencarian
   - Search: O(n) - Sequential
   - Access by index: O(n) - Tidak ada direct access

12. **Aplikasi Praktis**: Linked list adalah fondasi untuk banyak struktur data dan aplikasi:
   - **Stack**: Menggunakan insert/delete di head (LIFO)
   - **Queue**: Menggunakan insert di tail, delete di head (FIFO)
   - **Graph**: Adjacency list menggunakan linked list
   - **Hash Table**: Collision handling dengan chaining
   - **Undo/Redo**: Browser history, text editor
   - **Polynomial Arithmetic**: Representasi dan operasi polynomial

13. **Best Practices**: Beberapa praktik terbaik yang dipelajari:
   - Selalu cek kondisi list kosong (`head == nullptr`)
   - Gunakan temporary pointer untuk traversal
   - Dealokasi memory setelah delete node
   - Clear entire list saat program selesai
   - Handle edge cases (insert ke list kosong, delete head)

14. **Debugging Skills**: Bekerja dengan pointer mengajarkan skill debugging yang penting:
   - Tracking pointer references
   - Identifying memory leaks
   - Handling null pointer dereference
   - Visualizing data flow

15. **Fondasi untuk Struktur Data Lanjutan**: Singly Linked List adalah stepping stone untuk struktur data yang lebih kompleks:
   - **Doubly Linked List**: Menambahkan pointer prev
   - **Circular Linked List**: Tail menunjuk kembali ke head
   - **Skip List**: Multiple levels untuk search lebih cepat
   - **Graph**: Adjacency list representation
   - **Tree**: Binary tree dengan pointer left dan right

Penguasaan Singly Linked List tidak hanya tentang implementasi teknis, tetapi juga tentang memahami trade-offs dalam pemilihan struktur data. Linked list memberikan fleksibilitas dynamic memory allocation dengan trade-off pada access time. Pemahaman ini sangat penting untuk menjadi programmer yang dapat membuat keputusan desain yang tepat berdasarkan requirements aplikasi.

Konsep pointer manipulation, memory management, dan algorithmic thinking yang dipelajari di modul ini akan sangat berguna untuk mempelajari struktur data yang lebih advanced seperti tree, graph, dan hash table di modul-modul berikutnya.

## Referensi

1. Universitas Negeri Malang. (n.d.). Modul 6 Single & Double Linked List. Modul Struktur Data (PDF). https://elektro.um.ac.id/wp-content/uploads/2016/04/ASD-Modul-6-Linked-List.pdf
2. Universitas Esa Unggul. (n.d.). Linked List. Modul Kuliah Struktur Data. https://lms-paralel.esaunggul.ac.id/pluginfile.php?file=%2F86227%2Fmod_resource%2Fcontent%2F1%2FModul+Struktur+Data-Linked+List.pdf
3. Rumah Coding. (n.d.). "Struktur Data: Pengertian dan Implementasi Dasar Linked List". https://rumahcoding.co.id/linked-list-pengertian-dan-implementasi-dasar/
