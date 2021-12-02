/* NAMA : Muhammad Gilang Ramadhan */
/* NIM  : 13520137 */
/* 30 September 2021 */
/* tokenmachine */

#include <stdio.h>
#include "tokenmachine.h"
#include "charmachine.h"

boolean endToken;
Token currentToken;

void ignoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while ((currentChar == BLANK) && (currentChar != MARK))
    {
        adv();
    }
}
void startToken()
/* I.S. : currentChar sembarang
   F.S. : endToken = true, dan currentChar = MARK;
          atau endToken = false, currentToken adalah Token yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir Token */
{
    start();
    ignoreBlank();
    if (currentChar == MARK)
    {
        endToken = true;
    }
    else
    {
        endToken = false;
        salinToken();
    }
}
void advToken()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentToken adalah Token terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, maka endToken = true
   Proses : Akuisisi kata menggunakan procedure salinToken */
{
    ignoreBlank();
    if (currentChar == MARK)
    {
        endToken = true;
    }
    else
    {
        salinToken();
        ignoreBlank();
    }
}
void salinToken()
/* Mengakuisisi Token dan menyimpan hasilnya dalam currentToken
   I.S. : currentChar adalah karakter pertama dari Token
   F.S. : currentToken berisi Token yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata "dipotong" */
{
    int increment = 1;
    currentToken.val = 0;

    while ((currentChar != MARK) && (currentChar != BLANK) && (increment <= CAPACITY))
    {
        if ((currentChar != '+') && (currentChar != '-') && (currentChar != '*') && (currentChar != '/') && (currentChar != '^'))
        {
            switch (currentChar)
            {
            case '1':
                currentToken.val = currentToken.val * 10 + 1;
                break;
            case '2':
                currentToken.val = currentToken.val * 10 + 2;
                break;
            case '3':
                currentToken.val = currentToken.val * 10 + 3;
                break;
            case '4':
                currentToken.val = currentToken.val * 10 + 4;
                break;
            case '5':
                currentToken.val = currentToken.val * 10 + 5;
                break;
            case '6':
                currentToken.val = currentToken.val * 10 + 6;
                break;
            case '7':
                currentToken.val = currentToken.val * 10 + 7;
                break;
            case '8':
                currentToken.val = currentToken.val * 10 + 8;
                break;
            case '9':
                currentToken.val = currentToken.val * 10 + 9;
                break;
            default:
                currentToken.val = currentToken.val * 10 + 0;
                break;
            }
            currentToken.tkn = 'b';
        }
        else
        {
            currentToken.tkn = currentChar;
            currentToken.val = -1;
        }
        adv();
        increment++;
    }
}
