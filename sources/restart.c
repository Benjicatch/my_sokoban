/*
** EPITECH PROJECT, 2022
** restart.c
** File description:
** reset the game
*/
#include "project.h"

void free_list(struct linked_list *tri)
{
    list_t *tmp;

    while (tri != NULL) {
        tmp = tri;
        tri = tri->next;
        free(tmp);
    }
}

void free_all(char **str)
{
    for (int i = 0; str[i] != NULL; i++) {
        free(str[i]);
    }
    free(str);
}

void clean_map(map_s map, int i)
{
    for (int j = 0; map.map[i][j] != '\0'; j++) {
        if (map.map[i][j] == 'P' || map.map[i][j] == 'X')
            map.map[i][j] = ' ';
    }
}

void restart(map_s map, pos_s *pos, list_t *pos_X, list_t *pos_O)
{
    for (int i = 0; map.map[i] != NULL; i++) {
        clean_map(map, i);
    }
    map.map[pos->origin_col][pos->origin_row] = 'P';
    pos->col = pos->origin_col;
    pos->row = pos->origin_row;
    for (int i = 0; pos_X != NULL; i++) {
        map.map[pos_X->origin_col][pos_X->origin_row] = 'X';
        map.map[pos_O->origin_col][pos_O->origin_row] = 'O';
        pos_O->col = pos_O->origin_col;
        pos_O->row = pos_O->origin_row;
        pos_X->col = pos_X->origin_col;
        pos_X->row = pos_X->origin_row;
        pos_X = pos_X->next;
        pos_O = pos_O->next;
    }
}
