#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    const string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

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
        if ((argv[1][i] <= 'A' && argv[1][i] >= 'Z') || (argv[1][i] <= 'a' && argv[1][i] >= 'z'))
        {
            printf("Key must contain only letters\n");
        }

        else if (islower(argv[1][i]))
        {
            argv[1][i] = toupper(argv[1][i]);
        }
    }

    for (int j = 0; j < 26; j++)
    {
        for (int k = (j + 1); k < 26; k++)
        {
            if (argv[1][j] == argv[1][k])
            {
                printf("There can be no duplicate alphabets in the key\n");
            }
        }
    }

    string plain = get_string("plaintext: ");
    printf("ciphertext: ");
    int lenplain = strlen(plain);

    for (int i = 0; i < lenplain; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (isalpha(plain[i]))
            {
                if (isupper(plain[i]))
                {
                    plain[i] = alpha[j];
                    plain[i] = toupper(plain[i]);
                }

                else if (islower(plain[i]))
                {
                    plain[i] = alpha[j];
                    plain[i] = tolower(plain[i]);
                }
            }

            else
            {
                printf("%c", plain[i]);
            }

            printf("%c", plain[i]);
        }
    }

}