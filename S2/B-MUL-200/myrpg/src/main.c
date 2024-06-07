/*
** EPITECH PROJECT, 2023
** TEST
** File description:
** main
*/

#include "rpg.h"

int main(void)
{
    srand(time(NULL));
    sys_data *sys = init_sys();
    menu(sys);
    return 0;
}
