/* Nama : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* 25 November 2021 */

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

BinTree REK(int h)
{
    int A;
    if (h == 0)
    {
        scanf("%d", &A);
        return newTreeNode(A);
    }
    else
    {
        A = 0;
        BinTree root = newTreeNode(A);
        LEFT(root) = REK(h - 1);
        RIGHT(root) = REK(h - 1);
        ROOT(root) = ROOT(LEFT(root)) + ROOT(RIGHT(root));
        return root;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    long long i = 1;
    int count = 0;
    while (i < N)
    {
        count++;
        i <<= 1;
    }
    if (i > N)
        printf("Jumlah masukan tidak sesuai\n");
    else // jika i == N
    {
        BinTree T = REK(count);
        printTree(T, 2);
    }
    return 0;
}