/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** event_items
*/

#include "../../include/my.h"

static void choose_action(glob_t *v, item_t *item)
{
    printf("Stage = %d\n", v->stage);
    if (my_strcmp(item->id, "beer.png") == 0) {
        item->active = sfFalse;
    }
    if (my_strcmp(item->id, "cocaine.png") == 0) {
        sfSound_play(v->audios->cocaine);
        item->active = sfFalse;
    }
    if (my_strcmp(item->id, "cash.png") == 0) {
        v->cara->var_money += 10;
        sfText_setString(v->inventory->money_nbr,
        int_to_string(v->cara->var_money));
        item->active = sfFalse;
    }
}

void event_items(glob_t *v)
{
    item_t *tmp = v->items;
    sfFloatRect rect = sfSprite_getGlobalBounds(v->items->sprite);
    sfFloatRect perso = v->hitbox_hero;

    for (; tmp != NULL; tmp = tmp->next) {
        rect = sfSprite_getGlobalBounds(tmp->sprite);
        perso = v->hitbox_hero;
        if (sfFloatRect_intersects(&perso, &rect, NULL) &&
        tmp->active == sfTrue && tmp->stage == v->stage)
            choose_action(v, tmp);
    }
}
