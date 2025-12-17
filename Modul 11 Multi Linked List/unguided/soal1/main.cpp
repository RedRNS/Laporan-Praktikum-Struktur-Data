#include <iostream>
#include "multilist.h"
using namespace std;

int main() {

    listinduk LI;
    CreateListInduk(LI);

    cout << "==== INSERT INDUK ====" << endl;
    address_induk P1 = alokasiInduk(10);
    address_induk P2 = alokasiInduk(20);
    address_induk P3 = alokasiInduk(30);

    insertFirstInduk(LI, P1);
    insertLastInduk(LI, P2);   
    insertLastInduk(LI, P3);   

    printInfoInduk(LI);
    cout << endl;

    cout << "==== INSERT ANAK untuk induk 20 ====" << endl;
    address_induk parent = findElmInduk(LI, 20);

    if (parent != NULL) {
        address_anak A1 = alokasiAnak(101);
        address_anak A2 = alokasiAnak(102);
        address_anak A3 = alokasiAnak(103);

        insertFirstAnak(parent->anak, A1);     
        insertLastAnak(parent->anak, A2);     
        insertLastAnak(parent->anak, A3);    
    }

    printInfoInduk(LI);
    cout << endl;

    cout << "==== INSERT ANAK untuk induk 10 ====" << endl;
    parent = findElmInduk(LI, 10);

    if (parent != NULL) {
        insertLastAnak(parent->anak, alokasiAnak(999)); 
    }

    printInfoInduk(LI);
    cout << endl;


    cout << "==== DELETE ELEMENT ANAK pada induk 20 ====" << endl;
    parent = findElmInduk(LI, 20);

    if (parent != NULL) {
        address_anak delA;
        deleteFirstAnak(parent->anak, delA);
        dealokasiAnak(delA);
    }

    printInfoInduk(LI);
    cout << endl;


    cout << "==== DELETE ELEMENT INDUK (DELETE FIRST INDUK) ====" << endl;
    address_induk delI;
    deleteFirstInduk(LI, delI);
    dealokasiInduk(delI);

    printInfoInduk(LI);
    cout << endl;


    cout << "==== FIND ELEMEN INDUK ====" << endl;
    address_induk found = findElmInduk(LI, 30);
    if (found != NULL) {
        cout << "Induk 30 ditemukan!" << endl;
    } else {
        cout << "Induk 30 tidak ditemukan!" << endl;
    }

    cout << endl;

    cout << "==== PRINT JUMLAH ELEMEN ====" << endl;
    cout << "Jumlah Induk = " << nBelas(LI) << endl;

    if (findElmInduk(LI, 20) != NULL) {
        cout << "Jumlah Anak pada induk 20 = "
             << nBilas(findElmInduk(LI, 20)->anak)
             << endl;
    }

    cout << endl;

    cout << "==== PROGRAM SELESAI ====" << endl;

    return 0;
}