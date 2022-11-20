#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain only 26 characters\n");
        return 1;
    }

    int matches = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; argv[1][j] != '\0'; j++)
        {
            if (argv[1][j] == argv[1][i])
            {
                matches++;
            }
        }
    }

    if (matches != 26)
    {
        printf("There can be no duplicate alphabets in the key\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (islower(argv[1][i]))
        {
                      argv[1][i] = toupper(argv[1][i]);
        }
    }

    string plain = get_string("plaintext: ");
    int lenplain = strlen(plain);
    char cipher[lenplain + 1];

    for (int i = 0; i < lenplain, i++)
    {
        for (int j = 0; i < 26; j++)
        {
            if (isupper(argv[1][i]))
            {
                argv[1][i] = isupper(argv[1][i]
            }
        }
    }
}