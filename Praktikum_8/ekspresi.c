/* NAMA : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* 21 Oktober 2021 */
#include <stdio.h>
#include "stack.h"
#include "tokenmachine.h"
#include <math.h>

int main()
{
    Stack S;
    CreateStack(&S);
    int op1, op2, opr;
    startToken();
    //
    while (!endToken)
    {
        if (currentToken.tkn == 'b')
        {
            printf("%d\n", currentToken.val);
            push(&S, currentToken.val);
        }
        else
        {
            pop(&S, &op2);
            pop(&S, &op1);
            printf("%d %c %d\n", op1, currentToken.tkn, op2);
            if (currentToken.tkn == '+')
            {
                opr = op1 + op2;
            }
            else if (currentToken.tkn == '-')
            {
                opr = op1 - op2;
            }
            else if (currentToken.tkn == '*')
            {
                opr = op1 * op2;
            }
            else if (currentToken.tkn == '/')
            {
                opr = op1 / op2;
            }
            else
            {
                opr = pow(op1, op2);
            }
            push(&S, opr);
            printf("%d\n", opr);
        }
        advToken();
    }
    if (isEmpty(S))
    {
        printf("Ekspresi kosong\n");
    }
    else
    {
        pop(&S, &opr);
        printf("Hasil=%d\n", opr);
    }
    //
    return 0;
}