/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/
#include "project.h"

int main(int ac, char **av)
{
    char **str;
    int nb = 0;

    if (ac != 2) {
        return 84;
    } else if (my_strcmp("-h", av[1]) == 0) {
        display_help();
        return 0;
    }
    nb = check_all(av[1]);
    if (nb == 84) {
        my_printf("Error: invalid map.\n");
        return 84;
    }
    str = load_2d_arr_from_file(av[1]);
    nb = display_str(str);
    return nb;
}
