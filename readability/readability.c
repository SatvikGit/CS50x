#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int i;

int main(void)
{
    string text = get_string("Text: ");
    i = strlen(text);
    printf("%i\n", i);
}

int count_letters(string text)
