/* Nama      : Muhammad Gilang Ramadhan */
/* NIM       : 13520137 */
/* Deskripsi : List_Mono */

#include <stdio.h>
#include "listpos.h"

int main()
{
    ListPos L;
    ListPos Ldesc;
    ListPos Lasc;
    readList(&L);
    Ldesc = L;
    Lasc = Ldesc;
    boolean isAsc = true;
    sort(&Ldesc, !isAsc);
    sort(&Lasc, isAsc);
    if (isListEqual(L, Ldesc) && isListEqual(L, Lasc))
    {
        printf("Static Monotonic List\n");
    }
    else
    {
        if (isListEqual(L, Lasc))
        {
            printf("Non-descending Monotonic List\n");
        }
        else if (isListEqual(L, Ldesc))
        {
            printf("Non-ascending Monotonic List\n");
        }
        else
        {
            printf("Non-monotonic List\n");
        }
    }
    return 0;
}