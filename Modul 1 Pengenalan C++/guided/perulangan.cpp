#include <iostream>
using namespace std;

// Contoh 1: Perulangan FOR
void contohFOR() {
    int jum;
    cout << "\n=== Contoh FOR Loop ===" << endl;
    cout << "Jumlah perulangan: ";
    cin >> jum;
    for (int i = 0; i < jum; i++) {
        cout << "Perulangan ke-" << (i + 1) << endl;
    }
}

// Contoh 2: Perulangan WHILE
void contohWHILE() {
    int jum, i = 0;
    cout << "\n=== Contoh WHILE Loop ===" << endl;
    cout << "Jumlah perulangan: ";
    cin >> jum;
    while (i < jum) {
        cout << "Perulangan ke-" << (i + 1) << endl;
        i++;
    }
}

// Contoh 3: Perulangan DO-WHILE
void contohDOWHILE() {
    int jum, i = 0;
    cout << "\n=== Contoh DO-WHILE Loop ===" << endl;
    cout << "Jumlah perulangan: ";
    cin >> jum;
    do {
        cout << "Perulangan ke-" << (i + 1) << endl;
        i++;
    } while (i < jum);
}

int main()
{
    int pilihan;
    cout << "=== Program Struktur Perulangan ===" << endl;
    cout << "1. Contoh FOR" << endl;
    cout << "2. Contoh WHILE" << endl;
    cout << "3. Contoh DO-WHILE" << endl;
    cout << "Pilih contoh (1-3): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            contohFOR();
            break;
        case 2:
            contohWHILE();
            break;
        case 3:
            contohDOWHILE();
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
    }

    return 0;
}