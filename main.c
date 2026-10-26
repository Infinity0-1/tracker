#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void help(void);

int main(int argc, char *argv[])
{
    if (argc == 1 || strcmp(argv[1], "help") == 0 || strcmp(argv[1], "-h") == 0) {
        help();
        return EXIT_SUCCESS;
    }

    fprintf(stderr, "trac: unknown command '%s'\n", argv[1]);
    fprintf(stderr, "Try 'trac help' for more information.\n");

    return EXIT_FAILURE;
}


static void help(void)
{
    printf("\n    Usage: trac <command> [arguments]\n\n");

    printf("        Commands:\n");
    printf("            help, -h          Show help menu\n");
    printf("            init              Initiate tracker in the working directory\n");
    printf("            new               Create a new task\n");
    printf("            list, ls, -l      List open tasks\n");
    printf("            done              Mark a task as finished\n");
    printf("            delete, rm        Delete a task\n");

    printf("\n");
    printf("            show              Show full details of a task\n");
    printf("            edit              Change a task's text\n");
    printf("            undo              Reopen a finished task\n");
    printf("            status            Show a summary (open / done)\n");
    printf("            tag               Attach a label to a task\n");
    printf("            prio              Set task priority\n");

    printf("\n");
    printf("            due               Set a deadline\n");
    printf("            find              Search task text\n");
    printf("            today             Show tasks due today\n");
    printf("            overdue           Show overdue tasks\n");
    printf("            clear             Remove all finished tasks\n");
    printf("            archive           Move finished tasks to the archive\n");

    printf("\n");
    printf("            export            Export tasks to CSV or JSON\n");
    printf("            import            Import tasks from CSV or JSON\n");
    printf("\n");
}
