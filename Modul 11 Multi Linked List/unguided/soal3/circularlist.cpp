#include "circularlist.h"

// Membuat list kosong
void createList(List &L) {
    L.First = Nil;
}

// Alokasi node baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

// Dealokasi node
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// Insert pertama
void insertFirst(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        P->next = P;
    } else {
        address last = L.First;
        while (last->next != L.First) {
            last = last->next;
        }
        P->next = L.First;
        last->next = P;
        L.First = P;
    }
}

// Insert setelah Prec
void insertAfter(List &L, address Prec, address P) {
    if (Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

// Insert terakhir
void insertLast(List &L, address P) {
    if (L.First == Nil) {
        insertFirst(L, P);
    } else {
        address last = L.First;
        while (last->next != L.First) {
            last = last->next;
        }
        last->next = P;
        P->next = L.First;
    }
}

// Delete pertama
void deleteFirst(List &L, address &P) {
    if (L.First != Nil) {
        if (L.First->next == L.First) {
            P = L.First;
            L.First = Nil;
        } else {
            address last = L.First;
            while (last->next != L.First) {
                last = last->next;
            }
            P = L.First;
            L.First = P->next;
            last->next = L.First;
            P->next = Nil;
        }
    }
}

// Delete setelah Prec
void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != Nil && Prec->next != L.First) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    }
}

// Delete terakhir
void deleteLast(List &L, address &P) {
    if (L.First != Nil) {
        if (L.First->next == L.First) {
            P = L.First;
            L.First = Nil;
        } else {
            address last = L.First;
            address prec = Nil;

            while (last->next != L.First) {
                prec = last;
                last = last->next;
            }

            P = last;
            prec->next = L.First;
            P->next = Nil;
        }
    }
}

// Mencari data berdasarkan NIM
address findElm(List L, infotype x) {
    if (L.First != Nil) {
        address P = L.First;
        do {
            if (P->info.nim == x.nim) {
                return P;
            }
            P = P->next;
        } while (P != L.First);
    }
    return Nil;
}

// Menampilkan isi list
void printInfo(List L) {
    if (L.First != Nil) {
        address P = L.First;
        cout << "Isi Data Mahasiswa :" << endl;
        do {
            cout << "Nama : " << P->info.nama << endl;
            cout << "NIM  : " << P->info.nim << endl;
            cout << "L/P  : " << P->info.jenis_kelamin << endl;
            cout << "IPK  : " << P->info.ipk << endl;
            cout << "----------------------" << endl;
            P = P->next;
        } while (P != L.First);
    } else {
        cout << "List kosong" << endl;
    }
}