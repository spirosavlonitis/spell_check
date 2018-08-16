#include "hdr.h"

static void readargs(int, char **);

static char 	*new_words[NEWWORDS];
static FILE	 	*fp;

int main(int argc, char  *argv[])
{
	char	 	word[MAXWORD];
	TREENODE 	*root;
	SORTNODE	*snode;

	a = 0;

	if (argc == 1)
		fp = stdin;
	else
		readargs(argc, argv+1);
	
	if (a){
		addwords(new_words);
		printf("Dictionary updated\n");
		exit(EXIT_SUCCESS);
	}

	root = NULL;
	while (getword(fp, word, MAXWORD) != EOF)
		root = addtree(root, word);

	if (root == NULL)
		err_quit("No input !!");

	snode = NULL;
	snode = treesort(root, snode);
	snode = resetsort(snode);

	if (fp != stdin)
		fclose(fp);

	spellcheck(snode);

	exit(EXIT_SUCCESS);
}


static void readargs(int argc, char **argv)
{
	int 	i;
	char 	c;

	for (; --argc > 0 && (c = **argv) ; argv++)
		switch (c) {
			case '-':
				while (argc > 0 && (c = *++*argv))
					switch (c) {
						case 'a': 	/* words to add */
						 	a = 1;
						 	for (argv++, i = 0; --argc > 0 && (c = **argv) ; argv++)
								if (c == '-')
									break;
								else
									new_words[i++] = *argv;
						  	break;
						default:
							err_quit("unkown option %c", c);
							break;
					}
				break;
			default:
				fp = Fopen(*argv, "r");
				break;
		}
}