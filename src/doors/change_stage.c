/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** change_map
*/

#include "../../include/my.h"

static const maps_informations maps[] = {
    {"img/spawn/spawn.png", "img/spawn/spawn_hitbox.png", SPAWN},
    {"img/map/map_final.png", "img/map/map_final-hitbox.png", MAP},
    {"img/cellar/cellar.png", "img/cellar/cellar_hitbox.png", CELLAR},
    {"img/bedroom/bedroom.png", "img/bedroom/bedroom_hitbox.png", BEDROOM},
    {"img/night/night.png", "img/night/night_hitbox.png", NIGHT_CLUB},
    {"img/zara/zara.png", "img/zara/zara_hitbox.png", ZARA},
    {"img/docks/docks.png", "img/docks/docks_hitbox.png", DOCKS},
    {"img/shop/shop.png", "img/shop/hitbox_shop.png", SHOP}
};

static void load_new_stage(glob_t *v, int index)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(maps[index].map, NULL);
    sfImage *image_hitbox = sfImage_createFromFile(maps[index].hitbox);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite *sprite_hitbox = sfSprite_create();
    sfTexture *txt_hitbox = sfTexture_createFromFile(maps[index].hitbox, NULL);
    sfSprite_setTexture(sprite_hitbox, txt_hitbox, sfFalse);
    sfSprite_destroy(v->map);
    sfImage_destroy(v->map_h);
    v->map_sprite_hit = sprite_hitbox;
    v->map_h = image_hitbox;
    v->map = sprite;
}

void change_stage(glob_t *v)
{
    int index = 0;
    while (maps[index].stage != v->stage) index++;
    if (v->stage == MAP) sfView_zoom(v->view, 0.05);
    load_new_stage(v, index);
}
