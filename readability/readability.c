#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

float count_letters(string text);
float count_words(string text);
float count_sentences(string text);

int main(void)
{
    float L;
    float S;

    string text = get_string("Text: ");

    float l = count_letters(text);
    float w = count_words(text);
    float s = count_sentences(text);

    L = (l/w) * 100;
    S = (s/w) * 100;

    float index = 0.0588*L - 0.296*S - 15.8;

    printf("%f\n", L);
    printf("%f\n", w);
    printf("%f\n", S);
    printf("%f\n", index);
}

float count_letters(string text)
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

float count_words(string text)
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

float count_sentences(string text)
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