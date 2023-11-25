// Implement a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represent a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Keep track of amount of words in dictionary
int words_amount = 0;

// Return true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);

    // Set pointer to beggining of linked list at corresponding index in table, then iterates over it
    for (node *ptr = table[index]; ptr != NULL; ptr = ptr->next)
    {
        // If pointer points to node that contains word, case insensitive, word is in dictionary
        if (!strcasecmp(ptr->word, word))
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }



    char word[LENGTH + 1];

    while(fscanf(dict, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(dict);
            return false;
        }

        int index = hash(word);

        strcpy(n->word, word);

        n->next = table[index];

        table[index] = n;

        words_amount++;
    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
        return words_amount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *ptr = table[i]->next;
            free(table[i]);
            table[i] = ptr;
        }
    }

    return true;
}
