/*
** EPITECH PROJECT, 2021
** lists.c
** File description:
** function for lists
*/
#include "project.h"

void my_show_list(struct linked_list *list)
{
    for (int i = 0; list != NULL; i++) {
        my_printf("col = %i row = %i\n", list->col, list->row);
        list = list->next;
    }
}

void my_put_in_list(struct linked_list **list, int col, int row)
{
    struct linked_list *element = malloc(sizeof(*element));

    element->col = col;
    element->row = row;
    element->origin_col = col;
    element->origin_row = row;
    element->next = *list;
    *list = element;
}

void check_if_place(list_t **pos_object, char **map, int i, char boul)
{
    for (int j = 0; map[i][j] != '\0'; j++) {
        if (map[i][j] == 'O' && boul == 'O') {
            my_put_in_list(pos_object, i, j);
        }
        if (map[i][j] == 'X' && boul == 'X') {
            my_put_in_list(pos_object, i, j);
        }
    }
}

void get_pos_place(char **map, list_t **pos_object, char boul)
{
    for (int i = 0; map[i] != NULL; i++) {
        check_if_place(pos_object, map, i, boul);
    }
}

int check_placement(char **map, list_t *pos_object)
{
    int nb = 0;

    for (int i = 0; pos_object != NULL; i++) {
        if (map[pos_object->col][pos_object->row] == ' ' ||
        map[pos_object->col][pos_object->row] == 'O') {
            nb = 1;
            map[pos_object->col][pos_object->row] = 'O';
        }
        if (map[pos_object->col][pos_object->row] == 'P') {
            nb = 1;
        }
        pos_object = pos_object->next;
    }
    return nb;
}
