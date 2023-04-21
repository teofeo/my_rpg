/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** animation_player
*/

#include "../../include/my.h"

int change_texture_rect(glob_t *v)
{
    sfIntRect txt_rect = sfSprite_getTextureRect(v->player);

    if (txt_rect.top >= ((int) v->player_s.y / 6) * 5)
        txt_rect.top = 0;
    txt_rect.top += v->player_s.y / 6;
    sfSprite_setTextureRect(v->player, txt_rect);
    return (0);
}

void animation_player(glob_t *v)
{
    sfIntRect txt_rect = sfSprite_getTextureRect(v->player);
    int wait_animation = 1;

    if (key_down())
        wait_animation = change_texture_rect(v);
    if (key_right())
        wait_animation = change_texture_rect(v);
    if (key_up() && !key_left())
        wait_animation = change_texture_rect(v);
    if (key_left())
        wait_animation = change_texture_rect(v);
    if (wait_animation) {
        txt_rect.top = 64;
        sfSprite_setTextureRect(v->player, txt_rect);
    }
    if (!wait_animation) event_items(v);
}

int diagonal_animation_player(glob_t *v)
{
    if (key_down() && key_left())
        return change_texture_rect(v);
    if (key_down() && key_right())
        return change_texture_rect(v);
    if (key_up() && key_left())
        return change_texture_rect(v);
    if (key_up() && key_right())
        return change_texture_rect(v);
    return (1);
}
