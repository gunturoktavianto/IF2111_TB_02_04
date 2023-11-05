#include <stdio.h>
#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateSet(Set *S){
    /* I.S. Sembarang */
    /* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
    /* Ciri Set kosong : count bernilai Nil */
    (*S).Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptySet(Set S){
    /* Mengirim true jika Set S kosong*/
    /* Ciri Set kosong : count bernilai Nil */
    return (S.Count == Nil);
}

boolean IsFullSet(Set S){
    /* Mengirim true jika Set S penuh */
    /* Ciri Set penuh : count bernilai MaxEl */
    return (S.Count == MaxEl);
}

/* ********** Operator Dasar Set ********* */
void InsertSet(Set *S, InfoLagu Elmt){
    /* Menambahkan Elmt sebagai elemen Set S. */
    /* I.S. S mungkin kosong, S tidak penuh
            S mungkin sudah beranggotakan Elmt */
    /* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
    if (!IsMemberSet(*S,Elmt)){
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count++;
    }
}

void DeleteSet(Set *S, InfoLagu Elmt){
    /* Menghapus Elmt dari Set S. */
    /* I.S. S tidak kosong
            Elmt mungkin anggota / bukan anggota dari S */
    /* F.S. Elmt bukan anggota dari S */
    if (IsMemberSet(*S,Elmt)){
        boolean found = false;
        int i=0;
        while(found!=true && i < (*S).Count){
            if((*S).Elements[i]==Elmt){
                found = true;
                for(int j=i; j<(*S).Count-1; j++){
                    (*S).Elements[j] = (*S).Elements[j+1];
                }
            }
            i++;
        }
    (*S).Count--;
    }
}

boolean IsMemberSet(Set S, InfoLagu Elmt){
    /* Mengembalikan true jika Elmt adalah member dari S */
    boolean found = false;
    int i=0;
    while(found!=true && i < S.Count){
        if(S.Elements[i]==Elmt){
            found = true;
        }
        i++;
    }
    return found;
}













Set SetUnion(Set s1, Set s2) {
    // Mengembalikan set baru yang berisi elemen-elemen yang terdapat pada s1 atau s2
    // Contoh: [1, 2] U [2, 3] = [1, 2, 3] 
	Set s3 ;
	address idx1, idx2 ;
	idx1 = 0 ;
	idx2 = 0 ;
	CreateEmpty (&s3) ;

	while (idx1 < s1.Count) {
		Insert (&s3, s1.Elements[idx1]) ;
		idx1++ ;
	}
	while (idx2 < s2.Count) {
		Insert (&s3, s2.Elements[idx2]) ;
		idx2++ ;
	}
	return s3 ;
}

Set SetIntersection(Set s1, Set s2) {
    // Mengembalikan set baru yang berisi elemen-elemen dari s1 dan s2 yang terdapat pada kedua set
    // Contoh: [1, 2] ∩ [2, 3] = [2]
	Set s3 ;
	address idx = 0 ;
	CreateEmpty (&s3) ;
	while (idx < s1.Count) {
		if (IsMember(s2, s1.Elements[idx])) {
			Insert (&s3, s1.Elements[idx]) ;
		}
		idx++ ;
	}
	return s3 ;
}

Set SetSymmetricDifference(Set s1, Set s2) {
    // Mengembalikan set baru yang berisi elemen yang ada di s1 atau s2, tapi tidak pada keduanya
    // Contoh: [1, 2] ⊖ [2, 3] = [1, 3]
	Set s3 ;
	address idx1, idx2 ;
	idx1 = 0 ;
	idx2 = 0 ;
	CreateEmpty (&s3) ;
	while (idx1 < s1.Count) {
		if (!IsMember(s2, s1.Elements[idx1])) {
			Insert (&s3, s1.Elements[idx1]) ;
		}
		idx1++ ;
	}
	while (idx2 < s2.Count) {
		if (!IsMember(s1, s2.Elements[idx2])) {
			Insert (&s3, s2.Elements[idx2]) ;
		}
		idx2++ ;
	}
	return s3 ;
}

Set SetSubtract(Set s1, Set s2) {
    // Mengembalikan set baru yang berupa hasil pengurangan s1 dengan s2
    // Contoh:
    // s1 = [1, 2] s2 = [2, 3]
    // s1 - s2 = [1]
	Set s3 ;
	address idx = 0 ;
	CreateEmpty (&s3) ;
	while (idx < s1.Count) {
		if (!IsMember(s2, s1.Elements[idx])) {
			Insert (&s3, s1.Elements[idx]) ;
		}
		idx++ ;
	}
	return s3 ;
}