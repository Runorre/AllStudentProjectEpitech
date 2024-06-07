/*
** EPITECH PROJECT, 2023
** encoder
** File description:
** more_str_related
*/

#include "../include/asm.h"

char *my_strncpy(char *dest, char *source, int num)
{
    int i;
    for (i = 0; i < num && source[i]; i++)
        dest[i] = source[i];
    dest[i] = '\0';
    return dest;
}

char *hexa_to_str(char *hex_string)
{
    int hexa_len = my_strlen(hex_string), first_half, sec_half, i, j;
    char *text = malloc(((hexa_len / 2) + 1) * sizeof(char));
    for (i = 0, j = 0; i < hexa_len; i += 2, j++) {
        char hexa_char[3];
        my_strncpy(hexa_char, hex_string + i, 2);
        if (hexa_char[0] <= '9')
            first_half = hexa_char[0] - '0';
        else
            first_half = hexa_char[0] - 'a' + 10;

        if (hexa_char[1] <= '9')
            sec_half = hexa_char[1] - '0';
        else
            sec_half = hexa_char[1] - 'a' + 10;
        text[j] = (first_half << 4) + sec_half;
    }
    text[j] = '\0';
    return text;
}

int my_pow(int nb, int power)
{
    int ans = 1;
    for (int i = 0; i < power; i++)
        ans *= nb;
    return ans;
}

char i_love_c_one(int remainder, char *hex, int i)
{
    if (remainder < 10)
        hex[i] = remainder + '0';
    else
        hex[i] = remainder - 10 + 'a';
}

char *int_to_hex(int number)
{
    char *hex = malloc(3 * sizeof(char));
    int i = 0;
    if (number == 0) {
        hex[i++] = '0';
    } else {
        for (; number != 0; number /= 16)
            i_love_c_one(number % 16, hex, i++);
    }
    hex[i] = '\0';
    reverse_str(hex);
    return hex;
}
