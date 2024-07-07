/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** main
*/

#include "../include/server.h"

static void print_help(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height"
        "-n name1 name2 ... -c clientsNb -f freq"
        " the server socket listens.\n"
        "\tport\tis the port number\n"
        "\twidth\tis the width of the world\n"
        "\theight\tis the height of the world\n"
        "\tnameX\tis the name of the team X\n"
        "\tclientsNb   is the number of authorized clients per team\n"
        "\tfreq\tis the reciprocal of time unit for execution of actions\n");
    exit(0);
}

void signal_handler(int sig)
{
    if (sig == SIGINT) {
        printf("\nServer is closing by signal...\n");
        exit(0);
    }
}

void init_network(main_data_t *ms)
{
    ms->net->port = ms->arg->port;
    ms->net->id = -1;
    ms->net->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    ms->net->addr_serv.sin_family = AF_INET;
    ms->net->addr_serv.sin_port = htons((uint16_t)ms->net->port);
    ms->net->addr_serv.sin_addr.s_addr = INADDR_ANY;
    ms->net->sock_size = sizeof(ms->net->addr_serv);
    ms->net->server_client = NULL;
    ms->net->server_client = NULL;
}

void check_args(int argc, char **argv)
{
    if ((argc < 7) || (strcmp(argv[1], "-help") == 0)) {
        print_help();
    }
}

int main_server(int argc, char **argv)
{
    main_data_t *md = malloc(sizeof(main_data_t));
    time_t t = 0;

    md->net = malloc(sizeof(network_t));
    md->arg = malloc(sizeof(args_t));
    md->arg->teams = NULL;
    md->list_t = NULL;
    md->list_g = NULL;
    md->reset_res = 20;
    md->egg_id = -1;
    srand((unsigned)time(&t));
    check_args(argc, argv);
    signal(SIGINT, signal_handler);
    parse_args(argc, argv, md->arg);
    create_team(md);
    init_network(md);
    printf("Server is starting...\n");
    initialize_map(md);
    server_init(md);
    return 0;
}

int main(int argc, char **argv)
{
    return main_server(argc, argv);
}
