/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** menu_start
*/

#include "../include/my.h"

sfSprite *create_fond_menu(char *path)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(sprite, text, sfFalse);
    return sprite;
}

engrenange_t create_button_sett(sfVector2f posi)
{
    engrenange_t engrenage; sfSprite *reg = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("img/reglage.png", NULL);
    sfSprite_setTexture(reg, texture, sfFalse);
    sfFloatRect rect = sfSprite_getGlobalBounds(reg);
    sfSprite_setScale(reg, (sfVector2f) {0.2, 0.2});
    sfVector2f reel = {posi.x - (rect.width * 0.2) / 2, posi.y -
    (rect.height * 0.2) / 2};
    sfSprite_setPosition(reg, reel);
    sfSprite_setOrigin(reg, (sfVector2f) {rect.width / 2, rect.height / 2});
    engrenage.sprite = reg;
    sfRectangleShape *rect_reg = sfRectangleShape_create();
    sfVector2f size = {100, 100};
    sfRectangleShape_setSize(rect_reg, size);
    sfRectangleShape_setOrigin(rect_reg, (sfVector2f) {size.x, size.y});
    sfRectangleShape_setPosition(rect_reg, posi);
    sfRectangleShape_setFillColor(rect_reg,
    sfColor_fromRGBA(164, 169, 255, 200));
    engrenage.rectangle = rect_reg;
    engrenage.rect = sfSprite_getGlobalBounds(reg);
    engrenage.clock = sfClock_create(); return engrenage;
}

void init_menu(glob_t *v)
{
    sfFloatRect rect_fond_flou = sfSprite_getGlobalBounds(v->start->background);
    sfVector2f posi = {rect_fond_flou.width,
    rect_fond_flou.height};
    v->start->sett = create_button_sett(posi);
}

void rotate_settings(glob_t *v, sfVector2f popo)
{
    if (mouseisinrect(v->start->sett.rect, popo)) {
        sfTime elapsed = sfClock_getElapsedTime(v->start->sett.clock);
        float rotation = sfTime_asSeconds(elapsed) * 220;
        sfSprite_setRotation(v->start->sett.sprite, rotation);
    }
}

void menu(glob_t *v)
{
    sfVector2i posi = sfMouse_getPositionRenderWindow(v->win);
    sfVector2f popo = sfRenderWindow_mapPixelToCoords(v->win, posi, v->view);
    rotate_settings(v, popo);
    show_all_buttons(v);
}
