/*
** EPITECH PROJECT, 2022
** find_player.c
** File description:
** find position x and y of the P
*/
#include "project.h"

void if_found_player(char player, int i, int j, pos_s *position)
{
    if (player == 'P') {
        position->row = j;
        position->col = i;
        position->old_row = j;
        position->old_col = i;
        position->origin_row = j;
        position->origin_col = i;
        position->check_safe = 0;
    }
}

void find_player(map_s map, pos_s *position)
{
    for (int i = 0; map.map[i] != NULL; i++) {
        for (int j = 0; map.map[i][j] != '\0'; j++) {
            if_found_player(map.map[i][j], i, j, position);
        }
    }
}
