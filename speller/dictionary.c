// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Choose number of buckets in hash table
const unsigned int N = 100000;
int dicts = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //
    int hashv = hash(word);
    node* n = table[hashv];

    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int j = 0;
    // Improve this hash function
    for (int i = 0; i <= strlen(word); i++)
    {
        j += word[i];;
    }
    return j % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        return false;
    }

    char nextw[LENGTH + 1];

    while (fscanf(inptr, "%s", nextw) != EOF)
    {
        node* n = malloc(sizeof(node));

        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word,nextw);
        int hashv = hash(nextw);
        n->next = table[hashv];
        table[hashv] = n;
        dicts++;
    }
    fclose(inptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    //
    return dicts;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //
    for (int i = 0; i < N; i++)
    {
        node* n = table[i];

        while (n != NULL)
        {
            node* temp = n;
            n = n->next;
            free(temp);
        }

        if (n == NULL && i == (N - 1))
        {
            return true;
        }
    }
    return false;
}
