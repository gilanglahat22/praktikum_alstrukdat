#include <stdio.h>
#include "boolean.h"
#include "time.h"
#include <math.h>

int main()
{
    int banyak_telepon, a, b, c, d, e, f, detik_1, detik_2, terbesar, terkecil;
    TIME P, Q, Time_terkecil, Time_terbesar;
    terbesar = 0;
    terkecil = 0;
    scanf("%d", &banyak_telepon);
    for (int i = 1; i <= banyak_telepon; i++)
    {
        printf("[%d] \n", i);
        scanf("%d %d %d", &a, &b, &c);
        P = MakeTIME(a, b, c);
        BacaTIME(&P);
        detik_1 = TIMEToDetik(P);
        scanf("%d %d %d", &d, &e, &f);
        Q = MakeTIME(d, e, f);
        BacaTIME(&Q);
        detik_2 = TIMEToDetik(Q);
        printf("%d", abs(detik_1 - detik_2));
        if (detik_1 <= detik_2)
        {
            if (detik_2 >= terbesar)
            {
                terbesar = detik_2;
            }
            if (detik_1 <= terkecil)
            {
                terkecil = detik_1;
            }
        }
        else
        {
            if (detik_1 >= terbesar)
            {
                terbesar = detik_1;
            }
            if (detik_2 <= terkecil)
            {
                terkecil = detik_2;
            }
        }
    }
    Time_terkecil = DetikToTIME(terkecil);
    Time_terbesar = DetikToTIME(terbesar);
    TulisTIME(Time_terkecil);
    TulisTIME(Time_terbesar);
    return 0;
}