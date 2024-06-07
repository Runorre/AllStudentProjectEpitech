/*
** EPITECH PROJECT, 2023
** boggle
** File description:
** game
*/

#include "my.h"

int checkinside(char **str, char *check)
{
    int i = 0, j = 0, e = 0, end = 0;
    while (str[i] != NULL && end == 0) {
        if (check[e] == str[i][j])
            end = checknext(str, i, j, check);
        if (str[i][j] == '\0') {
            i++;
            j = 0;
        } else
            j++;
    }
    if (end == 1)
        return 1;
    return 0;
}

void notgoodmsg(char *str)
{
    my_putstr("The word ");
    my_putchar('"');
    my_putstr(str);
    my_putchar('"');
    my_putstr(" is not in the grid.\n");
}

int not_loop_game(char **str, char *word)
{
    if (checkinside(str, word) == 0)
        notgoodmsg(word);
    else {
        modifyforwin(str, word);
        showzone(str);
    }
    order66(str);
    return 0;
}

int main_game(char **str)
{
    int end = 0;
    size_t len = 0;
    char *buf = NULL;
    showzone(str);
    while (end == 0) {
        write(1, "> ", 2);
        getline(&buf, &len, stdin);
        checkword(buf);
        end = checkinside(str, buf);
        if (end == 0)
            notgoodmsg(buf);
    }
    modifyforwin(str, buf);
    showzone(str);
    free(buf);
    order66(str);
    return 0;
}

