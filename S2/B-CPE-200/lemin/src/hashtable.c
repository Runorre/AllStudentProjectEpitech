/*
** EPITECH PROJECT, 2023
** src/hash_test
** File description:
** hashtable used for parser
*/
#include "../include/lem_in.h"

size_t hash(char *name, size_t size)
{
    size_t sum = 0;
    int i;

    for (i = 0; i < my_strlen(name); i++) {
        sum += name[i];
    }
    return sum % size;
}

dic_t *create_node(char *name, int value)
{
    dic_t *node = malloc(sizeof(dic_t));
    node->name = malloc(my_strlen(name) + 1);
    my_strcpy(node->name, name);
    node->value = value;
    node->next = NULL;
    return node;
}

void free_node(dic_t *node)
{
    free(node->name);
    free(node);
}

void free_hash_table(hashtable *ht)
{
    size_t i;
    dic_t *current, *next;

    for (i = 0; i < ht->size; i++) {
        current = ht->buckets[i];
        while (current != NULL) {
            next = current->next;
            free_node(current);
            current = next;
        }
    }
    free(ht->buckets), free(ht);
}

void insert_into_hash_linked(hashtable *ht, size_t index, dic_t *node)
{
    if (ht->buckets[index] == NULL) {
        ht->buckets[index] = node;
    } else {
        node->next = ht->buckets[index];
    }
    ht->buckets[index] = node, ht->count++;
}
