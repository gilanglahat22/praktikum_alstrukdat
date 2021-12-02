/* NAMA : Muhammad Gilang Ramadhan */
/* NIM  : 13520137  */
/* 18 November 2021 */
/* PRAKTIKUM 12 */

#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

List splitOddIndex(List l)
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
ganjil pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
{
    if (length(l) >= 1)
    {
        if (length(l) == 1)
        {
            return konso(splitOddIndex(tail(l)), INFO(l));
        }
        else
        {
            return konso(splitOddIndex(tail(tail(l))), INFO(l));
        }
    }
    else
    {
        return NULL;
    }
}
List splitEvenIndex(List l)
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen pada indeks
genap pada list L, sesuai dengan urutannya. Elemen HEAD merupakan indeks 1.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
{
    if (length(l) >= 2)
    {
        return konso(splitEvenIndex(tail(tail(l))), INFO(tail(l)));
    }
    else
    {
        return NULL;
    }
}
List splitBeforeX(List l, ElType x)
/* Mengembalikan sebuah list baru yang elemennya adalah elemen-elemen di depan elemen
dengan nilai x pada list l, sesuai dengan urutannya. Jika x tidak ada pada list, maka
kembalikan list l.
Jika tidak ada elemen yang bisa diambil, kembalikan NULL */
{
    if (!isEmpty(l))
    {
        if (INFO(l) != x)
        {
            return konso(splitBeforeX(tail(l), x), INFO(l));
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}
List reverseList(List l)
/* Mengembalikan sebuah list baru yang urutannya merupakan kebalikan dari list l.
Jika l kosong, kembalikan list kosong. */
{
    if (!isEmpty(l))
    {
        return konsb(reverseList(tail(l)), INFO(l));
    }
    else
    {
        return NULL;
    }
}
void setSplitBeforeX(List *l, ElType x)
{
    *l = splitBeforeX(*l, x);
}
void setReverseList(List *l)
{
    *l = reverseList(*l);
}
void setKonso(List *l, ElType x)
{
    *l = konso(*l, x);
}
void setKonsb(List *l, ElType x)
{
    *l = konsb(*l, x);
}
int main()
{
    List L;
    L = NULL;
    Address p;
    int i;
    ElType B;
    char A;
    scanf("%c", &A);
    while (A != 'X')
    {
        if (A == 'B')
        {
            scanf("%d", &B);
            setKonsb(&L, B);
        }
        else if (A == 'F')
        {
            scanf("%d", &B);
            setKonso(&L, B);
        }
        else if (A == 'O')
        {
            L = splitOddIndex(L);
        }
        else if (A == 'E')
        {
            L = splitEvenIndex(L);
        }
        else if (A == 'R')
        {
            setReverseList(&L);
        }
        else if (A == 'P')
        {
            scanf("%d", &B);
            setSplitBeforeX(&L, B);
        }
        scanf("%c", &A);
    }
    if (length(L) == 0)
    {
        printf("Semua gugur\n");
    }
    displayList(L);
    return 0;
}