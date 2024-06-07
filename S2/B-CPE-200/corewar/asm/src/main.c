/*
** EPITECH PROJECT, 2023
** CoreWar
** File description:
** main
*/

#include "../include/asm.h"

int i_love_c_one_so_much(labels *temp, char *label)
{
    for (; temp; temp = temp->next)
        if (my_strcmp(temp->name, label) == 0)
            return 84;
    return 0;
}

int return_error(int err, char *message)
{
    write(2, message, my_strlen(message));
    write(2, "\n", 1);
    return err;
}

int error_gestion(char **lines, champion *champ)
{
    if (!champ->name || !champ->comment)
        return 84;
    return 0;
}

int main(int ac, char **av)
{
    char *source = av[1];
    FILE *file_source = fopen(source, "r");
    if (!file_source || ac > 2) return return_error(84, "./asm [source]");
    char *output_name = name_to_cor(source), *temp_z = hexa_to_str("00");
    int fd = open(output_name, O_CREAT | O_RDWR | O_TRUNC, 0666);
    if (fd == -1) return 84;
    size_t len = 0;
    char *line = NULL, *data = NULL, **line_by_line = NULL;
    while (getline(&line, &len, file_source) != -1)
        data = my_strcat(data, line);
    if (!data) return return_error(84, "File is empty");
    line_by_line = str_to_word_array(data, '\n');
    champion *champ = create_champion(line_by_line);
    if (error_gestion(line_by_line, champ) == 84) return 84;
    labels_l *labels_list = malloc(sizeof(labels_l));
    labels_list->ac_pos = 0;
    if (header_output(champ, fd, line_by_line, labels_list) == 84) return 84;
    for (int i = 0; line_by_line[i]; i++)
        parse_command(line_by_line[i], fd, labels_list);
    return 0;
}
