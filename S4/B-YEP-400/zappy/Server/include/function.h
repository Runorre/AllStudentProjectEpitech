/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** function
*/

#pragma once

#include "server.h"

typedef void (*action_function_t)(main_data_t *, linked_client_t *, char *);
void parse_args(int argc, char **argv, args_t *args);
void init_network(main_data_t *md);
void signal_handler(int sig);
int main_server(int argc, char **argv);
void parse_teams(int argc, char **argv, args_t *args, int i);
int select_for_first(network_t *network, int ac_max_sd);
void client_action(main_data_t *md, linked_team_t *tmp);
void new_connection(main_data_t *md);
void action_user_time(main_data_t *md, linked_client_t **user);
void action_clients(main_data_t *md);
void delete_client_a_list(main_data_t *md, client_t *client);
void action_client(main_data_t *md, linked_client_t *tmp);
int delete_list_socket(linked_client_t **list, linked_client_t *ptr, int f);
int add_in_list_socket(
    linked_client_t **list, linked_client_t *new, main_data_t **md
);
void delete_in_list_client(linked_client_t **list, client_t *ptr);
linked_client_t *add_node_client(int socket_client, main_data_t *md);
void loop_select(main_data_t *md) __attribute__((noreturn));
void server_init(main_data_t *md);
void free_one_socket(linked_client_t *ptr);
void checking_type_client(main_data_t *md, linked_client_t *tmp, char *com);
void command_graph(main_data_t *md, linked_client_t *tmp, char *com);
void command_client(main_data_t *md, linked_client_t *tmp, char *com);
void add_in_list_team(linked_team_t **list, char *name, main_data_t *md);
void create_team(main_data_t *md);
void ateam(main_data_t *md, linked_client_t **tmp, linked_team_t **team);
void commande_default(main_data_t *md, linked_client_t *tmp, const char *com);
void forward_function(main_data_t *md, linked_client_t *client, char *args);
void right_function(main_data_t *md, linked_client_t *client, char *args);
void left_function(main_data_t *md, linked_client_t *client, char *args);
int add_in_user_in_list(linked_client_t **list, client_t **client);
void inventory_function(main_data_t *md, linked_client_t *client, char *args);
void look_function(main_data_t *md, linked_client_t *client, char *args);
void upper(main_data_t *md, linked_client_t *client, Co_t *co, Off_t *offset);
void right(main_data_t *md, linked_client_t *client, Co_t *co, Off_t *offset);
void down(main_data_t *md, linked_client_t *client, Co_t *co, Off_t *offset);
void left(main_data_t *md, linked_client_t *client, Co_t *co, Off_t *offset);
void gteam(main_data_t *md, linked_client_t **tmp);
player_t *allocate_player(egg_node_t *egg_node);
int counter_team(int argc, char **argv, int i);
void parse_arg(const char *arg, const char *next_arg, args_t *args);
void initialize_map(main_data_t *md);
void position(main_data_t *md, linked_client_t *client, Co_t *co, Off_t *off);
const char *material_to_string(material_t material);
void print_forward(linked_client_t *client, int x, int y);
void check_arg_range(args_t *args);
linked_queue_t *add_node_queue(char *a, int t, action_function_t f);
int add_in_list_queue(linked_queue_t **list, linked_queue_t *new);
int remove_first_node(linked_queue_t **list);
void action_time(main_data_t *md);
void queue_user(main_data_t *md, linked_client_t **user);
void msz_function(main_data_t *md, linked_client_t *client, char *com);
void connect_nbr_function(main_data_t *md, linked_client_t *client, char *a);
void eject_function(main_data_t *md, linked_client_t *client, char *args);
void take_function(main_data_t *main_data, linked_client_t *client, char *arg);
void set_function(main_data_t *md, linked_client_t *client, char *arg);
void update_player_pos(player_t *player, int x, int y);
void move_player(main_data_t *md, linked_client_t *client);
void limiteur_check(main_data_t *md, linked_client_t *tmp, char *com, int j);
void fork_function(main_data_t *md, linked_client_t *client, char *args);
void incantation_function(main_data_t *md, linked_client_t *client, char *arg);
size_t count_same_level(
    main_data_t *m, size_t r, linked_client_t *c, client_t **l
);
void pro_visio(
    main_data_t *md, linked_client_t *client, string_t *result, int i
);
bool egg_at_position(main_data_t *md, int x, int y);
int player_at_position(main_data_t *md, int x, int y);
void allocate_map(main_data_t *md, int i);
void fill_map(main_data_t *md, int k, float resources[7]);
void distribute_resources(main_data_t *md, float resources[7]);
material_t set_to_material(char *arg);
void decrement_material(player_t *player, char *arg);
int get_material_count(inventory_t *stones, material_t material);
void increment_material(player_t *player, char *arg);
material_t string_to_material(char *arg);
void print_result(int fd, bool player_moved);
void destroy_egg_if_exists(team_t *team, linked_client_t *c, main_data_t *md);
bool verif_incan(main_data_t *md, linked_client_t *client, char *arg);
void init_eggs(egg_node_t **egg, int nbr_max, main_data_t *md, egg_node_t **l);
bool egg_in_team(team_t *team, int x, int y);
size_t get_required_players(int level);
material_t *get_materials(int level);
bool has_required_materials(main_data_t *main_data, linked_client_t *client);
void make_incantation(main_data_t *md, linked_client_t *c);
int direction(pos_t *a, pos_t *b, args_t *size, direction_t orientation);
int direction_cs(int dx, int dy);
int convert_orientation(direction_t orientation, int output);
void send_message_everyone(main_data_t *md, linked_client_t *c, char *m);
void broadcast_function(main_data_t *md, linked_client_t *c, char *a);
int direction_cs_next(int dx, int dy);
void remove_head_egg(egg_node_t **eggs);
void add_egg_to_end(egg_node_t *new, egg_node_t **last);
void error_handeling_parse(const char *arg);
void distribute_new(main_data_t *md, float initial[7], float current[7]);
void calculate_current_resources(main_data_t *md, float current_resources[7]);
void calculate_initial_resources(main_data_t *md, float initial_resources[7]);
void bct_function(main_data_t *md, linked_client_t *client, char *args);
void bct(main_data_t *md, linked_client_t *client, char *args);
void mct_function(main_data_t *md, linked_client_t *client, char *args);
void tna_function(main_data_t *md, linked_client_t *client, char *args);
void ppo_function(main_data_t *md, linked_client_t *client, char *args);
void plv_function(main_data_t *md, linked_client_t *client_list, char *args);
void pin_function(main_data_t *md, linked_client_t *client_list, char *args);
void sgt_function(main_data_t *md, linked_client_t *client, char *args);
void sst_function(main_data_t *md, linked_client_t *client, char *args);
void bct_only(int fd, map_t **map, int widght, int height);
void connection_g(main_data_t *md, linked_client_t *p, egg_node_t *e);
void init_team_graphic(const main_data_t *md, linked_client_t **c);
void add_egg_in_list(
    egg_node_t **eggs, egg_t *egg, main_data_t *md, egg_node_t **last
);
void distribute_mat(
    main_data_t *md, float initial[7], float current[7], int k
);
void update_current_resources(main_data_t *md, float current[7], int i, int j);
void reset_resources(main_data_t *md);
linked_client_t *find_client_by_id(linked_client_t *client_list, long c);
int show_orientation(direction_t orientation);
void cs_ai(main_data_t *md, linked_client_t *client, int x, int y);
void dead_event_graphic(main_data_t *md, linked_client_t **user);
void player_pos_graph(main_data_t *md, linked_client_t *user);
void eject_notif(main_data_t *md, linked_client_t *client, int x, int y);
void egg_graph(main_data_t *md, egg_node_t *e);
void cs_chec(char **str, linked_client_t *c, client_t *tmp);
void write_all_inc_g(
    char **str, main_data_t *md, linked_client_t *c, client_t **l
);
void graph_end_inc(main_data_t *md, linked_client_t *c, int r);
void pre_forh_g(main_data_t *md, linked_client_t *c);
void take_graph(main_data_t *md, linked_client_t *c, material_t mat);
void set_graph(main_data_t *md, linked_client_t *c, material_t mat);
void enw_graph(main_data_t *md, linked_client_t *c, egg_node_t *egg);
void start_inc_graph(main_data_t *md, linked_client_t *c, client_t **l);
void free_incantation(client_t **list);
void pin_event(int fd, linked_client_t *p);
void all_player_pos(main_data_t *md);
void ics(main_data_t *m, linked_client_t *c, linked_client_t *t, client_t **l);
void pl_inc_pre(linked_client_t *c, client_t **l);
void pl_inc_post(main_data_t *m, linked_client_t *c);
void plv_action(main_data_t *m, client_t *c);
size_t count_same_leve2(main_data_t *m, size_t r, linked_client_t *c);
void string_init(string_t *str);
void string_append(string_t *str, const char *append);
void string_free(string_t *str);
void stop_incantation(main_data_t *md, linked_client_t *c);
void forking(main_data_t *md, linked_client_t *client, char *args);
void print_incantation_list(linked_client_t *c);
void pin(int fd, const linked_client_t *p);
void check_args(int argc, char **argv);
int player_at_position2(int x, int y, int *count, linked_client_t *tmp);
void handle_select_result(main_data_t *md, int select_result);
void pins_event(main_data_t *md, linked_client_t **user);
void check_stop_incantation(main_data_t *md, linked_client_t **user);
void append_materials(main_data_t *md, string_t *result, int x, int y);
