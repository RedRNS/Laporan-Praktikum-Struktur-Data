# <h1 align="center">Laporan Praktikum Modul 7 <br>Stack</h1>

<p align="center">Renisa Assyifa Putri - 103112400123</p>

## Dasar Teori

Stack atau tumpukan adalah salah satu jenis struktur data linear yang menerapkan mekanisme LIFO (Last In, First Out). Artinya, data yang paling akhir dimasukkan justru akan menjadi data yang pertama kali dikeluarkan. Dalam struktur ini, akses data hanya dapat dilakukan melalui satu pintu saja, yaitu bagian paling atas yang dikenal dengan istilah top.

Terdapat beberapa operasi fundamental dalam pengelolaan Stack, antara lain:
- Push: Menyisipkan elemen baru ke posisi paling atas (top).
- Pop: Mengambil atau menghapus elemen yang berada di posisi paling atas.
- Peek/Top: Melihat nilai data pada posisi teratas tanpa menghapusnya.
- isEmpty: Validasi untuk mengecek apakah stack dalam keadaan kosong atau berisi.

Secara implementasi, Stack dapat dibangun menggunakan Array atau Linked List. Penggunaan Array cenderung lebih mudah namun memiliki batasan ukuran memori yang statis (bisa terjadi stack overflow jika penuh). Sebaliknya, implementasi dengan Linked List memungkinkan ukuran stack yang dinamis karena setiap data disimpan dalam node yang saling terhubung, sehingga lebih fleksibel dalam manajemen memori. Stack sangat krusial dalam dunia komputasi, sering digunakan untuk manajemen memori (call stack), fitur undo-redo di aplikasi editor, hingga notasi matematika (seperti konversi infix ke postfix). 

## Guided

### Guided 1

```cpp
#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* next;
};

bool isEmpty(Node *top) {
    return top == nullptr;
}

void push(Node *&top, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop(Node *&top)
{
    if (isEmpty(top)){
        cout << "Stack Kosong, Tidak Bisa Pop" << endl;
        return 0;
    }

    int poppedData = top->data;
    Node *temp = top;
    top = top->next;

    delete temp;
    return poppedData;
}

void show(Node *top) {
    if (isEmpty(top)) {
        cout << "Stack kosong.\n";
        return;
    }

    cout << "TOP -> ";
    Node *temp = top;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    Node *stack = nullptr;

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    cout << "Isi Stack setelah push:\n";
    show(stack);

    cout << "Pop: " << pop(stack) << endl;

    cout << "Menampilkan sisa stack: \n";
    show(stack);

    return 0;

}
```

#### Output Guided 1

![Screenshot guided 1](output/Screenshot_Guided.png)

#### Penjelasan Guided 1

Program di atas mendemonstrasikan pembuatan struktur data Stack dengan pendekatan Linked List menggunakan bahasa C++. Berbeda dengan array, di sini setiap elemen direpresentasikan sebagai sebuah `struct Node` yang menyimpan nilai (`data`) dan pointer (`next`) ke elemen di bawahnya.

Fungsi-fungsi utama meliputi `push()` yang menyisipkan node baru di bagian kepala (head/top), `pop()` yang memutus node teratas untuk mengambil datanya, serta `isEmpty()` untuk validasi. Fungsi `show()` bertugas melakukan iterasi (perulangan) dari node teratas sampai `NULL` untuk mencetak isi stack. Pada fungsi `main()`, simulasi dilakukan dengan memasukkan angka 10, 20, dan 30, lalu melakukan satu kali operasi `pop()` untuk membuktikan prinsip LIFO bekerja, di mana angka 30 (yang terakhir masuk) adalah yang pertama keluar.

## Unguided

### Soal 1

Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”

```
Type infotype : integer
Type Stack <
info : array [20] of integer
top : integer
>
procedure CreateStack( input/output S : Stack )
procedure push(input/output S : Stack,
	input x : infotype)
function pop(input/output t S : Stack )
	→ infotype
procedure printInfo( input S : Stack )
procedure balikStack(input/output S :
	Stack )
```

Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp”

```cpp
int main()
{
    cout << "Hello world!" <<
endl;
    Stack S;
    createStack(S);
    Push(S,3);
    Push(S,4);
    Push(S,8);
    pop(S)
    Push(S,2);
    Push(S,3);
    pop(S);
    Push(S,9);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

stack.h

```
#ifndef STACK_H
#define STACK_H

#define MAX 20
typedef int infotype;

typedef struct {
    infotype info[MAX];
    int top;
} Stack;

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
```

#### 2. stack.cpp

```cpp
#include <iostream>
#include "stack.h"

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}


void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong!" << endl;
        return -9999;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}
```

#### 3. main.cpp

```cpp
#include <iostream>
#include "stack.h"

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}


void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong!" << endl;
        return -9999;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}
