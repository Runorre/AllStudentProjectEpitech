/*
** EPITECH PROJECT, 2022
** my_compute_factorial_it
** File description:
** factoriel iterative
*/
int my_compute_factorial_it(int nb)
{
    if (nb < 0 || nb > 12) {
        return (0);
    }
    int result = 1;
    for (nb; nb != 0; nb--) {
        result *= nb;
    }
    return result;
}
