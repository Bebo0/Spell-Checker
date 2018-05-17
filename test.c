#include <ctype.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>

#include "dictionary.h"

typedef struct list
{
    int n;
    struct list* rest;
}
node;

typedef struct bst
{
    int n;
    struct bst* right;
    struct bst* left;
}
bstnode;

int main(void)
{
    load()
}