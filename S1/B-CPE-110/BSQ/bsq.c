/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-BSQ-angelo.anselmet
** File description:
** bsq
*/

#include "my.h"

char **getsquare(int fd, char *path)
{
    struct stat s;
    stat(path, &s);
    char *buffer = malloc(sizeof(char) * s.st_size);
    read(fd, buffer, s.st_size);
    buffer[s.st_size - 1] = '\0';
    if (buffer[0] != '\0') {
        char **square = my_str_to_word_array(buffer);
        free(buffer);
        return square;
    } else {
        char **square = malloc(sizeof(char *) * 1);
        free(buffer);
        return square;
    }
}

int **fullsquarevalue(char **square, int **finding)
{
    int y = 1, x = 1;
    while (square[y] != NULL && finding[0][0] == 0) {
        switch (square[y][x - 1]) {
        case 'o':
            finding[y][x] = 0;
            x++;
            break;
        case '.':
            finding[y][x] = placevalue(finding, x, y);
            x++;
            break;
        case '\0':
            y++;
            x = 1;
            break;
        default:
            finding[0][0] = -1; break;
        }
    }
    return finding;
}

int **createsquarevalue(char **square)
{
    int len_y = my_getnbr2(square[0]), len_x = my_strlen(square[1]);
    int **finding = malloc(sizeof(int *) * (len_y + 1));
    finding[0] = malloc(sizeof(int) * (len_x + 1));
    for (int i = 0; i != len_x + 1; i++)
        finding[0][i] = 0;
    for (int i = 1; i != len_y + 1; i++) {
        finding[i] = malloc(sizeof(int) * (len_x + 1));
        finding[i][0] = 0;
    }
    return fullsquarevalue(square, finding);
}

int findbigsquare(char **square)
{
    int i = my_strlen(square[1]) + 1;
    int **finding = createsquarevalue(square);
    if (finding[0][0] == -1)
        return 1;
    int *bigger = searchbigsquare(finding, my_getnbr2(square[0]) + 1, i);
    int y = bigger[1] - (bigger[0] - 1), x = bigger[2] - (bigger[0] - 1);
    while ((y != bigger[1] || x != bigger[2]) && bigger[0] != 0) {
        square[y][x] = 'x';
        if (x == bigger[2]) {
            y++;
            x = bigger[2] - (bigger[0] - 1);
        } else
            x++;
    }
    square[y][x] = checking(bigger, square[y][x]);
    my_putcharstar(square);
    free(finding);
    free(bigger);
}

int bsq(char *av)
{
    int fd = open(av, O_RDONLY);
    if (fd < 0 || read(fd, "", 0) == -1)
        return 84;
    char **square = getsquare(fd, av);
    if (square[0] == NULL) {
        return 84;
    }
    if (checkifsquare(square) == 1) {
        free(square);
        close(fd);
        return 84;
    }
    if (findbigsquare(square) == 1) {
        free(square);
        close(fd);
        return 84;
    }
    free(square);
    close(fd);
    return 0;
}
