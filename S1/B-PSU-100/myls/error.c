/*
** EPITECH PROJECT, 2022
** B-PSU-100-MAR-1-1-myls-angelo.anselmet
** File description:
** error
*/

#include "my.h"

int checkiferror(const char *path)
{
    struct stat fdir;
    if (stat(path, &fdir) == -1)
        return errormessagepath(path);
    else
        return 0;
}

int errormessagepath(const char *path)
{
    write(2,"my_ls: cannot access '", 23);
    write(2, path, my_strlen(path));
    perror("'");
    return 84;
}

int errormessageflag(char c, struct DataLS *data)
{
    write(2, "my_ls: option incorrecte — ' ", 31);
    write(2, &c, 1);
    write(2, " ' \nSaisissez « ls --help » pour plus d'informations.\n\0", 58);
    return data->error = 84;
}
