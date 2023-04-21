/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** create_fake_mob
*/

#include "../../include/my.h"

sfCircleShape *circle_fake(mob_t *enemy, sfVector2f ori)
{
    sfCircleShape *enemy_hitbox = sfCircleShape_create();
    sfCircleShape_setFillColor(enemy_hitbox, sfTransparent);
    sfCircleShape_setOutlineColor(enemy_hitbox, sfBlack);
    sfCircleShape_setOutlineThickness(enemy_hitbox, 1);
    sfCircleShape_setRadius(enemy_hitbox, sfSprite_getGlobalBounds
    (enemy->sprite).height / 2);
    sfCircleShape_setOrigin(enemy_hitbox, (sfVector2f)
    {sfSprite_getGlobalBounds(enemy->sprite).height / 2,
    sfSprite_getGlobalBounds(enemy->sprite).height / 2});
    sfVector2f po = {sfSprite_getPosition(enemy->sprite).x + ori.x,
    sfSprite_getPosition(enemy->sprite).y + ori.y};
    sfCircleShape_setPosition(enemy_hitbox, po);
    return enemy_hitbox;
}

entity_t create_fake_mob(glob_t *v)
{
    (void) v;
    entity_t enemy;
    sfSprite *enemy_sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("img/pnj.png", NULL);
    sfSprite_setTexture(enemy_sprite, texture, sfFalse);
    sfSprite_setScale(enemy_sprite, (sfVector2f) {0.05, 0.05});
    sfFloatRect rect_sprite = sfSprite_getGlobalBounds(enemy_sprite);
    sfVector2f ori = {rect_sprite.width / 2, rect_sprite.height / 2};
    sfSprite_setOrigin(enemy_sprite, ori);
    sfVector2f popo = {50, 100};
    sfSprite_setPosition(enemy_sprite, popo);
    enemy.sprite = enemy_sprite;
    enemy.dammage = 1;
    enemy.speed = 15; enemy.delay = 1; enemy.stage = SPAWN;
    enemy.life = 10; enemy.clock_attack = sfClock_create();
    enemy.id = 1;
    return enemy;
}
