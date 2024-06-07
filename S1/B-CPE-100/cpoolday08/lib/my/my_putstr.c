/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** show a string in console
*/
int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
