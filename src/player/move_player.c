/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** move_perso
*/

#include "../../include/my.h"

int change_texture_rect(glob_t *v);
void animation_player(glob_t *v);
int diagonal_animation_player(glob_t *v);
void manage_view_main_map(glob_t *v);

void change_position_player_hitbox(glob_t *v, sfVector2f center)
{
    sfSprite_setPosition(v->player, center);
    sfCircleShape_setPosition(v->enti_player.hitbox, center);
}

static void move_player(glob_t *v)
{
    sfVector2f center = sfSprite_getPosition(v->player);
    sfVector2f scale = sfSprite_getScale(v->player);
    float val = 90 * v->delta;
    if (key_down() && key_left()) val /= 1.5;
    if (key_down() && key_right()) val /= 1.5;
    if (key_up() && key_left()) val /= 1.5;
    if (key_up() && key_right()) val /= 1.5;
    if (key_down()) center.y += val;
    if (key_up())center.y -= val;
    if (key_right()) center.x += val;
    if (key_left()) center.x -= val;
    if (!possible_to_move_check(v, center))
        return;
    change_position_player_hitbox(v, center);
    sfRectangleShape_setPosition(v->player_square, center);
    center.x -= 12 / 2;
    center.y += (8 * scale.y) - 10;
    sfRectangleShape_setPosition(v->player_b, center);
    verification_in_door(v);
    manage_view_main_map(v);
}

static void set_good_axe_player(glob_t *v)
{
    sfIntRect txt_rect = sfSprite_getTextureRect(v->player);

    if (key_down()) txt_rect.left = 0;
    if (key_right()) txt_rect.left = ((v->player_s.x / 8) * 6);
    if (key_up() && !key_left()) txt_rect.left = ((v->player_s.x / 8) * 7);
    if (key_left()) txt_rect.left = ((v->player_s.x / 8) * 5);
    if (key_down() && key_left())
        txt_rect.left = (v->player_s.x / 8) * 3;
    if (key_down() && key_right())
        txt_rect.left = (v->player_s.x / 8) * 4;
    if (key_up() && key_left())
        txt_rect.left = (v->player_s.x / 8) * 2;
    if (key_up() && key_right())
        txt_rect.left = (v->player_s.x / 8) * 1;
    sfSprite_setTextureRect(v->player, txt_rect);
}

static void attaque_player(glob_t *v)
{
    if (sfKeyboard_isKeyPressed(sfKeyF)) {
        attaque(v);
    }
}

void player_event(glob_t *v)
{
    v->time += v->delta;

    while (v->time > 0.2) {
        if (diagonal_animation_player(v) != 0) {
            animation_player(v);
        }
        v->time -= 0.2;
    }
    audio_walk(v);
    set_good_axe_player(v);
    move_player(v);
    go_in_fight(v);
    attaque_player(v);
}
