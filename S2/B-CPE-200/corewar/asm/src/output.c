/*
** EPITECH PROJECT, 2023
** Bootstrap
** File description:
** output
*/

#include "../include/asm.h"

char *name_to_cor(char *name)
{
    for (int i = 0; name[i]; i++)
        if (name[i] == '.')
            name[i] = '\0';
    name = my_strcat(name, ".cor");
    return name;
}

int header_output(champion *champ, int fd, char **line_by_line, labels_l *list)
{
    int bytes_nb = 0;
    if (my_strlen(champ->name) > 128) return 84;
    if (my_strlen(champ->comment) > 2048) return 84;
    char *magic = hexa_to_str(COREWAR_EXEC_MAGIC), *temp = hexa_to_str("00");
    write(fd, temp, 1), write(fd, magic, my_strlen(magic));
    write(fd, champ->name, my_strlen(champ->name));
    for (int i = 0; i < 128 - (my_strlen(champ->name) - 3); i++)
        write(fd, temp, 1);
    for (int i = 0; line_by_line[i]; i++) {
        bytes_nb = count_bytes(line_by_line[i], fd, bytes_nb, list);
        if (bytes_nb == -1) return 84;
    }
    char *temp_by = hexa_to_str(int_to_hex(bytes_nb));
    for (int i = 4 - my_strlen(temp); i > 0; i--) write(fd, temp, 1);
    write(fd, temp_by, my_strlen(temp_by));
    write(fd, champ->comment, my_strlen(champ->comment));
    for (int i = 0; i < 2048 - (my_strlen(champ->comment) - 4); i++)
        write(fd, temp, 1);
    free(temp), free(magic);
}

void reverse_str(char *str)
{
    char temp;
    for (int start = 0, end = my_strlen(str) - 1; start < end; start++, end--)
        temp = str[start], str[start] = str[end], str[end] = temp;
}

int array_len(char **array)
{
    int i = 0;
    for (; array[i]; i++);
    return i;
}

int str_to_int(char *str)
{
    int num = 0;
    for (int i = 0; str[i] != '\0'; i++)
        num = num * 10 + (str[i] - 48);
    return num;
}
