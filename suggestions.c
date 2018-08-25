#include "hdr.h"

typedef struct s_node {
	char *suggestion;
	int	 n;
} Suggestion;

void suggestions(char *pattern, int flag)
{
	char 	word[MAXWORD], result[MAXWORD];
	int 	d, i, j, k, h, n, l;
	Suggestion sug;
	FILE	*fp;

	l = strlen(pattern);
	sug.n = 0;
	n = 0;

	for (d = 0; d < 2 ; ++d) {

		if (d == 0) 
			fp = Fopen("en-US_upper.dic", "r");
		else
			fp = Fopen("en-US_lower.dic", "r");

		while (getword(fp, word, MAXWORD) != EOF) {
			if ( (lower(*word)) < (lower(*pattern)) )
				continue;
			if ( (lower(word[strlen(word) - 1])) != (lower(pattern[l-1])) )		/* same last letter */
				continue;

			for (i = 0, n = 0; i < strlen(word) ; ++i)
				for ( j = 0; j < l ; ++j)
					for (k = j, h = i; k < l && word[k] == pattern[h] ; ++k, ++h)
						n++;
					

			if (n > sug.n) {
				printf(" %s", word);
				sug.n = n;
			}

			if ( (lower(*word)) > (lower(*pattern)))
				break;
		}
		fclose(fp);
	}

	putchar(10);

}