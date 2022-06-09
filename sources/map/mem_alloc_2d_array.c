/*
** EPITECH PROJECT, 2022
** mem_alloc_2d_array.c
** File description:
** malloc char **
*/
#include "project.h"

char **mem_alloc_2d_array(int nb_rows , int nb_cols)
{
    char **buffer = malloc(sizeof(char *) * (nb_rows + 1));

    for (int i = 0; i < nb_rows; i++) {
        buffer[i] = malloc(sizeof(char) * (nb_cols + 1));
    }
    return buffer;
}
