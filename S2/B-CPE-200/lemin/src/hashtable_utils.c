/*
** EPITECH PROJECT, 2023
** src/hashtable_utils
** File description:
** Hashtable
*/
#include "../include/lem_in.h"

hashtable *create_hash_table(size_t size)
{
    hashtable *ht = malloc(sizeof(hashtable));
    ht->buckets = my_calloc(size, sizeof(dic_t *));
    ht->size = size;
    ht->count = 0;
    return ht;
}

int find_value(hashtable *ht, char *name)
{
    size_t index = hash(name, ht->size);
    dic_t *current = ht->buckets[index];

    while (current != NULL) {
        if (my_strcmp(current->name, name) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

char *do_find_name(dic_t *current, int value)
{
    while (current != NULL) {
        if (current->value == value) {
            return current->name;
        }
        current = current->next;
    }
    return NULL;
}

char *find_name(hashtable *ht, int value)
{
    dic_t *current;
    char *name = NULL;

    for (size_t i = 0; i < ht->size; i++) {
        current = ht->buckets[i];
        name = do_find_name(current, value);
        if (name != NULL) return name;
    }
    return NULL;
}

int count_names(hashtable *ht)
{
    int count = 0;
    size_t i;
    dic_t *node;
    for (i = 0; i < ht->size; i++) {
        node = ht->buckets[i];
        while (node != NULL) {
            count++;
            node = node->next;
        }
    }
    return count;
}
