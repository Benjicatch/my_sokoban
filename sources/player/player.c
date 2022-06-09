/*
** EPITECH PROJECT, 2022
** player.c
** File description:
** functions for player
*/
#include "project.h"

int check_walls(int col, int row, map_s map, int boul)
{
    if (col < 0 || row < 0) {
        return 1;
    }
    if (boul == 0) {
        if (map.map[col] == NULL || map.map[col][row] == '#'
        || map.map[col][row] == '\0') {
            return 1;
        }
    } else {
        if (map.map[col] == NULL || map.map[col][row] == '#'
        || map.map[col][row] == '\0' || map.map[col][row] == 'X') {
            return 1;
        }
    }
    return 0;
}

int special_case(pos_s *position, map_s map)
{
    if (check_walls(position->col, position->row, map, 0) == 1) {
        position->col = position->old_col;
        position->row = position->old_row;
        return 1;
    }
    return 0;
}

void move_player(pos_s *position, map_s map, list_t *pos_object, list_t *pos_X)
{
    int nb = 0;

    nb = special_case(position, map);
    if (nb == 1)
        return;
    check_boxes(position, map, pos_X);
    if (position->check_safe == 1) {
        position->check_safe = 0;
    } else {
        map.map[position->col][position->row] = 'P';
        map.map[position->old_col][position->old_row] = ' ';
    }
    check_placement(map.map, pos_object);
}

void horizontal_move(pos_s *position, map_s map, list_t *pos_O, list_t *pos_X)
{
    switch (map.key) {
        case KEY_LEFT:
            position->old_row = position->row;
            position->row--;
            move_player(position, map, pos_O, pos_X);
            break;
        case KEY_RIGHT:
            position->old_row = position->row;
            position->row++;
            move_player(position, map, pos_O, pos_X);
            break;
        default:
            break;
    }
}

void choose_move(pos_s *position, map_s map, list_t *pos_object, list_t *pos_X)
{
    position->old_row = position->row;
    position->old_col = position->col;
    switch (map.key) {
        case KEY_UP:
            position->old_col = position->col;
            position->col--;
            move_player(position, map, pos_object, pos_X);
            break;
        case KEY_DOWN:
            position->old_col = position->col;
            position->col++;
            move_player(position, map, pos_object, pos_X);
            break;
        default:
            horizontal_move(position, map, pos_object, pos_X);
            break;
    }
}
