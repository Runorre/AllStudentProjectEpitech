/*
** EPITECH PROJECT, 2023
** MixWord
** File description:
** include
*/

#ifndef MIXWORD_H
    #define MIXWORD_H

    #include <unistd.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <time.h>

    typedef struct data_s {
        int size;
        int fd;
        char **array;
        char **tab;
    } data_t;

    // str_related.c
    char *str_from_str(char *str, int index_dep, int index_fin);
    char *file_to_str(char *filepath, data_t *data);
    char **str_to_word_array(char *str, char sep);
    char **change_upper_to_lower(char **array);
    void print_array(char **array, int word, data_t *data);

    // error_gestion.c
    int error_gestion(data_t *data);

    // algorithm.c
    char **create_empty_array(data_t *data);
    int main_algo(data_t *data);

    // str_related2.c
    int my_array_len(char **array);

    // check_dir.c
    int put_up_right(data_t *data, int x, int y, int word_index);
    int put_up(data_t *data, int x, int y, int word_index);
    int put_up_left(data_t *data, int x, int y, int word_index);
    int put_left(data_t *data, int x, int y, int word_index);
    int put_down_left(data_t *data, int x, int y, int word_index);

    // check_dir2.c
    int put_down(data_t *data, int x, int y, int word_index);
    int put_down_right(data_t *data, int x, int y, int word_index);
    int put_right(data_t *data, int x, int y, int word_index);
    
    //order66.c
    void order66(data_t *data);

#endif
