#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Function declarations
float count_letters(string text);
float count_words(string text);
float count_sentences(string text);

int main(void)
{
    float L;
    float S;

    // Gets input from user
    string text = get_string("Text: ");

    float l = count_letters(text);
    float w = count_words(text);
    float s = count_sentences(text);

    // Calculates letters per 100 words and sentences per 100 words
    L = (l/w) * 100;
    S = (s/w) * 100;

    // Calculates index
    int index = round(0.0588*L - 0.296*S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    printf("Grade %i\n", index);
}

// Counts the number of lee]tters]
float count_letters(string text)
{
    int letters = 0;
    int i = 0;

    for (i = 0; i <= strlen(text); i++)
    {
        // Checks if text[i] is an alphabet
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// Counts the number of words
float count_words(string text)
{
    int words = 0;
    int j = 0;

    for (j = 0; j < strlen(text); j++)
    {
        // Checks if there is a space
        if isspace(text[j])
        {
            words++;
        }
    }
    return words+1;
}

// Claculates the numver of setences
float count_sentences(string text)
{
    int sentences = 0;
    int k = 0;

    for (k = 0; k < strlen(text); k++)
    {
        // Checks if the word ends with . or ? or !
        if ((text[k]) == '.' || (text[k]) == '?' || (text[k]) == '!')
        {
            sentences++;
        }
    }
    return sentences;
}