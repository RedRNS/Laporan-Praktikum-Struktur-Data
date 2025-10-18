#include <iostream>
#include <string>

using namespace std;

struct Pembeli {
    string nama;
    string pesanan;
};

typedef Pembeli infotype;
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

bool isEmpty(List L) {
    return L.first == NULL;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (!isEmpty(L)) {
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}

void printInfo(List L) {
    if (isEmpty(L)) {
        cout << "[ Antrian Kosong ]" << endl;
    } else {
        address P = L.first;
        int i = 1;
        cout << "===== Daftar Antrian Saat Ini =====" << endl;
        while (P != NULL) {
            cout << i << ". Nama: " << P->info.nama << " | Pesanan: " << P->info.pesanan << endl;
            P = P->next;
            i++;
        }
        cout << "=================================" << endl;
    }
}

int main() {
    List antrian;
    createList(antrian);
    int pilihan;
    
    do {
        cout << "\n===== Sistem Antrian Cafe =====" << endl;
        cout << "1. Tambah Antrian" << endl;
        cout << "2. Layani Antrian" << endl;
        cout << "3. Tampilkan Antrian" << endl;
        cout << "4. Keluar" << endl;
        cout << "=============================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(); 

        switch (pilihan) {
            case 1: {
                infotype dataPembeli;
                cout << "Masukkan Nama Pembeli: ";
                getline(cin, dataPembeli.nama);
                cout << "Masukkan Pesanan: ";
                getline(cin, dataPembeli.pesanan);
                address P = alokasi(dataPembeli);
                insertLast(antrian, P);
                cout << "Pembeli '" << dataPembeli.nama << "' telah ditambahkan ke antrian." << endl;
                break;
            }
            case 2: {
                if (isEmpty(antrian)) {
                    cout << "Tidak ada antrian untuk dilayani." << endl;
                } else {
                    address P;
                    deleteFirst(antrian, P);
                    cout << "Melayani: '" << P->info.nama << "' dengan pesanan '" << P->info.pesanan << "'." << endl;
                    dealokasi(P);
                }
                break;
            }
            case 3: {
                printInfo(antrian);
                break;
            }
            case 4: {
                cout << "Terima kasih, program ditutup." << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid, coba lagi." << endl;
                break;
            }
        }
    } while (pilihan != 4);

    return 0;
}