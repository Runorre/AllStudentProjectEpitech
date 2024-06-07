/*
** EPITECH PROJECT, 2023
** encoder
** File description:
** functions
*/

#include "../include/asm.h"

op_t op_tab[] =
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

int print_command_index(char *command, int fd)
{
    char *temp;
    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        if (my_strcmp(op_tab[i].mnemonique, command) == 0) {
            temp = hexa_to_str(op_tab[i].code);
            write(fd, temp, 1);
            free(temp);
            return 1;
        }
    }
    return 0;
}

int print_hexa_values(char **commands_params, int fd, char *command,
                        labels_l *list)
{
    char *filter[5] = {"zjmp", "ldi", "sti", "fork", NULL};
    int filter_int = 0;
    for (int i = 0; filter[i]; i++)
        if (my_strcmp(filter[i], command) == 0)
            filter_int = 1;
    for (int i = 0, value = 0; commands_params[i]; i++) {
        if (commands_params[i][0] == 'r')
            list->ac_pos += print_reg_value(&commands_params[i][1], fd);
        if (commands_params[i][0] == '%' && filter_int == 0)
            list->ac_pos += print_direct_value(&commands_params[i][1], fd);
        if (commands_params[i][0] != 'r' &&
            (commands_params[i][0] != '%' || filter_int == 1))
            list->ac_pos += print_indirect_value(&commands_params[i][1],
                                                fd, list);
    }
    return 0;
}

int print_hexa_params(char **command, int fd, char *c_name, labels_l *list)
{
    if (array_len(command) <= 1)
        return print_hexa_values(command, fd, c_name, list);
    int binary[8] = {0, 0, 0, 0, 0, 0, 0, 0}, hexa[2] = {0, 0};
    for (int i = 0; command[i]; i++) {
        if (command[i][0] == 'r') binary[2 * i] = 0, binary[2 * i + 1] = 1;
        if (command[i][0] == '%') binary[2 * i] = 1, binary[2 * i + 1] = 0;
        if (command[i][0] != 'r' && command[i][0] != '%')
            binary[2 * i] = 1, binary[2 * i + 1] = 1;
    }
    for (int i = 0, pow = 3; i < 4; i++, pow--)
        if (binary[i]) hexa[0] += my_pow(2, pow);
    for (int i = 4, pow = 3; i < 8; i++, pow--)
        if (binary[i]) hexa[1] += my_pow(2, pow);
    char *temp1 = int_to_hex(hexa[0]), *temp2 = int_to_hex(hexa[1]);
    char *temp3 = my_strcat(temp1, temp2), *temp4 = hexa_to_str(temp3);
    write(fd, temp4, 1);
    free(temp1), free(temp2), free(temp3), free(temp4);
    list->ac_pos++;
    return print_hexa_values(command, fd, c_name, list);
}

void parse_command(char *line, int fd, labels_l *list)
{
    for (int i = 0; line[i]; i++)
        if (line[i] == ',')
            line[i] = ' ';
    char **command_parsed = str_to_word_array(line, ' ');
    int i = 0, fin = 0;
    if (my_strcmp(command_parsed[0], ".comment") == 0) return;
    if (my_strcmp(command_parsed[0], ".name") == 0) return;
    for (; fin == 0 && command_parsed[i]; i++) {
        if (command_parsed[i][my_strlen(command_parsed[i]) - 1] != ':') {
            list->ac_pos += print_command_index(command_parsed[i], fd);
            fin = 1;
        }
    }
    if (fin == 1)
        print_hexa_params(&command_parsed[i], fd, command_parsed[i - 1], list);
}
