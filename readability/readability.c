#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int l = count_letters(text);
    int w = count_words(text);
    int s = count_sentences(text);
    printf("%i\n", l);
    printf("%i\n", w);
    printf("%i\n", s);
}

int count_letters(string text)
{
    int letters = 0;
    int i = 0;

    for (i = 0; i <= strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    int j = 0;

    for (j = 0; j < strlen(text); j++)
    {
        if isspace(text[j])
        {
            words++;
        }
    }
    return words+1;
}

int count_sentences(string text)
{
    int sentences = 0;
    int k = 0;

    for (k = 0; k < strlen(text); k++)
    {
        if ((text[k]) == '.' || (text[k]) == '?' || (text[k]) == '!')
        {
            sentences++;
        }
    }
    return sentences;
}