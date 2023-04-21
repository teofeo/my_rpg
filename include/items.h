/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** my
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "stage.h"

typedef struct item_s {
    sfVector2f position;
    sfVector2f scale;
    sfSprite *sprite;
    places stage;
    struct item_s *next;
    char *id;
    sfBool active;
    int up;
    int down;
} item_t;
