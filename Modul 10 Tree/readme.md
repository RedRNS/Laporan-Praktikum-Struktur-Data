# <h1 align="center">Laporan Praktikum Modul 10 <br>Tree</h1>

<p align="center">Renisa Assyifa Putri - 103112400123</p>

## Dasar Teori
Rekursi merupakan sebuah teknik pemrograman di mana sebuah fungsi memanggil dirinya sendiri untuk menyelesaikan suatu masalah secara berulang. Pendekatan ini menawarkan keuntungan berupa kode yang lebih mudah dibaca (readability), terstruktur dalam modul-modul kecil (modularity), dan efisien karena dapat digunakan kembali (reusability). Agar fungsi rekursif dapat berjalan dengan benar dan tidak terjebak dalam perulangan tak terbatas (infinite loop), diperlukan dua komponen kunci: base case sebagai kondisi penghenti, dan recursive step yang melakukan pemanggilan diri sendiri hingga kondisi berhenti tercapai. Walaupun teknik ini sering menghasilkan kode yang lebih ringkas, rekursi memiliki kelemahan berupa penggunaan memori yang lebih besar untuk stack activation record dan waktu pemrosesan yang cenderung lebih lambat dibandingkan metode iteratif (looping biasa).

Dalam struktur data, Tree (pohon) didefinisikan sebagai struktur non-linear yang bersifat hirarkis, digambarkan sebagai graf terhubung yang tidak mengandung sirkuit. Elemen paling atas dalam tree disebut Root (akar) yang tidak memiliki pendahulu, sedangkan elemen lainnya memiliki tepat satu induk (parent). Istilah-istilah kunci dalam tree meliputi Leaf (daun) untuk node yang tidak memiliki anak, Internal Nodes untuk simpul cabang, serta Height (tinggi) atau Depth untuk mengukur kedalaman maksimum dari struktur tersebut. Salah satu varian populer adalah Binary Tree, di mana setiap node dibatasi maksimal memiliki dua percabangan (anak).

Implementasi spesifik dari Binary Tree yang banyak digunakan adalah Binary Search Tree (BST). BST menerapkan aturan pengurutan data yang ketat: nilai pada simpul anak kiri (Left Child) harus selalu lebih kecil dari induknya, sedangkan nilai pada simpul anak kanan (Right Child) harus lebih besar. Struktur ini sangat menguntungkan untuk efisiensi operasi pencarian (searching), penyisipan (insertion), dan penghapusan (deletion). Untuk membaca data dalam tree, terdapat tiga metode traversal utama: Pre-order (mencetak Root dahulu, lalu Kiri, kemudian Kanan), In-order (Kiri, Root, Kanan), dan Post-order (Kiri, Kanan, baru Root).
## Guided

