/*
** EPITECH PROJECT, 2022
** my_h
** File description:
** lem_in
*/
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "lib.h"

    /*containe all ant*/
    typedef struct list_ant {
        int pos;
        int move;
        int id;
        int prev_move;
        struct list_ant *next;
    }ant_t;

    /* graph */
    typedef struct vertex {
        int dest;
        int cost;
        struct vertex* next;
    } vertex_t;

    typedef struct graph {
        ant_t *ant;
        struct vertex* vertex;
        int n_vertex;
    } graph_t;

    //parsing
    typedef struct arcs {
        int src;
        int dest;
        struct arcs* next;
    } arcs_t;

    /* waiting list */
    typedef struct waiting {
        struct waiting *prev;
        int value;
        int cost;
        struct waiting *next;
    } waiting_t;

    typedef struct parsing_s {
        int nb_ants;
        char *beginning;
        char *end;
        int pos_begin, pos_end;
        int nb_vertex;
        int e, s;
    } pars_t;

    typedef struct node {
        char *data;
        struct node *next;
        struct node *prev;
    } list_t;

    typedef struct dict_s {
        char *name;
        int value;
        struct dict_s *next;
    } dic_t;

    typedef struct hashtable {
        dic_t **buckets;
        size_t size;
        size_t count;
    } hashtable;

#ifndef _LEM_IN_
    #define _LEM_IN_
    #define _GNU_SOURCE

    #define ABS(value) (value < 0 ? -value : value)
    #define TRUE 1
    #define FALSE 0
    #define GROWTH_FACTOR 2
    #define LOAD_FACTOR 0.75

    /* sprintf.c */
    int string_copy(char *dest, const char *src);
    int int_to_string(char *str, int num);
    int format_string(char *buffer, const char *format, va_list args);
    void my_research(char *str);

    /* error_handling.c */
    int check_errors(char **arr);
    int check_commands(char *str);
    bool is_alphanum(char c);
    int check_line(char *str);

    /* lem_in.c */
    char *my_strcpy(char *dest, const char *src);
    void print_2d_array(char **arr);
    void free_2d_array(char **array);
    char **str_to_word_array(char *str);
    void print_rooms(struct node *temp);
    void print_infos(arcs_t *arc, hashtable *ht, int iter_hash);

    /* graph.c */
    graph_t* init_graph(arcs_t* arcs, int n_vertex);
    vertex_t* add_vertex(vertex_t* head, int dest);
    arcs_t* add_arcs(arcs_t* head, int src, int dest, int oriented);
    void print_arcs(arcs_t* head);
    void print_graph(graph_t* graph);

    /* sprintf.c */
    int my_sprintf(char *str, const char *format, ...);
    int format_string(char *buffer, const char *format, va_list args);
    int int_to_string(char *str, int num);
    int string_copy(char *dest, const char *src);

    /* my_realloc */
    void *my_realloc(void *ptr, size_t size);
    void *my_memcpy(void *dest, const void *src, size_t n);

    /* my_strtok.c */
    int contains(const char *str, char c);
    char *my_strtok(char *str, const char *delim);

    /* copy functions (use strcpy2 if needed) */
    char *my_strdup(char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strcpy(char *dest, char const *src);
    char *my_strcpy2(char *dest, const char *src);

    /* linked.c */
    void append(struct node **head, char *data);
    void delete_node(struct node **head, struct node *del);
    void print_list(struct node *temp);
    void delete_list(struct node *head);

    /* my_strchr.c */
    char *my_strchr(const char *str, int c);
    void remove_char(char *str, char c);

    /* hashtable */
    hashtable *create_hash_table(size_t size);
    dic_t *create_node(char *name, int value);
    void free_node(dic_t *node);
    void free_hash_table(hashtable *ht);
    int insert(hashtable *ht, char *name, int value);
    void print_hashtable(hashtable *ht);
    int count_names(hashtable *ht);
    int find_value(hashtable *ht, char *name);
    char *find_name(hashtable *ht, int value);
    size_t hash(char *name, size_t size);
    hashtable *create_hash_table(size_t size);
    void insert_node_into_new_buckets(dic_t *node,
    dic_t **new_buckets, size_t new_size);
    void resize_hashtable(hashtable *ht);
    void insert_node(hashtable *ht, char *name, int value);
    void insert_node_into_bucket(hashtable *ht, size_t index, dic_t *node);
    void insert_node_into_new_buckets(dic_t *node,
    dic_t **new_buckets, size_t new_size);

    /* my_calloc.c */
    void *my_memset(void *s, int c, size_t n);
    void *my_calloc(size_t count, size_t size);

    /* free_graph.c */
    void free_vertex(vertex_t* head);
    void free_arcs(arcs_t* head);
    void free_graph(graph_t* graph);

    /* algo.c */
    int is_in_list(vertex_t* list, int value);
    vertex_t* stock_to_do(vertex_t* adjacents, vertex_t* path);
    void print_vertex(vertex_t* list);
    int path_len(vertex_t* list);
    vertex_t* algo(graph_t* graph, int current, int end, vertex_t* path);

    /* find_character.c */
    int find_character(char *text, char char_to_find);

    /* array_utils.c */
    void my_put_2d_arr(char **arr);

    /* error_handling_next.c */
    int check_tunnel_line(char *str);
    int start_not_connected_to_end(graph_t* graph, int start);

    /* error_tmp.c */
    void free_forgor(char* str, char* buf, char** lines, pars_t* parse);
    int bad_file(pars_t* parse);

    /* parse.c */
    void get_first_word(char *line, char **word);
    arcs_t *parse_rooms(char *line, hashtable *ht, arcs_t *arc, int *iter_hash);
    int parse_file(pars_t *parse, char **parsing);
    void parse_positions(pars_t *parse, char **parsing, int i, int iter_hash);

    /* moves functions */
    vertex_t *backtoback(graph_t *graph, vertex_t *tmp, int origine, int cost);
    waiting_t *assigncost(graph_t *graph, vertex_t *vertex, waiting_t *wait);
    waiting_t *addnode(waiting_t *current, int where, int cost);
    int init_dijkstra(graph_t *graph, pars_t *parse, hashtable *ht);
    ant_t *init_ant(int start, int nbr_ant);
    int my_putant(ant_t *ant, int check, hashtable *ht);
    int move_ant(graph_t *grap, int end, ant_t *tmp);
    int init_moves(arcs_t *arc, pars_t *parse, int iter_hash, hashtable *ht);
    void dijkstra_main(graph_t *grap, pars_t *parse, hashtable *ht);

    /* adam_to_word_array.c */
    char** my_str_to_word_array_adam(char* str, char limit);
    int count_until_limit(char* str, char limit, int i);
    int count_occurences(char* str, char c);
    void adapt_tab_for_vincent(char** tab);

    /* printing.c */
    void print_rooms_arr(char **arr);

#endif /* _LEM_IN_ */
