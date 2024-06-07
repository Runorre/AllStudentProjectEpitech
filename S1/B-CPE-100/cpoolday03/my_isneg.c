/*
** EPITECH PROJECT, 2022
** my_isneg
** File description:
** A function displays N if integer as negative else show P
*/

#include <unistd.h>

int my_isneg(int n)
{
    char result;
    if (n < 0){
        result = 78;
    } else {
        result = 80;
    }
    write(1, &result, 1);
}
