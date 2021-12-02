/* NAMA : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* cipher.c */

#include <stdio.h>
#include "wordmachine.h"

int main()
{
    int N;
    int TEMP = 0;

    startWord();
    while (!endWord)
    {
        if (TEMP == 0)
        {
            N = currentWord.length;
        }
        TEMP++;
        for (int i = 0; i < currentWord.length; i++)
        {
            TEMP = currentWord.contents[i];
            TEMP += N;
            while (TEMP >= 91)
            {
                TEMP = (TEMP % 91) + 65;
            }
            printf("%c", TEMP);
        }
        advWord();
        if (!endWord)
        {
            printf(" ");
        }
    }
    printf(".\n");
    return 0;
}