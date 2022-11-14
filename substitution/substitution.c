#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int i;
    APLHA[] = [ABCDEFGHIJKLMNOPQRSTUVWXYZ]

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
    }

    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
    }

    for (int i = 0; i < 26; i++)
    {
        if (int argv[1][i] <= 65 && int argv[1][i] >= 90 || int argv[1][i] <= 97 && int argv[1][i] >= 122)
        {
            printf("Key must contain only letters\n")
        }
    }
}