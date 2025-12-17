#include "multilist.h"
#include <iostream>
using namespace std;

void CreateListInduk(listinduk &L) {
    L.first = NULL;
    L.last = NULL;
}

void CreateListAnak(listanak &L) {
    L.first = NULL;
    L.last = NULL;
}

address_induk alokasiInduk(infotipeinduk X) {
    address_induk P = new elemen_list_induk;
    if (P != NULL) {
        P->info = X;
        CreateListAnak(P->anak);  
        P->next = NULL;
        P->prev = NULL;
    }
    return P;
}

void dealokasiInduk(address_induk P) {
    delete P;
}

address_anak alokasiAnak(infotipeanak X) {
    address_anak P = new elemen_list_anak;
    if (P != NULL) {
        P->info = X;
        P->next = NULL;
        P->prev = NULL;
    }
    return P;
}

void dealokasiAnak(address_anak P) {
    delete P;
}

address_induk findElmInduk(listinduk L, infotipeinduk X) {
    address_induk P = L.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

address_anak findElmAnak(listanak L, infotipeanak X) {
    address_anak P = L.first;
    while (P != NULL) {
        if (P->info == X) return P;
        P = P->next;
    }
    return NULL;
}

void insertFirstInduk(listinduk &L, address_induk P) {
    if (L.first == NULL) {
        L.first = P;
        L.last  = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastInduk(listinduk &L, address_induk P) {
    if (L.first == NULL) {
        L.first = P;
        L.last  = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertAfterInduk(listinduk &L, address_induk Prec, address_induk P) {
    if (Prec->next == NULL) {
        insertLastInduk(L, P);
    } else {
        P->next = Prec->next;
        Prec->next->prev = P;
        Prec->next = P;
        P->prev = Prec;
    }
}

void insertFirstAnak(listanak &L, address_anak P) {
    if (L.first == NULL) {
        L.first = P;
        L.last  = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastAnak(listanak &L, address_anak P) {
    if (L.first == NULL) {
        L.first = P;
        L.last  = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertAfterAnak(listanak &L, address_anak Prec, address_anak P) {
    if (Prec->next == NULL) {
        insertLastAnak(L, P);
    } else {
        P->next = Prec->next;
        Prec->next->prev = P;
        Prec->next = P;
        P->prev = Prec;
    }
}

void deleteFirstInduk(listinduk &L, address_induk &P) {
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        P = L.first;
        L.first = P->next;
        L.first->prev = NULL;
    }
}

void deleteLastInduk(listinduk &L, address_induk &P) {
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        P = L.last;
        L.last = P->prev;
        L.last->next = NULL;
    }
}

void deleteAfterInduk(listinduk &L, address_induk Prec, address_induk &P) {
    P = Prec->next;
    if (P == L.last) {
        deleteLastInduk(L, P);
    } else {
        Prec->next = P->next;
        P->next->prev = Prec;
    }
}

void deleteFirstAnak(listanak &L, address_anak &P) {
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        P = L.first;
        L.first = P->next;
        L.first->prev = NULL;
    }
}

void deleteLastAnak(listanak &L, address_anak &P) {
    if (L.first == NULL) {
        P = NULL;
    } else if (L.first == L.last) {
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        P = L.last;
        L.last = P->prev;
        L.last->next = NULL;
    }
}

void deleteAfterAnak(listanak &L, address_anak Prec, address_anak &P) {
    P = Prec->next;
    if (P == L.last) {
        deleteLastAnak(L, P);
    } else {
        Prec->next = P->next;
        P->next->prev = Prec;
    }
}

int nBelas(listinduk L) {
    int count = 0;
    address_induk P = L.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

int nBilas(listanak L) {
    int count = 0;
    address_anak P = L.first;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void printInfoInduk(listinduk L) {
    if (L.first == NULL) {
        cout << "List Induk Kosong" << endl;
    } else {
        address_induk P = L.first;
        while (P != NULL) {
            cout << P->info << ": ";
            printInfoAnak(P->anak);
            cout << endl;
            P = P->next;
        }
    }
}

void printInfoAnak(listanak L) {
    address_anak P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
}
