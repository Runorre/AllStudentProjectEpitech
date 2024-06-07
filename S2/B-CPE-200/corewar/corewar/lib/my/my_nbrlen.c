/*
** EPITECH PROJECT, 2022
** my_nbrlen
** File description:
** nbrlen
*/

int my_nbrlen(int n)
{
    int len = 0;
    if (n == 0)
        return 1;
    if (n < 0)
        n *= -1;
    while (n > 0) {
        n /= 10;
        len++;
    }
    return len;
}

int my_unnbrlen(unsigned int n)
{
    int len = 0;
    if (n == 0)
        return 1;
    if (n < 0)
        n *= -1;
    while (n > 0) {
        n /= 10;
        len++;
    }
    return len;
}

int my_longnbrlen(long n)
{
    int len = 0;
    if (n == 0)
        return 1;
    if (n < 0)
        n *= -1;
    while (n > 0) {
        n /= 10;
        len++;
    }
    return len;
}

int my_unlongnbrlen(unsigned long n)
{
    int len = 0;
    if (n == 0)
        return 1;
    if (n < 0)
        n *= -1;
    while (n > 0) {
        n /= 10;
        len++;
    }
    return len;
}
