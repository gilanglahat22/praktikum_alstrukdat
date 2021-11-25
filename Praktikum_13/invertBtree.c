/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* 25 November 2021 */

#include <stdio.h>
#include "bintree.h"

void invertBtree(BinTree *p)
/* I.S. Pohon p terdefinisi */
/* F.S. Pohon p diflip secara vertikal */
/*      Contoh:
           1
         2   5
        3 4 6
        Menjadi:
           1
         5   2
          6 4 3 */
{
    if (!isTreeEmpty(*p))
    {
        invertBtree(&(LEFT(*p)));
        invertBtree(&(RIGHT(*p)));
        *p = NewTree(ROOT(*p), RIGHT(*p), LEFT(*p));
    }
}