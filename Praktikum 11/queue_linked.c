/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* 8 November 2021 */

#include <stdio.h>
#include "queue_linked.h"

/* Prototype manajemen memori */
Address newNode(ElType x)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x,
   atau NULL jika alokasi gagal */
{
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL)
    {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}
boolean isEmpty(Queue q)
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
{
    return ((ADDR_HEAD(q) == NULL) && (ADDR_TAIL(q) == NULL));
}
int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
{
    int count = 0;
    Address cp = ADDR_HEAD(q);

    while (cp != NULL)
    {
        cp = NEXT(cp);
        count++;
    }
    return count;
}
/*** Kreator ***/
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
{
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}
/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x)
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
{
    Address p = newNode(x);
    if (p != NULL)
    {
        if (isEmpty(*q)) /* Kasus Jika list q kosong */
        {
            ADDR_HEAD(*q) = p;
            ADDR_TAIL(*q) = p;
        }
        else /* Kasus jika list q tidak kosong */
        {

            NEXT(ADDR_TAIL(*q)) = p;
            ADDR_TAIL(*q) = p;
        }
    }
}
void dequeue(Queue *q, ElType *x)
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    Address p = ADDR_HEAD(*q);

    if (NEXT(ADDR_HEAD(*q)) == NULL) /* Jika list hanya berisi 1 buah element */
    {
        CreateQueue(q);
    }
    else /* Jika lebih dari 1 */
    {
        ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    }
    *x = INFO(p);
    free(p);
}