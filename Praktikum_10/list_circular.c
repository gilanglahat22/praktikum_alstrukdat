/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* 29 Oktober 2021 */
#include <stdio.h>
#include "list_circular.h"
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (FIRST(l) == NULL);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. l sembarang */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    FIRST(*l) = NULL;
}
/****************** Manajemen Memori ******************/
Address allocate(ElType val)
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
{
    Address p = (Address)malloc(sizeof(ElmtList));
    if (p != NULL)
    {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}
void deallocate(Address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */
{
    free(P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val)
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
{
    if (!isEmpty(l))
    {
        Address i = FIRST(l);
        Address p = NULL;
        do
        {
            if (INFO(i) == val)
            {
                p = i;
            }
            i = NEXT(i);
        } while (p == NULL && i != FIRST(l));
        return p;
    }
    else
    {
        return NULL;
    }
}
boolean addrSearch(List l, Address p)
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    Address pt;
    if (isEmpty(l))
    {
        return false;
    }
    else
    {
        pt = FIRST(l);
        while ((NEXT(pt) != FIRST(l)) && (pt != p))
        {
            pt = NEXT(pt);
        }
        return (pt == p);
    }
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
/* Elemen terakhir list menunjuk ke address dari elemen pertama baru list */
{
    Address p, last;
    p = allocate(val);
    if (p != NULL)
    {
        if (isEmpty(*l))
        {
            NEXT(p) = p;
        }
        else
        {
            last = FIRST(*l);
            while (NEXT(last) != FIRST(*l))
            {
                last = NEXT(last);
            }
            NEXT(p) = FIRST(*l);
            NEXT(last) = p;
        }
        FIRST(*l) = p;
    }
}
void insertLast(List *l, ElType val)
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
/* Elemen terakhir baru list menunjuk ke address dari elemen pertama list */
{
    Address p, last;
    if (isEmpty(*l))
    {
        insertFirst(l, val);
    }
    else
    {
        p = allocate(val);
        if (p != NULL)
        {
            last = FIRST(*l);
            while (NEXT(last) != FIRST(*l))
            {
                last = NEXT(last);
            }
            NEXT(last) = p;
            NEXT(p) = FIRST(*l);
        }
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama List l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Jika list baru tidak kosong, Last element menunjuk ke First element baru */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen pertama list lama di-dealokasi */
{
    Address p, last;
    p = FIRST(*l);
    *val = INFO(p);
    if (NEXT(FIRST(*l)) == FIRST(*l))
    {
        FIRST(*l) = NULL;
    }
    else
    {
        last = FIRST(*l);
        while (NEXT(last) != FIRST(*l))
        {
            last = NEXT(last);
        }
        FIRST(*l) = NEXT(FIRST(*l));
        NEXT(last) = FIRST(*l);
    }
    free(p);
}
void deleteLast(List *l, ElType *val)
/* I.S. List l tidak kosong */
/* F.S. val adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen terakhir yg lama, jika ada */
/*      Jika list baru tidak kosong, Last element baru menunjuk ke First element */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen terakhir list lama di-dealokasi */
{
    Address last, precLast;
    last = FIRST(*l);
    precLast = NULL;
    while (NEXT(last) != FIRST(*l))
    {
        precLast = last;
        last = NEXT(last);
    }
    if (precLast == NULL)
    {
        FIRST(*l) = NULL;
    }
    else
    {
        NEXT(precLast) = FIRST(*l);
    }
    *val = INFO(last);
    free(last);
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    Address P;
    if (isEmpty(l))
    {
        printf("[]");
    }
    else
    {
        printf("[");
        P = FIRST(l);
        do
        {
            printf("%d", INFO(P));
            if (NEXT(P) != FIRST(l))
            {
                printf(",");
            }
            P = NEXT(P);
        } while (P != FIRST(l));
        printf("]");
    }
}
