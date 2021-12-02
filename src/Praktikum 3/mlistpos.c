/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* Deskripsi Praktikum 3 */

#include <stdio.h>
#include "listpos.h"

int main()
{
    ListPos L;
    readList(&L);
    int X = IDX_UNDEF;
    int maks = IDX_UNDEF;
    int min = IDX_UNDEF;
    int median = IDX_UNDEF;
    scanf("%d", &X);
    displayList(L);
    printf("\n");
    if (indexOf(L, X) != IDX_UNDEF)
    {
        printf("%d\n", indexOf(L, X));
        extremes(L, &maks, &min);
        sort(&L, true);
        // Jika maksimum
        if (X == maks)
        {
            printf("maksimum\n");
        }
        // Jika minimum
        if (X == min)
        {
            printf("minimum\n");
        }
        // Jika median
        if (length(L) % 2 == 0)
        {
            median = ((length(L)) / 2) - 1;
        }
        else
        {
            median = ((length(L)) / 2);
        }
        if (ELMT(L, median) == X && median >= 0)
        {
            printf("median\n");
        }
    }
    else
    {
        printf("%d tidak ada\n", X);
    }
    return 0;
}