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
            if (argv[1][j] = argv[1][i])
            {
                matches++
            }
        }
    }

    if (matches != 26)
    {
        printf("There can be no duplicate alphabets in the key\n");
        return 1;
    }

    string plain = get_string("plaintext: ");
    {
        printf("ciphertext: ");
    }
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