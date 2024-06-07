/*
** EPITECH PROJECT, 2022
** B-CPE-110-MAR-1-1-pushswap-angelo.anselmet
** File description:
** message
*/

#include "my.h"

struct buffer createbuffer(void)
{
    struct buffer buf;
    buf.str = malloc(sizeof(char) * 9000005);
    buf.i = 0;
    return buf;
}

void addtobuf(struct buffer *buf, char *str)
{
    if (buf->i >= 9000000) {
        buf->str[buf->i] = '\0';
        write(1, buf->str, buf->i);
        buf->i = 0;
        for (int j = 0; str[j]; j++) {
            buf->str[j] = str[j];
            buf->i++;
        }
    } else {
        for (int j = 0; str[j]; j++) {
            buf->str[buf->i] = str[j];
            buf->i++;
        }
    }
}

void showfinal(struct buffer *buf)
{
    buf->str[buf->i] = '\0';
    write(1, buf->str, buf->i);
    free(buf->str);
}
