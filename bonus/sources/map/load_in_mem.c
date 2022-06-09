/*
** EPITECH PROJECT, 2022
** load_in_mem.c
** File description:
** load file in mem
*/
#include "project.h"

char *load_file_in_mem(char const *filepath)
{
    struct stat st;
    int arg = open(filepath, O_RDONLY);
    char *buffer;

    stat(filepath, &st);
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    buffer[st.st_size] = '\0';
    read(arg, buffer, st.st_size);
    close(arg);
    return buffer;
}

void loop_j(char *base, char **str, int max_row, int i)
{
    int j = 0;
    static int nb = 0;

    for (; base[nb] != '\n' && j < max_row && base[nb] != '\0'; j++) {
        str[i][j] = base[nb];
        nb++;
    }
    if (base[nb] == '\n')
        j = check_space(str, i, j, max_row);
    nb++;
    str[i][j - 1] = '\0';
}

char **load_2d_arr_from_file(char const *filepath)
{
    char *base = load_file_in_mem(filepath);
    int max_col = max_cols(base);
    int max_row = max_rows(base);
    char **str = mem_alloc_2d_array(max_col, max_row);
    int i = 0;

    for (; i < max_col; i++) {
        loop_j(base, str, max_row, i);
    }
    str[i] = NULL;
    free(base);
    return str;
}
