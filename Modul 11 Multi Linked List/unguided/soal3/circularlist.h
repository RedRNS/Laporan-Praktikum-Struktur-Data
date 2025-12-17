#ifndef CIRCULARLIST_H_INCLUDED
#define CIRCULARLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

// Struktur data mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
    
    // Copy assignment operator
    mahasiswa& operator=(const mahasiswa& other) {
        if (this != &other) {
            nama = other.nama;
            nim = other.nim;
            jenis_kelamin = other.jenis_kelamin;
            ipk = other.ipk;
        }
        return *this;
    }
};

typedef mahasiswa infotype;

// Pointer ke elemen list
typedef struct ElmList *address;

// Struktur elemen list
struct ElmList {
    infotype info;
    address next;
};

// Struktur list
struct List {
    address First;
};

// Membuat list kosong
void createList(List &L);

// Alokasi node baru
address alokasi(infotype x);

// Menghapus node
void dealokasi(address &P);

// Insert data di awal list
void insertFirst(List &L, address P);

// Insert data setelah node tertentu
void insertAfter(List &L, address Prec, address P);

// Insert data di akhir list
void insertLast(List &L, address P);

// Hapus data pertama
void deleteFirst(List &L, address &P);

// Hapus data setelah node tertentu
void deleteAfter(List &L, address Prec, address &P);

// Hapus data terakhir
void deleteLast(List &L, address &P);

// Mencari data berdasarkan NIM
address findElm(List L, infotype x);

// Menampilkan seluruh isi list
void printInfo(List L);

#endif