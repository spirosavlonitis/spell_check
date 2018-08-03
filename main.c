#include "hdr.h"


int main(int argc, char  *argv[])
{
	char	word[MAXWORD];
	FILE	*fp;
	TREENODE *root;

	if (argc != 2)
		fp = stdin;
	else
		fp = Fopen(argv[1], "r");

	root = NULL;

	while (getword(fp, word, MAXWORD) != EOF)
		root = addtree(root, word);

	treeprint(root);

	if (fp != stdin)
		fclose(fp);

	exit(EXIT_SUCCESS);
}