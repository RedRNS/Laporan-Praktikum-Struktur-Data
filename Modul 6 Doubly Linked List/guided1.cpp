#include <iostream>
using namespace std;

// Struktur Node

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Pointer global
Node* head = nullptr;
Node* tail = nullptr;

// Fungsi : insert depan
void insertDepan(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr) {
        head->prev = newNode;
    } else {
        tail = newNode; // Jika list kosong, tail juga menunjuk ke newNode
    }
    head = newNode;
}

// Fungsi : insert belakang
void insertBelakang(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = tail;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        head = newNode; // Jika list kosong, head juga menunjuk ke newNode
    }
    tail = newNode;
}

// Fungsi : Insert setelah data tertentu
void insertSetelah(int target, int data) {
    Node* current = head;
    while (current != nullptr && current->data != target) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Data " << target << " tidak ditemukan dalam list." << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    } else {
        tail = newNode; // Jika current adalah tail, update tail
    }
}

void hapusDepan() {
    if (head == nullptr) {
        cout << "List kosong, tidak ada yang dihapus." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr; // Jika list menjadi kosong, update tail
    }

    cout << "🗑️ Data " << temp->data << " dihapus dari depan." << endl;
    delete temp;
}

//Fungsi : hapus dibelakang
void hapusBelakang() {
    if (tail == nullptr) {
        cout << "List kosong, tidak ada yang dihapus." << endl;
        return;
    }

    Node* temp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr; // Jika list menjadi kosong, update head
    }

    cout << "🗑️ Data " << temp->data << " dihapus dari belakang." << endl;
    delete temp;
}

void hapusData(int target) {
    if (head == nullptr) {
        cout << "List kosong, tidak ada yang dihapus." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr && current->data != target) {
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Data " << target << " tidak ditemukan dalam list." << endl;
        return;
    }

    if (current == head) {
        hapusDepan();
    } else if (current == tail) {
        hapusBelakang();
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        cout << "Data " << current->data << " berhasil dihapus.\n";
        delete current;
    }
}