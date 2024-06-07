/*
** EPITECH PROJECT, 2023
** encoder
** File description:
** functions_2
*/

#include "../include/asm.h"

int print_reg_value(char *command, int fd)
{
    int value = 0;
    if (command[0] && command[0] >= '0' && command[0] <= '9')
        value = command[0] - '0';
    if (command[1] && command[1] >= '0' && command[1] <= '6')
        value += command[1] - '0';
    char *temp = int_to_hex(value);
    if (my_strlen(temp) % 2 != 0)
        temp = my_strcat("0", temp);
    char *temp2 = hexa_to_str(temp);
    write(fd, temp2, 1);
    free(temp);
    free(temp2);
    return 1;
}

int print_direct_value(char *command, int fd)
{
    char *temp3 = command;
    if (my_strlen(command) % 2 != 0)
        temp3 = my_strcat("0", temp3);
    if (command[1] && command[1] >= '0' && command[1] <= '9')
        temp3 = int_to_hex(str_to_int(command));
    char *temp = hexa_to_str(temp3), *temp2 = hexa_to_str("00");
    for (int i = my_strlen(temp); i < 4; i++)
        write(fd, temp2, 1);
    write(fd, temp, my_strlen(temp));
    free(temp), free(temp2), free(temp3);
    return 4;
}

int search_pos_label(char *label, labels_l *list)
{
    labels *temp = list->first;
    for (int fin = 0, i = 0; temp->next && fin == 0; i++) {
        if (i != 0)
            temp = temp->next;
        if (my_strcmp(temp->name, label) == 0)
            fin = 1;
    }
    if (list->ac_pos < temp->abs_pos)
        return temp->abs_pos;
    else
        return temp->abs_pos - (list->ac_pos - 1);
}

int print_indirect_value(char *command, int fd, labels_l *list)
{
    if (command[0] == ':') {
        int pos = search_pos_label(&command[1], list);
        char *temp = int_to_hex(pos);
        if (my_strlen(temp) % 2 != 0) temp = my_strcat("0", temp);
        char *temp2 = hexa_to_str(temp);
        char *temp_z;
        if (pos > 0) temp_z = hexa_to_str("00");
        if (pos <= 0) temp_z = hexa_to_str("ff");
        if (my_strlen(temp) == 2) write(fd, temp_z, 1);
        write(fd, temp2, my_strlen(temp2));
        free(temp), free(temp_z);
        return 2;
    }
    if (my_strlen(command) % 2 != 0) command = my_strcat("0", command);
    char *temp = hexa_to_str(command), *temp2 = hexa_to_str("00");
    for (int i = my_strlen(temp); i < 2; i++) write(fd, temp2, 1);
    write(fd, temp, my_strlen(temp));
    free(temp), free(temp2);
    return 2;
}

char *chars_test(char *str, int i)
{
    if (str[i + 1])
        return NULL;
    str[i] = '\0';
    return str;
}
