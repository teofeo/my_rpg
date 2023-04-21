/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_loading_game
*/

#include "../include/my.h"

static void init_text_loading(glob_t *v)
{
    sfTexture *texture = sfTexture_createFromFile("img/loading.png", NULL);
    sfSprite *sprite = sfSprite_create();
    const sfTexture *background = sfSprite_getTexture(v->start->background);
    sfVector2u size_position = sfTexture_getSize(background);
    sfVector2u size = sfTexture_getSize(texture);
    sfVector2f origin = {(size.x / 2), (size.y / 2)};
    sfVector2f position = {size_position.x / 2, size_position.y / 2};

    sfSprite_setOrigin(sprite, origin);
    sfSprite_setPosition(sprite, position);
    sfSprite_setTexture(sprite, texture, sfFalse);
    v->start->loading_sprite = sprite;
}

static void init_rectangle_shape_bar(glob_t *v)
{
    sfVector2f pos = sfSprite_getPosition(v->start->loading_sprite);
    const sfTexture *texture = sfSprite_getTexture(v->start->loading_sprite);
    sfVector2u size = sfTexture_getSize(texture);
    sfVector2f scale = sfSprite_getScale(v->start->loading_sprite);
    scale = (sfVector2f) {size.x *= scale.x, size.y *= scale.y};
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfVector2f rectangle_p = {pos.x - 20 - size.x / 2, pos.y + size.y};
    sfVector2f rectangle_s = {size.x + 20, size.y - 30};
    sfRectangleShape_setPosition(rectangle, rectangle_p);
    sfRectangleShape_setSize(rectangle, rectangle_s);
    sfRectangleShape_setOutlineColor(rectangle, sfBlack);
    sfRectangleShape_setOutlineThickness(rectangle, 2);
    sfRectangleShape *loading_bar = sfRectangleShape_create();
    sfVector2f loading_p = {rectangle_p.x + 10, rectangle_p.y + 10};
    sfVector2f loading_s = {0, rectangle_s.y - 20};
    sfRectangleShape_setPosition(loading_bar, loading_p);
    sfRectangleShape_setSize(loading_bar, loading_s);
    sfRectangleShape_setFillColor(loading_bar, sfGreen);
    v->start->loading_bar = loading_bar;
    v->start->loading_rect = rectangle;
}

void init_loading_game(glob_t *v)
{
    sfTexture *texture = sfTexture_createFromFile("img/start.png", NULL);
    sfSprite *background = sfSprite_create();
    sfSprite_setTexture(background, texture, sfFalse);
    v->start->background = background;
    init_text_loading(v);
    init_rectangle_shape_bar(v);
}
