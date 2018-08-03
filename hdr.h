#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef	struct treenode {
	char 	*word;
	long	count;
	struct treenode *left, *right;
}	TREENODE;


#define MAXWORD		1000


int getword(FILE *, char *, int);
TREENODE *addtree(TREENODE *, char *);
void treeprint(TREENODE *);


void err_quit(char *, ...);


/* Wrapper functions */
FILE *Fopen(char *, char *);