#include "hdr.h"

static void shellsort(char **, int);
static void unget_word(FILE *, char *);

void addwords(char **words)
{
	int 	n, i, j, cmp, diceof;
	char	cur_ltr, dic_word[MAXWORD], low_dicword[MAXWORD];
	FILE 	*fp, *fp_orig;

	for (n = 0; words[n]; ++n)
		for (i = 0; i < strlen(words[n]) ; ++i)
			words[n][i] = lower(words[n][i]);

	shellsort(words, n);

	cur_ltr = **words;
	fp = Fopen("en-US.dic", "w");
	fp_orig = Fopen("en-US_original.dic", "r");

	for (i = 0; words[i] ; ++i) {
		if (*words[i] > cur_ltr )
			cur_ltr = *words[i];
		
		while ((diceof = getword(fp_orig, dic_word, MAXWORD)) != EOF) {			
			for (j = 0; dic_word[j] ; ++j)
				low_dicword[j] = lower(dic_word[j]);
			low_dicword[j] = '\0';

			if ( (cmp = strcmp(words[i], low_dicword)) <= 0){
				if (cmp < 0)
					unget_word(fp_orig, dic_word);
				fprintf(fp, "%s\n", words[i]);
				break;
			}else 
				fprintf(fp, "%s\n", dic_word);

			if (*low_dicword > cur_ltr ) {
				unget_word(fp_orig, dic_word);
				break;
			}
		}
	}

	if (diceof != EOF)		/* copy remaining dictionary words */
		while (getword(fp_orig, dic_word, MAXWORD) != EOF)
			fprintf(fp, "%s\n", dic_word);

	fclose(fp);
	fclose(fp_orig);

	/* update source dictionary */
	fp = Fopen("en-US.dic", "r");
	fp_orig = Fopen("en-US_original.dic", "w");

	while (getword(fp, dic_word, MAXWORD) != EOF)
		fprintf(fp_orig, "%s\n", dic_word);
	fclose(fp);
	fclose(fp_orig);

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

static void unget_word(FILE *fp, char *w)
{
	int 	i;

	for (i = strlen(w)-1; i >= 0 ; --i)
		ungetc(w[i], fp);
}