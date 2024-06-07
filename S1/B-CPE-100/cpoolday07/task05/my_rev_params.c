/*
** EPITECH PROJECT, 2022
** my_print_params
** File description:
** print a params
*/

int main(int argc, char **argv)
{
    for (int i = argc - 1; i != 0; i--) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    my_putstr(argv[0]);
    my_putchar('\n');
    return 0;
}
