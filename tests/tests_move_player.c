/*
** EPITECH PROJECT, 2022
** tests_move_player.c
** File description:
** tests
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "project.h"

Test(choose_move, move_left)
{
    char **res = load_2d_arr_from_file("maps/map");
    map_s map = init_struct_map(res, KEY_LEFT);
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    get_pos_place(map.map, &pos_X, 'X');
    choose_move(&position, map, pos_object, pos_X);
    cr_assert_str_eq(map.map[0], "############");
    cr_assert_str_eq(map.map[1], "#        O #");
    cr_assert_str_eq(map.map[2], "#P      ####");
    cr_assert_str_eq(map.map[3], "#           ");
    cr_assert_str_eq(map.map[4], "#######    #");
    cr_assert_str_eq(map.map[5], "# O ##     #");
    cr_assert_str_eq(map.map[6], "#   ##     #");
    cr_assert_str_eq(map.map[7], "#          #");
    cr_assert_str_eq(map.map[8], "#       XX #");
    cr_assert_str_eq(map.map[9], "#       #  #");
    cr_assert_str_eq(map.map[10], "############");
}

Test(choose_move, move_right)
{
    char **res = load_2d_arr_from_file("maps/map");
    map_s map = init_struct_map(res, KEY_RIGHT);
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    get_pos_place(map.map, &pos_X, 'X');
    choose_move(&position, map, pos_object, pos_X);
    cr_assert_str_eq(map.map[0], "############");
    cr_assert_str_eq(map.map[1], "#        O #");
    cr_assert_str_eq(map.map[2], "#  P    ####");
    cr_assert_str_eq(map.map[3], "#           ");
    cr_assert_str_eq(map.map[4], "#######    #");
    cr_assert_str_eq(map.map[5], "# O ##     #");
    cr_assert_str_eq(map.map[6], "#   ##     #");
    cr_assert_str_eq(map.map[7], "#          #");
    cr_assert_str_eq(map.map[8], "#       XX #");
    cr_assert_str_eq(map.map[9], "#       #  #");
    cr_assert_str_eq(map.map[10], "############");
}

Test(choose_move, move_down)
{
    char **res = load_2d_arr_from_file("maps/map");
    map_s map = init_struct_map(res, KEY_DOWN);
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    get_pos_place(map.map, &pos_X, 'X');
    choose_move(&position, map, pos_object, pos_X);
    cr_assert_str_eq(map.map[0], "############");
    cr_assert_str_eq(map.map[1], "#        O #");
    cr_assert_str_eq(map.map[2], "#       ####");
    cr_assert_str_eq(map.map[3], "# P         ");
    cr_assert_str_eq(map.map[4], "#######    #");
    cr_assert_str_eq(map.map[5], "# O ##     #");
    cr_assert_str_eq(map.map[6], "#   ##     #");
    cr_assert_str_eq(map.map[7], "#          #");
    cr_assert_str_eq(map.map[8], "#       XX #");
    cr_assert_str_eq(map.map[9], "#       #  #");
    cr_assert_str_eq(map.map[10], "############");
}

Test(choose_move, move_up)
{
    char **res = load_2d_arr_from_file("maps/map");
    map_s map = init_struct_map(res, KEY_UP);
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    get_pos_place(map.map, &pos_X, 'X');
    choose_move(&position, map, pos_object, pos_X);
    cr_assert_str_eq(map.map[0], "############");
    cr_assert_str_eq(map.map[1], "# P      O #");
    cr_assert_str_eq(map.map[2], "#       ####");
    cr_assert_str_eq(map.map[3], "#           ");
    cr_assert_str_eq(map.map[4], "#######    #");
    cr_assert_str_eq(map.map[5], "# O ##     #");
    cr_assert_str_eq(map.map[6], "#   ##     #");
    cr_assert_str_eq(map.map[7], "#          #");
    cr_assert_str_eq(map.map[8], "#       XX #");
    cr_assert_str_eq(map.map[9], "#       #  #");
    cr_assert_str_eq(map.map[10], "############");
}

Test(choose_move, stuck_up)
{
    char **res = load_2d_arr_from_file("maps/little_map");
    map_s map = init_struct_map(res, KEY_UP);
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    get_pos_place(map.map, &pos_X, 'X');
    choose_move(&position, map, pos_object, pos_X);
    cr_assert_str_eq(map.map[0], "###");
    cr_assert_str_eq(map.map[1], "#P#");
    cr_assert_str_eq(map.map[2], "###");
}

Test(choose_move, stuck_left)
{
    char **res = load_2d_arr_from_file("maps/little_map");
    map_s map = init_struct_map(res, KEY_LEFT);
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    get_pos_place(map.map, &pos_X, 'X');
    choose_move(&position, map, pos_object, pos_X);
    cr_assert_str_eq(map.map[0], "###");
    cr_assert_str_eq(map.map[1], "#P#");
    cr_assert_str_eq(map.map[2], "###");
}

Test(choose_move, stuck_right)
{
    char **res = load_2d_arr_from_file("maps/little_map");
    map_s map = init_struct_map(res, KEY_RIGHT);
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    get_pos_place(map.map, &pos_X, 'X');
    choose_move(&position, map, pos_object, pos_X);
    cr_assert_str_eq(map.map[0], "###");
    cr_assert_str_eq(map.map[1], "#P#");
    cr_assert_str_eq(map.map[2], "###");
}

Test(choose_move, stuck_down)
{
    char **res = load_2d_arr_from_file("maps/little_map");
    map_s map = init_struct_map(res, KEY_DOWN);
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    get_pos_place(map.map, &pos_X, 'X');
    choose_move(&position, map, pos_object, pos_X);
    cr_assert_str_eq(map.map[0], "###");
    cr_assert_str_eq(map.map[1], "#P#");
    cr_assert_str_eq(map.map[2], "###");
}
