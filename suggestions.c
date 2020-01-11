#include "hdr.h"

void suggestions(char *pattern, int flag)
{
	char 	word[MAXWORD], result[MAXWORD];
	int 	d, i, j, n, l;
	FILE	*fp;

	l = strlen(pattern);

	for (d = 0; d < 2 ; ++d) {

		if (d == 0) 
			fp = Fopen(UPPER_DIC, "r");
		else
			fp = Fopen(LOWER_DIC, "r");

		for ( n = l -2; getword(fp, word, MAXWORD) != EOF ; n = l -2) {
			if ( (lower(*word)) < (lower(*pattern)) )
				continue;
			if ( (lower(word[strlen(word) - 1])) != (lower(pattern[l-1])) )		/* same last letter */
				continue;

			for (i = 0, j = 0 ; i < strlen(word) && j < l ; ++i)		/* compare word to */
				if ( (lower(word[i])) == (lower(pattern[j])) )
					j++;
			if ( j >= n && strlen(word)-j <= 2 ) {
				printf(" %s", word);
				if (j > n)
					n = j;
			}
			if ( (lower(*word)) > (lower(*pattern)))
				break; 
		}
		fclose(fp);
	}
	putchar('\n');
}