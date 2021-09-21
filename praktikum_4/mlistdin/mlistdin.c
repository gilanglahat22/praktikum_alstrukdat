/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* 16 September 2021 */

#include <stdio.h>
#include "boolean.h"
#include "listdin.h"
#include <stdlib.h>

int main()
{
    int Capacity;
    int N;
    int Q;
    int op;
    int num;
    ListDin L;
    scanf("%d\n", &Capacity);
    scanf("%d\n", &N);
    if (N >= 0 && N <= Capacity)
    {
        CreateListDin(&L, Capacity);
        readList(&L);
        scanf("%d\n", &Q);
        for (int i = 0; i <= Q - 1; i++)
        {
            scanf("%d ", &op);
            if (op == 1)
            {
                if (isFull(L))
                {
                    printf("list sudah penuh \n");
                }
                else
                {
                    scanf("%d\n", &num);
                    insertLast(&L, num);
                }
            }
            else if (op == 2)
            {
                scanf("%d\n", &num);
                growList(&L, num);
            }
            else if (op == 3)
            {
                scanf("%d\n", &num);
                shrinkList(&L, num);
            }
            else if (op == 4)
            {
                compactList(&L);
            }
            printf("%d ", CAPACITY(L));
            displayList(L);
        }
    }
    return 0;
}