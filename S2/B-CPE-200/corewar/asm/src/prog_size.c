/*
** EPITECH PROJECT, 2023
** encoder
** File description:
** prog_size
*/

#include "../include/asm.h"

op_t op_tabe[] =
{{"live", 1, {T_DIR}, "01", 10, "alive"},
{"ld", 2, {T_DIR | T_IND, T_REG}, "02", 5, "load"},
{"st", 2, {T_REG, T_IND | T_REG}, "03", 5, "store"},
{"add", 3, {T_REG, T_REG, T_REG}, "04", 10, "addition"},
{"sub", 3, {T_REG, T_REG, T_REG}, "05", 10, "soustraction"},
{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, "06", 6,
"et (and  r1, r2, r3   r1&r2 -> r3"},
{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, "07", 6,
"ou  (or   r1, r2, r3   r1 | r2 -> r3"},
{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, "08", 6,
"ou (xor  r1, r2, r3   r1^r2 -> r3"},
{"zjmp", 1, {T_DIR}, "09", 20, "jump if zero"},
{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, "0a", 25,
"load index"},
{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, "0b", 25,
"store index"},
{"fork", 1, {T_DIR}, "0c", 800, "fork"},
{"lld", 2, {T_DIR | T_IND, T_REG}, "0d", 10, "long load"},
{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, "0e", 50,
"long load index"},
{0, 0, {0}, 0, 0, 0}};

int count_hexa_values(char **commands_params, int fd, char *command)
{
    char *filter[5] = {"zjmp", "ldi", "sti", "fork", NULL};
    int filter_int = 0, count = 0;
    for (int i = 0; filter[i]; i++)
        if (my_strcmp(filter[i], command) == 0)
            filter_int = 1;
    for (int i = 0, value = 0; commands_params[i]; i++) {
        if (commands_params[i][0] == 'r')
            count++;
        if (commands_params[i][0] == '%' && filter_int == 0)
            count += 4;
        if (commands_params[i][0] != 'r' &&
        (commands_params[i][0] != '%' || filter_int == 1))
            count += 2;
    }
    return count;
}

int count_hexa_params(char **command, int fd, char *c_name)
{
    if (array_len(command) <= 1)
        return count_hexa_values(command, fd, c_name);
    return 1 + count_hexa_values(command, fd, c_name);
}

int count_command_index(char *command, int fd)
{
    for (int i = 0; op_tabe[i].mnemonique != 0; i++)
        if (my_strcmp(op_tabe[i].mnemonique, command) == 0)
            return 1;
    return 0;
}

int add_label_list(labels_l *list, char *label, int byte_pos)
{
    label[my_strlen(label) - 1] = '\0';
    labels *current = malloc(sizeof(labels));
    current->name = label;
    current->abs_pos = byte_pos;
    current->next = NULL;
    if (!list->first)
        list->first = current;
    else {
        labels *temp = list->first;
        if (i_love_c_one_so_much(temp, label) == 84)
            return 84;
        temp->next = current;
    }
    return 0;
}

int count_bytes(char *line, int fd, int count_bits, labels_l *list)
{
    for (int i = 0; line[i]; i++) if (line[i] == ',') line[i] = ' ';
    char **command_parsed = str_to_word_array(line, ' ');
    int i = 0, fin = 0, r_value = 0;
    if (my_strcmp(command_parsed[0], ".comment") == 0) return 0;
    if (my_strcmp(command_parsed[0], ".name") == 0) return 0;
    for (; fin == 0 && command_parsed[i]; i++) {
        if (command_parsed[i][my_strlen(command_parsed[i]) - 1] != ':') {
            count_bits += count_command_index(command_parsed[i], fd);
            fin = 1;
        } else
            r_value = add_label_list(list, command_parsed[i], count_bits);
        if (r_value == 84)
            return -1;
    }
    if (fin == 1) count_bits += count_hexa_params(&command_parsed[i],
                                        fd, command_parsed[i - 1]);
    return count_bits;
}
