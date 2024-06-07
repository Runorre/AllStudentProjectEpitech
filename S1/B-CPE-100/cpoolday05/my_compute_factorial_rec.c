/*
** EPITECH PROJECT, 2022
** my_compute_factorial_rec
** File description:
** factorial recusive
*/
int my_compute_factorial_rec(int nb)
{
    if (nb < 0 || nb > 12) {
        return (0);
    }
    if (nb > 0) {
        return (nb * my_compute_factorial_rec(nb - 1));
    } else {
        return (1);
    }
}
