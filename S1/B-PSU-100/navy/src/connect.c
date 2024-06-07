/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** conncet
*/

#include "my.h"

siginfo_t *info_global;

void handler(int sig, siginfo_t *info, void *secret)
{
    info_global = info;
}

void prepare_sigaction(void)
{
    struct sigaction sign;
    sigemptyset(&sign.sa_mask);
    info_global = NULL;
    sign.sa_flags = 0 | SA_SIGINFO;
    sign.sa_sigaction = &handler;
    sigaction(SIGUSR1, &sign, NULL);
    sigaction(SIGUSR2, &sign, NULL);
}

int player1_connect(char *path, map_s *map)
{
    if (read_map(map, path) == 84)
        return 84;
    sys_data *sys = malloc(sizeof(*sys));
    sys->connect = 0;
    sys->player = 1;
    prepare_sigaction();
    my_printf("my_pid: %i\n", getpid());
    my_putstr("waiting for enemy connection...\n");
    pause();
    if (info_global->si_signo == SIGUSR1) {
        sys->pid_ennemie = info_global->si_pid;
        info_global = NULL;
        kill(sys->pid_ennemie, SIGUSR2);
    }
    my_printf("\nenemy connected\n\n");
    return game_p1(sys, map);
}

int player2_connect(int pid, char *path, map_s *map)
{
    if (read_map(map, path) == 84)
        return 84;
    my_printf("my_pid: %i\n", getpid());
    sys_data *sys = malloc(sizeof(*sys));
    sys->connect = 0;
    sys->player = 2;
    prepare_sigaction();
    kill(pid, SIGUSR1);
    usleep(1000);
    if (info_global && info_global->si_signo == SIGUSR2) {
            sys->pid_ennemie = info_global->si_pid;
            info_global = NULL;
            sys->connect = 1;
            my_printf("successfully connected\n\n");
            return game_p2(sys, map);
    } else {
        free(sys);
        free(map);
        return 84;
    }
}

int *get_pos(void)
{
    int end = 1;
    int *pos = malloc(sizeof(int) * 2);
    while (end) {
        pause();
        if (info_global->si_signo == SIGUSR1)
            pos[0]++;
        if (info_global->si_signo == SIGUSR2)
            end = 0;
    }
    info_global = NULL;
    while (end == 0) {
        pause();
        if (info_global->si_signo == SIGUSR1)
            pos[1]++;
        if (info_global->si_signo == SIGUSR2)
            end = 1;
    }
    return pos;
}
