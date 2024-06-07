/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** fight3
*/

#include "rpg.h"

int end_action(sfMusic *battle, fight_s *fight, sys_data *sys)
{
    sfMusic_stop(battle);
    sfMusic_destroy(battle);
    if (sys->fight == 0)
        return 0;
    if (sys->fight == 3) {
        gameover(fight, sys);
        return 3;
    }
    if (sys->fight == 4) {
        victory(fight, sys);
        return 1;
    }
}
