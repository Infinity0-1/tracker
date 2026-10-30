static int cmd_new(char *tast_title)
{
    char trac_dir[PATH_MAX];
    find_trac_dir(trac_dir);

    if (!strcmp(trac_dir, ""))
        return fprintf(stderr, "Tracker has not been initialized yet.\n");

    if (tast_title == NULL)
        return fprintf(stderr, "trac: cannot create emtpy task.\n");

    time_t now = time(NULL);
    struct tm *timestamps = localtime(&now);

    char unique_ID[32];
    strftime(unique_ID, sizeof(unique_ID), "%Y%m%d%H%M%S", timestamps);

    char folder_path[2 * PATH_MAX];
    snprintf(folder_path, sizeof(folder_path), "%s/%s", trac_dir, unique_ID);
    mkdir(folder_path, 0755);

    char file_path[3 * PATH_MAX];
    snprintf(file_path, sizeof(file_path), "%s/%s.md", folder_path, unique_ID);

    FILE *file = fopen(file_path, "wx");
    if (file == NULL)
        return fprintf(stderr, "trac: failed to create file. Slow down.\n");

    fprintf(file, "# %s\n\n", tast_title);
    fprintf(file, "- TAG: \n");
    fprintf(file, "- STATUS: OPEN \n");

    return EXIT_SUCCESS;
}
