# <h1 align="center">Laporan Praktikum Modul 8 <br>Queue</h1>

<p align="center">Renisa Assyifa Putri - 103112400123</p>

## Dasar Teori - Queue

Modul ke-8 ini membahas struktur data Queue atau antrean. Queue adalah struktur data linear yang menerapkan prinsip FIFO (First In, First Out), artinya data yang masuk pertama kali akan keluar pertama kali juga. Prinsip ini sama seperti antrean di kehidupan sehari-hari, misalnya antrean di bank atau kasir, dimana orang yang datang lebih dulu akan dilayani lebih dulu.

Queue memiliki dua ujung penting yaitu front (depan) sebagai tempat data keluar dan rear (belakang) sebagai tempat data masuk. Operasi dasar yang ada dalam Queue meliputi enqueue untuk menambahkan data di posisi belakang, dequeue untuk mengeluarkan data dari posisi depan, dan peek untuk melihat data terdepan tanpa menghapusnya. Selain itu ada fungsi validasi seperti isEmpty untuk mengecek apakah queue kosong dan isFull untuk mengecek apakah kapasitas sudah penuh.

Queue dapat diimplementasikan dengan dua cara yaitu menggunakan Array atau Linked List. Implementasi dengan Array biasa memiliki kelemahan karena ruang di bagian depan menjadi tidak terpakai saat indeks bergerak. Untuk mengatasinya digunakan Circular Queue yang membuat indeks terakhir terhubung kembali ke indeks awal sehingga memori lebih efisien. Sedangkan implementasi dengan Linked List lebih fleksibel karena kapasitasnya dinamis dan dapat bertambah sesuai kebutuhan tanpa terbatas oleh ukuran array. Queue sangat penting dalam komputasi, misalnya untuk CPU scheduling, antrean printer, dan algoritma Breadth First Search (BFS).

## Guided

### Guided 1

```cpp
#include <iostream>
using namespace std;

#define MAX 5

struct Queue {
    int data[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(Queue Q) {
    return (Q.tail == MAX - 1);
}

void printQueue(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue Kosong\n";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.data[i] << " ";
        }
        cout << endl;
    }
}

void enqueue(Queue &Q, int x) {
    if (isFull(Q)) {
        cout << "Queue Penuh\n";
    } else {
        if (isEmpty(Q)) {
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.data[Q.tail] = x;
        cout << "Enqueue: " << x << endl;
    }
}

void dequeue(Queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue Kosong\n";
    } else {
        cout << "Dequeue: " << Q.data[Q.head] << endl;
        if (Q.head == Q.tail) {
            Q.head = Q.tail = -1;
        } else {
            for (int i = Q.head; i < Q.tail; i++) {
                Q.data[i] = Q.data[i + 1];
            }
            Q.tail--;
        }
    }
}

int main() {
    Queue Q;
    createQueue(Q);

    enqueue(Q, 5);
    enqueue(Q, 2);
    enqueue(Q, 7);
    printQueue(Q);

    dequeue(Q);
    printQueue(Q);

    enqueue(Q, 4);
    enqueue(Q, 9);
    printQueue(Q);

    dequeue(Q);
    dequeue(Q);
    printQueue(Q);
	return 0;
	}
```

#### Output Guided 1

![Output](Output/Output-Guided1-Modul8.png)

#### Penjelasan Guided 1

Program ini membuat struktur data Queue menggunakan array statis dengan kapasitas maksimal 5 elemen. Variabel `head` dan `tail` berfungsi sebagai penunjuk indeks depan dan belakang queue, keduanya diinisialisasi dengan nilai -1 yang menandakan queue masih kosong.

Logika yang digunakan adalah pergeseran elemen (shifting). Saat operasi `enqueue()` dilakukan, data baru ditambahkan di posisi `tail`. Saat operasi `dequeue()`, data di posisi `head` (indeks 0) diambil kemudian semua data di belakangnya digeser maju satu posisi untuk mengisi tempat yang kosong. Cara ini memastikan elemen terdepan selalu berada di indeks 0. Jika setelah penghapusan queue menjadi kosong, maka `head` dan `tail` akan direset ke -1. Pada fungsi `main()`, program menguji fungsi-fungsi tersebut dengan memasukkan beberapa data, menampilkannya, kemudian menghapus beberapa data untuk memvalidasi prinsip FIFO.
## Unguided

### Soal 1

> Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file "queue.h":

```
Type infotype: integer
Type Queue: <
    info : array [5] of infotype {index array dalam C++
    dimulai dari 0}
    head, tail : integer
>
procedure CreateQueue (input/output Q: Queue)
function isEmptyQueue (Q: Queue) → boolean
function isFullQueue (Q: Queue) → boolean
procedure enqueue (input/output Q: Queue, input x: infotype)
function dequeue (input/output Q: Queue) → infotype
procedure printInfo (input Q: Queue)
```

> Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
   queue Alternatif 1 (head diam, tail bergerak).

```
int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    return 0;
}
```

#### 1. queue.h

```cpp
#ifndef QUEUE_H
#define QUEUE_H

const int MAX = 5;

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```

#### 2. queue.cpp

```cpp
#include <iostream>
#include "queue.h"

using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.tail == -1);
}bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Full!" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue Empty!" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    for (int i = 0; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;
    if (Q.tail < 0) {
        Q.head = Q.tail = -1;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t| ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }
    for (int i = 0; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}
```

#### 3. main.cpp

