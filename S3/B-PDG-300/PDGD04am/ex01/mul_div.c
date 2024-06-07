/*
** EPITECH PROJECT, 2024
** Day04AM
** File description:
** mul_div
*/

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a * b;
    if (b == 0)
        *div = 42;
    else
        *div = a / b;
}

void mul_div_short(int *a, int *b)
{
    int tmpA = *a;
    int tmpB = *b;

    *a = tmpA * tmpB;
    if (tmpB == 0)
        *b = 42;
    else
        *b = tmpA / tmpB;
}
