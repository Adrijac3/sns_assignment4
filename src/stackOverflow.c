    /* Vunlerable program: stack.c */

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #define BUF_SIZE 12
    int bof (char *str) {
        char buffer[BUF_SIZE];
        /* The following statement has a buffer overflow problem */
        strcpy(buffer, str);
        return 1;
    }

    int main (int argc, char **argv) {
        char str[517];
        FILE *badfile;
        char dummy[BUF_SIZE];
        memset(dummy, 0, BUF_SIZE);
        badfile = fopen("badfile", "r");
        fread(str, sizeof(char), 517, badfile);
        bof(str);
        printf("Returned Properly\n");
        return 1;
    }
