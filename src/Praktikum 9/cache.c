/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* 28 Oktober 2021 */

#include <stdio.h>
#include "list_linked.h"
#include <stdlib.h>
void Delete_P(List *L, ElType X)
{
    if (!isEmpty(*L))
    {
        Address now = FIRST(*L);
        Address dummy;
        ElType val;
        if (INFO(now) == X)
        {
            deleteFirst(L, &val);
        }
        else
        {
            while (NEXT(now) != NULL && INFO(NEXT(now)) != X)
            {
                now = NEXT(now);
            }
            if (NEXT(now) != NULL)
            {
                dummy = NEXT(now);
                NEXT(now) = NEXT(dummy);
            }
        }
    }
}
Address Search(List l, ElType x)
{
    if (isEmpty(l))
    {
        return NULL;
    }
    Address Now = FIRST(l);
    while (Now != NULL && INFO(Now) != x)
    {
        Now = NEXT(Now);
    }
    return Now;
}
int main()
{
    List L;
    CreateList(&L); /* Membuat List Kosong */
    int N, i;
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        Address A = newNode(i);
        insertLast(&L, INFO(A));
    }
    int len, X;
    scanf("%d", &len);
    for (i = 0; i < len; i++)
    {
        scanf("%d", &X);
        Address find = Search(L, X);
        if (find == NULL)
        {
            ElType Dummy_ELMT;
            deleteLast(&L, &Dummy_ELMT);
            insertFirst(&L, X);
            printf("miss ");
            displayList(L);
            printf("\n");
        }
        else
        {
            Delete_P(&L, X);
            insertFirst(&L, X);
            printf("hit ");
            displayList(L);
            printf("\n");
        }
    }
    return 0;
}