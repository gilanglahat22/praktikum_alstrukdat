#include <stdio.h>
#include "stack.h"
#include <string.h>
int main()
{
    Stack A, B, E;
    int j = 0;
    int t;
    int u = 0;
    CreateStack(&A);
    CreateStack(&B);
    CreateStack(&E);
    char C[CAPACITY];
    char D[CAPACITY];
    scanf("%s", &C);
    scanf("%s", &D);
    for (int i = 0; i < strlen(C) - 1; i++)
    {
        push(&A, (int)C[i] - 48);
    }
    for (int i = 0; i < strlen(D) - 1; i++)
    {
        push(&B, (int)D[i] - 48);
    }
    while (j <= IDX_TOP(A) && j <= IDX_TOP(B))
    {
        t = (A.buffer[IDX_TOP(A) - j] + B.buffer[IDX_TOP(B) - j] + u) % 10;
        u = (A.buffer[IDX_TOP(A) - j] + B.buffer[IDX_TOP(B) - j] + u - t) / 10;
        push(&E, t);
        j++;
    }
    if (IDX_TOP(A) > IDX_TOP(B))
    {
        for (int i = j; i <= IDX_TOP(A); i++)
        {
            if (IDX_TOP(A) - i != 0)
            {
                t = (A.buffer[IDX_TOP(A) - i] + u) % 10;
                u = (A.buffer[IDX_TOP(A) - i] + u - t) / 10;
            }
            else
            {
                t = (A.buffer[IDX_TOP(A) - i] + u);
            }
            push(&E, t);
        }
    }
    else if (IDX_TOP(B) > IDX_TOP(A))
    {
        for (int i = j; i <= IDX_TOP(B); i++)
        {
            if (IDX_TOP(B) - i != 0)
            {
                t = (B.buffer[IDX_TOP(B) - i] + u) % 10;
                u = (B.buffer[IDX_TOP(B) - i] + u - t) / 10;
            }
            else
            {
                t = (B.buffer[IDX_TOP(B) - i] + u);
            }
            push(&E, t);
        }
    }
    else
    {
        E.buffer[IDX_TOP(E)] = u * 10 + E.buffer[IDX_TOP(E)];
    }
    for (int i = 0; i <= IDX_TOP(E); i++)
    {
        printf("%d", E.buffer[IDX_TOP(E) - i]);
    }
    return 0;
}
