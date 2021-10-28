#include <stdio.h>
#include <string.h>
#include "charmachine.h"
#include "wordmachine.h"
int main()
{
    startWord();
    printf("%d", currentWord.length);
    /*while (!endWord)
    {
        int k = currentWord.contents[0];

        for (int i = 0; i < currentWord.length; i++)
        {
            for (int j = 0; j < strlen(currentWord.contents[i]); j++)
            {
                printf("%s", currentWord.contents[i]);
            }
        }
        advWord();
    } */
    return 0;
}