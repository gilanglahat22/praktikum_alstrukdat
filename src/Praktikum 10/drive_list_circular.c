#include <stdio.h>
#include "list_circular.h"

int main()
{
    List L, L2, L3;
    ElType X;
    Address a;
    int jar, jlh;

    CreateList(&L);
    CreateList(&L2);
    displayList(L);
    insertLast(&L, 0);
    displayList(L);
    insertLast(&L, 2);
    insertLast(&L, 3);
    insertFirst(&L, 10);
    displayList(L);
    insertFirst(&L, 1);
    insertLast(&L, 8);
    insertFirst(&L, 10);
    deleteFirst(&L, &X);
    insertFirst(&L, 10);
    insertLast(&L, 2);
    insertFirst(&L, 10);
    displayList(L);
    deleteLast(&L, &X);
    printf("%d", X);
    displayList(L);
    deleteFirst(&L, &X);
    printf("%d", X);
    printf("\n%d\n", allocate(X));
    deallocate(allocate(X));
    if (addrSearch(L, search(L, 10)) == true)
    {
        printf("Ya\n");
    }
    displayList(L);
    return 0;
}