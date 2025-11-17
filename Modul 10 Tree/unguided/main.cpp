#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Halo Dunia" << endl;
    
    alamat akarUtama = NULL; 
    tambahData(akarUtama, 1);
    tambahData(akarUtama, 2);
    tambahData(akarUtama, 6);
    tambahData(akarUtama, 4);
    tambahData(akarUtama, 5);
    tambahData(akarUtama, 3);
    tambahData(akarUtama, 6);
    tambahData(akarUtama, 7);
    
    cout << "\nUrutan In-Order: ";
    cetakInOrder(akarUtama); 
    cout << endl;

    cout << "\n Output Bagian 2 " << endl;
    cout << "Tinggi Pohon    : " << cariKedalaman(akarUtama) << endl;
    cout << "Total Simpul    : " << hitungTotalSimpul(akarUtama) << endl;
    cout << "Jumlah Nilai    : " << jumlahkanSemuaData(akarUtama) << endl;

    cout << "\n Output Bagian 3" << endl;
    cout << "Urutan Pre-Order  : ";
    cetakPreOrder(akarUtama);
    cout << endl;
    
    cout << "Urutan Post-Order : ";
    cetakPostOrder(akarUtama);
    cout << endl;

    return 0;
}