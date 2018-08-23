#include "hdr.h"

typedef struct s_node {
	char *suggestion;
	int	 n;
} Suggestion;

void suggestions(char *pattern, int flag)
{
	char 	word[MAXWORD], result[MAXWORD];
	int 	d, i, j, n, l;
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
			if ( (lower(word[strlen(word) - 1])) != (lower(pattern[l-1])) )
				continue;

			for (i = 0, j = 0, n = 0; i < l ; ++i)
				if ( (lower(word[i])) == (lower(pattern[n])) )
					n++;
			if (n > sug.n) {
				printf("%s\n", word);
				sug.n = n;
			}

			if ( (lower(*word)) > (lower(*pattern)))
				break;
		}
		fclose(fp);
	}

	printf(" %s\n", result);

}