#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string);

int main(void)
{
    string Text = get_string("Text: ");
    printf("%i\n", i);
}

int count_letters(string)
{
    int i = 0;
    for (int i = 0; i < strlen(Text); i++)
    {
        if isupper(Text[i]) || islower(Text[i])
        {
            return i;
        }
    }
}