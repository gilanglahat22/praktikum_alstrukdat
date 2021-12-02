/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */

#include <stdio.h>
#include <stdlib.h>
#include "queue_linked.h"

int main()
{
    int banyak_pengguna;
    int waktu;
    int waktu_sebelum;
    Queue Tampungan_waktu;
    int count = 0;
    CreateQueue(&Tampungan_waktu);
    scanf("%d", &banyak_pengguna);
    int A[banyak_pengguna];
    for (int i = 0; i < banyak_pengguna; i++)
    {
        scanf("%d", &waktu);
        enqueue(&Tampungan_waktu, waktu);
        A[i] = waktu;
    }
    for (int i = 0; i < banyak_pengguna; i++)
    {
        dequeue(&Tampungan_waktu, &waktu_sebelum);
        if (i == 0)
        {
            count++;
        }
        else
        {
            count = 1;
            for (int j = 0; j < i; j++)
            {
                if (waktu_sebelum - A[j] <= 300)
                {
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}