#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    Queue Q;
    int A;
    CreateQueue(&Q);
    enqueue(&Q, 1);
    enqueue(&Q, 2);
    enqueue(&Q, 3);
    enqueue(&Q, 4);
    enqueue(&Q, 5);
    enqueue(&Q, 6);
    enqueue(&Q, 7);
    enqueue(&Q, 8);
    enqueue(&Q, 9);
    enqueue(&Q, 10);
    dequeue(&Q, &A);
    enqueue(&Q, 11);
    printf("%d\n", A);
    dequeue(&Q, &A);
    enqueue(&Q, 12);
    printf("%d\n", A);
    dequeue(&Q, &A);
    enqueue(&Q, 13);
    printf("%d\n", A);
    dequeue(&Q, &A);
    enqueue(&Q, 14);
    printf("%d\n", A);
    dequeue(&Q, &A);
    enqueue(&Q, 15);
    printf("%d\n", A);
    dequeue(&Q, &A);
    enqueue(&Q, 16);
    printf("%d\n", A);
    dequeue(&Q, &A);
    enqueue(&Q, 17);
    printf("%d\n", A);
    dequeue(&Q, &A);
    enqueue(&Q, 18);
    printf("%d\n", A);
    dequeue(&Q, &A);
    enqueue(&Q, 19);
    printf("%d\n", A);
    dequeue(&Q, &A);
    enqueue(&Q, 20);
    printf("%d\n", A);
    dequeue(&Q, &A);
    enqueue(&Q, 21);
    printf("%d\n", A);
    dequeue(&Q, &A);
    enqueue(&Q, 22);
    printf("%d\n", A);
    dequeue(&Q, &A);
    enqueue(&Q, 23);
    printf("%d\n", A);
    dequeue(&Q, &A);
    enqueue(&Q, 24);
    printf("%d\n", A);
    dequeue(&Q, &A);
    enqueue(&Q, 25);
    printf("%d\n", A);
    dequeue(&Q, &A);
    enqueue(&Q, 26);
    printf("%d\n", A);
    dequeue(&Q, &A);
    enqueue(&Q, 27);
    printf("%d\n", A);
    return 0;
}