/*
** EPITECH PROJECT, 2023
** Stumper
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>

int is_num(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0'; i++) {
        if (i == 0 && str1[i] == '-')
            i++;
        if (!(str1[i] >= '0' && str1[i] <= '9'))
            return 1;
    }
    for (int e = 0; str2[e] != '\0'; e++) {
        if (e == 0 && str2[e] == '-')
            e++;
        if (!(str2[e] >= '0' && str2[e] <= '9'))
            return 1;
    }
    if (atoi(str1) > atoi(str2))
        return 1;
    return 0;
}

int main(int ac, char **ar)
{
    if (ac != 3 || is_num(ar[1], ar[2]))
        return 84;
    int end = atoi(ar[2]) + 1;
    int check = 0;
    for (int start = atoi(ar[1]); start != end; start++) {
        check = 0;
        if (start % 2 == 0) {
            printf("Fozz");
            check++;
        }
        if (start % 9 == 0) {
            printf("Bazz");
            check++;
        }
        if (check == 0)
            printf("%d", start);
        printf("\n");
    }
    return 0;
}
