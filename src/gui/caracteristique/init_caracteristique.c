/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "../../../include/my.h"

sfText *create_text(char *string, int size, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("font/test.otf");
    sfText_setCharacterSize(text, size);
    sfText_setString(text, string);
    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    return text;
}

void create_background(glob_t *v)
{
    v->cara->background = sfRectangleShape_create();
    sfVector2f pos = {sfView_getSize(v->view).x / 2,
    sfView_getSize(v->view).y / 2};
    sfRectangleShape_setSize(v->cara->background, (sfVector2f){500, 350});
    sfRectangleShape_setOrigin(v->cara->background, (sfVector2f){250, 175});
    sfRectangleShape_setPosition(v->cara->background, pos);
    sfRectangleShape_setFillColor(v->cara->background,
    sfColor_fromRGB(150, 150, 150));
    v->cara->sprite = sfSprite_create();
    const sfIntRect area = {0, 64, 32, 32};
    sfTexture *text = sfTexture_createFromFile("img/sprite_sheet.png", NULL);
    sfSprite_setTexture(v->cara->sprite, text, sfFalse);
    sfSprite_setTextureRect(v->cara->sprite, area);
    sfSprite_setPosition(v->cara->sprite, (sfVector2f){200, 300});
    sfSprite_setScale(v->cara->sprite, (sfVector2f){8, 8});
    v->cara->name = create_text("Personnage", 40, (sfVector2f){425, 350});
    v->cara->life = create_text("Vie Maximum :", 25, (sfVector2f){425, 410});
    v->cara->money = create_text("Solde Bancaire :",
    25, (sfVector2f){425, 455});
}

void init_caracteristique(glob_t *v)
{
    create_background(v);
    weapons_img(v);
    weapons_text(v);
    v->cara->poing_lvl = 1;
    v->cara->couteau_lvl = 1;
    v->cara->baton_lvl = 1;
}
