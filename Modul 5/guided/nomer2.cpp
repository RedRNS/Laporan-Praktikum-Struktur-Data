#include <iostream>

using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = NULL;
    return P;
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void printInfo(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info << " -> ";
        P = P->next;
    }
    cout << "NULL" << endl;
}

void reverseList(List &L) {
    address prev = NULL;
    address current = L.first;
    address next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    L.first = prev;
}

int main() {
    List myList;
    createList(myList);

    insertLast(myList, alokasi(1));
    insertLast(myList, alokasi(2));
    insertLast(myList, alokasi(3));
    insertLast(myList, alokasi(4));
    insertLast(myList, alokasi(5));

    cout << "List Awal: " << endl;
    printInfo(myList);

    reverseList(myList);

    cout << "\nList Setelah di-Reverse: " << endl;
    printInfo(myList);

    return 0;
}