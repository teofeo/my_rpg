/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** go_to_menu_start
*/

#include "../include/my.h"

void go_to_menu_start(glob_t *v)
{
    v->stage = START_M;
    sfRenderWindow_destroy(v->win);
    init_default_win(v);
}
