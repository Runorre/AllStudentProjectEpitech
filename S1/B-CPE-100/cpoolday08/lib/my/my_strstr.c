/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** strstr
*/

int checkword(char *str, char *to_find, int i)
{
    int e = 0;
    while (to_find[e] != '\0') {
        if (to_find[e] == str[i]) {
            e++;
            i++;
        } else {
            return 0;
        }
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    int found = 0, i = 0;
    while (str[i] != '\0' && found == 0) {
        if (str[i] == to_find[0]) {
            found = checkword(str, to_find, i);
        } else
            i++;
    }
    if (found != 0)
        return &str[i];
    else
        return;
}
