/*
** EPITECH PROJECT, 2024
** MyFTP
** File description:
** strcat_realloc
*/

#include "myftp.h"

char *strcat_r(char **dest, const char *src)
{
    size_t dest_len = strlen(*dest);
    size_t src_len = strlen(src);
    char *new_dest = realloc(*dest, dest_len + src_len + 1);

    if (new_dest == NULL)
        return NULL;
    *dest = new_dest;
    strcpy(*dest + dest_len, src);
    return *dest;
}
