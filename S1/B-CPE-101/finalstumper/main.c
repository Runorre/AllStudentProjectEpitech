/*
** EPITECH PROJECT, 2022
** Rush3 main
** File description:
** rush3
*/

#include <unistd.h>
#include "my.h"
#include "rush3.h"

int main(void)
{
    char buff[4097 + 1];
    int offset = 0, memverify = 0;
    int len;
    while ((len = read(0 , buff + offset , 4097 - offset)) > 0)
        offset = offset + len ;
    buff[offset] = '\0';
    while (buff[memverify] != '\0')
        memverify++;
    if (len < 0 || memverify == 4097) {
        write(2, "none", 5);
        write(1, "\n", 1);
        return (84);
    }
    return (rush3(buff));
}
