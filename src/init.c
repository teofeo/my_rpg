/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init
*/

#include "../include/my.h"

static void init_map(glob_t *v)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("img/spawn/spawn.png", NULL);
    sfImage *image = sfImage_createFromFile("img/spawn/spawn_hitbox.png");
    sfTexture *map_h = sfTexture_createFromImage(image, NULL);
    sfSprite *map_h_s = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, (sfVector2f) {0, 0});
    sfSprite_setTexture(map_h_s, map_h, sfFalse);
    v->map = sprite;
    v->map_h = image;
    v->map_sprite_hit = map_h_s;
}

static void init_view(glob_t *v)
{
    v->view = sfView_create();
    v->view_s.x = 400;
    v->view_s.y = 400;
    v->clock = sfClock_create();
    v->time = 0;
    v->time_pnj = 0;
}

void init_buttons_menu(glob_t *v)
{
    v->list_buttons = malloc(sizeof(button_t) * 2);
    v->list_buttons = create_list_buttons(sfSprite_getGlobalBounds
    (v->start->background));
    create_list_buttons_res(v, sfSprite_getGlobalBounds(v->start->background));
}

static void run_all_init_functions(glob_t *v)
{
    init_map(v);
    init_view(v);
    init_all_audio(v);
    init_gui(v);
    init_caracteristique(v);
    init_shop(v);
    init_inventory(v);
    init_player(v);
    init_loading_game(v);
    init_menu(v);
    init_settings_menu(v);
    init_buttons_menu(v);
    init_music_cocaine(v);
}

void init_main(glob_t *v)
{
    init_default_win(v);
    v->start = malloc(sizeof(start_stage_t));
    v->dialogue_pos_pnj = 0;
    v->inventory->tune = 0;
    v->stage = START_M;
    v->list_enemy = NULL;
    v->list_afk = NULL;
    v->full_screen = sfFalse;
    run_all_init_functions(v);
    sfRenderWindow_setFramerateLimit(v->win, 60);
}
