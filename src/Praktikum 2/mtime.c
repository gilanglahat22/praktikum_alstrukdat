/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* mtime.c */

#include <stdio.h>
#include "time.h"

int main()
{
    int N = 0, i = 0;
    long waktuMin = 86400, waktuMaks = -1;
    /* Membaca Jumlah Kasus */
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        printf("[%d]\n", i + 1);
        TIME T1, T2;
        BacaTIME(&T1);
        BacaTIME(&T2);
        /* Mengubah nilai waktu maks / waktu min */
        if (TIMEToDetik(T1) > waktuMaks)
            waktuMaks = TIMEToDetik(T1);
        if (TIMEToDetik(T2) > waktuMaks)
            waktuMaks = TIMEToDetik(T2);
        if (TIMEToDetik(T1) < waktuMin)
            waktuMin = TIMEToDetik(T1);
        if (TIMEToDetik(T2) < waktuMin)
            waktuMin = TIMEToDetik(T2);

        printf("%li\n", (TLT(T1, T2)) ? Durasi(T1, T2) : Durasi(T2, T1));
    }
    /* Menulis jam mulai paling awal dan akhir */
    TulisTIME(DetikToTIME(waktuMin));
    printf("\n");
    TulisTIME(DetikToTIME(waktuMaks));
    printf("\n");
    return 0;
}