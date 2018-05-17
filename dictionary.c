/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

#include "dictionary.h"

typedef struct NODE
{
    bool isword;
	struct NODE* arrayofpointers[27];
}
NODE;

NODE *r; 
int twords;

/**
 * Char -> Boolean
 * Converts a letter/apostrophe into a number between 0 and 26
 */

short uplow(char x)
{
    short xx = (short)x;
        
    if (xx >= 97)
    {
        xx = xx - 96;
    }
    
    else if (xx >= 65)
    {
        xx = xx - 64;
    }

    else
    {
        xx = 0;
    }

    return xx;
    

}


/**
 * Array of characters -> Boolean
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    NODE *nextnode = malloc(sizeof(NODE));
    *nextnode= *r;
    int lettercount = 0;
    int actual = 0;
    for(int i = 0; word[i] != '\0'; i++)
    {
        actual++;
    }
    for(int i = 0; word[i] != '\0'; i++)
    {
        
        if (nextnode->arrayofpointers[uplow(word[i])] != NULL)
        {
            nextnode = nextnode->arrayofpointers[uplow(word[i])];
        }
        else
        {
            
            break;
        }
        lettercount++;
        
    }
    
    if (nextnode->isword == true & actual == lettercount)
    {

        return true;
    }
    else
    {

         return false;
    }

    
}


/**
 * Textfile -> Trie
 * Loads dictionary into memory. Returns true if successful else false.
 * (check-expect load()
 */
bool load(const char *dictionary)
{
    // TODO
    FILE *inptr = fopen(dictionary, "r");
    int index = 0, words = 0;
    //NODE root;33
    r = malloc(sizeof(NODE));
    r->isword = false;
    NODE *curnode = r;
    NODE *nxtnode;
    
    char word[LENGTH+1];
    
    if (ferror(inptr))
    {
        fclose(inptr);
        printf("Error reading %s.\n", dictionary);
        return false;
    }

    // spell-check each word in text
    for (int c = fgetc(inptr); c != EOF; c = fgetc(inptr))
    {
        // allow only alphabetical characters and apostrophes
        if (isalpha(c) || (c == '\'' && index > 0))
        {

            nxtnode = curnode->arrayofpointers[uplow(c)];
            if (nxtnode == NULL)
            {
                
                NODE *node = malloc(sizeof(NODE));
               
                curnode->arrayofpointers[uplow(c)] = node;
                nxtnode = node;
           
            }
           
            
            curnode = nxtnode;
          
            word[index] = c;
            
            index++;

            // ignore alphabetical strings too long to be words
            if (index > LENGTH)
            {
                // consume remainder of alphabetical string
                while ((c = fgetc(inptr)) != EOF && isalpha(c));

                // prepare for new word
                index = 0;
               
            }
        }

        // ignore words with numbers (like MS Word can)
        else if (isdigit(c))
        {
            // consume remainder of alphanumeric string
            while ((c = fgetc(inptr)) != EOF && isalnum(c));

            // prepare for new word
            index = 0;
           
        }

        // we must have found a whole word
        else if (index > 0)
        {
            // terminate current word
            word[index] = '\0';

            // update counter
            words++;

            // prepare for next word
            index = 0;
            curnode->isword = true;
            //printf("%d \n", curnode->isword);
            
            curnode = r;
            twords++;
            //free(r);
            
        }
    }


    fclose(inptr);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return twords;
    
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */


void unloadHelper(NODE* root)
{
    for (int x = 0; x < 26; x++)
    {
        
        NODE* curr;
        curr = root->arrayofpointers[x];
        if(curr != NULL)
        {
            unloadHelper(curr);

        }
       
        
        
    }
    free(root);

}

    
bool unload(void)
{

    unloadHelper(r);
    //return false;
    free(r);
    return true;
}
