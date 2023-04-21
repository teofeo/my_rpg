/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** possible_move_check
*/

#include "../../include/my.h"

static int check_pixel_move_player(glob_t *v, int y, sfVector2f rect_p)
{
    sfColor color;
    sfColor model = sfBlack;
    sfVector2f rect_s = sfRectangleShape_getSize(v->player_b);

    for (int x = rect_p.x; x < rect_p.x + rect_s.x; x++) {
        color = sfImage_getPixel(v->map_h, x, y);
        if (color.r == model.r && color.g == model.g &&
        color.b == model.b && color.a == model.a)
            return (1);
    }
    return (0);
}

int possible_to_move_check(glob_t *v, sfVector2f rect_p)
{
    sfVector2f rect_s = sfRectangleShape_getSize(v->player_b);
    sfVector2f scale = sfSprite_getScale(v->player);
    rect_p.y += (8 * scale.y) - 10;
    rect_p.x -= 12 / 2;

    for (int y = rect_p.y; y < rect_p.y + rect_s.y; y++)
        if (check_pixel_move_player(v, y, rect_p))
            return (0);
    return (1);
}
