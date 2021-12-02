#include <stdio.h>
#include "matrix.h"

int main()
{
    int N, TC, M;
    int j, t, u, k;
    int maximum_1 = 0;
    int maximum_2 = 0;
    int X = 0;
    Matrix m;
    scanf("%d\n", &TC);
    for (int i = 0; i < TC; i++)
    {
        scanf("%d\n", &N);
        readMatrix(&m, N, N);
        scanf("%d\n", &M);
        for (j = 0; j <= N - M; j++)
        {
            for (t = 0; t <= N - M; t++)
            {
                if (j == 0 && t == 0)
                {
                    for (u = 0; u <= M - 1; u++)
                    {
                        for (k = 0; k <= M - 1; k++)
                        {
                            maximum_1 += ELMT(m, u, k);
                        }
                    }
                }
                else
                {
                    for (u = j; u <= j + M - 1; u++)
                    {
                        for (k = t; k <= t + M - 1; k++)
                        {
                            maximum_2 += ELMT(m, u, k);
                        }
                    }
                    if (maximum_1 <= maximum_2)
                    {
                        maximum_1 = maximum_2;
                    }
                    maximum_2 = 0;
                }
            }
        }
        X = maximum_1;
        maximum_1 = 0;
        printf("%d\n", X);
    }
    return 0;
}