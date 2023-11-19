#include <stdio.h>
#include "list.h"

// Konstruktor

ListPenyanyi MakeList() {
	ListPenyanyi L;
	IdxType i;
	for (i = 0; i < MaxEl; i++) {
		L.InfoPenyanyi[i] = Mark;
	}
	return L;
}

boolean IsEmpty(ListPenyanyi L) {
	return (L.InfoPenyanyi[0] == Mark);
}

int Length(ListPenyanyi L) {
	int i = 0;
	while (L.InfoPenyanyi[i] != Mark) {
		i += 1;
	}
	return i;
}

ElType Get(ListPenyanyi L, IdxType i) {
	return L.InfoPenyanyi[i];
}

void Modify(ListPenyanyi *L, IdxType i, ElType v) {
	(*L).InfoPenyanyi[i] = v;
}

IdxType FirstIdx(ListPenyanyi L) {
    return 0;
}

IdxType LastIdx(ListPenyanyi L) {
	int i = FirstIdx(L);
	while ((i < MaxEl) && (L.InfoPenyanyi[i+1] != Mark)) {
		i += 1;
	}
	return i;
}

boolean IsIdxValid (ListPenyanyi L, IdxType i) {
	return (0 <= i) && (MaxEl >= i);
}

boolean IsIdxEff (ListPenyanyi L, IdxType i) {
	return (FirstIdx(L) <= i) && (LastIdx(L) >= i);
}

boolean Search(ListPenyanyi L, ElType X) {
	int i = FirstIdx(L);
	int j = LastIdx(L);
	boolean found = false;
	while ((i <= j) && !found) {
		if (L.InfoPenyanyi[i] == X) {
			found = true;
		}
		i += 1;
	}
    return found;
}

void InsertFirst(ListPenyanyi *L, ElType X) {
	IdxType i = LastIdx(*L);
	while (i >= 0) {
		Set(L, i+1, Get(*L, i));
		i--;
	}
	Set(L, 0, X);
}

void InsertAt(ListPenyanyi *L, ElType X, IdxType i) {
    IdxType j = LastIdx(*L);
	while (i <= j) {
		Set(L, j+1, Get(*L, j));
        j--;
	}
	Set(L, i, X);
}

void InsertLast(ListPenyanyi *L, ElType X) {
    if (IsEmpty(*L)) {
        InsertFirst(L, X);
    } else {
        (*L).InfoPenyanyi[LastIdx(*L) + 1] = X;
    }
}

void DeleteFirst(ListPenyanyi *L) {
	int i = FirstIdx(*L);
	while (i < LastIdx(*L)) {
		(*L).InfoPenyanyi[i] = (*L).InfoPenyanyi[i+1];
        i++;
	}
    (*L).InfoPenyanyi[i] = Mark;
}

void DeleteAt(ListPenyanyi *L, IdxType i) {
	int j = LastIdx(*L);
	while (i <= j) {
		(*L).InfoPenyanyi[i] = (*L).InfoPenyanyi[i+1];
        i++;
	}
}

void DeleteLast(ListPenyanyi *L) {
	(*L).InfoPenyanyi[LastIdx(*L)] = Mark;
}

ListPenyanyi Concat(ListPenyanyi L1, ListPenyanyi L2) {
	ListPenyanyi L3 = MakeList();
	int i = FirstIdx(L1);
	int j = FirstIdx(L2);
	int idx = 0;
	while (i <= LastIdx(L1)) {
		L3.InfoPenyanyi[idx] = L1.InfoPenyanyi[i];
        idx++;
        i++;
	}
	while (j <= LastIdx(L2)) {
		L3.InfoPenyanyi[idx] = L2.InfoPenyanyi[j];
        idx++;
        j++;
	}

    return L3;
}