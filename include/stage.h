/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** stage
*/

#pragma once

#include <unistd.h>

typedef enum places_e{
    SPAWN,
    BEDROOM,
    MAP,
    BASIC_FIT,
    NIGHT_CLUB,
    ZARA,
    DOCKS,
    CELLAR,
    START_M,
    OPTION_M,
    LOADING_GAME,
    SETTINGS,
    SHOP,
    DEAD,
    ZERO
} places;

typedef struct maps_struct {
    char *map;
    char *hitbox;
    places stage;
} maps_informations;

typedef struct load_file_s {
    char *str;
    places stage;
} load_file_stage_t;
