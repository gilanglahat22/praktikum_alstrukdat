/* NAMA : Muhammad Gilang Ramadhan */
/* NIM : 13520137 */
/* 4 November 2021 */

#include <stdio.h>
#include "list_circular.h"

void deleteRR(List *l, ElType tQ)
/* Jika l tidak kosong, "menghapus" elemen terakhir list l, misal last, sesuai aturan round robin, yaitu:
- jika INFO(last)>tQ, maka last "diantrikan" kembali sebagai first elemen dengan INFO(last)=INFO(last)-tQ
- jika INFO(last)<=tQ, maka deleteLast(l,x) dan menampilkan x ke layar */
/* Jika l kosong, cetak "List kosong" */
/* I.S. tQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir l diproses sesuai aturan round-robin.
l mungkin menjadi kosong. */
{
    ElType T;
    if (!isEmpty(*l))
    {
        ElType val;
        deleteLast(l, &val);
        if (val > tQ)
        {
            printf("%d\n", tQ);
            val -= tQ;
            insertFirst(l, val);
        }
        else
        {
            printf("%d\n", val);
        }
    }
    else
    {
        printf("List kosong\n");
    }
}

float average(List l)
/* Menghasilkan nilai rata-rata elemen l. l tidak kosong. */
{
    float sum = 0;
    int count = 0;

    Address P = FIRST(l);
    do
    {
        sum += INFO(P);
        count += 1;
        P = NEXT(P);

    } while (P != FIRST(l));

    return sum / count;
}

int main(void)
{
    boolean is_inputTrue = false;
    ElType TQ = -1;
    int N;
    List l;
    CreateList(&l);
    while (is_inputTrue == false) /* Kalo seaindainya input TQ tidak sesuai yaitu <= 0*/
    {
        scanf("%d", &TQ);
        if (TQ <= 0)
        {
            is_inputTrue = false;
        }
        else
        {
            is_inputTrue = true;
        }
    }
    char cc;
    while (true)
    {
        scanf("\n%c", &cc);
        if (cc == 'A') /* kalo cc = A */
        {
            scanf("%d", &N);
            if (N > 0) /* Kalo seandainya N > 0 */
            {
                insertFirst(&l, N);
            }
        }
        else if (cc == 'D') /* kalo cc = D */
        {
            deleteRR(&l, TQ);
        }
        else if (cc == 'F') /* kalo cc = F */
        {
            break;
        }
        else /* kalo cc selain A, D, F */
        {
            printf("Kode salah\n");
        }
    }

    if (!isEmpty(l)) /* kalo isi list kosong */
    {
        float avg = average(l);
        printf("%.2f\n", avg);
    }
    else /* kalo tidak, ini sudah masuk tahap akhir */
    {
        printf("Proses selesai\n");
    }
}