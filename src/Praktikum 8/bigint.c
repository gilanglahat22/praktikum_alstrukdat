#include <stdio.h>
#include "stack.h"

int CharToInt(char X)
{
    if (X == '0')
    {
        return 0;
    }
    else if (X == '1')
    {
        return 1;
    }
    else if (X == '2')
    {
        return 2;
    }
    else if (X == '3')
    {
        return 3;
    }
    else if (X == '4')
    {
        return 4;
    }
    else if (X == '5')
    {
        return 5;
    }
    else if (X == '6')
    {
        return 6;
    }
    else if (X == '7')
    {
        return 7;
    }
    else if (X == '8')
    {
        return 8;
    }
    else if (X == '9')
    {
        return 9;
    }
}

int main()
{
    char i1 = 'Y';
    char i2 = 'X';
    Stack S1, S2, S3;
    CreateStack(&S1);
    CreateStack(&S2);
    CreateStack(&S3);
    int buang1, buang2;
    while (i1 != '#')
    {
        scanf("%c", &i1);
        if (i1 != '#' && i1 != '\n' && i1 != ' ')
        {
            push(&S1, CharToInt(i1));
        }
    }
    while (i2 != '#')
    {
        scanf("%c", &i2);
        if (i2 != '#' && i2 != '\n' && i2 != ' ')
        {
            push(&S2, CharToInt(i2));
        }
    }
    int count1;
    int count2;
    int A;
    int B = 0;

    while ((IDX_TOP(S1) != IDX_UNDEF) && (IDX_TOP(S2) != IDX_UNDEF))
    {
        if (IDX_TOP(S1) == IDX_TOP(S2))
        {
            if (IDX_TOP(S1) == 0)
            {
                A = (TOP(S1) + TOP(S2) + B);
            }
            else
            {
                A = (TOP(S1) + TOP(S2) + B) % 10;
                B = (TOP(S1) + TOP(S2) + B - A) / 10;
            }
        }
        else
        {
            A = (TOP(S1) + TOP(S2) + B) % 10;
            B = (TOP(S1) + TOP(S2) + B - A) / 10;
        }
        push(&S3, A);
        pop(&S1, &count1);
        pop(&S2, &count2);
    }
    while (IDX_TOP(S1) != IDX_UNDEF)
    {
        if (IDX_TOP(S1) == 0)
        {
            A = (TOP(S1) + B);
        }
        else
        {
            A = (TOP(S1) + B) % 10;
            B = (TOP(S1) + B - A) / 10;
        }
        push(&S3, A);
        pop(&S1, &count1);
    }
    while (IDX_TOP(S2) != IDX_UNDEF)
    {
        if (IDX_TOP(S2) == 0)
        {
            A = (TOP(S2) + B);
        }
        else
        {
            A = (TOP(S2) + B) % 10;
            B = (TOP(S2) + B - A) / 10;
        }
        push(&S3, A);
        pop(&S2, &count2);
    }
    int count3 = IDX_TOP(S3);
    while (count3 != IDX_UNDEF)
    {
        printf("%d", S3.buffer[count3]);
        count3 -= 1;
    }
    printf("\n");

    return 0;
}