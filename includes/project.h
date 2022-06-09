/*
** EPITECH PROJECT, 2022
** project.h
** File description:
** project
*/

#ifndef PROJECT_H
    #define PROJECT_H

    #include <ncurses.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>

enum result {NOT_FINSH, WIN, LOSE};

typedef struct map {
    char **map;
    int key;
} map_s;

typedef struct linked_list {
    int col;
    int row;
    int origin_col;
    int origin_row;
    struct linked_list *next;
} list_t;

typedef struct pos {
    int row;
    int col;
    int old_row;
    int old_col;
    int origin_row;
    int origin_col;
    int check_safe;
} pos_s;

void my_printf(char *s, ...);
char **my_str_to_word_array(char const *str);
int my_strcmp(char const *s1 , char const *s2);
char *my_strcat(char *dest, char const *src);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int my_str_isnum(char const *str);
void display_help(void);
int check_all(char *str);
char *load_file_in_mem(char const *filepath);
char **mem_alloc_2d_array(int nb_rows , int nb_cols);
char **load_2d_arr_from_file(char const *filepath);
void find_player(map_s map, pos_s *position);
void choose_move(pos_s *position, map_s map, list_t *pos_O, list_t *pos_X);
int display_str(char **str);
int max_rows(char *str);
int max_cols(char *str);
int check_max(int nb, int max);
int check_space(char **str, int i, int j, int max_row);
void check_boxes(pos_s *pos, map_s map, list_t *pos_X);
int check_walls(int col, int row, map_s map, int boul);
void my_show_list(struct linked_list *list);
void my_put_in_list(struct linked_list **list, int col, int row);
int my_list_size(list_t const *begin);
void free_all(char **str);
void free_list(struct linked_list *tri);
void get_pos_place(char **map, list_t **pos_object, char boul);
int check_placement(char **map, list_t *pos_object);
void restart(map_s map, pos_s *pos, list_t *pos_X, list_t *pos_O);
int stuck_boxes(list_t *pos_X, map_s map);
void move_boxes(pos_s *pos, map_s map, list_t *pos_X);

map_s init_struct_map(char **str, int key);

#endif
