/*
** EPITECH PROJECT, 2022
** boxes.c
** File description:
** functions for boxes
*/
#include "project.h"

int reset_pos(pos_s *pos, map_s map)
{
    if (check_walls(pos->col, pos->row, map, 1) == 1) {
        pos->col = pos->old_col;
        pos->row = pos->old_row;
        return 1;
    }
    return 0;
}

void horizonal_boxes(pos_s *pos, map_s map, list_t *pos_X)
{
    switch (map.key) {
        case KEY_LEFT: pos->row--;
            if (reset_pos(pos, map) == 1)
                break;
            pos->row++;
            move_boxes(pos, map, pos_X);
            break;
        case KEY_RIGHT: pos->row++;
            if (reset_pos(pos, map) == 1)
                break;
            pos->row--;
            move_boxes(pos, map, pos_X);
            break;
        default:
            break;
    }
}

void choose_movement_boxes(pos_s *pos, map_s map, list_t *pos_X)
{
    switch (map.key) {
        case KEY_UP: pos->col--;
            if (reset_pos(pos, map) == 1)
                break;
            pos->col++;
            move_boxes(pos, map, pos_X);
            break;
        case KEY_DOWN: pos->col++;
            if (reset_pos(pos, map) == 1)
                break;
            pos->col--;
            move_boxes(pos, map, pos_X);
            break;
        default:
            horizonal_boxes(pos, map, pos_X);
    }
}

void check_boxes(pos_s *pos, map_s map, list_t *pos_X)
{
    if (map.map[pos->col][pos->row] == 'X') {
        pos->check_safe = 1;
        choose_movement_boxes(pos, map, pos_X);
    }
}
