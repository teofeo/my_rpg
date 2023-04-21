/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_default_win
*/

#include "../include/my.h"

void init_default_win(glob_t *v)
{
    sfVideoMode w_size = sfVideoMode_getDesktopMode();
    sfVideoMode mode = {1020, 768, 30};
    w_size.width -= w_size.width / 2;
    w_size.height -= w_size.height / 2;
    v->win = sfRenderWindow_create(mode, "my_rpg", sfClose, NULL);
    sfVector2i pos_win = {(w_size.width / 2) - 100, (w_size.height / 2) - 100};
    sfRenderWindow_setPosition(v->win, pos_win);
}
