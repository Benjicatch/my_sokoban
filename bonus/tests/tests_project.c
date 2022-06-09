/*
** EPITECH PROJECT, 2022
** tests_project.c
** File description:
** tests
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "project.h"

char *map_test[12] = {"############",
"#        O #",
"# P     ####",
"#           ",
"#######    #",
"# O ##     #",
"#   ##     #",
"#          #",
"#       XX #",
"#       #  #",
"############"};

map_s init_struct_map(char **str, char *filepath, int key)
{
    map_s map;

    map.map = str;
    map.key = key;
    return map;
}

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(display_help, display_h, .init = redirect_all_stdout)
{
    display_help();
    cr_assert_stdout_eq_str("USAGE\n"
    "\t./my_sokoban map\n"
    "DESCRIPTION\n"
    "\tmap file representing the warehouse map, containing '#' for walls,\n"
    "\t\t'P' for the player, 'X' for boxes and 'O' for storage locations.\n");
}

Test(check_all, no_existing)
{
    int nb = check_all("hello");

    cr_assert_eq(nb, 84);
}

Test(check_all, good_display)
{
    int nb = check_all("maps/map");

    cr_assert_eq(nb, 0);
}

Test(check_all, two_players)
{
    int nb = check_all("maps/wrong_map");

    cr_assert_eq(nb, 84);
}

Test(check_all, char_not_allowed)
{
    int nb = check_all("maps/secund_wrong_map");

    cr_assert_eq(nb, 84);
}

Test(check_all, wrong_len_of_boxes)
{
    int nb = check_all("maps/nb_boxes");

    cr_assert_eq(nb, 84);
}

Test(mem_alloc_2d_array, mallo_2d, .init = redirect_all_stdout)
{
    char **res = mem_alloc_2d_array(5, 5);

    for (int i = 0; i < 5; i++) {
        cr_assert_str_eq(res[i], "");
    }
    for (int i = 0; i < 6; i++)
        free(res[i]);
    free(res);
}

Test(load_2d_arr_from_file, load_map, .init = redirect_all_stdout)
{
    char **res = load_2d_arr_from_file("maps/map");

    cr_assert_str_eq(res[0], "############");
    cr_assert_str_eq(res[1], "#        O #");
    cr_assert_str_eq(res[2], "# P     ####");
    cr_assert_str_eq(res[3], "#           ");
    cr_assert_str_eq(res[4], "#######    #");
    cr_assert_str_eq(res[5], "# O ##     #");
    cr_assert_str_eq(res[6], "#   ##     #");
    cr_assert_str_eq(res[7], "#          #");
    cr_assert_str_eq(res[8], "#       XX #");
    cr_assert_str_eq(res[9], "#       #  #");
    cr_assert_str_eq(res[10], "############");
    free_all(res);
}

Test(my_show_list, show_the_list, .init = redirect_all_stdout)
{
    list_t *list1 = NULL;

    my_put_in_list(&list1, 6, 5);
    my_put_in_list(&list1, 5, 6);
    my_show_list(list1);
    cr_assert_stdout_eq_str("col = 5 row = 6\ncol = 6 row = 5\n");
}

Test(find_player, find_pos_player)
{
    char **res = load_2d_arr_from_file("maps/secund_map");
    map_s map = init_struct_map(res, "maps/secund_map", 0);
    pos_s position;

    find_player(map, &position);
    cr_assert_eq(position.col, 7);
    cr_assert_eq(position.row, 1);
    cr_assert_eq(position.origin_col, 7);
    cr_assert_eq(position.origin_row, 1);
    cr_assert_eq(position.old_col, 7);
    cr_assert_eq(position.old_row, 1);
}

Test(get_pos_place, pos_O)
{
    char **res = map_test;
    map_s map = init_struct_map(res, "maps/secund_map", 0);
    pos_s position;
    list_t *pos_object = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    cr_assert_eq(pos_object->row, 2);
    cr_assert_eq(pos_object->col, 5);
    pos_object = pos_object->next;
    cr_assert_eq(pos_object->row, 9);
    cr_assert_eq(pos_object->col, 1);
}

Test(get_pos_place, pos_X)
{
    char **res = map_test;
    map_s map = init_struct_map(res, "maps/secund_map", 0);
    pos_s position;
    list_t *pos_object = NULL;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'X');
    cr_assert_eq(pos_object->row, 9);
    cr_assert_eq(pos_object->col, 8);
    cr_assert_eq(pos_object->origin_row, 9);
    cr_assert_eq(pos_object->origin_col, 8);
    pos_object = pos_object->next;
    cr_assert_eq(pos_object->row, 8);
    cr_assert_eq(pos_object->col, 8);
    cr_assert_eq(pos_object->origin_row, 8);
    cr_assert_eq(pos_object->origin_col, 8);
}

Test(stuck_boxes, not_stuck)
{
    char **res = load_2d_arr_from_file("maps/map");
    map_s map = init_struct_map(res, "maps/secund_map", KEY_UP);
    pos_s position;
    list_t *pos_object = NULL;
    list_t *pos_X = NULL;
    int nb = 0;

    find_player(map, &position);
    get_pos_place(map.map, &pos_object, 'O');
    get_pos_place(map.map, &pos_X, 'X');
    nb = stuck_boxes(pos_X, map);
    cr_assert_eq(nb, 0);
}
