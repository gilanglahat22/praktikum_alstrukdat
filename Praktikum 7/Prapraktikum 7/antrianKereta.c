#include <stdio.h>
#include "queue.h"

float avgElmt(Queue Q)
{
    int sum = 0;
    for (int i = IDX_HEAD(Q); i <= IDX_TAIL(Q); i++)
    {
        sum += Q.buffer[i];
    }
    return (sum / length(Q));
}
int main()
{
    Queue Q;
    int val;
    int deleted;
    CreateQueue(&Q);
    int A;
    scanf("%d", &A);
    while (A != 0)
    {
        if (A == 1)
        {
            scanf("%d", &val);
            if (isFull(Q))
            {
                printf("Queue penuh\n");
            }
            else
            {
                enqueue(&Q, val);
            }
        }
        else if (A == 2)
        {
            if (isEmpty(Q))
            {
                printf("Queue kosong\n");
            }
            else
            {
                dequeue(&Q, &deleted);
            }
        }
        scanf("%d", &A);
    }
    printf("%d\n", length(Q));
    if (isEmpty(Q))
    {
        printf("Tidak bisa dihitung\n");
    }
    else
    {
        printf("%.2f\n", avgElmt(Q));
    }
    return 0;
}