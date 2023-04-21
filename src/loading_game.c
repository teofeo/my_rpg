/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** loading_game
*/

#include "../include/my.h"

static void reload_loading_game(glob_t *v)
{
    sfColor map_color = sfSprite_getColor(v->start->background);
    map_color.a = 255;
    sfSprite_setColor(v->start->background, map_color);
    v->stage = SPAWN;
    resize_window_change_view(v, 1);
    change_window(v);
}

void loading_bar(glob_t *v)
{
    sfVector2f size = sfRectangleShape_getSize(v->start->loading_bar);
    sfRectangleShape *rectange = v->start->loading_rect;
    sfVector2f rectangle_s = sfRectangleShape_getSize(rectange);
    sfSprite *background_map = v->start->background;
    sfColor map_color = sfSprite_getColor(background_map);
    int value = (rectangle_s.x - 20 - size.x) * 255 / (rectangle_s.x - 20);

    if (size.x >= rectangle_s.x - 20)
        reload_loading_game(v);
    if (size.x <= rectangle_s.x - 20) {
        size.x += 350 * v->delta;
        map_color.a = value;
        sfSprite_setColor(background_map, map_color);
        sfRectangleShape_setSize(v->start->loading_bar, size);
    }
}
