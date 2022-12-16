#include <string.h>

#include "../include/utils.h"

char *strToLower(char *word)
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z') // ou if(c >= 65 && c <= 90)
        {
            word[i] = word[i] + 'a' - 'A'; // ou m = c + 32;
        }
    }
    return word;
}