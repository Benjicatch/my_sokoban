/*
** EPITECH PROJECT, 2022
** endgame.c
** File description:
** function if stuck boxes
*/
#include "project.h"

int stuck_boxes(list_t *pos_X, map_s map)
{
    int i = 0;
    int max = 0;

    for (; pos_X != NULL; i++) {
        if ((check_walls(pos_X->col - 1, pos_X->row, map, 1) == 1
        && check_walls(pos_X->col, pos_X->row - 1, map, 1) == 1)
        || (check_walls(pos_X->col - 1, pos_X->row, map, 1) == 1
        && check_walls(pos_X->col, pos_X->row + 1, map, 1) == 1)
        || (check_walls(pos_X->col + 1, pos_X->row, map, 1) == 1
        && check_walls(pos_X->col, pos_X->row + 1, map, 1) == 1)
        || (check_walls(pos_X->col + 1, pos_X->row, map, 1) == 1
        && check_walls(pos_X->col, pos_X->row - 1, map, 1) == 1)) {
            max += 1;
        }
        pos_X = pos_X->next;
    }
    if (max == i) {
        return 1;
    }
    return 0;
}
