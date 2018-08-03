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

SORTNODE *treesort(TREENODE *p, SORTNODE	*s)
{
	SORTNODE *temp, *low, *high;

	if (p != NULL) {
		s = treesort(p->left, s);

		if (s == NULL) {
			s = (SORTNODE *) malloc(sizeof(SORTNODE));
			s->t_node = p;
			s->next = s->prev = NULL;
		}else if (strcmp(s->t_node->word, p->word) > 0) {
			high = s;
			low = s->prev;

			while (low != NULL && strcmp(low->t_node->word, p->word) > 0)
				high = low,low = low->prev;

			temp = (SORTNODE *) malloc(sizeof(SORTNODE));
			temp->t_node = p;
			temp->prev = low;
			temp->next = high, high->prev = temp;
			if (low)
				low->next = temp;
		}else {
			temp = (SORTNODE *) malloc(sizeof(SORTNODE));
			temp->t_node = p;
			temp->prev = s, s->next = temp;
			temp->next = NULL;
			s = temp;
		}
		s = treesort(p->right, s);
	}

	return	s;
}


SORTNODE *resetsort(SORTNODE *p)
{
	for ( ;p->prev != NULL; p = p->prev)
		;
	return p;
}