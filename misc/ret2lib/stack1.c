#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int bof(char *str)
{
	char buffer[64];
	/* The following statement has a buffer overflow problem */

	strcpy(buffer, str);

}

int main(int argc, char **argv)
{

	if (argc==1)
	{printf("arguments error");
exit(EXIT_FAILURE);}
bof(argv[1]);
	printf("Returned Properly\n");
}