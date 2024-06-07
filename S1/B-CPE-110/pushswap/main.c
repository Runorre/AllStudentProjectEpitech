/*
** EPITECH PROJECT, 2022
** Bootstrap
** File description:
** main
*/

#include "my.h"

char *rotate(struct node **list_a, struct node **list_b, int j, int m)
{
    if (j < m)
        return rotate_left(list_a, 1);
    else
        return rotate_right(list_a, 1);
}

int findmiddle(struct node *list)
{
    struct node *tmp;
    if (list == NULL)
        return 0;
    if (list->next == NULL)
        return 1;
    tmp = list->next;
    int i = 1;
    while (tmp != NULL) {
        i++;
        tmp = tmp->next;
    }
    i /= 2;
    return i;
}

int findminus(struct node *list_a)
{
    struct node *tmp;
    if (list_a == NULL)
        return 0;
    if (list_a->next != NULL)
        tmp = list_a->next;
    else
        return list_a->value;
    int i = 0, j = 0, minus = list_a->value;
    while (tmp->next != NULL) {
        if (tmp->value < minus) {
            minus = tmp->value;
        }
        tmp = tmp->next;
    }
    if (tmp->value < minus) {
        minus = tmp->value;
    }
    return minus;
}

void insertion_sort(struct node *list_a, struct node *list_b, int size)
{
    int minus = findminus(list_a), middle = findmiddle(list_a);
    int j = indicemin(list_a, minus);
    struct buffer buf = createbuffer();
    while (list_a != NULL){
        if (minus == list_a->value) {
            addtobuf(&buf, swap_list(&list_a, &list_b, 0));
            minus = findminus(list_a);
            j = indicemin(list_a, minus);
            middle = findmiddle(list_a);
        } else {
            addtobuf(&buf ,rotate(&list_a, &list_b, j, middle));
        }
        addtobuf(&buf, " ");
    }
    while (list_b != NULL) {
        addtobuf(&buf, swap_list(&list_b, &list_a, 1));
        if (list_b != NULL)
            addtobuf(&buf, " ");
    }
    showfinal(&buf);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        write(1, "\n", 1);
        return 0;
    }
    if (checkargu(av, ac) == 84)
        return 84;
    struct node *list_a;
    struct node *list_b;
    list_b = NULL;
    list_a = create(av, ac);
    if (ac > 2 && checkcomplete(list_a) == 0)
        insertion_sort(list_a, list_b, ac);
    write(1, "\n", 1);
    free(list_a);
    free(list_b);
    return 0;
}
