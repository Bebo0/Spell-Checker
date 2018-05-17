#include <cs50.h>
#include <stdio.h>


typedef struct node
{
    bool isword;
	struct node *arrayofpointers[26];
}
node;

int main(void)
{
    
    
    // node TRIE;
    // node BEBO;
    // BEBO.isword = true;
    // TRIE.isword = false;
    // node *x = malloc(sizeof(node)); // allocates 2 pointers that can point to integers
    // x = &BEBO;
    // printf("%d", x->isword);
    // *x = TRIE;
    // printf("%d \n", x->isword);
    // node *y = malloc(sizeof(node));
    // x = y;
    // y->isword = true;
    // printf("%d \n", y->isword);
    // y->arrayofpointers[0] = malloc(sizeof(node));
    // y->arrayofpointers[0]->isword = true;
    // printf("%d \n", y->arrayofpointers[0]->isword);
    // if (x->arrayofpointers[0]->arrayofpointers[0] != NULL)
    // printf("it works");
    char *word = "bebo";
    //int g = sizeof(word);
    for(int i = 0; word[i] != '\0'; i++)
    {
        printf("%d", i);
    }
    //printf("%d \n", g);
    //printf("%d", (x->arrayofpointers[0]->arrayofpointers[0]->isword));
    //x->isword= false;
    //int *y;
    //x = malloc(sizeof(int)); // setting up pointee and lets x point to it
    //y = malloc(sizeof(int));
    
    //*x = 42; // stores 42 at the address
    //*y = *x;
    //*y = 47;
    //printf("%d", BEBO.isword);
    
    // //RGBTRIPLE triple;
    // //int s = 0L;
    // //printf("%d \n", s);
    // char *infile = "large.bmp";
    // int g = sizeof(*infile);
    // printf ("%d \n", g);
    // //short y = -sizeof(SIGNATURE);
    // //printf ("%hd \n", y);
    
    // FILE *inptr = fopen(infile, "r");
    //  //for (int i = 0, totalblocks = szof/512; i < totalblocks; i++)
     
    // for (int i = 0; i < 5; i++)
    // {
    //     char buffer[50];

    //     int ii = i;

    //     sprintf(buffer,"%d", ii);

    //     printf("%s\n", buffer);
        
    //     FILE *outptr = fopen(buffer, "w");
    //     SIGNATURE s;
    //     fwrite(&s, sizeof(SIGNATURE), 1, outptr);
    //     fclose(outptr);
        
    // }
    
    // //FILE *outptr = fopen(i, "w");
    // fseek(inptr, 0L, SEEK_END);
    // int szof = ftell(inptr);
    // printf ("%d \n", szof);
    // rewind(inptr);
    
    // int z = 1;
    // z = z + 1;
    // printf("%d \n", z);
    
    // int arr[486];
    // FILE *outptr1 = fopen("n.bmp", "w");
    // fread(arr, 486, 1, inptr);
    // fwrite(arr, 486, 1, outptr1);
    // int bebo = 000;
    // bebo = 10;
    // printf("%03d \n", bebo);
    //free(arr);
  
   // for (int z = 0; z < 4; z++)
    //{
       // x[z] = z;
        //printf("%f \n", x[z]);
    //}
}

// x -> x.jpeg file or nothing