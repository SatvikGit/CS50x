#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>

int main(int argc, string argv[])
 {

    // check for 2 arguments only
    if (argc != 2)
    {
        printf(" ./substitution key\n");
        return 1;
    }

    // once I check for correct argv put key into an int k
    string key = (argv[1]);

    // check if the keylength is 26
    if (strlen(key)!=26)
    {
        printf("Nope only 26 letters\n");
        return 1;
    }
//Check for duplicate characters (case-insensitive)
   { int matches = 0;

    for (int i = 0; i<26; i++)
    {
        for (int j = 0; argv[1][j] != '\0'; j++)
        {

            if (argv[1][j] == argv[1][i])
            {
                matches++;
            }
        }
    }
if (matches!= 26)
    {
        printf("do not repeat letters in key\n");
        return 1;
    }
    }

    {
        // prompt user for a code to encrypt
        string code = get_string("enter text:");
        {
// print ciphertext

printf("ciphertext: ");
}{

{
 string abc = "abcdefghijklmnopqrstuvwxyz"; // initialize lower case alpha in a string abc
 {
 for (int i = 0, n = strlen(code); i < n; i++)
 {
     for (int j = 0; j < 26; j++)

            {
{
 if(isalpha(code[i]))
{
                //check if the letter is uppercase or lowercase then convert
                if( islower(code[i]))
                {
                if(code[i]==abc[j] ) // equating code to string abc and converting key to lowercase to encrypt code

                        {   code[i] = tolower(key[j]);
                        }


                }

                 if (isupper(code[i]))
                {
                        if(abc[j] == tolower(code[i]))
                        {
                            code[i] = toupper(key[j]); //converting key to uppercase since code is in uppercase
}

                            }
                            }
                            }

                            { // for characters that arent alphabets
                              if (!isalpha(code[i]))
                 {
                     printf("%c", code[i]); // print other characters using %c
                 }
}
              printf("ciphertext: %c\n", code[i]); // print alphabets using %s as we initialized ciphertext as string
              }
            return 0;
            }
            }
}
 }
    }
 }