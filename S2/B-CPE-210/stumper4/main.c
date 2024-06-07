/*
** EPITECH PROJECT, 2023
** MixWord
** File description:
** MixWord
*/

#include "include.h"

data_t *checkarrgument(int ac, char **ar)
{
    if (strcmp("-f", ar[1]) != 0)
        exit(84);
    if (ac > 3 && (strcmp("-s", ar[3]) != 0 || atoi(ar[4]) <= 0))
        exit(84);
    int fd = open(ar[2], O_RDONLY);
    if (fd == -1)
        exit(84);
    data_t *data = malloc(sizeof(data_t));
    data->fd = fd;
    if (ac > 3)
        data->size = atoi(ar[4]);
    else
        data->size = 8;
    return data;
}

int main(int ac, char **ar)
{
    if (ac < 3 || ac > 5 || ac == 4)
        return 84;
    data_t *data = checkarrgument(ac, ar);
    char *str = file_to_str(ar[2], data);
    data->array = str_to_word_array(str, '\n');
    if (error_gestion(data) == 84)
        return 84;
    srand(time(NULL));
    int word_putted = main_algo(data);
    print_array(data->tab, word_putted, data);
    order66(data);
    free(str);
}
