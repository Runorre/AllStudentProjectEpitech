/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** my
*/
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include "struct.h"
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#ifndef MY_H_
    #define MY_H_
int my_printf(char const *format, ...);
int my_strlen(char const *str);
int checkflag(int av, char **ar, struct DataLS *data);
int errormessageflag(char c, struct DataLS *data);
int checkiferror(const char *path);
int errormessagepath(const char *path);
int flagd(char const *path, struct DataLS *data);
char *converter(unsigned int nb, int base, int maj, char *tab);
int showdetalls(char const *path, struct DataLS *data);
char *my_strcat(char const *dest, char const *src);
void my_putchar(char c);
void perml(struct stat *info);
#endif /* !MY_H_ */
