/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** display
*/

#include "../include/my.h"


// void display_enemy(glob_t *v)
// {
//     linked_list_enemy_t *tmp = v->list_enemy;
//     for (; tmp != NULL; tmp = tmp->next) {
//         if (tmp->entite.stage == v->stage) {
//             sfRenderWindow_drawSprite(v->win, tmp->entite.sprite, NULL);
//             sfRenderWindow_drawCircleShape(v->win, tmp->entite.hitbox, NULL);
//         }
//     }
//     linked_list_enemy_t *tmpo = v->list_afk;
//     for (; tmpo != NULL; tmpo = tmpo->next) {
//         if (tmpo->entite.stage == v->stage) {
//             sfRenderWindow_drawSprite(v->win, tmpo->entite.sprite, NULL);
//             sfRenderWindow_drawCircleShape(v->win, tmpo->entite.hitbox, NULL);
//         }
//     }
// }

static void display_start_and_loading(glob_t *v)
{
    if (v->stage == START_M || v->stage == LOADING_GAME)
        menu(v);
    if (v->stage == SETTINGS)
        settings(v);
    if (v->stage == LOADING_GAME) {
        sfRenderWindow_drawRectangleShape(v->win, v->start->loading_rect, NULL);
        sfRenderWindow_drawRectangleShape(v->win, v->start->loading_bar, NULL);
        sfRenderWindow_drawSprite(v->win, v->start->loading_sprite, NULL);
        loading_bar(v);
    }
    if (v->stage == DEAD) {
        v->stage = START_M;
    }
}

void displays(glob_t *v)
{
    if (v->stage != START_M && v->stage != LOADING_GAME){
        sfRenderWindow_drawSprite(v->win, v->map, NULL);
        display_inventory(v);
        display_pnj(v);
        display_items(v);
        display_mobs(v);
        sfRenderWindow_drawSprite(v->win, v->player, NULL);
        sfRenderWindow_drawCircleShape(v->win, v->enti_player.hitbox, NULL);
    }
    display_start_and_loading(v);
    if (sfKeyboard_isKeyPressed(sfKeyB))
        sfRenderWindow_drawSprite(v->win, v->map_sprite_hit, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyC))
        display_caracteristique(v);
}
