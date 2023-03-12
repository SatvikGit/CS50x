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
    // Genearates an array for lowercase words and adding an extra space for null character
    char lcaseword[strlen(word) + 1];
    for (int i = 0; i < strlen(word); i++)
    {
        lcaseword[i] = tolower(word[i]);
    }

    lcaseword[strlen(word)] = '\0';
    unsigned int hash_value = hash(lcaseword);
    node* trav = table[hash_value];

    // Checks fro word by going to position outputted by hash function
    while (trav != NULL)
    {
        if (strcmp(trav->word, lcaseword) == 0)
        {
            return true;
        }
        trav = trav->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int j = 0;
    // Adds ASCII values of characters of word to a variable j
    for (int i = 0; i <= strlen(word); i++)
    {
        j += tolower(word[i]);
    }
    return j % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Opens a file for reading
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        return false;
    }

    char nextw[LENGTH + 1];
    // Scans the file for word and string it into a buffer array named nextw
    while (fscanf(inptr, "%s", nextw) != EOF)
    {
        // Creates a traversal node
        node* n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // Points to a new head of linked list
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
    return dicts;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
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
