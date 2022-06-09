/*
** EPITECH PROJECT, 2022
** tests_boxes.c
** File description:
** tests of boxe
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "project.h"

Test(choose_move, move_boxe_down)
{
    char **res = load_2d_arr_from_file("maps/boxes_map");
    map_s map = init_struct_map(res, KEY_DOWN);
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    get_pos_place(map.map, &pos_X, 'X');
    choose_move(&position, map, pos_object, pos_X);
    cr_assert_str_eq(map.map[0], "#######");
    cr_assert_str_eq(map.map[1], "#     #");
    cr_assert_str_eq(map.map[2], "# OXO #");
    cr_assert_str_eq(map.map[3], "# X X #");
    cr_assert_str_eq(map.map[4], "# OPO #");
    cr_assert_str_eq(map.map[5], "#  X  #");
    cr_assert_str_eq(map.map[6], "#######");
}

Test(choose_move, move_boxe_up)
{
    char **res = load_2d_arr_from_file("maps/boxes_map");
    map_s map = init_struct_map(res, KEY_UP);
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    get_pos_place(map.map, &pos_X, 'X');
    choose_move(&position, map, pos_object, pos_X);
    cr_assert_str_eq(map.map[0], "#######");
    cr_assert_str_eq(map.map[1], "#  X  #");
    cr_assert_str_eq(map.map[2], "# OPO #");
    cr_assert_str_eq(map.map[3], "# X X #");
    cr_assert_str_eq(map.map[4], "# OXO #");
    cr_assert_str_eq(map.map[5], "#     #");
    cr_assert_str_eq(map.map[6], "#######");
}

Test(choose_move, move_boxe_right)
{
    char **res = load_2d_arr_from_file("maps/boxes_map");
    map_s map = init_struct_map(res, KEY_RIGHT);
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    get_pos_place(map.map, &pos_X, 'X');
    choose_move(&position, map, pos_object, pos_X);
    cr_assert_str_eq(map.map[0], "#######");
    cr_assert_str_eq(map.map[1], "#     #");
    cr_assert_str_eq(map.map[2], "# OXO #");
    cr_assert_str_eq(map.map[3], "# X PX#");
    cr_assert_str_eq(map.map[4], "# OXO #");
    cr_assert_str_eq(map.map[5], "#     #");
    cr_assert_str_eq(map.map[6], "#######");
}

Test(choose_move, move_boxe_left)
{
    char **res = load_2d_arr_from_file("maps/boxes_map");
    map_s map = init_struct_map(res, KEY_LEFT);
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    get_pos_place(map.map, &pos_X, 'X');
    choose_move(&position, map, pos_object, pos_X);
    cr_assert_str_eq(map.map[0], "#######");
    cr_assert_str_eq(map.map[1], "#     #");
    cr_assert_str_eq(map.map[2], "# OXO #");
    cr_assert_str_eq(map.map[3], "#XP X #");
    cr_assert_str_eq(map.map[4], "# OXO #");
    cr_assert_str_eq(map.map[5], "#     #");
    cr_assert_str_eq(map.map[6], "#######");
}

Test(choose_move, move_boxe_left_up)
{
    char **res = load_2d_arr_from_file("maps/boxes_map");
    map_s map = init_struct_map(res, KEY_LEFT);
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    get_pos_place(map.map, &pos_X, 'X');
    choose_move(&position, map, pos_object, pos_X);
    map.key = KEY_UP;
    choose_move(&position, map, pos_object, pos_X);
    cr_assert_str_eq(map.map[0], "#######");
    cr_assert_str_eq(map.map[1], "#     #");
    cr_assert_str_eq(map.map[2], "# PXO #");
    cr_assert_str_eq(map.map[3], "#X  X #");
    cr_assert_str_eq(map.map[4], "# OXO #");
    cr_assert_str_eq(map.map[5], "#     #");
    cr_assert_str_eq(map.map[6], "#######");
}

Test(choose_move, move_boxe_left_up_left)
{
    char **res = load_2d_arr_from_file("maps/boxes_map");
    map_s map = init_struct_map(res, KEY_LEFT);
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    get_pos_place(map.map, &pos_X, 'X');
    choose_move(&position, map, pos_object, pos_X);
    map.key = KEY_UP;
    choose_move(&position, map, pos_object, pos_X);
    map.key = KEY_LEFT;
    choose_move(&position, map, pos_object, pos_X);
    cr_assert_str_eq(map.map[0], "#######");
    cr_assert_str_eq(map.map[1], "#     #");
    cr_assert_str_eq(map.map[2], "#POXO #");
    cr_assert_str_eq(map.map[3], "#X  X #");
    cr_assert_str_eq(map.map[4], "# OXO #");
    cr_assert_str_eq(map.map[5], "#     #");
    cr_assert_str_eq(map.map[6], "#######");
}

Test(choose_move, stuck_boxe)
{
    char **res = load_2d_arr_from_file("maps/boxes_map");
    map_s map = init_struct_map(res, KEY_LEFT);
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    get_pos_place(map.map, &pos_X, 'X');
    choose_move(&position, map, pos_object, pos_X);
    map.key = KEY_LEFT;
    choose_move(&position, map, pos_object, pos_X);
    cr_assert_str_eq(map.map[0], "#######");
    cr_assert_str_eq(map.map[1], "#     #");
    cr_assert_str_eq(map.map[2], "# OXO #");
    cr_assert_str_eq(map.map[3], "#XP X #");
    cr_assert_str_eq(map.map[4], "# OXO #");
    cr_assert_str_eq(map.map[5], "#     #");
    cr_assert_str_eq(map.map[6], "#######");
}
