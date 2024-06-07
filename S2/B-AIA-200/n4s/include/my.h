/*
** EPITECH PROJECT, 2023
** Blank
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "lib.h"

    typedef struct libdar_s {
        float left;
        float midleft;
        float middle;
        float midright;
        float right;
    }values;

    values *my_str_to_float_struct(char *str);
    char *sendintrustion(char *str, int debug);
    void rotateright(values *val);
    void fontcinq(values *val);
    void rotateleft(values *val);


#endif /* !MY_H_ */
