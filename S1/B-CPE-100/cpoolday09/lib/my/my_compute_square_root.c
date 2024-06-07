/*
** EPITECH PROJECT, 2022
** my_compute_sqare_root.c
** File description:
** find the square root of number
*/
int my_compute_square_root(int nb)
{
    if (nb < 0) {
        return 0;
    }
    int number = 0;
    for (int i; (i * i) != nb && i < nb; i++) {
        number++;
    }
    if (number == nb) {
        return 0;
    } else {
    return number;
    }
}
