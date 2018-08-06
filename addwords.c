#include "hdr.h"

static void shellsort(char **, int);

void addwords(char **words)
{
	int 	i, n, cmp;
	char	cur_ltr, dic_word[MAXWORD];
	FILE 	*fp;

	for (n = 0; words[n]; ++n)
		for (i = 0; i < strlen(words[n]) ; ++i)
			words[n][i] = lower(words[n][i]);

	shellsort(words, n);

	cur_ltr = **words;
	fp = Fopen("en-US.dic", "r+");

	for (i = 0; words[i] ; ++i) {
		if (*words[i] > cur_ltr )
			cur_ltr = *words[i];

		while (getlow_word(fp, dic_word, MAXWORD) != EOF) {
			if (cur_ltr > *dic_word)
				continue;
			if ((cmp = strcmp(words[i], dic_word)) == 0) {
				printf("%s alredy in dictionary\n", words[i]);
				break;
			}
			if (*dic_word > cur_ltr)
				break;
		}

		fseek(fp, SEEK_SET, 0);
	}

	fclose(fp);

}

static void shellsort(char **w, int n)
{
	int		i, j, g;
	char 	*temp;

	for (g = n/2; g > 0 ; g /= 2)
		for (i = 1; w[i] ; i += g)
			for (j = i-g; j >= 0 && strcmp(w[j], w[j+g]) > 0 ; j -= g)
				temp = w[j], w[j] = w[j+g], w[j+g] = temp;

}