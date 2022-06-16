char * simplifyPath(char * path){
    char *dirs[100], *p = path, dir_top = -1;
    while (*path) {
        char *slash1 = strchr(path, '/');
        char *slash2 = strchr(slash1 + 1, '/');
        slash2 ? *slash2 = 0 : 0;   
        if (isalpha(slash1[1]))
            slash1[1] ? dirs[++dir_top] = strdup(slash1 + 1) : 0;
        else if (slash1[1] == '.' && slash1[2] == '.')
            slash1[3] == '/' || !slash1[3] ? dir_top >= 0 ? dir_top-- : 0 :
            (dirs[++dir_top] = strdup(slash1 + 1), 0);
        else if (slash1[1] == '.' && slash1[2] && slash1[2] != '/')
            slash1[1] ? dirs[++dir_top] = strdup(slash1 + 1) : 0;
        slash2 ? *slash2 = '/' : 0;
        path = slash2 ? slash2 : "";
    }
    for (int i = (strcpy(p, "/"), 0) ; i <= dir_top && (strcat(p, dirs[i]), free(dirs[i]), 1) ; ++i <= dir_top ? strcat(p, "/") : 0);
    return p;
}