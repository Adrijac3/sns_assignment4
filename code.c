#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int vuln(char* s)
{
	char buffer[64];
	strcpy(buffer, s);
}

int main(int argc, char **argv)
{
	
	vuln(argv[1]);
	//printf("Returned Properly\n");
	return 0;
}
