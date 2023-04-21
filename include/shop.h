/*
** EPITECH PROJECT, 2023
** B-MUL-200-NCY-2-1-myrpg-teo.franoux
** File description:
** shop
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "pnj.h"

typedef struct node_shop_s {
    sfRectangleShape *item;
    sfText *niv_b;
    sfText *fleche;
    sfText *niv_a;
    sfText *price;
    sfText *var_niv_b;
    sfText *var_niv_a;

    sfRectangleShape *buy;
    sfFloatRect buy_hitbox;
    state_t state;

    int price_item;
} node_shop_t;

typedef struct shop_s {
    sfSprite *vendeur;
    sfSprite *letter;
    sfFloatRect hitbox;
    state_t state;
    sfText *error;
    int bool_error;
    
    node_shop_t **node;
    sfRectangleShape *background;

} shop_t;
