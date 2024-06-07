/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-navy-anaelle.urbon
** File description:
** main
*/

#include "my.h"
int arg_h(int ac, char **av)
{
    int i = 0;
    while (i != ac) {
        if (av[i][0] == '-' && av[i][1] == 'h') {
            my_printf("USAGE\n");
            my_printf("\t./navy [first_player_pid] navy_positions\n");
            my_printf("DESCRIPTION\n");
            my_printf("\tfirst_player_pid:");
            my_printf("\tonly for the 2nd player. pid of the first player.\n");
            my_printf("\tnavy_positions:");
            my_printf("\t\tfile representing the positions of the ships\n");
            return (1);
        }
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    if (arg_h(ac, av) == 1)
        return 0;
    map_s *map = NULL;
    map = ini_map(map);
    if (ac == 2) {
        return player1_connect(av[1], map);
    }
    if (ac == 3) {
        return player2_connect(my_getnbr(av[1]), av[2], map);
    }
}
