#include "hdr.h"


int main(int argc, char  *argv[])
{
	char	 	word[MAXWORD];
	FILE	 	*fp;
	TREENODE 	*root;
	SORTNODE	*snode;

	if (argc != 2)
		fp = stdin;
	else
		fp = Fopen(argv[1], "r");
	root = NULL;

	while (getword(fp, word, MAXWORD) != EOF)
		root = addtree(root, word);

	snode = NULL;
	snode = treesort(root, snode);
	snode = resetsort(snode);

	
	
	if (fp != stdin)
		fclose(fp);

	exit(EXIT_SUCCESS);
}