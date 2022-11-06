#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");
    printf("%i\n", letters);
}

int count_letters(string text)
{
    int letters = 0;
    int i = 0;

    for (i = 0; i <= strlen(text); i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            return letters;
            letters++;
        }
    }
    return letters;
}