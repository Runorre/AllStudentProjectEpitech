/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** give power of number recusive
*/
int my_compute_power_rec(int nb, int p)
{
    if (p < 0 || nb > 21000000000) {
        return 0;
    }
    if (p > 0) {
        return (nb * my_compute_power_rec(nb, (p - 1)));
    } else {
        return 1;
    }
}
