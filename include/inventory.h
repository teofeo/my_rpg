/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** my
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Window.h>

typedef struct inventory_button_s {
    sfRectangleShape *square;
    sfRectangleShape *img;
    sfRectangleShape *hover_square;
    int index;
} inventory_button_t;

typedef struct inventory_s {
    sfSprite *heart;
    sfRectangleShape *outline;
    sfRectangleShape **life_square;

    sfSprite *money;
    sfText *money_nbr;
    int tune;
    sfRectangleShape *background;
    sfView *view;
    int item_index;
    inventory_button_t **inventory_button;
} inventory_t;
