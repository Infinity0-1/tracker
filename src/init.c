static int find_trac_dir(char *trac_path)
{
    char *path = getcwd(NULL, 0);
    if (path == NULL)
        return fprintf(stderr, "trac: unable to get working directory.\n");

    while (strcmp(path, "/home"))
    {
        DIR *directory = opendir(path);
        if (directory == NULL) 
            return fprintf(stderr, "trac: unable to open path.\n");

        struct dirent *file;
        while ((file = readdir(directory)) != NULL)
        {
            if (!strcmp(file->d_name, ".trac"))
            {
                snprintf(trac_path, PATH_MAX, "%s/%s", path, ".trac");
                return EXIT_SUCCESS;
            }
        }

        closedir(directory);
        free(path);

        if (chdir("..")) 
            return fprintf(stderr, "trac: unable to change directory.\n");

        path = getcwd(NULL, 0);
        if (path == NULL)
            return fprintf(stderr, "trac: unable to get new directory.\n");
    }

    return EXIT_SUCCESS;
}

static int cmd_init()
{
    char *working_directory = getcwd(NULL, 0);
    if (working_directory == NULL)
        return fprintf(stderr, "trac: unable to get working directory.\n");

    char folder_path[PATH_MAX];
    find_trac_dir(folder_path);

    if (strcmp(folder_path, ""))
        return !printf("Tracker is already initialized.\n");

    snprintf(folder_path, PATH_MAX, "%s/%s", working_directory, ".trac");

    if (mkdir(folder_path, 0755))
        return fprintf(stderr, "trac: failed to create .trac directory.\n");

    printf("Initialized tracker on \"%s\"\n", working_directory);

    return EXIT_SUCCESS;
}
