/*
** EPITECH PROJECT, 2023
** test
** File description:
** rtest
*/

#include "../../include/my.h"

void detect_colision(glob_t *v, pnj_t *tmp)
{
    if (sfFloatRect_intersects(&v->hitbox_hero, &tmp->hitbox, NULL)) {
        if (sfKeyboard_isKeyPressed(sfKeyR)) {
            tmp->state = PRESSED;
        }
        if (tmp->state != PRESSED)
            tmp->state = HOVER;
    } else {
        sfText_setString(tmp->dialogue,"");
        tmp->state = NONE;
    }
}

void pnj_event(glob_t *v)
{
    v->hitbox_hero = sfRectangleShape_getGlobalBounds(v->player_square);
    pnj_t *tmp = v->pnj;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->stage == v->stage) {
            detect_colision(v, tmp);
        }
    }
    shop_event(v);
}