```

#### Output Soal 1

![Screenshot unguided 1](output/Screenshot_Soal1.png)

#### Penjelasan Soal 1

Pada latihan ini, implementasi Stack dilakukan menggunakan Array statis dengan kapasitas maksimal 20 elemen sebagaimana didefinisikan dalam header file (`stack.h`). Variabel `top` diinisialisasi dengan nilai -1 pada fungsi `createStack()` sebagai penanda bahwa stack masih kosong.

Fungsi operasional meliputi `push()` untuk menambah data (dengan menaikkan indeks `top`), `pop()` untuk mengambil data (menurunkan indeks `top`), dan `printInfo()` untuk menampilkan seluruh data dari indeks `top` ke 0. Selain itu, terdapat prosedur tambahan `balikStack()` yang berfungsi membalik urutan elemen stack dengan cara memindahkan seluruh isi stack utama ke stack sementara (temporary stack). Hasil akhirnya, urutan data yang awalnya [9, 2, 4, 3] berubah urutannya menjadi terbalik setelah prosedur dijalankan.

### Soal 2

> Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)

```cpp
int main()
{
	cout << "Hello world!" << endl;
	Stack S;
	createStack(S);
	pushAscending(S,3);
	pushAscending(S,4);
	pushAscending(S,8);
	pushAscending(S,2);
	pushAscending(S,3);
	pushAscending(S,9);
	printInfo(S);
	cout<<"balik stack"<<endl;
	balikStack(S);
	printInfo(S);
	return 0;
}
```

#### 1. main.cpp

```cpp
#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

#### 2. stack.cpp

```cppcpp
#include <iostream>
#include "stack.h"

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong!" << endl;
        return -9999;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}
```

#### 3. stack.h

```cpp
#ifndef STACK_H
#define STACK_H

#define MAX 20
typedef int infotype;

typedef struct {
    infotype info[MAX];
    int top;
} Stack;

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
#endif
```

#### Output Soal 2

![Screenshot unguided 2](output/Screenshot_Soal2.png)

#### Penjelasan Soal 2

Pada soal kedua, program dimodifikasi dengan penambahan prosedur `pushAscending()`. Prosedur ini bertujuan menjaga agar elemen di dalam stack selalu terurut secara menaik (ascending) setiap kali data baru dimasukkan, bukan sekadar menumpuk di atas (top).

Logikanya adalah dengan membandingkan data inputan dengan data di `top`. Jika data di `top` lebih besar dari input, data tersebut dikeluarkan dulu (`pop`) ke stack sementara. Setelah posisi yang tepat ditemukan (atau stack kosong), data inputan baru dimasukkan (`push`), lalu data-data dari stack sementara dikembalikan lagi ke stack utama. Hasil eksekusi menunjukkan bahwa meskipun input dimasukkan secara acak, isi stack tetap tersusun rapi dari nilai terkecil hingga terbesar.

### Soal 3

> Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

```cpp
int main()
{
	cout << "Hello world!" << endl;
	Stack S;
	createStack(S);
	getInputStream(S);
	printInfo(S);
	cout<<"balik stack"<<endl;
	balikStack(S);
	printInfo(S);
	return 0;
}
```

#### 1. main.cpp

```cpp
#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);

    getInputStream(S);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

stack.cpp

```
#include <iostream>
#include "stack.h"

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

infotype pop(Stack &S) {
    if (!isEmpty(S)) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    } else {
        cout << "Stack kosong!" << endl;
        return -9999;
    }
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (!isEmpty(S)) {
        push(temp, pop(S));
    }
    S = temp;
}

void getInputStream(Stack &S) {
    char ch;
    while (true) {
        ch = cin.get();
        if (ch == '\n') break;
        if (ch >= '0' && ch <= '9') {
            push(S, ch - '0');
        }
    }
}
```

stack.h

```
#ifndef STACK_H
#define STACK_H

#define MAX 20
typedef int infotype;

typedef struct {
    infotype info[MAX];
    int top;
} Stack;

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif
```

#### Output Soal 3

![Screenshot unguided 3](output/Screenshot_Soal3.png)

#### Penjelasan Soal 3

Pengembangan terakhir pada soal ketiga adalah penambahan fitur interaktif melalui prosedur `getInputStream()`. Fitur ini memungkinkan program menerima input angka secara kontinu dari pengguna dalam satu baris (seperti mengetik string angka), lalu memecahnya menjadi elemen integer terpisah untuk dimasukkan ke dalam stack.

Menggunakan fungsi `cin.get()`, program membaca input karakter per karakter hingga tombol Enter ditekan. Setiap karakter angka dikonversi menjadi tipe data integer sebelum di-`push` ke dalam stack. Demonstrasi pada `main()` memperlihatkan bagaimana deretan angka yang diketik pengguna langsung tersusun dalam stack, ditampilkan, dan kemudian urutannya dibalik menggunakan fungsi `balikStack()` yang telah dibuat sebelumnya.

## Referensi

[1] Modul Praktikum 4 – Stack, Universitas Negeri Malang. Modul Struktur Data (PDF) https://elektro.um.ac.id/wp-content/uploads/2016/04/Struktur-Data-Modul-Praktikum-4-Stack.pdf

[2] JUTECH. "Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List". Jurnal JUTECH. [Online PDF]. Tersedia: https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/download/4263/pd

[3] Trivusi. (2022). Struktur Data Stack: Pengertian, Karakteristik, dan Kegunaannya. [Online]. Tersedia: https://trivusi.web.id/2022/07/struktur-data-stack.html