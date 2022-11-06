#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char count_letters(string text);
int i;

int main(void)
{
    string text = get_string("Text: ");
    char number_letters = count_letters(text);
    printf("%c\n", number_letters);
}

char count_letters(string text)
{
    for (i = 0; i < strlen(text); i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        return text[i];
    }
    return i;
}