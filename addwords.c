#include "hdr.h"

static void shellsort(char **, int);

void addwords(char **words)
{
	int 	i, n;

	for (n = 0; words[n]; ++n)
		;

	shellsort(words, n);

	for (i = 0; words[i]; ++i)
		printf("%s\n", words[i]);
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