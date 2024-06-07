/*
** EPITECH PROJECT, 2023
** src/array_utils
** File description:
** minishell2
*/
#include "../include/lem_in.h"

void print_2d_array(char **arr)
{
    while (*arr != NULL) {
        my_putstr(*arr++);
    }
    if (*arr != NULL)
        my_putchar('\n');
}

void my_put_2d_arr(char **arr)
{
    int i = 0;
    while (arr[i]) {
        my_putstr(arr[i]);
        my_putchar('\n');
        i++;
    }
}

void free_2d_array(char **array)
{
    int i;

    for (i = 0; array[i]; i++) {
        free(array[i]);
    }
    free (array);
}

void my_research(char *str)
{
    write(1, "|", 1);
    write(1, str, my_strlen(str));
    write(1, "|", 1);
}

void print_hashtable(hashtable *ht)
{
    size_t i;
    dic_t *current;
    my_putstr("This is the hashtable :\n");
    for (i = 0; i < ht->size; i++) {
        current = ht->buckets[i];
        while (current != NULL) {
            my_putstr("Name =\t"), my_putstr(current->name);
            my_putstr("\t|\tValue = "), my_putnbr(current->value);
            my_putchar('\n');
            current = current->next;
        }
    }
}
