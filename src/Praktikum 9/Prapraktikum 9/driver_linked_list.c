#include <stdio.h>
#include "list_linked.h"
int main()
{
    List l;
    int n;
    ElType x;
    ElType y;
    CreateList(&l);
    printf("%d", length(l));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insertAt(&l, x, i);
    }
    deleteAt(&l, 2, &y);
    displayList(l);
    printf("%d\n", y);
    printf("%d\n", length(l));
    printf("%d", indexOf(l, 3));
    return 0;
}