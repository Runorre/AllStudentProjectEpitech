/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** commands
*/

#pragma once

#include "server.h"

extern const int waiting_time[12];

extern const char *com_client_s[13];

extern void (*com_client_f[12])(main_data_t *, linked_client_t *, char *);

extern const char *com_graph_s[10];

extern void (*com_graph_f[9])(main_data_t *, linked_client_t *, char *);
