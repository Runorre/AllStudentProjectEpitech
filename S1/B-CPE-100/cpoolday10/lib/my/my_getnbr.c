/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** return int if enter str
*/

int to_negative(int negative, int number)
{
    if (negative == 1) {
        return (number *= -1);
    } else {
        return number;
    }
}

int my_getnbr(char const *str)
{
    int start = 0, negative = 0, result = 0;
    while ((str[start] > 48 || str[start] < 57) || str[start] != '\0') {
        start++;
    }
    if (str[start - 1] == '-') {
        negative++;
    }
    int end = start;
    while ((str[end] >= 48 && str[end] <= 57) || str[end] != '\0') {
        end++;
    }
    for (start; start != end + 1; start++) {
        result *= 10;
        result += (str[start] - 48);
    }
    result = to_negative(negative, result);
    if (result > 2147483647 || result < -2147483647) {
        return 0;
    }
    return result;
}
