/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** display_hitbox_event
*/

#include "../include/my.h"

void display_hitbox_event(glob_t *v)
{
    if (v->evt.type == sfEvtKeyPressed && v->evt.key.code == sfKeyM)
        get_position(v);
    if (v->evt.type == sfEvtKeyPressed && v->evt.key.code == sfKeyL)
        v->stage = LOADING_GAME;
}
