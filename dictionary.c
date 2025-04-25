// Implements a dictionary's functionality
#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
int sized = 0;
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // hash word to obtain a hash value
    int hashh = hash(word);
    // linked list
    node *cursor = table[hashh];

    while (cursor != NULL)
    {
        // check if word exists
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char words[LENGTH + 1];
    // open dictionary file
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        printf("error\n");
        return false;
    }
    // read strings from file
    while (fscanf(input, "%s", words) == 1)
    {
        // create a new node
        sized++;
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n->word, words);
        // hash word
        int hashh = hash(words);
        // insert node into hash table
        n->next = table[hashh];
        table[hashh] = n;
    }
    fclose(input);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // done hehehehehehe

    return sized;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i = 0;i<N;i++)
    {
        node *cursor = table[i];
        node *temp = table[i];
        while(cursor != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
    }
    return true;
}
