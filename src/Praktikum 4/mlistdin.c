/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* mlistdin.c */

#include <stdio.h>
#include "listdin.h"

void Display(ListDin L)
{
    printf("%d ", CAPACITY(L));
    displayList(L);
    printf("\n");
}

boolean operasi1(ListDin *L, int val)
{
    if (isFull(*L))
    {
        printf("list sudah penuh\n");
        return false;
    }
    else
    {
        insertLast(L, val);
        return true;
    }
}

boolean operasi2(ListDin *L, int val)
{
    growList(L, val);
    return true;
}

boolean operasi3(ListDin *L, int val)
{
    int buang;
    if (CAPACITY(*L) < val)
    {
        printf("list terlalu kecil\n");
        return false;
    }
    else
    {
        if ((CAPACITY(*L) - val) < NEFF(*L))
        {
            for (int i = 0; i <= NEFF(*L) - (CAPACITY(*L) - val); i++)
            {
                deleteLast(L, &buang);
            }
        }
        shrinkList(L, val);
        return true;
    }
}

boolean operasi4(ListDin *L)
{
    compactList(L);
    return true;
}

void DoOperation(ListDin *L)
{
    int op, X;
    scanf("%d", &op);
    boolean operasi = false;
    switch (op)
    {
    case 1:
        scanf("%d", &X);
        operasi = operasi1(L, X);
        break;
    case 2:
        scanf("%d", &X);
        operasi = operasi2(L, X);
        break;
    case 3:
        scanf("%d", &X);
        operasi = operasi3(L, X);
        break;
    case 4:
        operasi = operasi4(L);
        break;
    default:
        break;
    }
    if (operasi)
    {
        Display(*L);
    }
}

int main()
{
    ListDin L;
    int capacity, Q;
    scanf("%d", &capacity);
    CreateListDin(&L, capacity);
    readList(&L);
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++)
    {
        DoOperation(&L);
    }
    return 0;
}