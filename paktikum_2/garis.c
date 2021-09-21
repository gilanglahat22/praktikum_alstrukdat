#include <stdio.h>
#include "boolean.h"
#include "point.h"
#include "garis.h"
#include <math.h>

void MakeGARIS(POINT P1, POINT P2, GARIS *L)
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
{
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}
void BacaGARIS(GARIS *L)
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk GARIS yang valid 
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
   "Garis tidak valid" */
/* Contoh:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3 
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */
{
    POINT P1, P2;
    P1 = PAwal(*L);
    P2 = PAkhir(*L);
    scanf("%f %f", &Absis(P1), &Ordinat(P1));
    scanf("%f %f", &Absis(P2), &Ordinat(P2));
    if ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)))
    {
        printf("Garis tidak valid");
    }
    else
    {
        printf("Terbentuk garis L dengan L.PAw= %f dan L.PAkh = %f \n", P1, P2);
    }
}
void TulisGARIS(GARIS L)
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */
{
    float x1, y1, x2, y2;
    x1 = Absis(PAwal(L));
    y1 = Ordinat(PAwal(L));
    x2 = Absis(PAkhir(L));
    y2 = Ordinat(PAkhir(L));
    printf("(%f %f), (%f %f)", x1, y1, x2, y2);
}

/* *** Kelompok operasi garis *** */
float PanjangGARIS(GARIS L)
{
    POINT P1, P2;
    P1 = PAwal(L);
    P2 = PAkhir(L);
    return Panjang(P1, P2);
}

/* Menghitung panjang garis L : berikan rumusnya */
float Gradien(GARIS L)
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
{
    POINT P1, P2;
    P1 = PAwal(L);
    P2 = PAkhir(L);
    return ((Ordinat(P2) - Ordinat(P1)) / (Absis(P2) - Absis(P1)));
}
void GeserGARIS(GARIS *L, float deltaX, float deltaY)
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */
{
    POINT P1, P2;
    P1 = PAwal(*L);
    P2 = PAkhir(*L);
    Absis(P1) += deltaX;
    Absis(P2) += deltaX;
    Ordinat(P1) += deltaY;
    Ordinat(P2) += deltaY;
}
/* *** Kelompok predikat *** */
boolean IsTegakLurus(GARIS L1, GARIS L2)
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
{
    return (Gradien(L1) * Gradien(L2) == -1);
}
boolean IsSejajar(GARIS L1, GARIS L2)
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
{
    return (Gradien(L1) == Gradien(L2));
}