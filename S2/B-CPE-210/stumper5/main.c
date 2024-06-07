/*
** EPITECH PROJECT, 2023
** B-CPE-210-MAR-2-1-stumper5-angelo.anselmet
** File description:
** main
*/

#include "my.h"

int main(int ac, char **ar)
{
    if (ac == 1) {
        game *test = check_nothing(NULL);
        game_loop(test);
        return 0;
    }
    if (ac > 7)
        return 84;
    game *test = init_game(ac, ar);
    game_loop(test);
    return 0;
}
