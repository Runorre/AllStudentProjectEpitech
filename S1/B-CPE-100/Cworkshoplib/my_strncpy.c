/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** copies n characters from a string into another.
*/
char *my_strncpy(char *dest, char const *str, int n)
{
    for (int i = 0; i != n; i++)
        dest[i] = str[i];
    if (str[n] != '\0')
        dest[n] == '\0';
    return dest;
}
