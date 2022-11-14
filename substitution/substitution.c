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
        return 1;
    }

    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if ((argv[1][i] <= 'A' && argv[1][i] >= 'Z') || (argv[1][i] <= 'a' && argv[1][i] >= 'z'))
        {
            printf("Key must contain only letters\n");
            return 1;
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
                return 1;
            }
        }
    }

    string plain = get_string("plaintext: ");
    int lenplain = strlen(plain);
    char cipher[lenplain + 1];

    for (int i = 0; i < lenplain; i++)
    {
        if (isupper(plain[i]) != 0)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (plain[i] == alpha[j])
                    {
                        cipher[i] = argv[1][j];
                        break;
                    }
                }
            }

        else if (islower(plain[i]) != 0)
            {
                for (int j = 0; j < strlen(alpha); j++)
                    {
                        if (plain[i] == tolower(alpha[j]))
                        {
                            cipher[i] = tolower(argv[1][j]);
                            break;
                        }
                    }
            }

            else
            {
                cipher[i] = plain[i];
            }

            cipher[lenplain] = '\0';

            printf("ciphertext: %s", cipher);
            return 0;
        }
}