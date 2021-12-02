/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* vector.c */

#include "point.h"
#include "vector.h"
#include <stdio.h>
#include <math.h>
#include "boolean.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk VECTOR *** */
VECTOR MakeVector(float x, float y)
/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */
{
    VECTOR v;
    v.X = x;
    v.Y = y;
    return v;
}
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v)
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */
{
    printf("<%.2f,%.2f>", v.X, v.Y);
}
/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v)
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
{
    return (sqrt(pow(v.X, 2) + pow(v.Y, 2)));
}
VECTOR Add(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
{
    VECTOR RS;
    RS.X = a.X + b.X;
    RS.Y = a.Y + b.Y;
    return RS;
}
VECTOR Substract(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
{
    VECTOR RS;
    RS.X = a.X - b.X;
    RS.Y = a.Y - b.Y;
    return RS;
}
float Dot(VECTOR a, VECTOR b)
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
{
    return a.X * b.X + a.Y * b.Y;
}
VECTOR Multiply(VECTOR v, float s)
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * a.x, s * a.y) */
{
    VECTOR RS;
    RS.X = v.X * s;
    RS.Y = v.Y * s;
    return RS;
}