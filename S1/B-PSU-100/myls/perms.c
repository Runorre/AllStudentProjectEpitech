/*
** EPITECH PROJECT, 2022
** B-PSU-100-MAR-1-1-myls-angelo.anselmet
** File description:
** perms
*/

#include "my.h"

void checktypefile(struct stat *info)
{
    if (S_ISREG(info->st_mode))
        my_putchar('-');
    if (S_ISDIR(info->st_mode))
        my_putchar('d');
    if (S_ISLNK(info->st_mode))
        my_putchar('l');
}

void checkpermsuser(struct stat *info)
{
    if (info->st_mode & S_IRUSR)
        my_putchar('r');
    else
        my_putchar('-');
    if (info->st_mode & S_IWUSR)
        my_putchar('w');
    else
        my_putchar('-');
    if (info->st_mode & S_IXUSR)
        my_putchar('x');
    else
        my_putchar('-');
}

void checkpermsgrp(struct stat *info)
{
    if (info->st_mode & S_IRGRP)
        my_putchar('r');
    else
        my_putchar('-');
    if (info->st_mode & S_IWGRP)
        my_putchar('w');
    else
        my_putchar('-');
    if (info->st_mode & S_IXGRP)
        my_putchar('x');
    else
        my_putchar('-');
}

void checkpermsother(struct stat *info)
{
    if (info->st_mode & S_IROTH)
        my_putchar('r');
    else
        my_putchar('-');
    if (info->st_mode & S_IWOTH)
        my_putchar('w');
    else
        my_putchar('-');
    if (info->st_mode & S_IXOTH)
        my_putchar('x');
    else
        my_putchar('-');
}

void perml(struct stat *info)
{
    checktypefile(&(*info));
    checkpermsuser(&(*info));
    checkpermsgrp(&(*info));
    checkpermsother(&(*info));
}
