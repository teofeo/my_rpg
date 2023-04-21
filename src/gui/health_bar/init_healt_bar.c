/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "../../../include/my.h"

sfRectangleShape *create_life(sfVector2f pos)
{
    sfRectangleShape *square = sfRectangleShape_create();
    sfRectangleShape_setPosition(square, pos);
    sfRectangleShape_setSize(square, (sfVector2f){14, 14});
    sfRectangleShape_setFillColor(square, sfRed);
    return square;
}

sfSprite *create_icon(char *file, sfVector2f pos, sfVector2f scale)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile(file, NULL);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, text, sfFalse);
    return sprite;
}

void init_health_bar(glob_t *v)
{
    v->inventory->heart = create_icon("img/inventory/hearth.png",
    (sfVector2f){-375, 20},(sfVector2f){0.03, 0.03});
    v->inventory->outline = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(v->inventory->outline, 3);
    sfRectangleShape_setOutlineColor(v->inventory->outline, sfBlack);
    sfRectangleShape_setFillColor(v->inventory->outline, sfWhite);
    sfRectangleShape_setPosition(v->inventory->outline, (sfVector2f){-350, 40});
    sfRectangleShape_setSize(v->inventory->outline, (sfVector2f){164, 19});
    v->inventory->life_square = malloc(sizeof(sfRectangleShape*) * 8);
    for (int i = 0; i != 8; i++) {
        v->inventory->life_square[i] = malloc(sizeof(sfRectangleShape*));
    }
    sfVector2f pos = {-318, 42};
    for (int i = 0; i != 8; i++) {
        v->inventory->life_square[i] = create_life(pos);
        pos.x += 16;
    }
}

void init_money(glob_t *v)
{
    v->inventory->money = create_icon("img/inventory/money.png",
    (sfVector2f){-370, 80},(sfVector2f){0.130, 0.13});
    v->inventory->money_nbr = sfText_create();
    v->cara->var_money = 50;
    sfFont *font = sfFont_createFromFile("font/test.otf");
    sfText_setCharacterSize(v->inventory->money_nbr, 50);
    sfText_setColor(v->inventory->money_nbr, sfWhite);
    sfText_setFont(v->inventory->money_nbr, font);
    sfText_setPosition(v->inventory->money_nbr, (sfVector2f){-315, 70});
    sfText_setString(v->inventory->money_nbr,
    int_to_string(v->cara->var_money));
}

void init_gui(glob_t *v)
{
    init_health_bar(v);
    init_money(v);
}
