/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */

#include <stdio.h>
#include "matrix.h"
#include "math.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m)
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
{
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}
/* *** Selektor *** */
/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j)
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */
{
    return ((i >= 0 && i <= ROW_CAP - 1) && (j >= 0 && j <= COL_CAP - 1));
}
/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m)
/* Mengirimkan Index baris terbesar m */
{
    return (ROWS(m) - 1);
}
Index getLastIdxCol(Matrix m)
/* Mengirimkan Index kolom terbesar m */
{
    return (COLS(m) - 1);
}
boolean isIdxEff(Matrix m, Index i, Index j)
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
{
    return ((i >= 0 && i <= ROWS(m) - 1) && (j >= 0 && j <= COLS(m) - 1));
}
ElType getElmtDiagonal(Matrix m, Index i)
/* Mengirimkan elemen m(i,i) */
{
    return ELMT(m, i, i);
}
/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes)
/* Melakukan assignment MRes = MIn */
{
    Index i, j;
    CreateMatrix(ROWS(mIn), COLS(mIn), mRes);
    for (i = 0; i <= ROWS(mIn) - 1; i++)
    {
        for (j = 0; j <= COLS(mIn) - 1; j++)
        {
            ELMT(*mRes, i, j) = ELMT(mIn, i, j);
        }
    }
}
/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    Index i, j;
    ElType num;
    num = 0;
    CreateMatrix(nRow, nCol, m);
    for (i = 0; i <= ROWS(*m) - 1; i++)
    {
        for (j = 0; j <= COLS(*m) - 1; j++)
        {
            if (j == COLS(*m) - 1)
            {
                if (i != ROWS(*m) - 1)
                {
                    scanf("%d\n", &num);
                }
                else
                {
                    scanf("%d", &num);
                }
            }
            else
            {
                scanf("%d ", &num);
            }
            ELMT(*m, i, j) = num;
        }
    }
}
void displayMatrix(Matrix m)
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    Index i, j;
    for (i = 0; i <= ROWS(m) - 1; i++)
    {
        for (j = 0; j <= COLS(m) - 1; j++)
        {
            printf("%d", ELMT(m, i, j));
            if (j < COLS(m) - 1)
            {
                printf(" ");
            }
            else
            {
                if (i != ROWS(m) - 1)
                {
                    printf("\n");
                }
            }
        }
    }
}
/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
{
    Index i, j;
    Matrix MHs;
    CreateMatrix(ROWS(m1), COLS(m1), &MHs);
    for (i = 0; i <= ROWS(m1) - 1; i++)
    {
        for (j = 0; j <= COLS(m1) - 1; j++)
        {
            ELMT(MHs, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return MHs;
}
Matrix subtractMatrix(Matrix m1, Matrix m2)
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
{
    Index i, j;
    Matrix MHs;
    CreateMatrix(ROWS(m1), COLS(m1), &MHs);
    for (i = 0; i <= ROWS(m1) - 1; i++)
    {
        for (j = 0; j <= COLS(m1) - 1; j++)
        {
            ELMT(MHs, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return MHs;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2)
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
{
    Index i, j, k;
    ElType sum;
    Matrix MHs;
    CreateMatrix(ROWS(m1), COLS(m1), &MHs);
    for (i = 0; i <= ROWS(m1) - 1; i++)
    {
        for (j = 0; j <= COLS(m1) - 1; j++)
        {
            sum = 0;
            for (k = 0; k <= COLS(m1) - 1; k++)
            {
                sum += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
            ELMT(MHs, i, j) = sum;
        }
    }
    return MHs;
}
Matrix multiplyConst(Matrix m, ElType x)
/* Mengirim hasil perkalian setiap elemen m dengan x */
{
    Index i, j;
    Matrix MHs;
    CreateMatrix(ROWS(m), COLS(m), &MHs);
    for (i = 0; i <= ROWS(m) - 1; i++)
    {
        for (j = 0; j <= COLS(m) - 1; j++)
        {
            ELMT(MHs, i, j) = ELMT(m, i, j) * x;
        }
    }
    return MHs;
}
void pMultiplyConst(Matrix *m, ElType k)
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
{
    Index i, j;
    for (i = 0; i <= ROWS(*m) - 1; i++)
    {
        for (j = 0; j <= COLS(*m) - 1; j++)
        {
            ELMT(*m, i, j) = ELMT(*m, i, j) * k;
        }
    }
}
/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
{
    Index i, j;
    if ((COLS(m1) == COLS(m2)) && (ROWS(m1) == ROWS(m2)))
    {
        for (i = 0; i <= ROWS(m1) - 1; i++)
        {
            for (j = 0; j <= COLS(m1) - 1; j++)
            {
                if (ELMT(m1, i, j) != ELMT(m2, i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
boolean isNotEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika m1 tidak sama dengan m2 */
{
    return !(isEqual(m1, m2));
}
boolean isSizeEqual(Matrix m1, Matrix m2)
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
{
    return ((COLS(m1) == COLS(m2)) && (ROWS(m1) == ROWS(m2)));
}
/* ********** Operasi lain ********** */
int count(Matrix m)
/* Mengirimkan banyaknya elemen m */
{
    return (ROWS(m) * COLS(m));
}
/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
{
    return (COLS(m) == ROWS(m));
}
boolean isSymmetric(Matrix m)
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
{
    Index i, j;
    if (!(isSquare(m)))
    {
        return false;
    }
    else
    {
        for (i = 0; i <= ROWS(m) - 1; i++)
        {
            for (j = 0; j <= COLS(m) - 1; j++)
            {
                if (ELMT(m, i, j) != ELMT(m, j, i))
                {
                    return false;
                }
            }
        }
        return true;
    }
}
boolean isIdentity(Matrix m)
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    Index i, j;

    if (!(isSquare(m)))
    {
        return false;
    }
    else
    {
        for (i = 0; i <= ROWS(m) - 1; i++)
        {
            for (j = 0; j <= COLS(m) - 1; j++)
            {
                if (i == j)
                {
                    if (ELMT(m, i, j) != 1)
                    {
                        return false;
                    }
                }
                else
                {
                    if (ELMT(m, i, j) != 0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
boolean isSparse(Matrix m)
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    Index i, j;
    int counter = 0;
    int limit = ROWS(m) * COLS(m) * 0.05;

    for (i = 0; i <= ROWS(m) - 1; i++)
    {
        for (j = 0; j <= COLS(m) - 1; j++)
        {
            if (ELMT(m, i, j) != 0)
            {
                counter += 1;
            }
        }
    }

    if (counter <= limit)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Matrix inverse1(Matrix m)
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    return multiplyConst(m, -1);
}
void pInverse1(Matrix *m)
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    pMultiplyConst(m, -1);
}
float determinant(Matrix m)
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
{
    float temp;
    float ratio, det = 1;
    int i, j, k;
    /* Applying Gauss Elimination */
    for (i = 0; i < ROWS(m); i++)
    {
        if (ELMT(m, i, i) == 0)
        {
            k = i + 1;
            while (ELMT(m, k, i) == 0 && k < ROWS(m))
            {
                k += 1;
            }
            if (k >= ROWS(m))
            {
                return 0;
            }
            else
            {
                for (int u = 0; u < ROWS(m); u++)
                {
                    temp = ELMT(m, i, u);
                    ELMT(m, i, u) = ELMT(m, k, u);
                    ELMT(m, k, u) = temp;
                }
                det *= -1;
            }
        }
        for (j = i + 1; j < ROWS(m); j++)
        {
            ratio = ELMT(m, j, i) / ELMT(m, i, i);

            for (int l = 0; l < ROWS(m); l++)
            {
                ELMT(m, j, l) = ELMT(m, j, l) - (ratio * ELMT(m, i, l));
            }
        }
    }
    for (i = 0; i < ROWS(m); i++)
    {
        det = det * ELMT(m, i, i);
    }
    if (det == -0)
    {
        return 0;
    }
    else
    {
        return det;
    }
}
void transpose(Matrix *m)
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
{
    ElType temp;
    Index i, j;

    for (i = 0; i <= ROWS(*m) - 1; i++)
    {
        for (j = i; j <= COLS(*m) - 1; j++)
        {
            temp = ELMT(*m, i, j);
            ELMT(*m, i, j) = ELMT(*m, j, i);
            ELMT(*m, j, i) = temp;
        }
    }
}