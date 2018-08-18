#include "hdr.h"

void spellcheck(SORTNODE *p)
{
	int		match;
	char	cur_ltr, word[MAXWORD];
	FILE 	*fp;

	match = 0;

	cur_ltr = *p->t_node->word;

	fp = Fopen("en-US.dic", "r");


	printf("%s\n", p->t_node->word);

	return;

	for ( ; p != NULL ; p = p->next, match = 0 ) {
		if (*p->t_node->word > cur_ltr)
			cur_ltr = *p->t_node->word;

		while (getword(fp, word, MAXWORD) != EOF) {
			if (cur_ltr > *word)	/* haven't reached current letter */
				continue;
			if (strcmp(p->t_node->word, word) == 0) {
				match = 1;
				break;
			}
			if (*word > cur_ltr)	/* passed current letter thus mistake */
				break;
		}
		if (match == 0)
			printf("%s\n", p->t_node->word);
		fseek(fp, 0, SEEK_SET);
	} 
	fclose(fp);
}