/*
** EPITECH PROJECT, 2022
** B-PSU-100-MAR-1-1-myls-angelo.anselmet
** File description:
** myls
*/

#include "my.h"


int myls(char const *path, struct DataLS *data)
{
    struct stat s;
    stat(path, &s);
    if (data->flagd == 1)
        return flagd(path, &(*data));
    DIR *fdir = opendir(path);
    if (fdir == NULL && S_ISREG(s.st_mode))
        return my_printf("%s\n", path);
    else if (fdir == NULL)
        return data->error = errormessagepath(path);
    struct dirent *re = readdir(fdir);
    while (re != NULL) {
        if (re->d_name[0] != '.' || data->showhide == 1) {
            my_printf("%s  ", re->d_name);
        }
        re = readdir(fdir);
    }
    my_printf("\n");
    closedir(fdir);
    return 0;
}

int checkingflag(char const *path, struct DataLS *data)
{
    if (data->flagl == 1)
        return showdetalls(path, &(*data));
    else
        return myls(path, &(*data));
}

int main(int argc, char *argv[])
{
    struct DataLS data; struct stat s;
    data.showhide = 0, data.lenpath = 0, data.flagd = 0;
    data.flagl = 0, data.error = 0;
    data.path = malloc(sizeof(char**) * argc);
    checkflag(argc, argv, &data);
    if (data.error == 84)
        return data.error;
    if (data.lenpath == 0)
        return checkingflag(".", &data);
    for (int e = 0; e != data.lenpath; e++) {
        stat(data.path[e], &s);
        if ((data.lenpath > 1 && data.flagd == 0) && S_ISDIR(s.st_mode))
            my_printf("%s:\n", data.path[e]);
        checkingflag(data.path[e], &data);
        if (data.lenpath > 1 && (e != (data.lenpath - 1) || data.flagd == 1))
            my_printf("\n");
    }
    free(data.path);
    return data.error;
}
