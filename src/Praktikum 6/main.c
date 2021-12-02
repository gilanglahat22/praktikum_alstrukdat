#include <stdio.h>
#include <string.h>
#include "charmachine.h"
#include "wordmachine.h"
// gcc -o wordmachine  wordmachine.c main.c  charmachine.c
int main()
{
    startWord();
    while (!endWord)
    {
        for (int i = 0; i < currentWord.length; i++)
        {
            printf("%c", currentWord.contents[i]);
        }
        printf("");
        printf("%d", currentWord.length);
        printf("\n");
        advWord();
    }
    return 0;
}
