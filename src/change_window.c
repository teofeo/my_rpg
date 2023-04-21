/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** change_window
*/

#include "../include/my.h"

void change_window(glob_t *v)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    sfRenderWindow_destroy(v->win);
    v->win = sfRenderWindow_create(mode, "my_rpg", sfDefaultStyle, NULL);
}
