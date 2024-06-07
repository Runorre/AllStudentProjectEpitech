/*
** EPITECH PROJECT, 2023
** CoreWar
** File description:
** parsing
*/

#include "../include/asm.h"

int is_one_in_two(char *str_one, char *str_two)
{
    int ac_letter = 0, len = my_strlen(str_two), l_index = 0;
    for (int i = 0; str_one[i]; i++) {
        if (str_one[i] != str_two[ac_letter] && ac_letter != len - 1)
            ac_letter = 0;
        if (str_one[i] == str_two[ac_letter] && ac_letter != len)
            ac_letter++, l_index = i;
        if (ac_letter == my_strlen(str_two))
            return l_index + 1;
    }
    return 0;
}

char *clear_str(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == '"')
            chars_test(str, i);
    return str;
}

char *find_name(char **champ_env)
{
    int temp_int = 0, temp_ind = 0, nb_found = 0, int_use = 0;
    for (int i = 0; champ_env[i]; i++) {
        if ((temp_int = is_one_in_two(champ_env[i], ".name \"")) > 0)
            temp_ind = i, nb_found++, int_use = temp_int;
        if (nb_found > 1)
            return NULL;
    }
    if (nb_found == 1)
        return clear_str(&champ_env[temp_ind][int_use]);
    return NULL;
}

char *find_comment(char **champ_env)
{
    int temp_int = 0, temp_ind = 0, nb_found = 0, int_use = 0;
    for (int i = 0; champ_env[i]; i++) {
        if ((temp_int = is_one_in_two(champ_env[i], ".comment \"")) > 0)
            temp_ind = i, nb_found++, int_use = temp_int;
        if (nb_found > 1)
            return NULL;
    }
    if (nb_found == 1)
        return clear_str(&champ_env[temp_ind][int_use]);
    return NULL;
}

champion *create_champion(char **champ_env)
{
    champion *champ = malloc(sizeof(champion));
    for (int i = 0, j = 0; champ_env[i]; j++) {
        if (champ_env[i][j] == '#')
            champ_env[i][j] = '\0';
        if (!champ_env[i][j])
            i++, j = -1;
    }
    champ->name = find_name(champ_env);
    champ->comment = find_comment(champ_env);
    return champ;
}
