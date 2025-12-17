#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
using namespace std;

typedef int infotipeinduk;
typedef int infotipeanak;

struct elemen_list_anak;
struct elemen_list_induk;

typedef elemen_list_induk* address_induk;
typedef elemen_list_anak*  address_anak;

struct listanak {
    address_anak first;
    address_anak last;
};

struct elemen_list_anak {
    infotipeanak info;
    address_anak next;
    address_anak prev;
};

struct listinduk {
    address_induk first;
    address_induk last;
};

struct elemen_list_induk {
    infotipeinduk info;
    listanak anak;         
    address_induk next;
    address_induk prev;
};

// membuat list kosong
void CreateListInduk(listinduk &L);
void CreateListAnak(listanak &L);

// alokasi / dealokasi
address_induk alokasiInduk(infotipeinduk X);
void dealokasiInduk(address_induk P);

address_anak alokasiAnak(infotipeanak X);
void dealokasiAnak(address_anak P);

// find element
address_induk findElmInduk(listinduk L, infotipeinduk X);
address_anak findElmAnak(listanak L, infotipeanak X);

// insert induk
void insertFirstInduk(listinduk &L, address_induk P);
void insertLastInduk(listinduk &L, address_induk P);
void insertAfterInduk(listinduk &L, address_induk Prec, address_induk P);

// insert anak
void insertFirstAnak(listanak &L, address_anak P);
void insertLastAnak(listanak &L, address_anak P);
void insertAfterAnak(listanak &L, address_anak Prec, address_anak P);

// delete induk
void deleteFirstInduk(listinduk &L, address_induk &P);
void deleteLastInduk(listinduk &L, address_induk &P);
void deleteAfterInduk(listinduk &L, address_induk Prec, address_induk &P);

// delete anak
void deleteFirstAnak(listanak &L, address_anak &P);
void deleteLastAnak(listanak &L, address_anak &P);
void deleteAfterAnak(listanak &L, address_anak Prec, address_anak &P);

// hitung elemen
int nBelas(listinduk L);
int nBilas(listanak L);

// print
void printInfoInduk(listinduk L);
void printInfoAnak(listanak L);

#endif