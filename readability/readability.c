#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int i;

int main(void)
{
    string text = get_string("Text: ");
    int number_letters = count_letters(text);
    printf("%i\n", number_letters);
}

int count_letters(string text)
{
    for (i = 0; i < strlen(text); i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        return strlen(text);
    }
    return strlen(text);
}