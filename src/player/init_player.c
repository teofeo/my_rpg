/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** init_player
*/

#include "../../include/my.h"

static void create_bracelet_electronique(glob_t *v)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfVector2f size = {11, 5};
    sfVector2f position = sfSprite_getPosition(v->player);
    sfVector2f scale = sfSprite_getScale(v->player);
    position.x -= size.x / 2;
    position.y += (8 * scale.y) - 10;
    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setFillColor(rectangle, sfBlack);
    sfRectangleShape_setPosition(rectangle, position);
    v->player_b = rectangle;
}

void init_player_hitbox(glob_t *v)
{
    sfCircleShape *hit_box = sfCircleShape_create();
    sfCircleShape_setFillColor(hit_box, sfTransparent);
    sfCircleShape_setOutlineColor(hit_box, sfBlack);
    sfCircleShape_setOutlineThickness(hit_box, 1);
    sfCircleShape_setRadius(hit_box, 20);
    sfCircleShape_setOrigin(hit_box, (sfVector2f) {20, 20});
    sfCircleShape_setPosition(hit_box, sfSprite_getPosition(v->player));
    v->enti_player.hitbox = hit_box;
    v->enti_player.delay = 0.5;
    v->enti_player.life = 10;
    v->enti_player.dammage = 1;
    v->enti_player.clock_attack = sfClock_create();
}

void init_player(glob_t *v)
{
    sfSprite *sprt = sfSprite_create();
    sfTexture *txt = sfTexture_createFromFile("img/sprite_sheet.png", NULL);
    sfSprite_setTexture(sprt, txt, sfFalse);
    sfVector2u size = sfTexture_getSize(txt);
    v->player_s = size;
    sfIntRect rect = {0, 0, size.x / 8, size.y / 6};
    sfSprite_setTextureRect(sprt, rect);
    sfSprite_setScale(sprt, (sfVector2f) {80 / 32, 80 / 32});
    sfVector2f origin = {rect.width / 2, rect.height / 2};
    sfSprite_setOrigin(sprt, origin);
    sfVector2f position = {277, 180};
    sfSprite_setPosition(sprt, position);
        v->player_square = sfRectangleShape_create();
    sfRectangleShape_setFillColor(v->player_square, sfTransparent);
    sfRectangleShape_setPosition(v->player_square, position);
    sfRectangleShape_setSize(v->player_square, (sfVector2f){16, 36});
    sfRectangleShape_setOrigin(v->player_square, (sfVector2f){8, 18});
    v->player = sprt;
    create_bracelet_electronique(v);
    init_player_hitbox(v);
}
