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

    for (int i = 0; i < strlen(plain); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (isalpha(plain[i]))
            {
                if (islower(plain[i]))
                {
                    if (plain[i] == alpha[j])
                    {
                        plain[i] = tolower(argv[1][j]);
                    }
                }

                else if (isupper(plain[i]))
                {
                    if (alpha[j] == tolower(plain[i]))
                    {
                        plain[i] = toupper(argv[1][j]);
                    }
                }
            }
        }

        if (!isalpha(plain[i]))
        {
            printf("%c", plain[i]);
        }
        printf("ciphertext: %c\n", plain[i]);
        return 0;
    }
}