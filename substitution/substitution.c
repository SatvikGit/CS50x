#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Declares string of alphabets
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, string argv[])
{
    // Checks if user provided right number of arguements
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Checks if user provided 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain only 26 characters\n");
        return 1;
    }

    // Checks if user has provided only alphabetical characters
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only alphabetical characters\n");
            return 1;
        }
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

    // Checks for duplicate characters
    if (matches != 26)
    {
        printf("There can be no duplicate alphabets in the key\n");
        return 1;
    }

    // Converts arguements to uppertext
    for (int i = 0; i < 26; i++)
    {
        if (islower(argv[1][i]))
        {
                      argv[1][i] = toupper(argv[1][i]);
        }
    }

    // Collects input from user
    string plain = get_string("plaintext: ");
    int lenplain = strlen(plain);
    char cipher[lenplain + 1];

    for (int i = 0; i < lenplain; i++)
    {
            // Ciphers uppertext characters
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

            // Ciphers lowetext characters
            else if (islower(plain[i]) != 0)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (plain[i]  == tolower(alpha[j]))
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
    }


    cipher[lenplain] = '\0';

    printf("ciphertext: %s\n", cipher);
    return 0;
}