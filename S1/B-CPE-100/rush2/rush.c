/*
** EPITECH PROJECT, 2022
** Rush 2
** File description:
** Rush 2 Epitech
*/

int float_int(int count, int counta)
{
    float ratio = ((float) count / (float) counta) * 10000;
    int ratiot = ratio, floa1 = 0, floa2 = 0;
    for (int i = 0; i != 2; i++) {
        if (i == 0) {
            floa2 = ratiot % 10;
            ratiot /= 10;
        } else {
            floa1 = ratiot % 10;
            ratiot /= 10;
        }
    }
    my_put_nbr(ratiot);
    my_putchar('.');
    my_put_nbr(floa1);
    my_put_nbr(floa2);
}

int count_letter(int ar, char **av, int i)
{
    int count = 0, countletter = 0;
    char letter = av[i][0];
    my_strupcase(av[1]);
    my_strupcase(av[i]);
    for (int e = 0; av[1][e] != '\0'; e++) {
        if (av[1][e] == av[i][0])
            count++;
        if (av[1][e] >= 'A' && av[1][e] <= 'Z')
            countletter++;
    }
    my_putchar(letter);
    my_putchar(':');
    my_put_nbr(count);
    my_putstr(" (");
    float_int(count, countletter);
    my_putstr("%)");
    my_putchar('\n');
}

int main(int ar, char **av)
{
    if (ar <= 2)
        return (84);
    for (int i = 2; i != ar; i++) {
        count_letter(ar, av, i);
    }
    return (0);
}
