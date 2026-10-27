static int trac_find(char *trac_path)
{
    char *path = getcwd(NULL, 0);
    if (path == NULL)
        return error_print("trac init: unable to get working directory.");

    while (strcmp(path, "/home"))
    {
        DIR *directory = opendir(path);
        if (directory == NULL) 
            return error_print("trac init: unable to open path.");

        struct dirent *file;
        while ((file = readdir(directory)) != NULL)
        {
            if (!strcmp(file->d_name, ".trac"))
            {
                snprintf(trac_path, PATH_MAX, "%s/%s", path, ".trac");
                return error_print("Tracker is already initialized.");
            }
        }

        closedir(directory);
        free(path);

        if (chdir("..")) 
            return error_print("trac init: unable to change directory.");

        path = getcwd(NULL, 0);
        if (path == NULL)
            return error_print("trac init: unable to get new directory.");
    }

    return EXIT_SUCCESS;
}

static int cmd_init()
{
    char *working_directory = getcwd(NULL, 0);
    if (working_directory == NULL)
        return error_print("trac init: unable to get working directory.");

    char folder_path[PATH_MAX];
    if (trac_find(folder_path))
        return EXIT_FAILURE;

    snprintf(folder_path, PATH_MAX, "%s/%s", working_directory, ".trac");

    if (mkdir(folder_path, 0755))
        return error_print("trac init: failed to create .trac directory.");

    printf("Initialized tracker on \"%s\"\n", working_directory);
    return EXIT_SUCCESS;
}
