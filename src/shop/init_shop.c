/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "../../include/my.h"

static sfCircleShape *create_circle_hitbox(int size, sfSprite *sprite)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setRadius(circle, size);
    sfVector2f center = {size, size};
    sfVector2f pos_circle = {sfSprite_getPosition(sprite).x,
    sfSprite_getPosition(sprite).y};
    sfCircleShape_setOrigin(circle, center);
    sfCircleShape_setPosition(circle, pos_circle);
    return circle;
}

void init_pnj_shop(glob_t *v)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile("img/pnj/v_aigris.png", NULL);
    sfVector2f center = {sfTexture_getSize(text).x / 2,
    sfTexture_getSize(text).y / 2};
    sfSprite_setOrigin(sprite, center);
    sfSprite_setTexture(sprite, text, sfFalse);
    sfSprite_setPosition(sprite, (sfVector2f){80, 55}),
    sfSprite_setScale(sprite, (sfVector2f){0.5, 0.5});
    v->shop->hitbox = sfCircleShape_getGlobalBounds
    (create_circle_hitbox(20, sprite));
    v->shop->vendeur = sprite;
    v->shop->letter = create_letter_sprite(sprite);
}

void init_var_menu(glob_t *v)
{
    int niv_up = v->cara->poing_lvl + 1;
    v->shop->node[0]->var_niv_b = create_text
    (int_to_string(v->cara->poing_lvl), 40, (sfVector2f){415, 350});
    v->shop->node[1]->var_niv_b = create_text
    (int_to_string(v->cara->baton_lvl), 40, (sfVector2f){415, 475});
    v->shop->node[2]->var_niv_b = create_text
    (int_to_string(v->cara->couteau_lvl), 40, (sfVector2f){415, 600});

    v->shop->node[0]->var_niv_a = create_text
    (int_to_string(niv_up), 40, (sfVector2f){565, 350});
    v->shop->node[1]->var_niv_a = create_text(int_to_string
    (niv_up), 40, (sfVector2f){565, 475});
    v->shop->node[2]->var_niv_a = create_text(int_to_string
    (niv_up), 40, (sfVector2f){565, 600});

    v->shop->node[0]->price = create_text(my_strcat(int_to_string
    (v->cara->poing_lvl * 10), "$"), 40, (sfVector2f){640, 350});
    v->shop->node[1]->price = create_text(my_strcat(int_to_string
    (v->cara->baton_lvl * 10), "$"), 40, (sfVector2f){640, 475});
    v->shop->node[2]->price = create_text(my_strcat(int_to_string
    (v->cara->couteau_lvl * 10), "$"), 40, (sfVector2f){640, 600});
}

void init_menu_shop(glob_t *v)
{
    sfVector2f pos = {500, 500};
    sfVector2f size = {70, 70};
    v->shop->background = sfRectangleShape_create();
    sfRectangleShape_setSize(v->shop->background, (sfVector2f){600, 400});
    sfRectangleShape_setFillColor(v->shop->background, sfColor_fromRGB(150, 150, 150));
    sfRectangleShape_setPosition(v->shop->background, pos);
    sfRectangleShape_setOrigin(v->shop->background, (sfVector2f){300, 200});
    v->shop->node[0]->item = create_img((sfVector2f){275, 375}, size, "img/inventory/poing.png");
    v->shop->node[1]->item = create_img((sfVector2f){275, 500}, size, "img/inventory/batte-de-baseball.png");
    v->shop->node[2]->item = create_img((sfVector2f){275, 625}, size, "img/inventory/couteau.png");
    v->shop->node[0]->niv_b = create_text("niv", 40, (sfVector2f){350, 350});
    v->shop->node[1]->niv_b = create_text("niv", 40, (sfVector2f){350, 475});
    v->shop->node[2]->niv_b = create_text("niv", 40, (sfVector2f){350, 600});

    v->shop->node[0]->fleche = create_text("->", 40, (sfVector2f){450, 350});
    v->shop->node[1]->fleche = create_text("->", 40, (sfVector2f){450, 475});
    v->shop->node[2]->fleche = create_text("->", 40, (sfVector2f){450, 600});

    v->shop->node[0]->niv_a = create_text("niv", 40, (sfVector2f){500, 350});
    v->shop->node[1]->niv_a = create_text("niv", 40, (sfVector2f){500, 475});
    v->shop->node[2]->niv_a = create_text("niv", 40, (sfVector2f){500, 600});
}

void init_cart_button(glob_t *v)
{
    sfVector2f size = {50, 50};
    v->shop->node[0]->buy = create_img((sfVector2f){745, 375}, size, "img/shop/shopping.png");
    v->shop->node[1]->buy = create_img((sfVector2f){745, 500}, size, "img/shop/shopping.png");
    v->shop->node[2]->buy = create_img((sfVector2f){745, 625}, size, "img/shop/shopping.png");
    for (int i = 0; i != 3; i++) {
        v->shop->node[i]->buy_hitbox = sfRectangleShape_getGlobalBounds(v->shop->node[i]->buy);
        v->shop->node[i]->state = NONE;
    }
    sfVector2f pos = {200, 700};
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("font/test.otf");
    sfText_setCharacterSize(text, 50);
    sfText_setString(text, "ta pas assez de thune petiot");
    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    sfText_setColor(text, sfRed);
    v->shop->error = text;
    v->shop->bool_error = 0;
}

void init_shop(glob_t *v)
{
    init_pnj_shop(v);
    init_menu_shop(v);
    init_var_menu(v);
    init_cart_button(v);
}
