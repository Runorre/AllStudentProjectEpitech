/*
** EPITECH PROJECT, 2023
** Dev
** File description:
** connect2
*/

#include "my.h"

void send_pos(int *pos, sys_data *sys)
{
    for (int i = 0; i != pos[0]; i++) {
        kill(sys->pid_ennemie, SIGUSR1);
        usleep(1000);
    }
    kill(sys->pid_ennemie, SIGUSR2);
    usleep(1000);
    for (int i = 0; i != pos[1]; i++) {
        kill(sys->pid_ennemie, SIGUSR1);
        usleep(1000);
    }
    kill(sys->pid_ennemie, SIGUSR2);
}

void iftouch(sys_data *sys, int *pos, map_s *map)
{
    pause();
    convertcood(pos);
    if (info_global->si_signo == SIGUSR1) {
        my_putstr("hit\n\n");
        map->enemy_map[pos[1]][pos[0]] = 'x';
    }
    if (info_global->si_signo == SIGUSR2) {
        my_putstr("missed\n\n");
        map->enemy_map[pos[1]][pos[0]] = 'o';
    }
    info_global = NULL;
}

void enemyattack(map_s *map, sys_data *sys)
{
    my_putstr("waiting for enemy’s attack...\n");
    int touch = verif_pos_ship(map->joueur_map, convertcood(get_pos()));
    usleep(1000);
    if (touch == 1) {
        kill(sys->pid_ennemie, SIGUSR1);
        my_putstr("hit\n\n");
    } else {
        kill(sys->pid_ennemie, SIGUSR2);
        my_putstr("missed\n\n");
    }
}
