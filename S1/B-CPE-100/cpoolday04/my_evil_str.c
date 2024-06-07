/*
** EPITECH PROJECT, 2022
** my_evil_str
** File description:
** evil programe *evil laugh*
*/
char *my_evil_str(char *str)
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
