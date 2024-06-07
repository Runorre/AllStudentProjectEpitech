/*
** EPITECH PROJECT, 2023
** getnbr
** File description:
** getnbr
*/

int my_getnbr(char *str)
{
    int i = 0;
    int j = 0;
    int final = 0;
    while (str[i] < '0' || str[i] > '9') {
        i++;
    }
    i = j;
    while (str[i] >= '0' && str[i] <= '9') {
        final *= 10;
        final += str[i] - '0';
        i++;
    }
    if (j != 0 && str[j - 1] == '-')
        final *= -1;
    return final;
}
