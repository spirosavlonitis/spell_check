#include "hdr.h"

typedef struct s_node {
	char *suggestion;
	int	 n;
} Suggestion;

void suggestions(char *pattern)
{
	char 	word[MAXWORD];
	int 	i,n, l;
	Suggestion sug;
	FILE	*fp;

	fp = Fopen("en-US_upper.dic", "r");
	l = strlen(pattern);
	sug.n = 0;
	n = 0;

	while (getword(fp, word, MAXWORD) != EOF) {
		if ( (lower(*word)) < (lower(*pattern)) )
			continue;

		for (i = 0, n = 0; i < l ; ++i)
			if ( (lower(word[i])) == (lower(pattern[i])) )
				n++;
		if (sug.n < n) {
			sug.suggestion = strdup(word);
			sug.n = n;
		}

		if ( (lower(*word)) > (lower(*pattern)))
			break;
	}

	fclose(fp);

	printf(" %s\n", sug.suggestion);

}