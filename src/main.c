#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "help.c"
#include "init.c"

int main(int argc, char *argv[])
{
    if (argc == 1 || strcmp(argv[1], "help") == 0 || strcmp(argv[1], "-h") == 0)
        return help_menu();

    if (argc <= 3 && !strcmp(argv[1], "init"))
        return cmd_init();

    fprintf(stderr, "trac: unknown command '%s'. Try 'trac help' for more information.\n", argv[1]);
    return EXIT_FAILURE;
}
