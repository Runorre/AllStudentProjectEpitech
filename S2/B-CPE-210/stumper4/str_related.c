/*
** EPITECH PROJECT, 2023
** MixWord
** File description:
** str_related
*/

#include "./include.h"

char *str_from_str(char *str, int index_dep, int index_fin)
{
    int i = 0;
    char *ans = malloc((index_fin - index_dep + 1) * sizeof(char));
    for (; index_dep < index_fin; index_dep++, i++)
        ans[i] = str[index_dep];
    ans[i] = '\0';
    return ans;
}

char **str_to_word_array(char *str, char sep)
{
    int nb_word = 1, j = 0, i_d = 0;
    for (int i = 0, word = 0; str[i]; i++) {
        if (str[i] != sep)
            word = 1;
        if (str[i] == sep && word == 1)
            nb_word++, word = 0;
    }
    char **array = malloc((nb_word + 1) * sizeof(char *));
    for (int i = 0, word = 0, i_f = 0; str[i]; i++) {
        if (str[i] != sep && word == 0)
            i_d = i, word = 1;
        if (str[i] == sep && word == 1) {
            i_f = i, word = 0;
            array[j++] = str_from_str(str, i_d, i_f);
        }
    }
    array[j] = NULL;
    return array;
}

char *file_to_str(char *filepath, data_t *data)
{
    struct stat *stats = malloc(sizeof(struct stat));
    stat(filepath, stats);
    char *str = malloc((stats->st_size + 1) *sizeof(char));
    read(data->fd, str, stats->st_size);
    str[stats->st_size] = '\0';
    free(stats);
    return str;
}

void print_array(char **array, int word, data_t *data)
{
    change_upper_to_lower(array);
    int array_len = my_array_len(data->array);
    printf("%d/%d words inserted in the grid.\n", word, array_len);
    for (int i = 0; i < data->size + 2; i++)
        printf("+");
    printf("\n");
    for (int i = 0; array[i]; i++)
		printf("|%s|\n", array[i]);
    for (int i = 0; i < data->size + 2; i++)
        printf("+");
    printf("\n");
}

char **change_upper_to_lower(char **array)
{
    for (int i = 0, j = 0; array[i]; j++) {
        if (!array[i][j])
            j = 0, i++;
        if (array[i] && array[i][j] >= 'A' && array[i][j] <= 'Z')
            array[i][j] += ' ';
    }
    return array;
}
