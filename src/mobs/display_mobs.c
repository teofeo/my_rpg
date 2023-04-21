/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** display
*/

#include "../../include/my.h"

void display_mobs(glob_t *v)
{
    mob_t *tmp = v->mobs;

    for (; tmp; tmp = tmp->next) {
        if (tmp->stage == v->stage)
            sfRenderWindow_drawSprite(v->win, tmp->sprite, NULL);
    }
}
