/*
** EPITECH PROJECT, 2023
** boggle
** File description:
** main
*/

#include "my.h"

int init_game(char **argv)
{
    int x = 3, size = 4;
    char *w_word = NULL;
    while (argv[x] != NULL) {
        if (strcmp(argv[x], "-s") == 0) {
            x++;
            size = atoi(argv[x]);
        }
        if (strcmp(argv[x], "-w") == 0) {
            x++;
            w_word = argv[x];
        }
        x++;
    }
    if (my_strlen(argv[2]) != (size * size))
        return 84;
    if (w_word == NULL)
        return check_game(my_str_to_word_array(argv[2], size));
    else
        return not_loop_game(my_str_to_word_array(argv[2], size),
                             w_word);
}

int main(int argc, char **argv)
{
    if (argc < 3)
        return 84;
    int x = 0;
    while (argv[x] != NULL) {
        if (result(argv, x) == 84) {
            return (84);
        }
        x++;
    }
    return init_game(argv);
}

