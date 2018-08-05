#include "hdr.h"

void spellcheck(SORTNODE *p)
{
	int		match;
	char	cur_ltr, low_word[MAXWORD];
	FILE 	*fp;

	match = 0;

	cur_ltr = *p->t_node->lowcase;

	fp = Fopen("en-US.dic", "r");

	for ( ; p != NULL ; p = p->next, match = 0 ) {
		if (*p->t_node->lowcase > cur_ltr)
			cur_ltr = *p->t_node->lowcase;

		while (getword(fp, low_word, MAXWORD) != EOF) {
			if (cur_ltr > *low_word)	/* haven't reached current letter */
				continue;
			if (strcmp(p->t_node->lowcase, low_word) == 0) {
				match = 1;
				break;
			}
			if (*low_word > cur_ltr)	/* passed current letter thus mistake */
				break;
		}

		if (match == 0)
			printf("%s\n", p->t_node->word);
		fseek(fp, 0, SEEK_SET);
	} 
	fclose(fp);
}