#include "hdr.h"


void spellcheck(SORTNODE *p)
{
	int		match;
	char	word[MAXWORD];
	FILE 	*fp;

	match = 0;

	for ( ; p != NULL ; p = p->next, match = 0 ) {
		fp = Fopen("en-US.dic", "r");
		while (getword(fp, word, MAXWORD) != EOF)
			if (strcmp(p->t_node->word, word) == 0) {
				match = 1;
				break;
			}
		if (match == 0)
			printf("%s\n", p->t_node->word);
		fclose(fp);
	}

}