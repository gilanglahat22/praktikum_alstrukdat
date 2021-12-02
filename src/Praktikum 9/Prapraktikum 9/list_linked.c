/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* 25 Oktober 2021 */

#include <stdio.h>
#include "list_linked.h"
#include "boolean.h"
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    FIRST(*l) = NULL;
}
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong */
{
    return (FIRST(l) == NULL);
}
/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
    int count = 0;
    Address p = FIRST(l);
    while (count < idx)
    {
        count++;
        p = NEXT(p);
    }
    return INFO(p);
}
void setElmt(List *l, int idx, ElType val)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
{
    int count = 0;
    Address p = FIRST(*l);
    while (count < idx)
    {
        count++;
        p = NEXT(p);
    }
    INFO(p) = val;
}
int indexOf(List l, ElType val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
{
    Address p = FIRST(l);
    boolean ketemu = false;
    int indeks = 0;
    while ((p != NULL) && (!ketemu))
    {
        if (INFO(p) == val)
        {
            ketemu = true;
        }
        else
        {
            indeks++;
            p = NEXT(p);
        }
    }
    if (ketemu)
    {
        return indeks;
    }
    else
    {
        return IDX_UNDEF;
    }
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
    Address newfirst = newNode(val);
    if (newfirst != NULL)
    {
        NEXT(newfirst) = FIRST(*l);
        FIRST(*l) = newfirst;
    }
}
void insertLast(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    Address P = newNode(val);
    if (P != NULL)
    {
        Address last;
        if (isEmpty(*l))
        {
            NEXT(P) = FIRST(*l);
            FIRST(*l) = P;
        }
        else
        {
            last = FIRST(*l);
            while (NEXT(last) != NULL)
            {
                last = NEXT(last);
            }
            NEXT(P) = NEXT(last);
            NEXT(last) = P;
        }
    }
}
void insertAt(List *l, ElType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    Address p = newNode(val);
    Address lokasi;
    int count;
    if (idx == 0)
    {
        insertFirst(l, val);
    }
    else
    {
        p = newNode(val);
        if (p != NULL)
        {
            count = 0;
            lokasi = FIRST(*l);
            while (count < idx - 1)
            {
                count++;
                lokasi = NEXT(lokasi);
            }
            NEXT(p) = NEXT(lokasi);
            NEXT(lokasi) = p;
        }
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
{
    Address p = FIRST(*l);
    FIRST(*l) = NEXT(FIRST(*l));
    NEXT(p) = NULL;
    *val = INFO(p);
    free(p);
}
void deleteLast(List *l, ElType *val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
{
    Address p = FIRST(*l);
    Address lokasi = NULL;
    while (NEXT(p) != NULL)
    {
        lokasi = p;
        p = NEXT(p);
    }
    if (lokasi == NULL)
    {
        FIRST(*l) = NULL;
    }
    else
    {
        NEXT(lokasi) = NULL;
    }
    *val = INFO(p);
    free(p);
}
void deleteAt(List *l, int idx, ElType *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
{
    Address p, lokasi;
    int count;
    if (idx == 0)
    {
        deleteFirst(l, val);
    }
    else
    {
        count = 0;
        lokasi = FIRST(*l);
        while (count < idx - 1)
        {
            count++;
            lokasi = NEXT(lokasi);
        }
        p = NEXT(lokasi);
        *val = INFO(p);
        NEXT(lokasi) = NEXT(p);
        free(p);
    }
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!(isEmpty(l)))
    {
        Address now = FIRST(l);
        while (now != NULL)
        {
            printf("%d", INFO(now));
            now = NEXT(now);

            if (now != NULL)
                printf(",");
        }
    }
    printf("]");
}
int length(List l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    Address P = FIRST(l);
    while (P != NULL)
    {
        count++;
        P = NEXT(P);
    }
    return count;
}
/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2)
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    List l3;
    Address p;
    CreateList(&l3);
    p = FIRST(l1);
    while (p != NULL)
    {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = FIRST(l2);
    while (p != NULL)
    {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}