/* NAMA : MUHAMMAD GILANG RAMADHAN */
/* NIM  : 13520137 */
/* 23 September 2021 */

#include <stdio.h>
#include "matrix.h"

/* Operasi berbasis baris dan per kolom */

float rowMean(Matrix m, Index i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
    int sum = 0;
    for (int j = 0; j < COLS(m); j++)
    {
        sum += ELMT(m, i, j);
    }
    return (sum / COLS(m));
}

float colMean(Matrix m, Index j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
    int sum = 0;
    for (int i = 0; i < ROWS(m); i++)
    {
        sum += ELMT(m, i, j);
    }
    return (sum / ROWS(m));
}

void rowExtremes(Matrix m, Index i, ElType *max, ElType *min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
    *max = ELMT(m, i, 0);
    *min = ELMT(m, i, 0);
    for (int j = 1; j < COLS(m); j++)
    {
        if (*max <= ELMT(m, i, j))
        {
            *max = ELMT(m, i, j);
        }
        if (*min >= ELMT(m, i, j))
        {
            *min = ELMT(m, i, j);
        }
    }
}

void colExtremes(Matrix m, Index j, ElType *max, ElType *min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
    *max = ELMT(m, 0, j);
    *min = ELMT(m, 0, j);
    for (int i = 1; i < ROWS(m); i++)
    {
        if (*max <= ELMT(m, i, j))
        {
            *max = ELMT(m, i, j);
        }
        if (*min >= ELMT(m, i, j))
        {
            *min = ELMT(m, i, j);
        }
    }
}

int countValOnRow(Matrix m, Index i, ElType val)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
    int banyaknya_kemunculan = 0;
    for (int j = 0; j < COLS(m); j++)
    {
        if (ELMT(m, i, j) == val)
        {
            banyaknya_kemunculan += 1;
        }
    }
    return banyaknya_kemunculan;
}

int countValOnCol(Matrix m, Index j, ElType val)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
    int banyaknya_kemunculan = 0;
    for (int i = 0; i < ROWS(m); i++)
    {
        if (ELMT(m, i, j) == val)
        {
            banyaknya_kemunculan += 1;
        }
    }
    return banyaknya_kemunculan;
}