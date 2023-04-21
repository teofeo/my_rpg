/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** move_mob
*/

#include "../../include/my.h"

void move_reel_bot(glob_t *v, mob_t *tmp, sfVector2f pos_player)
{
    sfVector2f pos_enemy = sfSprite_getPosition(tmp->sprite);
    sfVector2f vecteur = {pos_player.x - pos_enemy.x,
    pos_player.y - pos_enemy.y};
    float norme = sqrt((pow(pos_player.x - pos_enemy.x, 2)) +
    pow(pos_player.y - pos_enemy.y, 2));
    pos_enemy.x += ((tmp->speed / norme * vecteur.x)) * (v->delta);
    pos_enemy.y += ((tmp->speed / norme * vecteur.y)) * (v->delta);
    sfSprite_setPosition(tmp->sprite, pos_enemy);
    sfFloatRect rect_sprite = sfSprite_getGlobalBounds(tmp->sprite);
    sfVector2f ori = {rect_sprite.width / 2, rect_sprite.height / 2};
    sfVector2f pos_circle = {pos_enemy.x + ori.x, pos_enemy.y + ori.y};
    sfCircleShape_setPosition(tmp->hitbox, pos_circle);
}

void move_bot(glob_t *v)
{
    sfVector2f pos_player = sfSprite_getPosition(v->player);
    mob_t *tmp = v->mobs;
    for (; tmp != NULL; tmp = tmp->next) {
        if (v->stage == tmp->stage) {
            move_reel_bot(v, tmp, pos_player);
        }
    }
}
