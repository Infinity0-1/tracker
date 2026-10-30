#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

#include "help.c"
#include "init.c"
#include "new.c"

static int cmd_list()
{
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    if (argc == 1 || strcmp(argv[1], "help") == 0 || strcmp(argv[1], "-h") == 0)
        return help_menu();

    if (!strcmp(argv[1], "init") && argc == 2)
        return cmd_init();

    if (!strcmp(argv[1], "new") && argc <= 3)
        return cmd_new(argv[2]);

    if (strcmp(argv[1], "list") == 0 || strcmp(argv[1], "ls") == 0)
        return cmd_list();

    fprintf(stderr, "trac: unknown command '%s'. Try 'trac help' for more information.\n", argv[1]);

    return EXIT_FAILURE;
}
