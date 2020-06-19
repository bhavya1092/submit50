#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

#define lenght 45
#define hashtable_size 65536

char word[lenght+1];
int count = 0;

/*
*
* Hash function. Thanks to Brenda from cs50 reddit.
*/
int hash_it(const char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % hashtable_size;
}

typedef struct node
{
    char* word;
    struct node* next;
}node;

node* previous;
node* hashtable[hashtable_size];


/*
*
* Loads dictionary into memory.  Returns true if successful else false.
*/
bool load(const char* dictionary)
{
    char word[lenght+1];
    FILE* dict = fopen(dictionary,"r");

    for(int i = 0; i < 26;i++)
    {
        hashtable[i] = NULL;
        for(int a = fgetc(dict); a != EOF; a = fgetc(dict))
        {
            count++;

            int hashvalue = hash_it(word);

            node* new = malloc(sizeof(node));

            if(hashtable[hashvalue] == NULL)
            {
                hashtable[hashvalue] = new;
                new -> next = NULL;
            }
            else
            {
                new -> next = hashtable[hashvalue];
                hashtable[hashvalue] = new;
            }
        }
    }
    fclose(dict);
    return true;
}

/*
*
* Returns true if word is in dictionary else false.
*/
bool check(const char* word)
{

    char tmp[lenght + 1];
    int lenghtw = strlen(word);
    for (int i = 0; i < lenghtw; i++)
    {
        tmp[i] = tolower(word[i]);
    }


    int index = hash_it(tmp);

    if (hashtable[index] == NULL)
    {
        return false;
    }

    node* cursor = hashtable[index];

    while(cursor != NULL)
    {
        if(strcmp(tmp, cursor -> word) == 0)
        {
            return true;
        }
        cursor = cursor -> next;
    }

    return false;
}

/*
*
* Returns number of words in dictionary if loaded else 0 if not yet loaded.
*/
unsigned int size(void)
{
    return count;
}

bool load(const char *dictionary) {
    char line[256];
    FILE *dict = fopen(dictionary, "r");

    if (!dict)
        return false;

    while (fgets(line, sizeof line, dict) != NULL) {
        char *p = line + strspn(line, " \t");  // skip blanks

        p[strcspn(p, " \t\r\n")] = '\0'; // strip trailing blanks

        if (*p == '\0' || *p == '#' || *p == ';')
            continue;  // ignore blank lines and comments

        count++;

        int hashvalue = hash_it(p);
        node *np = malloc(sizeof(node));

        np->word = strdup(p);
        np->next = hashtable[hashvalue];
        hashtable[hashvalue] = np;
    }
    fclose(dict);
    return true;
}

int main(int argc, char **argv)
{

    if (argc != 2)
        return 3;

    if (!load("dictionary"))
        return 1;

    printf("loaded %d words\n", size());
    printf("word '%s'%s found\n", argv[1], check(argv[1]) ? "" : " not");
    unload();
    return 0;
}