#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int bof(char *str)
{
	char buffer[14];
	/* The following statement has a buffer overflow problem */

	strcpy(buffer, str);
printf("%d",strlen(buffer));
 int (*ret)() = (int(*)())buffer;

     ret();
	return 1;
}

int main(int argc, char *argv[])
{
printf("bbb");
	char str[517];
	FILE *badfile;
	badfile = fopen("badfile1", "r");
	fread(str, sizeof(char), 517, badfile);
	bof(str);
	printf("Returned Properly\n");
	return 1;
}