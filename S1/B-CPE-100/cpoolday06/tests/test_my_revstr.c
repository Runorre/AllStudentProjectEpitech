/*
** EPITECH PROJECT, 2022
** test_my_strncpy
** File description:
** test
*/

#include <criterion/criterion.h>

char *my_revstr(char *str)
    ;
Test (my_revstr , copy_five_characters_in_empty_array)
{
    char str[] = "Hello";
    my_revstr(str);
    cr_assert_str_eq(str,"olleH");
}