### Guided 1
```c++
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *kiri, *kanan;
};

Node *buatNode(int nilai)
{
    Node *baru = new Node();
    baru->data = nilai;
    baru->kiri = baru->kanan = NULL;
    return baru;
}

Node *insert(Node *root, int nilai)
{
    if (root == NULL)
        return buatNode(nilai);
    
    if (nilai < root->data)
        root->kiri = insert(root->kiri, nilai);
    else if (nilai > root->data)
        root->kanan = insert(root->kanan, nilai);

    return root;
}

Node *search(Node *root, int nilai)
{
    if (root == NULL || root->data == nilai)
        return root;

    if (nilai < root->data)
        return search(root->kiri, nilai);

    return search(root->kanan, nilai);
}

Node *nilaiTerkecil(Node *node)
{
    Node *current = node;
    while (current && current->kiri != NULL)
        current = current->kiri;

        return current;
}

Node *hapus(Node *root, int nilai)
{
    if (root == NULL)
        return root;

    if (nilai < root->data)
        root->kiri = hapus(root->kiri, nilai);
    else if (nilai > root->data)
        root->kanan = hapus(root->kanan, nilai);
    else
    {
        if (root->kiri == NULL)
        {
            Node *temp = root->kanan;
            delete root;
            return temp;
        }
        else if (root->kanan == NULL){
            Node *temp = root->kiri;
            delete root;
            return temp;
        }
        Node *temp = nilaiTerkecil(root->kanan);
        root->data = temp->data;
        root->kanan = hapus(root->kanan, temp->data);
    }
    return root;
}

Node *update(Node *root, int Lama, int baru)
{
    if (search(root, Lama) != NULL)
    {
        root = hapus(root, Lama);
        root = insert(root, baru);
        cout << "Data " << Lama << " diupdate menjadi " << baru << endl;
    }
    else
    {
        cout << "Data " << Lama << " tidak ditemukan!" << endl;
    }
    return root;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

int main()
{
    Node *root = NULL;

    cout << "=== 1. INSERT DATA ===" << endl;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 3);
    insert(root, 7);
    insert(root, 15);
    insert(root, 25);
    cout << "Data berhasil dimasukan.\n" << endl;

    cout << "=== 2. TAMPILKAN TREE (TRAVELSAL) ===" << endl;
    cout << "PreOrder : ";
    preOrder(root);
    cout << endl;
    cout << "InOrder : ";
    inOrder(root);
    cout << endl;
    cout << "PostOrder : ";
    postOrder(root);
    cout << "\n" << endl;

    cout << "=== 3. TEST SEARCH ===" << endl;
    int cari1 = 7, cari2 = 99;
    cout << "Cari " << cari1 << ": " << (search(root,cari1) ? "Ketemu" : "Tidak Aada") << endl;
    cout << "Cari " << cari2 << ": " << (search(root,cari2) ? "Ketemu" : "Tidak Aada") << endl;
    cout << endl;

    cout << "=== 4. TEST UPDATE ===" << endl;
    root = update(root, 5, 8);
    cout << "Hasil Order setelah update: ";
    cout << endl;
    cout << endl;

    cout << "PreOrder : ";
    preOrder(root);
    cout << endl;
    cout << "InOrder : ";
    inOrder(root);
    cout << endl;
    cout << "PostOrder : ";
    postOrder(root);
    cout << "\n" << endl;

    cout << "== 5. TEST DELETE ===" << endl;
    cout << "Menghapus angka 20..." << endl;
    root = hapus(root, 20);

    cout << "PreOrder : ";
    preOrder(root);
    cout << endl;
    cout << "InOrder : ";
    inOrder(root);
    cout << endl;
    cout << "PostOrder : ";
    postOrder(root);
    cout << "\n" << endl;

    return 0;
}
```

> Output
> 
> ![Screenshot bagian x](OUTPUT/guided1.png)

Program di atas menyajikan implementasi Binary Search Tree (BST) secara utuh dalam satu file (single-file implementation). Fitur yang disediakan mencakup operasi CRUD (Create, Read, Update, Delete) secara lengkap. Keunggulan dari kode ini adalah penanganan logika yang detail, mulai dari pencarian nilai (searching), mekanisme pembaruan data yang menggabungkan proses hapus dan sisip ulang, hingga algoritma penghapusan node (delete) yang secara adaptif menangani berbagai skenario (node tanpa anak, satu anak, atau dua anak).

## UNGUIDED

#### bstree.h
```c++
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
```
#### bstree.cpp
```c++
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
```
#### main.cpp
```c++
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
```
> Output soal 1,2,3
> 
> ![Screenshot bagian x](OUTPUT/unguided1.png)

Kode program ini mendemonstrasikan implementasi Binary Search Tree (BST) dengan pendekatan modular, di mana struktur kode dipecah menjadi tiga bagian: file header (.h), file implementasi fungsi (.cpp), dan program utama (main). Fokus utama program ini adalah operasi-operasi esensial pada BST, seperti penyisipan node (insert), serta tiga jenis metode penelusuran data (traversal). Selain itu, terdapat fungsi statistik yang berguna untuk menganalisis properti tree, seperti menghitung kedalaman maksimum (depth), total jumlah node, dan penjumlahan seluruh nilai data yang ada dalam tree.


## Referensi

1. GeeksforGeeks. (2025). Binary Search Tree Data Structure. Diakses dari https://www.geeksforgeeks.org/cpp/cpp-binary-search-tree/ pada 29 November 2025.

2. GeeksforGeeks. (2025). Deletion in Binary Search Tree. Diakses dari https://www.geeksforgeeks.org/dsa/deletion-in-binary-search-tree/ pada 29 November 2025.

3. GeeksforGeeks. (2025). Tree Traversals (Inorder, Preorder and Postorder). Diakses dari https://www.geeksforgeeks.org/dsa/tree-traversals-inorder-preorder-and-postorder/ pada 29 November 2025.