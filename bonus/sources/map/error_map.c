/*
** EPITECH PROJECT, 2022
** error_map.c
** File description:
** errors for map
*/
#include "project.h"

int *check_car_secund(char c, int *return_and_boxes)
{
    switch (c) {
        case 'O':
            return_and_boxes[2]++;
            return_and_boxes[0] = 0;
            return return_and_boxes;
        case 'P':
            return_and_boxes[0] = 1;
            return return_and_boxes;
        default:
            return_and_boxes[0] = 84;
            return return_and_boxes;
    }
}

int *check_car(char c)
{
    static int return_and_boxes[3] = {0, 0, 0};

    switch (c) {
        case ' ':
            return_and_boxes[0] = 0;
            return return_and_boxes;
        case '\n':
            return_and_boxes[0] = 0;
            return return_and_boxes;
        case '#':
            return_and_boxes[0] = 0;
            return return_and_boxes;
        case 'X':
            return_and_boxes[1]++;
            return_and_boxes[0] = 0;
            return return_and_boxes;
        default:
            return check_car_secund(c, return_and_boxes);
    }
}

int check_return(int nb)
{
    static int check_player = 0;

    switch (nb) {
        case 84:
            return 84;
        case 1:
            if (check_player == 1) {
                return 84;
            }
            check_player = 1;
            return 0;
        default:
            break;
    }
    return 0;
}

int check_all(char *str)
{
    char *file;
    int *nb;

    if (fopen(str, "r") == NULL) {
        return 84;
    }
    file = load_file_in_mem(str);
    for (int i = 0; file[i] != '\0'; i++) {
        nb = check_car(file[i]);
        nb[0] = check_return(nb[0]);
        if (nb[0] == 84) {
            free(file);
            return 84;
        }
    }
    free(file);
    if (nb[1] != nb[2])
        return 84;
    return 0;
}
