/*
** EPITECH PROJECT, 2023
** src/parse
** File description:
** lem_in
*/
#include "../include/lem_in.h"

void parse_positions(pars_t *parse, char **parsing, int i, int iter_hash)
{
    if (my_strcmp(parsing[i], "##start\n") == 0) {
        if (parsing[i + 1] == NULL)
            return;
        parse->beginning = parsing[i + 1];
        parse->pos_begin = iter_hash;
        parse->e++;
    }
    if (my_strcmp(parsing[i], "##end\n") == 0) {
        if (parsing[i + 1] == NULL)
            return;
        parse->end = parsing[i + 1];
        parse->pos_end = iter_hash;
        parse->s++;
    }
}

void get_first_word(char *line, char **word)
{
    char *start = line;
    size_t length;
    while (*start == ' ') {
        start++;
    }
    char *end = start;
    while (*end != '\0' && *end != ' ') {
        end++;
    }
    length = end - start;
    *word = (char *)my_realloc(*word, length + 1);
    my_strncpy(*word, start, length);
    (*word)[length] = '\0';
}

arcs_t *parse_arc(char *word, hashtable *ht, arcs_t *arc)
{
    char *name = NULL, *tun = NULL, *nel = NULL;
    int exist = 0;

    remove_char(word, '\n'), name = word;
    tun = my_strtok(name, "-"), nel = my_strtok(NULL, "-");
    exist += find_value(ht, tun), exist += find_value(ht, nel);
    arc = add_arcs(arc, find_value(ht, tun), find_value(ht, nel), 0);

    if (exist < 0) {
        arc = NULL;
    }
    return arc;
}

arcs_t *parse_rooms(char *line, hashtable *ht, arcs_t *arc, int *iter_hash)
{
    char *token = my_strtok(line, " \t\n"), *word = NULL;
    int count = 0, exist = 0, inserted = 0;
    if (token != NULL && token[0] == '#') return 0;
    while (token != NULL && count < 1) {
        get_first_word(token, &word);
        if (my_strlen(word) > 0 && !find_character(word, '-')) {
            count++, inserted = insert(ht, word, *iter_hash);
            *iter_hash = inserted == 0 ? -2 : *iter_hash;
            *iter_hash += inserted;
        } if (*iter_hash == -2) return (NULL);
        if (my_strlen(word) > 0 && find_character(word, '-')) {
            arc = parse_arc(word, ht, arc), exist = 1;
        } if (exist == 1 && arc == NULL) {
            *iter_hash = -2;
            return (NULL);
        } exist = 0, inserted = 0, token = my_strtok(NULL, " \t\n");
    } free(word);
    if (count == 2 && token != NULL && token[0] == '#') *token = '\0';
    return (arc);
}

int parse_file(pars_t *parse, char **parsing)
{
    int i = 0, iter_hash = 0, error = 0;
    arcs_t *arc = NULL;
    hashtable *ht = create_hash_table(100);
    parse->e = 0, parse->s = 0;
    parse->nb_ants = my_getnbr(parsing[0]);
    for (i = 1; parsing[i]; i++) {
        parse_positions(parse, parsing, i, iter_hash);
        arc = parse_rooms(parsing[i], ht, arc, &iter_hash);
        if (iter_hash == -2) return (84);
    }
    error = init_moves(arc, parse, iter_hash, ht);
    free_arcs(arc), free_hash_table(ht);
    if (!error && !bad_file(parse)) return 0;
    return 84;
}
