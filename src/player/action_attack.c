/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** action_attack
*/

#include "../../include/my.h"

void attack_hit(glob_t *v, linked_list_enemy_t *tmp)
{
    tmp->entite.life -= v->enti_player.dammage;
    sfCircleShape_setOutlineColor(v->enti_player.hitbox, sfGreen);
    sfSound_play(v->audios->sword_hit);
    if (tmp->entite.life <= 0) {
        skipentity(&v->list_enemy, tmp->entite);
        sfSound_play(v->audios->die_sword);
    }
}

void attacks_all_enemy(glob_t *v, linked_list_enemy_t *tmp)
{
    if (tmp == NULL)
        sfSound_play(v->audios->sword_miss);
    for (; tmp != NULL; tmp = tmp->next) {
        sfFloatRect rect_hit = sfCircleShape_getGlobalBounds
        (v->enti_player.hitbox);
        sfFloatRect rect_enemy = sfSprite_getGlobalBounds(tmp->entite.sprite);
        if (sfFloatRect_intersects(&rect_hit, &rect_enemy, NULL)) {
            attack_hit(v, tmp);
        } else {
            sfSound_play(v->audios->sword_miss);
        }
    }
}

void attaque(glob_t *v)
{
    sfTime time = sfClock_getElapsedTime(v->enti_player.clock_attack);
    float time_s = sfTime_asSeconds(time);

    if (time_s > 0.5) {
        linked_list_enemy_t *tmp = v->list_enemy;
        sfCircleShape_setOutlineColor(v->enti_player.hitbox, sfRed);
        attacks_all_enemy(v, tmp);
        sfClock_restart(v->enti_player.clock_attack);
    }
}
