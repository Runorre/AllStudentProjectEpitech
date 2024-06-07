/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-mypaint-angelo.anselmet
** File description:
** event_file
*/

#include "my.h"

void save_file(sys_data *sys)
{
    char *line = NULL;
    size_t len;
    my_putstr("Name of file:");
    getline(&line, &len, stdin);
    line = my_strcat(line, ".jpg");
    sfImage_saveToFile(sys->canva->canva_image, line);
}

void open_file(sys_data *sys)
{
    char *line = NULL;
    size_t len;
    my_putstr("Name of the file to open :");
    getline(&line, &len, stdin);
    line = my_strcat(line, ".jpg");
    sys->canva->canva_image = sfImage_createFromFile(line);
    if (sys->canva->canva_image == NULL)
        sys->canva->canva_image = sfImage_createFromColor(1880, 800, sfWhite);
    sfRenderWindow_display(sys->window);
}

void new_file(sys_data *sys)
{
    sys->canva->canva_image = sfImage_createFromColor(1880, 800, sfWhite);
}
