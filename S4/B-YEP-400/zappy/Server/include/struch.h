/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** struch
*/

#pragma once

#include "server.h"

typedef enum {
    NOTCONNECT,
    GRAPHIC,
    CLIENT
} type_t;

typedef enum {
    UP,
    RIGHT,
    DOWN,
    LEFT
} direction_t;

typedef struct args_s {
    int port;
    int width;
    int height;
    int nb_teams;
    char **teams;
    int clientsNb;
    int freq;
} args_t;

typedef struct linked_client_s linked_client_t;

typedef struct egg_s {
    int id;
    int x;
    int y;
} egg_t;

typedef struct egg_node {
    egg_t *egg;
    struct egg_node *next;
} egg_node_t;

typedef struct string_s {
    char *data;
    size_t len;
    size_t cap;
} string_t;

typedef struct team_s {
    char *name;
    int nbr_max_member;
    int nbr_member;
    int nbr_live;
    egg_node_t *eggs;
    egg_node_t *last;
    linked_client_t *list;
} team_t;

typedef struct linked_team_s {
    team_t *team_s;
    struct linked_team_s *next;
} linked_team_t;

typedef struct Off {
    int i;
    int j;
} Off_t;

typedef struct Co {
    int x;
    int y;
} Co_t;

typedef struct pos_s {
    int x;
    int y;
} pos_t;

typedef struct inventory_s {
    int LINEMATE;
    int DERAUMERE;
    int SIBUR;
    int MENDIANE;
    int PHIRAS;
    int THYSTAME;
    int FOOD;
} inventory_t;

typedef struct client_s client_t;

typedef struct player_s {
    int id;
    int level;
    int life;
    pos_t *pos;
    inventory_t *stones;
    direction_t direction;
    client_t **incantation_list;
    bool is_in_incantation;
} player_t;

typedef struct main_data_s main_data_t;

typedef struct queue_s {
    int time_left;
    char *agrs;
    void (*action)(main_data_t *, linked_client_t *, char *);
} queue_t;

typedef struct linked_queue_s {
    queue_t *queue;
    struct linked_queue_s *next;
} linked_queue_t;

typedef struct client_s {
    int id;
    int fd;
    struct sockaddr_in addr;
    int disconnect;
    FILE *fdpe;
    type_t type;
    team_t *team_link;
    player_t *player;
    int nbr_queue;
    linked_queue_t *queue;
} client_t;

typedef struct linked_client_s {
    client_t *client;
    struct linked_client_s *next;
} linked_client_t;

typedef struct network_s {
    int port;
    int sockfd;
    fd_set readfds;
    int id;
    struct sockaddr_in addr_serv;
    socklen_t sock_size;
    linked_client_t *last;
    linked_client_t *server_client;
} network_t;

typedef enum {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    NOTHING
} material_t;

typedef struct map_s {
    int materials[7];
} map_t;

typedef struct main_data_s {
    network_t *net;
    args_t *arg;
    linked_team_t *list_t;
    map_t **map;
    linked_client_t *list_g;
    int reset_res;
    int egg_id;
} main_data_t;
