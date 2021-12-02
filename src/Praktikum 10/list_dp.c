/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
#include <stdio.h>
#include "list_dp.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return ((FIRST(l) == NULL) && (LAST(l) == NULL));
}
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. l sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    FIRST(*l) = NULL;
    LAST(*l) = NULL;
}
/****************** Manajemen Memori ******************/
Address allocate(ElType val)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL. */
/* Misalnya: menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL, PREV(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL. */
{
    Address result;
    result = (Address)malloc(sizeof(Node));
    if (result != NULL)
    {
        INFO(result) = val;
        NEXT(result) = NULL;
        PREV(result) = NULL;
    }
    return result;
}
void deallocate(Address p)
/* I.S. p terdefinisi */
/* F.S. p dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */
{
    free(p);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val)
/* Mencari apakah ada elemen list dengan INFO(P)=val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
{
    Address now = FIRST(l);
    while ((now != NULL) && (INFO(now) != val))
    {
        now = NEXT(now);
    }
    return now;
}
/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    Address p = allocate(val);
    if (p != NULL)
    {
        if (FIRST(*l) == NULL)
        {
            LAST(*l) = p;
        }
        else
        {
            PREV(FIRST(*l)) = p;
        }
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}
void insertLast(List *l, ElType val)
/* I.S. List l terdefinisi */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    Address p = allocate(val);
    if (p != NULL)
    {
        if (LAST(*l) == NULL)
        {
            FIRST(*l) = p;
        }
        else
        {
            NEXT(LAST(*l)) = p;
        }
        PREV(p) = LAST(*l);
        LAST(*l) = p;
    }
}
void insertAfter(List *L, Address p, Address pRec)
/* I.S. pRec pasti elemen list; p sudah dialokasi */
/* F.S. Insert p sebagai elemen sesudah elemen beralamat pRec */
{
    if (pRec == LAST(*L))
    {
        insertLast(L, INFO(p));
    }
    else
    {
        NEXT(p) = NEXT(pRec);
        PREV(NEXT(pRec)) = p;
        PREV(p) = pRec;
        NEXT(pRec) = p;
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen pertama di-dealokasi */
{
    Address p;
    p = FIRST(*l);
    FIRST(*l) = NEXT(FIRST(*l));
    if (FIRST(*l) == NULL)
    {
        CreateList(l);
    }
    else
    {
        PREV(FIRST(*l)) = NULL;
    }
    *val = INFO(p);
    deallocate(p);
}
void deleteLast(List *l, ElType *val)
/* I.S. list l tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada val */
/*      dan alamat elemen terakhir di-dealokasi */
{
    Address p;
    p = LAST(*l);
    LAST(*l) = PREV(LAST(*l));
    if (LAST(*l) == NULL)
    {
        CreateList(l);
    }
    else
    {
        NEXT(LAST(*l)) = NULL;
    }
    *val = INFO(p);
    deallocate(p);
}
void deleteAfter(List *l, Address *pDel, Address pRec)
/* I.S. List tidak kosong. pRec adalah anggota list.
        NEXT(pRec)!=NULL */
/* F.S. Menghapus NEXT(pRec): */
{
    *pDel = NEXT(pRec);
    NEXT(pRec) = NEXT(*pDel);
    if (NEXT(*pDel) != NULL)
    {
        PREV(NEXT(*pDel)) = pRec;
    }
    else
    {
        LAST(*l) = pRec;
    }
    NEXT(*pDel) = NULL;
    PREV(*pDel) = NULL;
}
/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!isEmpty(l))
    {
        Address gilang = FIRST(l);
        do
        {
            printf("%d", INFO(gilang));
            gilang = NEXT(gilang);
            if (gilang != NULL)
            {
                printf(",");
            }
        } while (gilang != NULL);
    }
    printf("]");
}
void displayListBackwards(List l)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!isEmpty(l))
    {
        Address gilang = LAST(l);
        do
        {
            printf("%d", INFO(gilang));
            gilang = PREV(gilang);
            if (gilang != NULL)
            {
                printf(",");
            }
        } while (gilang != NULL);
    }
    printf("]");
}