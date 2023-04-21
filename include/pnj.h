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

typedef enum state_s {
    NONE,
    HOVER,
    PRESSED,
    PASSED,
} state_t;

typedef struct pnj_s {
    sfSprite *sprite;
    sfSprite *letter;
    sfText *dialogue;
    char *pnj_dialogue;
    state_t state;
    places stage;
    sfFloatRect hitbox;
    struct pnj_s *next;
} pnj_t;
