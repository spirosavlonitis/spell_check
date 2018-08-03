#include "hdr.h"


TREENODE *addtree(TREENODE *p, char *w)
{
	int cmp;

	if (p == NULL){
		p = (TREENODE *)  malloc(sizeof(TREENODE));
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}else if ( (cmp = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cmp > 0)
		p->right = addtree(p->right, w);
	else
		p->left = addtree(p->left, w);


	return p;
}


void treeprint(TREENODE *p)
{
	if (p != NULL) {
		treeprint(p->left);
		printf("%s\n", p->word);
		treeprint(p->right);
	}
}