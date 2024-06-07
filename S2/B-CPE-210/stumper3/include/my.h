/*
** EPITECH PROJECT, 2023
** Blank
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include "lib.h"
    int checknbr(char *str);
    void modify_maj_letter(int key, char *buffer, int i);
    void modify_min_letter(int key, char *buffer, int i);
    void file_cesar(int key, FILE *fd, int cryptfd);
    void str_line_cesar(int key, char *buffer, int cryptfd);
    int init_cesar(int ac, char **ar);
#endif /* !MY_H_ */
