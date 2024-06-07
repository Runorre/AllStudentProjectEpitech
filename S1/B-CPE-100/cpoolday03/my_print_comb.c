/*
** EPITECH PROJECT, 2022
** my_print_comb
** File description:
** function that displays, in ascending order
** all the numbers composed by three different digits num-
** bers (012, 013, 014, 015, 016, 017, 018, 019, 023, . . . , 789)
*/

#include <unistd.h>

int showresult(int left, int middle, int right)
{
    int comma = 44, space = 32;
    write(1, &left, 1);
    write(1, &middle, 1);
    write(1, &right ,1);
    if (left != 55) {
        write(1, &comma, 1);
        write(1, &space, 1);
    }
}

int my_print_comb(void)
{
    int left = 48, middle = 49, right = 49;
    while (left != '7') {
        if (middle == 56) {
            left++;
            middle = left +1;
            right = middle;
        }
        if (right != 57) {
            right++;
        } else {
            middle++;
            right = middle + 1;
        }
        showresult(left,middle,right);
    }
}
