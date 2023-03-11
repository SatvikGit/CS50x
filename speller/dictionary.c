// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    char* buffer[LENGTH];
    gets(buffer, LENGTH, inptr);
    if (word == buffer[LENGTH])
    {
        return true;
    }
    else
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    for (char i = word[0]; i != "\n"; i++)
    {
        int j = 0;
        j += word[i];
        k = j % N;
    }
    return k;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *inptr = fopen(dictionary, "r")
    if (inptr = NULL)
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

        strcopy(n->word, nextw);
        int hashv = hash(nextw);
        n->next = table[hashv];
        table[hashv] = n;
        
    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;
    // TODO
    if (inptr != NULL)
    {
        while ((ch = getc(inptr)) != EOF)
        {
            if (ch = "\n")
            {
                count++;
                return count;
            }
        }
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
