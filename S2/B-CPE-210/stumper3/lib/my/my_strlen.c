/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** return len of string
*/
int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
