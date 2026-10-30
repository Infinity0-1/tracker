static int help_menu()
{
    printf("A cli utility tool to track tasks.\n\n");

    printf("Usage: trac <command> [arguments]\n\n");

    printf("Commands:\n");
    printf("    help    Show help menu.\n");
    printf("    init    Initiate tracker.\n");
    printf("    new     Create a new task.\n");

    printf("\n");
    printf("Use \"trac <command> --help\" for more information about a command.\n");

    return EXIT_SUCCESS;
}

    // printf("    new           Create a new task\n");
    // printf("    delete, -d    Delete a task\n");
    // printf("    list, -l      List open tasks\n");
    // printf("    done          Mark a task as finished\n");
    //
    // printf("\n");
    // printf("    show          Show full details of a task\n");
    // printf("    edit          Change a task's text\n");
    // printf("    undo          Reopen a finished task\n");
    // printf("    status        Show a summary (open / done)\n");
    // printf("    tag           Attach a label to a task\n");
    // printf("    prio          Set task priority\n");
    //
    // printf("\n");
    // printf("    due           Set a deadline\n");
    // printf("    find          Search task text\n");
    // printf("    today         Show tasks due today\n");
    // printf("    overdue       Show overdue tasks\n");
    // printf("    clear         Remove all finished tasks\n");
    // printf("    archive       Move finished tasks to the archive\n");
    //
    // printf("\n");
    // printf("    export        Export tasks to CSV or JSON\n");
    // printf("    import        Import tasks from CSV or JSON\n");
