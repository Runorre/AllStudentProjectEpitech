/*
** EPITECH PROJECT, 2022
** my_strupcase
** File description:
** a faire
*/

char *my_strupcase(char *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] <= 'z' && str[a] >= 'a')
            str[a] = str[a] - 32;
    }
    return str;
}
