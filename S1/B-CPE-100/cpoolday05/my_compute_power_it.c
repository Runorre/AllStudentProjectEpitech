/*
** EPITECH PROJECT, 2022
** my_compute_power_it
** File description:
** give power of number
*/
int my_compute_power_it(int nb, int p)
{
    int result = 1;
    if (p < 0) {
        return 0;
    }
    for (p; p != 0; p--) {
        result *= nb;
        if (result > 2100000000) {
            return 0;
        }
    }
    return result;
}
