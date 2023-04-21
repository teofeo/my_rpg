/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** map_view
*/

#include "../../include/my.h"

void manage_view_main_map(glob_t *v)
{
    if (v->stage != MAP && v->stage != ZARA) return;
    sfVector2f player_p = sfSprite_getPosition(v->player);
    sfView_setCenter(v->view, player_p);
    sfRenderWindow_setView(v->win, v->view);
}
