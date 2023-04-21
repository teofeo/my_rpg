/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** full_screen
*/

#include "../include/my.h"

void change_full_screen(glob_t *v)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    sfRenderWindow_destroy(v->win);
    v->win = sfRenderWindow_create(mode, "my_rpg", sfFullscreen, NULL);
    sfRenderWindow_setPosition(v->win, (sfVector2i) {0, 0});
    resize_window_change_view(v, 1);
    v->full_screen = sfTrue;
}

void event_full_screen(glob_t *v, int manual)
{
    if ((sfKeyboard_isKeyPressed(sfKeyF11) &&
    sfKeyboard_isKeyPressed(sfKeyLControl)) || manual) {
        if (v->full_screen == sfFalse) {
            change_full_screen(v);
            return;
        }
        if (v->full_screen == sfTrue &&
        (v->stage == START_M || v->stage == SETTINGS) ) {
            sfRenderWindow_destroy(v->win);
            init_default_win(v);
            resize_window_change_view(v, 1);
            v->full_screen = sfFalse;
            return;
        }
        if (v->stage != START_M && v->stage != SETTINGS) {
            change_window(v);
            resize_window_change_view(v, 1);
            v->full_screen = sfFalse;
        }
    }
}
