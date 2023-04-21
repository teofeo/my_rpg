/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** resize_wi* (v->evt.size.height / 10)ndow
*/

#include "../../include/my.h"

static int set_zoom_view(glob_t *v)
{
    if (v->stage != MAP && v->stage != ZARA) return (1);
    sfView_zoom(v->view, 0.25);
    return (0);
}

void resize_view(glob_t *v, int manual, sfVector2f win_s )
{
    if ((v->evt.type == sfEvtResized || manual)) {
        sfVector2f map_p = sfSprite_getPosition(v->map);
        const sfTexture *map_texture = sfSprite_getTexture(v->map);
        sfVector2u map_s = sfTexture_getSize(map_texture);
        sfVector2f map_center = {map_p.x + (map_s.x / 2), 0};
        map_center.y = map_p.y + (map_s.y / 2);
        float value = ((map_s.y / win_s.y) + (map_s.x / win_s.x) / 2 + 0.05);
        sfView_setSize(v->view, win_s);
        if (set_zoom_view(v))
            sfView_zoom(v->view, value);
        sfView_setCenter(v->view, map_center);
        sfRenderWindow_setView(v->win, v->view);
    }
}

void resize_window_change_view(glob_t *v, int manual)
{
    sfVector2u window_s = sfRenderWindow_getSize(v->win);
    sfVector2f win_s = {(float)window_s.x, (float) window_s.y};

    if ((v->stage == START_M || v->stage == SETTINGS)) {
        sfFloatRect rect = sfSprite_getGlobalBounds(v->start->background);
        sfView_destroy(v->view);
        v->view = sfView_createFromRect(rect);
        sfRenderWindow_setView(v->win, v->view);
        return;
    }
    resize_view(v, manual, win_s);
}
