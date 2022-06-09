/*
** EPITECH PROJECT, 2022
** sub_functions.c
** File description:
** little functions for loading map
*/
#include "project.h"

int max_cols(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            nb++;
    }
    return nb;
}

int check_max(int nb, int max)
{
    if (nb >= max)
        max = nb;
    return max;
}

int max_rows(char *str)
{
    int nb = 0;
    int max = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb++;
        if (str[i] == '\n') {
            max = check_max(nb, max);
            nb = 0;
        }
    }
    return max;
}

int check_space(char **str, int i, int j, int max_row)
{
    for (; j < max_row; j++)
        str[i][j] = ' ';
    return j;
}
