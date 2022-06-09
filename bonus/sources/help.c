/*
** EPITECH PROJECT, 2022
** help.c
** File description:
** display help
*/
#include "project.h"

void display_help(void)
{
    my_printf("USAGE\n"
    "\t./my_sokoban map\n"
    "DESCRIPTION\n"
    "\tmap file representing the warehouse map, containing '#' for walls,\n"
    "\t\t'P' for the player, 'X' for boxes and 'O' for storage locations.\n");
}
