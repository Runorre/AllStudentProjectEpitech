/*
** EPITECH PROJECT, 2022
** my_print_params
** File description:
** print a params
*/

int main(int argc, char **argv)
{
    for (int i = 0; i != argc; i++) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
    return 0;
}
