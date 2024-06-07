/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** swap two integers
*/
void my_swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
