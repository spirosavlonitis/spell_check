#include "hdr.h"
#include <ctype.h>

#define lowercase(a)	( (a) >= 'A' && (a) <= 'Z') ?	a + 32 : a;

int getword(FILE *fp, char *w, int limit)
{
	register char 	*wp;

	wp = w;

	while (!isalpha(*wp = fgetc(fp)))
		if (*wp == EOF)
			return EOF;
	*wp = lowercase(*wp);
	for (wp++; isalpha(*wp = fgetc(fp)) ; wp++)
			*wp = lowercase(*wp);

	ungetc(*wp, fp);
	*wp = '\0';

	return *w;
}