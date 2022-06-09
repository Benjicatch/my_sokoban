/*
** EPITECH PROJECT, 2022
** print_map.c
** File description:
** print_the_map
*/
#include "project.h"

void print_boxes_and_place(int i, int j, char **str)
{
    switch (str[i][j]) {
        case 'X':
            attron(COLOR_PAIR(2));
            printw("%c", str[i][j]);
            attroff(COLOR_PAIR(2));
            break;
        case 'O':
            attron(COLOR_PAIR(3));
            printw("%c", str[i][j]);
            attroff(COLOR_PAIR(3));
            break;
        default:
            printw("%c", str[i][j]);
            break;
    }
}

void print_char(int i, int j, char **str)
{
    switch (str[i][j]) {
        case 'P':
            attron(COLOR_PAIR(1));
            printw("%c", str[i][j]);
            attroff(COLOR_PAIR(1));
                break;
        case '#':
            attron(COLOR_PAIR(4));
            printw("%c", str[i][j]);
            attroff(COLOR_PAIR(4));
            break;
        default:
            print_boxes_and_place(i, j, str);
            break;
    }
}

int print_map(char **str)
{
    char *sent = "Terminal too small to dislay map";

    for (int i = 0; str[i] != NULL; i++) {
        if (my_strlen(str[i]) > LINES || i > COLS) {
            mvprintw(LINES / 2, (COLS - (COLS / 2) - 16) / 2, sent);
            getch();
            endwin();
            return 1;
        }
        for (int j = 0; str[i][j] != '\0'; j++) {
            print_char(i, j, str);
        }
        printw("\n");
    }
    return 0;
}
