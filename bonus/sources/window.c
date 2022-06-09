/*
** EPITECH PROJECT, 2022
** window.c
** File description:
** functions for ncurses
*/
#include "project.h"

int infin_loop(map_s map, pos_s *pos, list_t *pos_O, list_t *pos_X)
{
    map.key = getch();
    if (map.key == 27)
        return 1;
    else if (map.key == ' ')
        restart(map, pos, pos_X, pos_O);
    else
        choose_move(pos, map, pos_O, pos_X);
    clear();
    print_map(map.map);
    refresh();
    map.key = check_placement(map.map, pos_O);
    if (map.key == 0) {
        usleep(100000);
        return WIN;
    }
    if (stuck_boxes(pos_X, map) == 1) {
        usleep(100000);
        return LOSE;
    }
    return NOT_FINSH;
}

void init_screen(char **str, list_t **pos_object, list_t **pos_X, map_s *map)
{
    map->map = str;
    get_pos_place(str, pos_object, 'O');
    get_pos_place(str, pos_X, 'X');
    initscr();
    start_color();
    init_pair(1, COLOR_CYAN, 0);
    init_pair(2, COLOR_RED, COLOR_MAGENTA);
    init_pair(3, COLOR_YELLOW, 0);
    init_pair(4, COLOR_WHITE, COLOR_WHITE);
    if (can_change_color()) {
        init_color(COLOR_MAGENTA, 720, 380, 0);
        init_color(COLOR_YELLOW, 0, 999, 0);
        init_color(COLOR_CYAN, 9, 999, 999);
        init_color(COLOR_RED, 820, 770, 615);
    }
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
}

int display_str(char **str)
{
    map_s map;
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;
    int nb = 0;

    init_screen(str, &pos_object, &pos_X, &map);
    print_map(map.map);
    find_player(map, &position);
    while (1) {
        nb = infin_loop(map, &position, pos_object, pos_X);
        if (nb != NOT_FINSH)
            break;
    }
    endwin();
    free_list(pos_object);
    free_list(pos_X);
    free_all(map.map);
    return nb - 1;
}
