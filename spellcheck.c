#include "hdr.h"

static int uppercheck(TREENODE *);

void spellcheck(SORTNODE *p)
{
	int		match;
	char	cur_ltr, word[MAXWORD];
	FILE 	*fp;

	match = 0;

	cur_ltr = lower(*p->t_node->word);

	fp = Fopen("en-US_lower.dic", "r");

	for ( ; p != NULL ; p = p->next, match = 0 ) {
		if (isupper(*p->t_node->word)) {	
			if ( (match = uppercheck(p->t_node)))
				continue;
		}else if (*p->t_node->word > cur_ltr)	/* increase current letter */
			cur_ltr = *p->t_node->word;

		while (getword(fp, word, MAXWORD) != EOF) {			
			if (cur_ltr > *word)	/* haven't reached current letter */
				continue;
			if (strcasecmp(p->t_node->word, word) == 0) {
				match = 1;
				break;
			}
			if (*word > cur_ltr)	/* passed current letter thus mistake */
				break;
		}
		if (match == 0) {
			if (s){
				printf("%s: Did you mean ?", p->t_node->word);
				suggestions(p->t_node->word, isupper(*p->t_node->word) ? UPPER : LOWER );
			}
			else
				printf("%s\n", p->t_node->word);
		}
		fseek(fp, 0, SEEK_SET);
	} 

	fclose(fp);
}


static int uppercheck(TREENODE *t_node)
{
	int		match;
	static char	 cur_ltr;
	char	word[MAXWORD];
	FILE 	*fp;

	match = 0;
	if (cur_ltr == 0)
		cur_ltr = *t_node->word;
	else if (*t_node->word > cur_ltr)
		cur_ltr = *t_node->word;

	fp = Fopen("en-US_upper.dic", "r");

	while (getword(fp, word, MAXWORD) != EOF) {
		if (cur_ltr > *word)	/* haven't reached current letter */
			continue;
		if (strcasecmp(t_node->word, word) == 0) {
			match = 1;
			break;
		}
		if (*word > cur_ltr)	/* passed current letter thus mistake */
			break;
	}

	fclose(fp);
	return match;
}