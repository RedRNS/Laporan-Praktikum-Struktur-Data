#ifndef POHON_H
#define POHON_H
#include <iostream>

using namespace std;

typedef int tipeInfo;
typedef struct Simpul *alamat;

struct Simpul {
    tipeInfo data;
    alamat kiri;
    alamat kanan;
};

alamat buatSimpul(tipeInfo x);
void tambahData(alamat &akar, tipeInfo x);
void cetakInOrder(alamat akar);

int hitungTotalSimpul(alamat akar);
int jumlahkanSemuaData(alamat akar);
int cariKedalaman(alamat akar);
void cetakPreOrder(alamat akar);
void cetakPostOrder(alamat akar);

#endif