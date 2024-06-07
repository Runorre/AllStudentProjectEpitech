/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** lem_in
*/
#include "../include/lem_in.h"
#include <string.h>

void print_infos(arcs_t *arc, hashtable *ht, int iter_hash)
{
    graph_t *graph = init_graph(arc, iter_hash);
    print_arcs(arc), my_putnbr(iter_hash);
    my_putchar('\n'), print_hashtable(ht);
    free_graph(graph);
}

int destroy_comment(char *src, char ch, char *dest)
{
    int a = 0, i;

    for (i = 0; src[i] != '\0'; i++) {
        src[i] = src[i + a];
        dest[i] = src[i];
        if (dest[i] == ch) {
            dest[i] = '\0';
            a++;
        }
    }
    return a;
}

struct node *is_start_or_end(char *strt_line,
char *data, char *comment_pos, struct node *head)
{
    int is_strend = 0;
    if (my_strcmp(strt_line, "##start") == 0
    || my_strcmp(strt_line, "##end") == 0) {
        data = malloc(sizeof(char) * (my_strlen(strt_line) + 2));
        my_strcpy(data, strt_line), my_strcat(data, "\n");
        append(&head, data);
        is_strend = 1;
    } else {
        is_strend = 0;
        comment_pos = my_strchr(strt_line, '#');
        if (comment_pos != NULL) {
            *comment_pos = '\0';
        }
        if (*strt_line != '\0' && !is_strend) {
            data = malloc(sizeof(char) * (my_strlen(strt_line) + 2));
            my_strcpy(data, strt_line), my_strcat(data, "\n");
            append(&head, data);
        }
    }
    return (head);
}

char **append_to_list(char *str)
{
    struct node *head = NULL, *temp = NULL;
    char **arr = NULL, *data = NULL;
    char *comment_pos = NULL, *strt_line = str, *line_end;
    int i = 0, size = 0;
    for (i = 0; str[i] != '\0'; i++) if (str[i] == '\n') size++;
    while (*str != '\0') {
        if (*str == '\n') {
            line_end = str, *line_end = '\0';
            head = is_start_or_end(strt_line, data, comment_pos, head);
            strt_line = str + 1, size++;
        } str++;
    } if (head == NULL) return (NULL);
    print_rooms(head);
    arr = malloc(sizeof(char *) * (size + 1)), temp = head, i = 0;
    while (temp != NULL) {
        arr[i] = malloc(sizeof(char) * (my_strlen(temp->data) + 1));
        my_strcpy(arr[i], temp->data), temp = temp->next, i++;
    }
    arr[i] = NULL, delete_list(head);
    return arr;
}

int main(int argc, char **argv)
{
    char *buf = NULL, *str = malloc(sizeof(char) * 100), **lines = NULL;
    size_t buf_size, len_str = 0, error;
    pars_t *parse = malloc(sizeof(pars_t));
    if (argc != 1) {
        return (84);
    }
    str[0] = '\0', (void)argv;
    while (getline(&buf, &buf_size, stdin) != EOF) {
        len_str = my_strlen(str);
        str = my_realloc(str, len_str + my_strlen(buf) + 1);
        str = my_strcat(str, buf);
    }
    lines = append_to_list(str);
    if (lines == NULL || !lines[0] || check_errors(lines) == -1) {
        free_forgor(str, buf, lines, parse);
        return (84);
    }
    error = parse_file(parse, lines);
    return (error);
}
