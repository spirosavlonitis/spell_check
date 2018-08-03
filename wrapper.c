#include "hdr.h"


FILE *Fopen(char *path, char *op)
{
	FILE *fp;

	if ( (fp = fopen(path, op)) == NULL)
		err_quit("file not found");
	return fp;
}