/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** parser
*/

#include "../include/server.h"

int counter_team(int argc, char **argv, int i)
{
    int z = 0;

    for (int j = i + 1; j != argc; j++) {
        if (argv[j][0] == '-')
            return z;
        z++;
    }
    return z;
}

void parse_teams(int argc, char **argv, args_t *args, int i)
{
    int j = 0;
    int len_team = counter_team(argc, argv, i);

    args->teams = calloc((size_t)(len_team) + 1, sizeof(char *));
    for (j = 0; j < len_team; j++)
        args->teams[j] = NULL;
    j = 0;
    for (int k = i + 1; k < argc; k++) {
        if ((argv[k][0] == '-') || (j >= argc)) {
            break;
        }
        args->teams[j] = strdup(argv[k]);
        j++;
    }
    args->teams[j] = NULL;
    args->nb_teams = j;
}

void parse_arg(const char *arg, const char *next_arg, args_t *args)
{
    char *endptr = NULL;
    long val = 0;

    if (next_arg == NULL)
        exit(84);
    val = strtol(next_arg, &endptr, 10);
    if (endptr == next_arg)
        exit(84);
    if (strcmp(arg, "-p") == 0)
        args->port = (int)val;
    if (strcmp(arg, "-x") == 0)
        args->width = (int)val;
    if (strcmp(arg, "-y") == 0)
        args->height = (int)val;
    if (strcmp(arg, "-c") == 0)
        args->clientsNb = (int)val;
    if (strcmp(arg, "-f") == 0)
        args->freq = (int)val;
    error_handeling_parse(arg);
}

void check_arg_range(args_t *args)
{
    if ((args->port < 1) || (args->port > 99999)) {
        fprintf(stderr, "Error: Port value out of range.\n");
        exit(84);
    }
    if ((args->width < 1) || (args->width > 100)) {
        fprintf(stderr, "Error: Width value out of range.\n");
        exit(84);
    }
    if ((args->height < 1) || (args->height > 100)) {
        fprintf(stderr, "Error: Height value out of range.\n");
        exit(84);
    }
    if (args->clientsNb < 1) {
        fprintf(stderr, "Error: ClientsNb value out of range.\n");
        exit(84);
    }
    if (args->freq < 1) {
        fprintf(stderr, "Error: Frequences value out of range.\n");
        exit(84);
    }
}

void parse_args(int argc, char **argv, args_t *args)
{
    int i = 1;

    args->port = 4242;
    args->width = 10;
    args->height = 10;
    args->clientsNb = 5;
    args->freq = 100;
    while (i < argc) {
        if (strcmp(argv[i], "-n") == 0) {
            parse_teams(argc, argv, args, i);
            i += args->nb_teams + 1;
        } else {
            parse_arg(argv[i], argv[i + 1], args);
            i += 2;
        }
    }
    check_arg_range(args);
}
