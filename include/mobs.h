/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** mobs
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "stage.h"

typedef struct mob_s {
    sfCircleShape *hitbox;
    float delay;
    int life;
    int dammage;
    sfSprite *sprite;
    sfClock *clock_attack;
    places stage;
    int speed;
    char *id;
    struct mob_s *next;
} mob_t;
