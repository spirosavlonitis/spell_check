#include "hdr.h"


static void shellsort(char **, int);
static void unget_word(FILE *, char *);
static void updatedic(char **, int );

void addwords(char **words)
{
	int 	n, i, j;
	char	*upper_words[NEWWORDS], *lower_words[NEWWORDS];
	FILE 	*fp, *fp_orig;

	for (int i = 0; i < NEWWORDS; ++i)
		upper_words[i] = lower_words[i] = NULL;

	for (n = i = j = 0; words[n] ; ++n)
		if (isupper(*words[n]))
			upper_words[i++] = words[n];
		else
			lower_words[j++] = words[n];

	if (*upper_words) {
		shellsort(upper_words, i);
		updatedic(upper_words, UPPER);
	}
	
	if (*lower_words) {
		shellsort(lower_words, j);
		updatedic(lower_words, LOWER);
	}

	return;
}


static void updatedic(char **words, int flag)
{
	int 	i, cmp, diceof;
	char	dic_word[MAXWORD];
	FILE 	*fp, *fp_orig;

	if ( ~(~0 << 3) & flag == UPPER){
		fp_orig =  Fopen("en-US_upper_original.dic", "r");
		fp =  Fopen("en-US_upper.dic", "w");
	}else{
		fp_orig = Fopen("en-US_lower_original.dic", "r");
		fp =  Fopen("en-US_lower.dic", "w");
	}

	for (i = 0; words[i] ; ++i) {
		while ((diceof = getword(fp_orig, dic_word, MAXWORD)) != EOF) {	
			if ( (cmp =  strcasecmp(words[i], dic_word)) <= 0){		/* word to add is lesser or equal to dictionary word */
				if (cmp < 0)				/* if lesser push dictionary word back to read buffer */
					unget_word(fp_orig, dic_word);		/* push dic_word back to buffer to be compared with the next word */
				fprintf(fp, "%s\n", words[i]);		/* print word to file */
				break;
			}else 		
				fprintf(fp, "%s\n", dic_word);	/* print dictionary word to file */
		}
	}

	if (diceof != EOF)		/* copy remaining dictionary words */
		while (getword(fp_orig, dic_word, MAXWORD) != EOF)
			fprintf(fp, "%s\n", dic_word);

	fclose(fp);
	fclose(fp_orig);

	/* update source dictionary */
	if ( ~(~0 << 3) & flag == UPPER){
		fp_orig =  Fopen("en-US_upper_original.dic", "w");
		fp =  Fopen("en-US_upper.dic", "r");
	}else{
		fp_orig = Fopen("en-US_lower_original.dic", "w");
		fp =  Fopen("en-US_lower.dic", "r");
	}

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