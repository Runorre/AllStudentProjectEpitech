/*
** EPITECH PROJECT, 2023
** boggle
** File description:
** game2tty
*/

#include "my.h"

int check_game(char **str)
{
    if (isatty(0))
        return main_game(str);
    else {
        int end = 0;
        size_t len = 0;
        char *buf = NULL;
        showzone(str);
        write(1, "> ", 2);
        getline(&buf, &len, stdin);
        checkword(buf);
        end = checkinside(str, buf);
        if (end == 0) {
            notgoodmsg(buf);
            write(1, "> ", 2);
        } else {
            modifyforwin(str, buf), showzone(str);
        }
        free(buf);
        return 0;
    }
}

int checknext(char **str, int x, int y, char *word)
{
    int where = 1, len = my_strlen(word) - 1, tmp = 1;
    while (len + 1 > where) {
        if (str[x + 1] && str[x + 1][y] == word[where]) {
            x++, where++;
        }
        if (str[x][y + 1] == word[where]) {
            y++, where++;
        }
        if (y != 0 && str[x][y - 1] == word[where]) {
            y--, where++;
        }
        if (x != 0 && str[x - 1][y] == word[where]) {
            x--, where++;
        }
        if (tmp != where)
            tmp = where;
        else
            return 0;
    }    
    return 1;
}
