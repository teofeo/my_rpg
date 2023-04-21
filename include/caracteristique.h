/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Window.h>

typedef struct node_s {
    sfSprite *img;
    sfText *title;
    sfText *niveau_txt;
    sfText *degat_txt;
    int stat;
} node_t;

typedef struct caracteristique_s {
    sfRectangleShape *background;
    sfSprite *sprite;
    sfText *life;
    sfText *money;
    sfText *name;

    node_t **node;

    int var_life;
    int var_money;
    int poing_lvl;
    int baton_lvl;
    int couteau_lvl;
} caracteristique_t;
