/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** nlist
*/

#include "rpg.h"

char* open_file(char* file)
{
    char* str;
    struct stat st;
    FILE* stream = fopen(file, "r");
    if (stream == NULL)
        return NULL;
    if (stat(file, &st) == -1)
        return NULL;
    str = malloc(sizeof(char) * st.st_size + 1);
    fread(str, st.st_size, st.st_size, stream);
    str[st.st_size] = '\0';
    return str;
}

int count_until_limit(char* str, char lim)
{
    int i = 0;
    while (str[i] != '\0' && str[i] != lim) {
        i ++;
    }
    return i;
}

nlist* add_num(nlist* head, int n)
{
    nlist* node = malloc(sizeof(nlist));
    node->n = n;
    if (head == NULL) {
        node->next = NULL;
        return node;
    }
    node->next = head;
    return node;
}

nlist* reverse_nlist(nlist* list)
{
    if (list == NULL)
        return NULL;
    nlist* prev = NULL, *tmp = list, *next = NULL;
    while (tmp != NULL) {
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    list = prev;
    return list;
}

nlist* init_nlist(char* file)
{
    char* src = open_file(file);
    char* dest;
    int i = 0, j;
    nlist* num = NULL;
    while (src[i] != '\0') {
        dest = malloc(sizeof(char) * count_until_limit(&src[i], ' ') + 1);
        j = 0;
        while (src[i] != ' ' && src[i] != '\n' && src[i] != '\0') {
            dest[j] = src[i];
            i ++, j ++;
        }
        dest[j] = '\0';
        num = add_num(num, str_to_int(dest));
        if (src[i] != '\0')
            i ++;
    }
    return reverse_nlist(num);
}
