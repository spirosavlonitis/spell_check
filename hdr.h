#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef	struct treenode {
	char 	*word;
	long	count;
	struct treenode *left, *right;
}	TREENODE;

typedef struct sortnode {
	TREENODE 	*t_node;
	struct sortnode *next, *prev;
}	SORTNODE;

#define MAXWORD		1000

int getword(FILE *, char *, int);

TREENODE *addtree(TREENODE *, char *);
void treeprint(TREENODE *);

SORTNODE *treesort(TREENODE *, SORTNODE *);
SORTNODE *resetsort(SORTNODE *);
void	sortprint(SORTNODE *);


void err_quit(char *, ...);


/* Wrapper functions */
FILE *Fopen(char *, char *);