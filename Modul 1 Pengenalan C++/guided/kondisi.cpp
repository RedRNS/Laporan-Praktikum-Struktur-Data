#include <iostream>
using namespace std;

// Contoh 1: Struktur IF sederhana
void contohIF() {
    double tot_pembelian, diskon;
    cout << "\n=== Contoh IF Sederhana ===" << endl;
    cout << "Total pembelian: Rp";
    cin >> tot_pembelian;
    diskon = 0;
    if (tot_pembelian >= 100000)
        diskon = 0.05 * tot_pembelian;
    cout << "Besar diskon = Rp" << diskon << endl;
}

// Contoh 2: Struktur IF-ELSE
void contohIFELSE() {
    double tot_pembelian, diskon;
    cout << "\n=== Contoh IF-ELSE ===" << endl;
    cout << "Total pembelian: Rp";
    cin >> tot_pembelian;
    if (tot_pembelian >= 100000)
        diskon = 0.05 * tot_pembelian;
    else
        diskon = 0;
    cout << "Besar diskon = Rp" << diskon << endl;
}

// Contoh 3: Struktur SWITCH-CASE
void contohSWITCH() {
    int kode_hari;
    cout << "\n=== Contoh SWITCH-CASE ===" << endl;
    cout << "Menentukan hari kerja/libur\n" << endl;
    cout << "1=Senin 3=Rabu 5=Jumat 7=Minggu" << endl;
    cout << "2=Selasa 4=Kamis 6=Sabtu" << endl;
    cout << "Masukkan kode hari: ";
    cin >> kode_hari;
    switch (kode_hari)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        cout << "Hari Kerja" << endl;
        break;
    case 6:
    case 7:
        cout << "Hari Libur" << endl;
        break;
    default:
        cout << "Kode masukan salah!!!" << endl;
    }
}

int main()
{
    int pilihan;
    cout << "=== Program Struktur Kontrol Percabangan ===" << endl;
    cout << "1. Contoh IF" << endl;
    cout << "2. Contoh IF-ELSE" << endl;
    cout << "3. Contoh SWITCH-CASE" << endl;
    cout << "Pilih contoh (1-3): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            contohIF();
            break;
        case 2:
            contohIFELSE();
            break;
        case 3:
            contohSWITCH();
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
    }

    return 0;
}