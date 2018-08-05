#include "hdr.h"
#include <ctype.h>

int getword(FILE *fp, char *w, int limit)
{
	register char 	*wp;

	wp = w;

	while (!isalpha(*wp = fgetc(fp)))
		if (*wp == EOF)
			return EOF;

	for (wp++; isalpha(*wp = fgetc(fp)) || *wp == '\'' ; wp++)
			;
		
	ungetc(*wp, fp);
	*wp = '\0';

	return *w;
}

int getlow_word(FILE *fp, char *w, int limit)
{
	register char 	*wp;

	wp = w;

	while (!isalpha(*wp = fgetc(fp)))
		if (*wp == EOF)
			return EOF;

	for (wp++; isalpha(*wp = fgetc(fp)) || *wp == '\'' ; wp++)
			;
		
	ungetc(*wp, fp);
	*wp = '\0';

	return *w;
}