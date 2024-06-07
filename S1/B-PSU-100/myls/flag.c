/*
** EPITECH PROJECT, 2022
** B-PSU-100-MAR-1-1-myls-angelo.anselmet
** File description:
** flag
*/

#include "my.h"

int flag(char s, struct DataLS *data)
{
    switch (s) {
    case 'a':
        return data->showhide = 1;
    case 'l':
        return data->flagl = 1;
    case 'R':
        return 0;
    case 'd':
        return data->flagd = 1;
    case 'r':
        return 0;
    case 't':
        return 0;
    default:
        return errormessageflag(s, &(*data));
    }
}

int loopchar(struct DataLS *data, char *option)
{
    for (int i = 1; option[i] != '\0'; i++)
        flag(option[i], &(*data));
}

int checkflag(int av, char **ar, struct DataLS *data)
{
    int j = 1, i = 0;
    while (j != av) {
        if (ar[j][0] == '-')
            loopchar(&(*data), ar[j]);
        else {
            i = data->lenpath;
            data->path[i] = malloc(sizeof(char*) * my_strlen(ar[j]));
            data->path[i] = ar[j];
            data->error = checkiferror(data->path[i]);
            data->lenpath++;
        }
        j++;
    }
}

int flagd(char const *path, struct DataLS *data)
{
    if (data->lenpath == 0){
        my_printf("%s\n", path);
        return 0;
    } else {
        my_printf("%s  ", path);
        return 0;
    }
}
