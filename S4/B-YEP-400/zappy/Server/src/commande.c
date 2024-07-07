/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** commande
*/

#include "../include/server.h"

const int waiting_time[12] = {
    7,
    7,
    7,
    7,
    1,
    7,
    7,
    42,
    7,
    7,
    7,
    300
};

const char *com_client_s[13] = {
    "Forward",
    "Right",
    "Left",
    "Look",
    "Inventory",
    "Broadcast",
    "Connect_nbr",
    "Fork",
    "Eject",
    "Take",
    "Set",
    "Incantation",
    NULL
};

void (*com_client_f[12])(main_data_t *, linked_client_t *, char *) = {
    forward_function,
    right_function,
    left_function,
    look_function,
    inventory_function,
    broadcast_function,
    connect_nbr_function,
    fork_function,
    eject_function,
    take_function,
    set_function,
    incantation_function
};

const char *com_graph_s[10] = {
    "msz",
    "bct",
    "mct",
    "tna",
    "ppo",
    "plv",
    "pin",
    "sgt",
    "sst",
    NULL
};

void (*com_graph_f[9])(main_data_t *, linked_client_t *, char *) = {
    msz_function,
    bct_function,
    mct_function,
    tna_function,
    ppo_function,
    plv_function,
    pin_function,
    sgt_function,
    sst_function,
};
