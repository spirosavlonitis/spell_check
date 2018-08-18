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
#define NEWWORDS 	100
#define lower(a) ( (a) >= 'A' && (a) <= 'Z') ?	a + 32 : a;


/* get_word.c */
int getword(FILE *, char *, int);
int getlow_word(FILE *, char *, int );

/* bintree.c */
TREENODE *addtree(TREENODE *, char *);
void treeprint(TREENODE *);

SORTNODE *treesort(TREENODE *, SORTNODE *);
SORTNODE *resetsort(SORTNODE *);
void	sortprint(SORTNODE *);

/* spellcheck.c */
void spellcheck(SORTNODE *);

/* addword */
void addwords(char **);

/* wrapper.c */
FILE *Fopen(char *, char *);


/* error.c */
void err_quit(char *, ...);

/* options */
int 	a;