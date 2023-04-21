/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** verification
*/

#include "../../include/my.h"

static const door_position_t doors[] = {
    {(sfFloatRect){280, 234, 50, 6}, SPAWN, MAP},
    {(sfFloatRect){353, 55, 30, 20}, SPAWN, BEDROOM},
    {(sfFloatRect){352, 80, 27, 24}, SPAWN, CELLAR},
    {(sfFloatRect){33, 51, 13, 23}, BEDROOM, SPAWN},
    {(sfFloatRect){32, 68, 16, 25}, CELLAR, SPAWN},
    {(sfFloatRect){50, 125, 15, 10}, MAP, SPAWN},
    {(sfFloatRect){621, 124, 38, 10}, MAP, NIGHT_CLUB},
    {(sfFloatRect){241, 402, 17, 14}, MAP, BASIC_FIT},
    {(sfFloatRect){463, 338, 17, 16}, MAP, DOCKS},
    {(sfFloatRect){655, 348, 20, 10}, MAP, SHOP},
    {(sfFloatRect){90, 665, 16, 12}, MAP, ZARA},
    {(sfFloatRect){326, 468, 37, 12}, ZARA, MAP},
    {(sfFloatRect){20, 228, 41, 12}, DOCKS, MAP},
    {(sfFloatRect){0, 0, 0, 0}, BASIC_FIT, MAP},
    {(sfFloatRect){48, 140, 60, 20}, SHOP, MAP},
    {(sfFloatRect){57, 386, 31, 14}, NIGHT_CLUB, MAP},
    {(sfFloatRect){0, 0, 0, 0}, ZERO, ZERO}
};

static const posi_player_door new_position[] = {
    {(sfVector2f){55, 140}, SPAWN, MAP},
    {(sfVector2f){65, 56}, SPAWN, BEDROOM},
    {(sfVector2f){62, 65}, SPAWN, CELLAR},
    {(sfVector2f){337, 58}, BEDROOM, SPAWN},
    {(sfVector2f){339, 95}, CELLAR, SPAWN},
    {(sfVector2f){304, 205}, MAP, SPAWN},
    {(sfVector2f){85, 350}, MAP, NIGHT_CLUB},
    {(sfVector2f){0, 0}, MAP, BASIC_FIT},
    {(sfVector2f){40, 201}, MAP, DOCKS},
    {(sfVector2f){80, 120}, MAP, SHOP},
    {(sfVector2f){343, 436}, MAP, ZARA},
    {(sfVector2f){97, 685}, ZARA, MAP},
    {(sfVector2f){470, 361}, DOCKS, MAP},
    {(sfVector2f){0, 0}, BASIC_FIT, MAP},
    {(sfVector2f){656, 361}, SHOP, MAP},
    {(sfVector2f){638, 134}, NIGHT_CLUB, MAP},
    {(sfVector2f){0, 0}, ZERO, ZERO}
};

void verification_in_door(glob_t *v)
{
    sfFloatRect bracelet = sfRectangleShape_getGlobalBounds(v->player_b);
    for (int i = 0; doors[i].from != ZERO; i++) {
        if (sfFloatRect_intersects(&doors[i].dim, &bracelet, NULL) &&
        v->stage == doors[i].from) {
            sfSprite_setPosition(v->player, new_position[i].position);
            v->stage = doors[i].dest;
            change_stage(v);
            resize_window_change_view(v, 1);
        }
    }
}
