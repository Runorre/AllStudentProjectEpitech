/*
** EPITECH PROJECT, 2024
** B-NWP-400-MAR-4-1-myteams-angelo.anselmet
** File description:
** client
*/

    #include "client.h"

void print_h(void)
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("       ip   is the server ip address on");
    printf("which the server socket listens\n");
    printf("       port is the port number on");
    printf("which the server socket listens\n");
    exit(0);
}

void remove_quotes(char *str)
{
    int i = 0;
    int j = 0;
    char temp[strlen(str) + 1];

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\"') {
            temp[j] = str[i];
            j++;
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

client_t init_client(client_t client, int server_socket, char **av)
{
    client.server_socket = server_socket;
    client.ip = av[1];
    client.port = atoi(av[2]);
    client.uid = NULL;
    client.name = NULL;
    client.status = 0;
    client.use = NO_USE;
    return (client);
}

int check_error(char *str, client_t *client)
{
    if (strcmp(str, "400") == 0 || strcmp(str, "500") == 0 || str == NULL)
        return (1);
    if (strcmp(str, "401") == 0) {
        client_error_unauthorized();
        return (1);
    }
    if (strcmp(str, "404") == 0)
        return (2);
    if (strcmp(str, "409") == 0) {
        client_error_already_exist();
        return (1);
    }
    if (strcmp(str, "600") == 0)
        client->use = TEAM;
    if (strcmp(str, "601") == 0)
        client->use = CHANNEL;
    if (strcmp(str, "602") == 0)
        client->use = THREAD;
    return 0;
}

int main(int ac, char **av)
{
    int server_socket = socket(AF_INET, SOCK_STREAM, 6);
    struct sockaddr_in server_address;
    client_t client;

    if (strcmp(av[1], "-help") == 0)
        print_h();
    if (server_socket == -1)
        exit(84);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(atoi(av[2]));
    server_address.sin_addr.s_addr = inet_addr(av[1]);
    if (connect(server_socket, (struct sockaddr *)&server_address,
    sizeof(server_address)) == -1)
        exit(84);
    client = init_client(client, server_socket, av);
    read_command(&client);
    return (0);
}