```cpp
#include <iostream>
#include "queue.h"

using namespace std;
int main() {
    cout << "Hello world!" << endl;
    cout << "---------------------------" << endl;
    cout << "H - T\t: Queue Info" << endl;
    cout << "---------------------------" << endl;

    Queue Q;
    CreateQueue(Q);
    printInfo(Q);

    enqueue(Q, 5);  printInfo(Q);
    enqueue(Q, 2);  printInfo(Q);
    enqueue(Q, 7);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);
    enqueue(Q, 4);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);
    return 0;
}
```

### Soal 2

> Buatlah implementasi ADT Queue pada file "queue.cpp" dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

#### 1. queue.h
```cpp
#ifndef QUEUE_H
#define QUEUE_H

const int MAX = 5;

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```

#### 2. queue.cpp

```cpp
#include <iostream>
#include "queue.h"

using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Full!" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue Empty!" << endl;
        return -1;
    }
    infotype x = Q.info[Q.head];
    Q.head++;
    if (Q.head > Q.tail) {
        Q.head = Q.tail = -1;
    }
    return x;
}
void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t| ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}
```
### main.cpp
```cpp
#include <iostream>
#include "queue.h"

using namespace std;
int main() {
    cout << "Hello world!" << endl;
    cout << "---------------------------" << endl;
    cout << "H - T\t: Queue Info" << endl;
    cout << "---------------------------" << endl;

    Queue Q;
    CreateQueue(Q);
    printInfo(Q);

    enqueue(Q, 5);  printInfo(Q);
    enqueue(Q, 2);  printInfo(Q);
    enqueue(Q, 7);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);
    enqueue(Q, 4);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);
    return 0;
}
```

#### 3. main.cpp

```cpp
#include <iostream>
#include "queue.h"

using namespace std;
int main() {
    cout << "Hello world!" << endl;
    cout << "---------------------------" << endl;
    cout << "H - T\t: Queue Info" << endl;
    cout << "---------------------------" << endl;

    Queue Q;
    CreateQueue(Q);
    printInfo(Q);

    enqueue(Q, 5);  printInfo(Q);
    enqueue(Q, 2);  printInfo(Q);
    enqueue(Q, 7);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);
    enqueue(Q, 4);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);
    return 0;
}
```

### Soal 3

> Buatlah implementasi ADT Queue pada file "queue.cpp" dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

#### 1. queue.h
```cpp
#ifndef QUEUE_H
#define QUEUE_H

const int MAX = 5;

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```

#### 2. queue.cpp

```cpp
#include <iostream>
#include "queue.h"
using namespace std;

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue Full!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue Empty!" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t| ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}
```

#### 3. main.cpp

```cpp
#include <iostream>
#include "queue.h"

using namespace std;
int main() {
    cout << "Hello world!" << endl;
    cout << "---------------------------" << endl;
    cout << "H - T\t: Queue Info" << endl;
    cout << "---------------------------" << endl;

    Queue Q;
    CreateQueue(Q);
    printInfo(Q);

    enqueue(Q, 5);  printInfo(Q);
    enqueue(Q, 2);  printInfo(Q);
    enqueue(Q, 7);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);
    enqueue(Q, 4);  printInfo(Q);
    dequeue(Q);     printInfo(Q);
    dequeue(Q);     printInfo(Q);
    return 0;
}
```

#### Output Soal 1 - 3

![Output](Output/Output-Unguided.png)

#### Penjelasan Soal 1 - 3

Ketiga soal ini menunjukkan tiga cara berbeda dalam mengimplementasikan ADT Queue dengan C++. Walaupun semuanya menggunakan fungsi dasar yang sama yaitu `enqueue()` dan `dequeue()`, cara pengelolaan indeks dan memorinya memiliki perbedaan mendasar.

**Alternatif 1 (Soal 1)** menggunakan metode pergeseran elemen dimana posisi `head` selalu tetap di indeks 0. Setiap kali `dequeue` dipanggil, semua elemen yang tersisa akan digeser ke depan untuk mengisi posisi yang kosong. Kelebihannya data terlihat rapi dari awal array, namun kelemahannya membutuhkan waktu lebih lama karena harus melakukan looping untuk menggeser elemen setiap kali ada data yang keluar.

**Alternatif 2 (Soal 2)** menggunakan metode floating head dan tail tanpa pergeseran data. Saat `dequeue` dipanggil, indeks `head` hanya dinaikkan saja. Metode ini lebih cepat karena tidak perlu menggeser data, namun kelemahannya terjadi pemborosan memori karena ruang di depan yang sudah ditinggalkan `head` tidak dapat digunakan lagi sampai queue direset.

**Alternatif 3 (Soal 3)** menerapkan konsep Circular Queue yang merupakan solusi paling optimal. Metode ini membuat indeks `tail` yang sudah mencapai akhir array dapat kembali ke indeks 0 jika posisi tersebut kosong. Dengan operasi modulus, memori menjadi sangat efisien karena tidak ada ruang yang terbuang dan tidak perlu proses pergeseran data.

Secara keseluruhan, ketiga implementasi berhasil menerapkan prinsip FIFO dengan baik. Perbedaan output yang terlihat disebabkan oleh perbedaan strategi pengelolaan indeks array yang digunakan.

## Referensi

[1] Modul Praktikum Struktur Data – Queue, Universitas Negeri Malang. https://elektro.um.ac.id/wp-content/uploads/2016/04/Struktur-Data-Modul-Praktikum-5-Queue.pdf

[2] Abdillah, G. (2021). "Struktur Data Queue: Konsep, Operasi, dan Implementasi." Trivusi. https://trivusi.web.id/2022/07/struktur-data-queue.html

[3] Khotimah, K. (2020). "Implementasi Queue Menggunakan Array dan Linked List dalam Pemrograman C++." Jurnal Teknologi dan Sistem Informasi, 8(2). https://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/download/4264/pdf








