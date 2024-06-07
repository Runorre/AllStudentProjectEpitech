/*
** EPITECH PROJECT, 2022
** my_print_comb2
** File description:
** like task05 but its is with 2 numbers
*/

#include <unistd.h>

int show_result(int left1, int right1, int left2, int right2)
{
    int space = 32, comma = 44;
    write(1, &left2, 1);
    write(1, &right2, 1);
    write(1, &space, 1);
    write(1, &left1, 1);
    write(1, &right1, 1);
    if (left2 != '9' || right2 != '8' || left1 != '9' || right1 != '9') {
    write(1, &comma, 1);
    write(1, &space, 1);
    }
}

int my_print_comb2(void)
{
    int left1 = 48, right1 = 48, left2 = 48, right2 = 48;
    while (left2 != '9' || right2 != '8' || left1 != '9' || right1 != '9') {
        if (left1 == 57 && right1 == 57) {
            right2++;
            left1 = left2;
            right1 = right2;
        }
        if (right2 == 57) {
            left2++;
            right2 = 48;
        }
        if (right1 == 57) {
            left1++;
            right1 = 48;
        } else {
            right1++;
        }
        show_result(left1, right1, left2, right2);
    }
}
