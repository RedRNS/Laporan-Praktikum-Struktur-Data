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