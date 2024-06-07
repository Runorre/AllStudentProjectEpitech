/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** reverse a string
*/

char *my_revstr(char *str)
{
    int start = 0;
    int end = my_strlen(str) - 1;
    char c;
    while (start < end) {
        c = str[start];
        str[start] = str[end];
        str[end] = c;
        start++;
        end--;
    }
    return (str);
}
