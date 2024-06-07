/*
** EPITECH PROJECT, 2022
** my_is_pirme
** File description:
** pirme?
*/
int my_is_prime(int nb)
{
    for (int i = 2; i != nb; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}
