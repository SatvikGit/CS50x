#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int N = 26;
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int letters[N];
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if ((argv[1][i] < 'A' && argv[1][i] > 'Z') || (argv[1][i] < 'a' && argv[1][i] > 'z'))
        {
            printf("Key must contain only letters\n");
            return 2;
        }

        else if (islower(argv[1][i]))
        {
            argv[1][i] = toupper(argv[1][i]);
        }
    }

    for (int j = 0; j < N; j++)
    {
        for (int k = (j + 1); k < N; k++)
        {
            if (argv[j] == argv[k])
            {
                printf("There can be no duplicate alphabets in the key\n");
                return 3;
            }
        }
        letters[i] = argv[1][i];
    }

    string plain = get_string("plaintext: ");
    int lenplain = strlen(plain);
    char cipher[lenplain + 1];

    for (int i = 0; i < lenplain; i++)
    {
        if (isupper(plain[i]) != 0)
            {
                for (int j = 0; j < N; j++)
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

            printf("ciphertext: %s\n", cipher);
            return 0;
        }
}