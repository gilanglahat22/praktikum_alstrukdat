/* NAMA : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* 21 Oktober 2021 */
#include <stdio.h>
#include "stack.h"
#include "tokenmachine.h"
#include "charmachine.h"
#include <math.h>

int main()
{
    Stack S;
    ElType op1, op2;
    char x;
    /*algoritma*/
    CreateStack(&S);
    startToken();
    while (!endToken)
    {
        if (currentToken.val < 0)
        {
            Pop(&S, &op2);
            Pop(&S, &op1);
            x = currentToken.tkn;
            printf("%d %c %d\n", op1, x, op2);
            switch (x)
            {
            case '*':
                op1 *= op2;
                break;
            case '/':
                op1 /= op2;
                break;
            case '+':
                op1 += op2;
                break;
            case '-':
                op1 -= op2;
                break;
            case '^':
                pow(op1, op2);
                break;
            }
            Push(&S, op1);
        }
        else
        {
            Push(&S, currentToken.val);
            ElType x;
            Stack R;
            CreateEmpty(&R);
            while (!isEmpty(S))
            {
                pop(&S, &x);
                printf("%d ", x);
                push(&R, x);
            } // R inverse S
            while (!isEmpty(R))
            {
                pop(&R, &x);
                push(&S, x);
            }
            printf("\n");
            advToken(0);
        }
    }
    if (isEmpty(S))
    {
        printf("Ekspresi kosong\n");
    }
    else
    {
        printf("Hasil: %d\n", TOP(S));
    }
    return 0;
}
