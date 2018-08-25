#include "hdr.h"

void suggestions(char *pattern, int flag)
{
	char 	word[MAXWORD], result[MAXWORD];
	int 	d, i, j, n, l;
	FILE	*fp;

	l = strlen(pattern);
	n = 1;

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

			for (i = 0, j = 0 ; i < strlen(word) && j < l ; ++i)		/* compare word to */
				if (word[i] == pattern[j])
					j++;
			if ( j > n) {
				printf("%d: %s\n",j ,word);
				n = j;
			}

			if ( (lower(*word)) > (lower(*pattern)))
				break; 
		}
		fclose(fp);
	}

	putchar(10);

}