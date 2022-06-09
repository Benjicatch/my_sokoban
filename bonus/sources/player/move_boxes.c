/*
** EPITECH PROJECT, 2022
** move_boxes.c
** File description:
** movement of boxes
*/
#include "project.h"

void new_pos_boxes(map_s map, list_t *pos_X)
{
    switch (map.key) {
        case KEY_UP:
            pos_X->col -= 1;
            break;
        case KEY_DOWN:
            pos_X->col += 1;
            break;
        case KEY_LEFT:
            pos_X->row -= 1;
            break;
        case KEY_RIGHT:
            pos_X->row += 1;
            break;
        default:
            break;
    }
}

int do_check_walls(pos_s *pos, map_s map, list_t *pos_X)
{
    for (; pos_X != NULL; pos_X = pos_X->next) {
        if (pos_X->col == pos->col && pos_X->row == pos->row) {
            map.map[pos->col][pos->row] = 'P';
            map.map[pos->old_col][pos->old_row] = ' ';
            new_pos_boxes(map, pos_X);
        }
    }
    return 0;
}

void move_boxes(pos_s *pos, map_s map, list_t *pos_X)
{
    do_check_walls(pos, map, pos_X);
    switch (map.key) {
        case KEY_UP:
            map.map[pos->old_col - 2][pos->old_row] = 'X';
            pos->col = pos->old_col - 1;
            break;
        case KEY_DOWN:
            map.map[pos->old_col + 2][pos->old_row] = 'X';
            pos->col = pos->old_col + 1;
            break;
        case KEY_LEFT:
            map.map[pos->old_col][pos->old_row - 2] = 'X';
            pos->row = pos->old_row - 1;
            break;
        case KEY_RIGHT:
            map.map[pos->old_col][pos->old_row + 2] = 'X';
            pos->row = pos->old_row + 1;
            break;
    }
}
