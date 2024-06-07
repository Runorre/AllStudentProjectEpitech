/*
** EPITECH PROJECT, 2023
** src/insert_hashtable
** File description:
** lem_in
*/
#include "../include/lem_in.h"

int insert(hashtable *ht, char *name, int value)
{
    if (find_value(ht, name) != -1) {
        return 0;
    }
    if ((double)ht->count / ht->size >= LOAD_FACTOR) {
        resize_hashtable(ht);
    }
    insert_node(ht, name, value);
    if ((double)ht->count / ht->size >= LOAD_FACTOR) {
        resize_hashtable(ht);
    }
    return 1;
}

void resize_hashtable(hashtable *ht)
{
    size_t new_size, i;
    dic_t **new_buckets, *current, *next;
    new_size = ht->size * GROWTH_FACTOR;
    new_buckets = my_calloc(new_size, sizeof(dic_t *));
    for (i = 0; i < ht->size; i++) {
        current = ht->buckets[i];
        while (current != NULL) {
            next = current->next;
            insert_node_into_new_buckets(current, new_buckets, new_size);
            current = next;
        }
    }
    free(ht->buckets);
    ht->buckets = new_buckets;
    ht->size = new_size;
}

void insert_node(hashtable *ht, char *name, int value)
{
    size_t index;
    dic_t *node;
    index = hash(name, ht->size);
    node = create_node(name, value);
    insert_node_into_bucket(ht, index, node);
}

void insert_node_into_bucket(hashtable *ht, size_t index, dic_t *node)
{
    if (ht->buckets[index] == NULL) {
        ht->buckets[index] = node;
    } else {
        node->next = ht->buckets[index];
        ht->buckets[index] = node;
    }
    ht->count++;
}

void insert_node_into_new_buckets(dic_t *node,
dic_t **new_buckets, size_t new_size)
{
    size_t index = hash(node->name, new_size);
    node->next = new_buckets[index];
    new_buckets[index] = node;
}
