/*
** EPITECH PROJECT, 2023
** supp
** File description:
** bot_attaque
*/

#include "../include/my.h"

void attaque_bot(glob_t *v)
{
    linked_list_enemy_t *tmp = v->list_enemy;
    sfFloatRect rect_p = sfSprite_getGlobalBounds(v->player);
    for (; tmp != NULL; tmp = tmp->next) {
        sfFloatRect rect_hit = sfCircleShape_getGlobalBounds
        (tmp->entite.hitbox);
        if (sfFloatRect_intersects(&rect_hit, &rect_p, NULL) && sfTime_asSeconds
        (sfClock_getElapsedTime(tmp->entite.clock_attack)) > 1) {
            v->enti_player.life -= tmp->entite.dammage;
            sfClock_restart(tmp->entite.clock_attack);
        }
    }
}
