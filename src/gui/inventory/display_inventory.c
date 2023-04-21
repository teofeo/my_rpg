/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "../../../include/my.h"

static void display_health(glob_t *v)
{
    sfRenderWindow_drawRectangleShape(v->win, v->inventory->outline, NULL);
    sfRenderWindow_drawSprite(v->win, v->inventory->heart, NULL);
    for (int i = 0; i != 8; i++) {
        sfRenderWindow_drawRectangleShape(v->win,
        v->inventory->life_square[i], NULL);
    }
    sfRenderWindow_drawSprite(v->win, v->inventory->money, NULL);
    sfRenderWindow_drawText(v->win, v->inventory->money_nbr, NULL);
}

void dislpay_inventory_move_border(glob_t *v, int i)
{
    if (v->inventory->item_index ==
    v->inventory->inventory_button[i]->index) {
        sfRectangleShape_setOutlineColor
        (v->inventory->inventory_button[i]->square, sfWhite);
    } else {
        sfRectangleShape_setOutlineColor
        (v->inventory->inventory_button[i]->square,
        sfTransparent);
    }
}

void display_inventory(glob_t *v)
{
    sfRenderWindow_setView(v->win, v->inventory->view);
    sfRenderWindow_drawRectangleShape(v->win,
    v->inventory->background, NULL);
    display_health(v);
    for (int i = 0; i != 5; i++) {
        sfRenderWindow_drawRectangleShape(v->win,
        v->inventory->inventory_button[i]->square, NULL);
        dislpay_inventory_move_border(v, i);
        sfRenderWindow_drawRectangleShape(v->win,
        v->inventory->inventory_button[i]->img, NULL);
    }
    sfRenderWindow_setView(v->win, v->view);
}
