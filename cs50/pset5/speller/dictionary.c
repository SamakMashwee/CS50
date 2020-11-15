// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word){

    char word_copy[LENGTH + 1];
    for(int i = 0; i < strlen(word);i++){
        word_copy[i] = tolower(word[i]);
    }

    word_copy[strlen(word)] = '\0';
    int h = hash(word_copy);
    node *cursor = table[h];

    while(cursor != NULL){

        if(strcasecmp(cursor -> word, word_copy) == 0){
            return(true);
        }

        else{
            cursor = cursor -> next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word){
    unsigned int index = tolower(word[0] - 'a');
    return index;
}

unsigned int word_count = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary){

    FILE *file = fopen(dictionary, "r");

    if(file == NULL)
        return false;

    char word[LENGTH + 1];
    while(fscanf(file, "%s", word) != EOF){

        node *n = malloc(sizeof(node));

        if(n == NULL)
            return false;

        strcpy(n -> word, word);
        n -> next = NULL;

        int index = hash(word);
        if(table[index] == NULL){
            table[index] = n;
            word_count++;
        }
        else{
            n -> next = table[index];
            table[index] = n;
            word_count++;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void){
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void){

    node *head = NULL;
    node *cursor = head;
    // freeing linked lists
    while (cursor != NULL)
    {
        node *temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
    return true;
}
