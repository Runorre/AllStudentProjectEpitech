/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** reverse a string
*/

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

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
