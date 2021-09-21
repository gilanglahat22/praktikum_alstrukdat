#include <stdio.h>
#include "boolean.h"
#include "point.h"
#include "garis.h"
#include "vector.h"
#include <math.h>

VECTOR MakeVector(float x, float y)
/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
{
    VECTOR vektor;
    AbsisComponent(vektor) = x;
    OrdinatComponent(vektor) = y;
    return vektor;
}
void TulisVector(VECTOR v)
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */
{
    printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v));
}
float Magnitude(VECTOR v)
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
{
    return sqrt((AbsisComponent(v) * AbsisComponent(v)) + (OrdinatComponent(v) * OrdinatComponent(v)));
}
VECTOR Add(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
{
    VECTOR v;
    AbsisComponent(v) = AbsisComponent(a) + AbsisComponent(b);
    OrdinatComponent(v) = OrdinatComponent(a) + OrdinatComponent(b);
    return v;
}
VECTOR Substract(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
{
    VECTOR v;
    AbsisComponent(v) = AbsisComponent(a) - AbsisComponent(b);
    OrdinatComponent(v) = OrdinatComponent(a) - OrdinatComponent(b);
    return v;
}
float Dot(VECTOR a, VECTOR b)
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
{
    float v;
    v = AbsisComponent(a) * AbsisComponent(b) + OrdinatComponent(a) * OrdinatComponent(b);
    return v;
}
VECTOR Multiply(VECTOR v, float s)
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * a.x, s * a.y) */
{
    VECTOR r;
    AbsisComponent(r) = AbsisComponent(v) * s;
    OrdinatComponent(r) = OrdinatComponent(v) * s;
    return r;
}