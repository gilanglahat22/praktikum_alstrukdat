/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
#include <stdio.h>
#include "prioqueue.h"

int main()
{
    PrioQueue pq;
    CreatePrioQueue(&pq);
    ElType element;
    int N;
    scanf("%d", &N);
    int T, I, M, D;
    if (N != 0)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d %d %d", &T, &I, &M, &D);
            element.tArrival = T; /* Time */
            element.id = I;       /* ID */
            element.score = M;    /* Mark */
            element.dService = D; /* Waktu Pelayanan */
            enqueue(&pq, element);
        }
        /* Sorting */
        int u;
        ElType temp;
        for (int i = IDX_HEAD(pq); i <= IDX_TAIL(pq); i++)
        {
            if (i == IDX_HEAD(pq))
            {
                u = ((pq).buffer[i]).tArrival + ((pq).buffer[i]).dService;
            }
            else
            {
                if ((pq).buffer[i].tArrival >= u)
                {
                    u = ((pq).buffer[i]).tArrival + ((pq).buffer[i]).dService;
                }
                else
                {
                    int p = i;
                    while (((pq).buffer[p]).tArrival < u)
                    {
                        p++;
                    }
                    int r = i;
                    for (int o = i + 1; o < p; o++)
                    {
                        if ((pq).buffer[r].score < (pq).buffer[o].score)
                        {
                            r = o;
                        }
                    }
                    temp = (pq).buffer[i];
                    (pq).buffer[i] = (pq).buffer[r];
                    (pq).buffer[r] = temp;
                    u += ((pq).buffer[i]).dService;
                }
            }
        }
        /* Menampilkan ke layar */
        int t, j, W, y;
        for (int i = IDX_HEAD(pq); i <= IDX_TAIL(pq); i++)
        {
            if (i == IDX_HEAD(pq))
            {
                t = ((pq).buffer[i]).tArrival;
                j = ((pq).buffer[i]).id;
                W = 0;
            }
            else
            {
                if (((pq).buffer[i]).tArrival < ((pq).buffer[i - 1]).dService + ((pq).buffer[i - 1]).tArrival)
                {
                    t = t + ((pq).buffer[i - 1]).dService;
                    j = ((pq).buffer[i]).id;
                    W = t - ((pq).buffer[i]).tArrival;
                }
                else
                {
                    t = ((pq).buffer[i]).tArrival;
                    j = j = ((pq).buffer[i]).id;
                    W = 0;
                }
            }
            printf("%d %d %d\n", t, j, W);
        }
    }
    else
    {
        printf("Tidak ada layanan");
    }
    return 0;
}
