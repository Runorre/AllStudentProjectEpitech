/*
** EPITECH PROJECT, 2022
** B-PSU-100-MAR-1-1-myls-angelo.anselmet
** File description:
** flagL
*/

#include "my.h"

char *gettime(char *ti)
{
    int i = 0;
    while (ti[i] != '\0') {
        if (ti[i] == ':') {
            i += 3;
            break;
        }
        i++;
    }
    ti[i] = '\0';
    return ti;
}

int showuser(struct stat *info)
{
    struct passwd *uid = getpwuid(info->st_uid);
    struct group *gid = getgrgid(info->st_gid);
    my_printf(" %i %s %s ", info->st_nlink, uid->pw_name, gid->gr_name);
    my_printf("%i %s", info->st_size, gettime(ctime(&info->st_mtime) + 4));
}

int flagld(char const *path, struct stat *info)
{
    perml(&(*info));
    showuser(&(*info));
    my_printf(" %s\n", path);
    return 0;
}

int showdetalls(char const *path, struct DataLS *data)
{
    struct stat info;
    stat(path, &info);
    if (data->flagd == 1)
        return flagld(path, &info);
    DIR *fdir = opendir(path);
    struct dirent *re = readdir(fdir);
    while (re != NULL) {
        stat(my_strcat(my_strcat(path, "/"), re->d_name), &info);
        if (re->d_name[0] != '.' || data->showhide == 1) {
            perml(&info);
            showuser(&info);
            my_printf(" %s\n", re->d_name);
        }
        re = readdir(fdir);
    }
    closedir(fdir);
}
