/*                                                                                                                                                            
** EPITECH PROJECT, 2023                                                                                                                                      
** B-CPE-210-MAR-2-1-solostumper01-angelo.anselmet                                                                                                            
** File description:                                                                                                                                          
** Main                                                                                                                                                   
*/

#include <stdlib.h>
void my_putchar(char c);
void my_putdiffstr(char *str, int i);

int my_checkupper(char c1, char c2)
{
    char tmp1 = c1, tmp2 = c2;
    if (c1 >= 'A' && c1 <= 'Z')
        tmp1 += 32;
    if (c2 >= 'A' && c2 <= 'Z')
        tmp2 += 32; 
    if (tmp1 < tmp2)
        return 1;
    return 0;        
}

int sort_word(char *array, int i)
{
    while (array[i] == ' ' && array[i] != '\0')
        i++;
    if (array[i] == '\0')
        return 0;
    printf("debub 2 : %i", i);
    int big = i, word = 0, checker = 0;
    int end = i;
    for (int e = i; array[e] != '\0'; e++) {
        if (array[e] == ' ') {
            word = 0;
            checker = 0;
        }
        if (word == 1)
            end++;
        if (my_checkupper(array[e], array[big]) == 1 && word == 0) {
            big = e - checker;
            word = 1;
            end = big;
        }
        if (array[e] == array[big] && word == 0)
            checker++;
    }
    my_putdiffstr(array, big);
    return sort_word(array, end + 1);
}

int main(int ac, char **ar)
{
    if (ac == 1) {
         my_putchar('\n');
         return 0;
    }
    if (ac == 2) {
         sort_word(ar[1], 0);
         my_putchar('\n');
         return 0;
    }
}