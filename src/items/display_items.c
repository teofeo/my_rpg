/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** display
*/

#include "../../include/my.h"

static void effect_items_move(glob_t *v, item_t *item)
{
    float move = 0.01 * v->delta;
    sfVector2f scale = sfSprite_getScale(item->sprite);
    float x = item->scale.x;
    if (scale.x < x + 0.01f && item->up) {
        scale.x += move;
        scale.y += move;
    }
    if (scale.x >= x + 0.01f) {
        item->down = 1;
        item->up = 0;
    }
    if (scale.x > x && item->down) {
        scale.x -= move;
        scale.y -= move;
    }
    if (scale.x <= x) {
        item->down = 0;
        item->up = 1;
    }
    sfSprite_setScale(item->sprite, scale);
}

void display_items(glob_t *v)
{
    item_t *tmp = v->items;

    for (; tmp; tmp = tmp->next) {
        if (tmp->stage == v->stage && tmp->active) {
            sfRenderWindow_drawSprite(v->win, tmp->sprite, NULL);
            effect_items_move(v, tmp);
        }
    }
}
