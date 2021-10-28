/* NAMA : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
#include <stdio.h>
#include "stack.h"
#include <string.h>
int main()
{
    Stack A, B, C;
    CreateStack(&A);
    CreateStack(&B);
    CreateStack(&C);
    char D[CAPACITY];
    char E[CAPACITY];
    scanf("%s", &D);
    scanf("%s", &E);
    int satuan;
    int puluhan = 0;
    int j;
    int z = 0;
    for (int i = 0; i < strlen(D) - 1; i++)
    {
        push(&A, (int)D[i] - 48);
    }
    for (int i = 0; i < strlen(E) - 1; i++)
    {
        push(&B, (int)E[i] - 48);
    }
    if (IDX_TOP(A) > IDX_TOP(B))
    {
        for (int i = 0; i <= IDX_TOP(B); i++)
        {
            satuan = (A.buffer[IDX_TOP(A) - i] + B.buffer[IDX_TOP(B) - i] + puluhan) % 10;
            puluhan = (A.buffer[IDX_TOP(A) - i] + B.buffer[IDX_TOP(B) - i] + puluhan - satuan) / 10;
            j = i;
            push(&C, satuan);
        }
        for (int i = j + 1; i <= IDX_TOP(A); i++)
        {
            if (IDX_TOP(A) - i != 0)
            {
                satuan = (A.buffer[IDX_TOP(A) - i] + puluhan) % 10;
                puluhan = (A.buffer[IDX_TOP(A) - i] + puluhan - satuan) / 10;
                push(&C, satuan);
            }
            else
            {
                satuan = (A.buffer[IDX_TOP(A) - i] + puluhan);
                push(&C, satuan);
            }
        }
    }
    else if (IDX_TOP(B) > IDX_TOP(A))
    {
        for (int i = 0; i <= IDX_TOP(A); i++)
        {
            satuan = (A.buffer[IDX_TOP(A) - i] + B.buffer[IDX_TOP(B) - i] + puluhan) % 10;
            puluhan = (A.buffer[IDX_TOP(A) - i] + B.buffer[IDX_TOP(B) - i] + puluhan - satuan) / 10;
            j = i;
            push(&C, satuan);
        }
        for (int i = j + 1; i <= IDX_TOP(B); i++)
        {
            if (IDX_TOP(B) - i != 0)
            {
                satuan = (B.buffer[IDX_TOP(B) - i] + puluhan) % 10;
                puluhan = (B.buffer[IDX_TOP(B) - i] + puluhan - satuan) / 10;
                push(&C, satuan);
            }
            else
            {
                satuan = (B.buffer[IDX_TOP(B) - i] + puluhan);
                push(&C, satuan);
            }
        }
    }
    else
    {
        for (int i = 0; i <= IDX_TOP(A); i++)
        {
            if (IDX_TOP(A) - i != 0)
            {
                satuan = (A.buffer[IDX_TOP(A) - i] + B.buffer[IDX_TOP(B) - i] + puluhan) % 10;
                puluhan = (A.buffer[IDX_TOP(A) - i] + B.buffer[IDX_TOP(B) - i] + puluhan - satuan) / 10;
                j = i;
                push(&C, satuan);
            }
            else
            {
                satuan = (A.buffer[IDX_TOP(A) - i] + B.buffer[IDX_TOP(B) - i] + puluhan);
                push(&C, satuan);
            }
        }
    }
    for (int i = 0; i <= IDX_TOP(C); i++)
    {
        printf("%d", C.buffer[IDX_TOP(C) - i]);
    }
    return 0;
}
