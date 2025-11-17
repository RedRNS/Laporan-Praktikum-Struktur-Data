#include "bstree.h"

alamat buatSimpul(tipeInfo x) {
    alamat P = new Simpul;
    if (P != NULL) {
        P->data = x;
        P->kiri = NULL;
        P->kanan = NULL;
    }
    return P;
}

void tambahData(alamat &akar, tipeInfo x) {
    if (akar == NULL) {
        akar = buatSimpul(x);
    } else {
        if (x < akar->data) {
            tambahData(akar->kiri, x); 
        } else if (x > akar->data) {
            tambahData(akar->kanan, x); 
        }
    }
}

void cetakInOrder(alamat akar) {
    if (akar != NULL) {
        cetakInOrder(akar->kiri);
        cout << akar->data << " ";
        cetakInOrder(akar->kanan);
    }
}

void cetakPreOrder(alamat akar) {
    if (akar != NULL) {
        cout << akar->data << " ";
        cetakPreOrder(akar->kiri);
        cetakPreOrder(akar->kanan);
    }
}

void cetakPostOrder(alamat akar) {
    if (akar != NULL) {
        cetakPostOrder(akar->kiri);
        cetakPostOrder(akar->kanan);
        cout << akar->data << " ";
    }
}

int hitungTotalSimpul(alamat akar) {
    if (akar == NULL) {
        return 0;
    } else {
        return 1 + hitungTotalSimpul(akar->kiri) + hitungTotalSimpul(akar->kanan);
    }
}

int jumlahkanSemuaData(alamat akar) {
    if (akar == NULL) {
        return 0;
    } else {
        return akar->data + jumlahkanSemuaData(akar->kiri) + jumlahkanSemuaData(akar->kanan);
    }
}

int cariKedalaman(alamat akar) {
    if (akar == NULL) {
        return 0;
    } else {
        int dalamKiri = cariKedalaman(akar->kiri);
        int dalamKanan = cariKedalaman(akar->kanan);
        
        if (dalamKiri > dalamKanan)
            return (dalamKiri + 1);
        else 
            return (dalamKanan + 1);
    }
}