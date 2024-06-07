/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-navy
** File description:
** error
*/

#include "my.h"

int checkifboatright(char *line)
{
    if ((line[2] != line[5]) &&
        (line[3] != line[6])) {
        return 1;
    }
    return 0;
}

int checkifcodisgood(char *line)
{
    if (!(line[2] >= 'A' && line[2] <= 'H') &&
        !(line[5] >= 'A' && line[5] <= 'H')) {
        return 1;
    }
    if (!(line[3] >= '1' && line[3] <= '8') &&
        !(line[6] >= '1' && line[6] <= '8')) {
        return 1;
    }
    return 0;
}

int checkstrlen(char *line)
{
    if (my_strlen(line) == 8 && line[7] == '\n')
        return 0;
    if (my_strlen(line) == 7)
        return 0;
    return 1;
}

int verif_line(char *line, char c)
{
    if (line[0] != c || line[1] != ':' ||
        line[4] != ':' || checkstrlen(line) == 1)
        return 84;
    if (checkifboatright(line) == 1)
        return 84;
    if (checkifcodisgood(line) == 1)
        return 84;
    return 0;
}
