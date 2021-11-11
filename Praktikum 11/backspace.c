/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */

#include <stdio.h>
#include <stdlib.h>
#include "stack_linked.h"

int main()
{
    int N, M;
    int A, B;
    Stack S1, S2;
    CreateStack(&S1);
    CreateStack(&S2);
    int Hapus1, Hapus2;
    boolean isSame = true;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A);
        if (A != 0)
        {
            push(&S1, A);
        }
        else
        {
            if (!isEmpty(S1))
            {
                pop(&S1, &Hapus1);
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &B);
        if (B != 0)
        {
            push(&S2, B);
        }
        else
        {
            if (!isEmpty(S2))
            {
                pop(&S2, &Hapus2);
            }
        }
    }
    /* Cek apakah kedua stack sama */
    Hapus1 = 1;
    Hapus2 = 1;
    while ((isEmpty(S1) == false) && (isEmpty(S2) == false) && (Hapus1 == Hapus2))
    {
        pop(&S1, &Hapus1);
        pop(&S2, &Hapus2);
    }
    if (Hapus1 != Hapus2)
    {
        isSame = false;
    }
    if ((isEmpty(S1) == false) && (isEmpty(S2) == true))
    {
        isSame = false;
    }
    else if (isEmpty(S1) == true && isEmpty(S2) == false)
    {
        isSame = false;
    }
    if (isSame == true)
    {
        printf("Sama\n");
    }
    else
    {
        printf("Tidak sama\n");
    }
    return 0;
}