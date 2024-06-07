/*
** EPITECH PROJECT, 2023
** Dev
** File description:
** game
*/

#include "my.h"

int verifywin(sys_data *sys, map_s *map)
{
    verif_lose(map);
    usleep(1000);
    if (map->lose == 1) {
        kill(sys->pid_ennemie, SIGUSR2);
        return 1;
    } else {
        kill(sys->pid_ennemie, SIGUSR1);
        return 0;
    }
}

int checkenemiewin(sys_data *sys, map_s *map)
{
    pause();
    if (info_global->si_signo == SIGUSR2)
        return 2;
    if (info_global->si_signo == SIGUSR2)
        return 0;
    return 0;
}

int game_p1(sys_data *sys, map_s *map)
{
    int end = 0;
    while (end == 0) {
        print_map(map);
        my_putchar('\n');
        int *pos = get_request_p();
        send_pos(pos, sys);
        iftouch(sys, pos, map);
        end = verifywin(sys, map);
        if (end == 0) {
            enemyattack(map, sys);
            end = checkenemiewin(sys, map);
        }
        free(pos);
    }
    print_map(map);
    if (end == 1)
        my_putstr("\nEnemy won\n");
    if (end == 2)
        my_putstr("\nI won\n");
    return 0;
}

int game_p2(sys_data *sys, map_s *map)
{
    int end = 0;
    while (end == 0) {
        print_map(map);
        my_putchar('\n');
        enemyattack(map, sys);
        end = checkenemiewin(sys, map);
        if (end == 0) {
            int *pos = get_request_p();
            send_pos(pos, sys);
            iftouch(sys, pos, map);
            end = verifywin(sys, map);
            free(pos);
        }
    }
    print_map(map);
    if (end == 1)
        my_putstr("\nEnemy won\n");
    if (end == 2)
        my_putstr("\nI won\n");
    return 0;
}
