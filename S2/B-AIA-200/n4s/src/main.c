/*
** EPITECH PROJECT, 2023
** Blank
** File description:
** main
*/

#include "../include/my.h"

char *sendintrustion(char *str, int debug)
{
    char *str2 = NULL;
    size_t len = 0;
    my_putstr(str);
    getline(&str2, &len, stdin);
    if (debug)
        my_putstrerr(str2);
    return str2;
}

void action_car(values *val)
{
    if (val->left > val->right && val->right < 400.0)
        return rotateright(val);
    if (val->left < 500.0)
        return rotateleft(val);
    return fontcinq(val);
}

int main(int ac, char **ar)
{
    size_t len = 0;
    int push = 1;
    int round = 0;
    sendintrustion("START_SIMULATION\n", 1);
    sendintrustion("WHEELS_DIR:0\n", 0);
    while (1) {
        char *str = sendintrustion("GET_INFO_LIDAR\n", 0);
        values *val = my_str_to_float_struct(&str[22]);
        fprintf(stderr, "DEBUG : %f %f %f %f %f\n",
        val->left, val->midleft, val->middle, val->midright, val->right);
        action_car(val);
        free(val);
        free(str);
    }
    return 0;
}
