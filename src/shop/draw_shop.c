/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "../../include/my.h"

void draw_shop_menu(glob_t *v)
{
    sfRenderWindow_setView(v->win, v->inventory->view);
    sfRenderWindow_drawRectangleShape(v->win, v->shop->background, NULL);
    for (int i = 0; i != 3; i++) {
        sfRenderWindow_drawRectangleShape(v->win, v->shop->node[i]->item, NULL);
        sfRenderWindow_drawText(v->win, v->shop->node[i]->niv_b, NULL);
        sfRenderWindow_drawText(v->win, v->shop->node[i]->fleche, NULL);
        sfRenderWindow_drawText(v->win, v->shop->node[i]->niv_a, NULL);
        sfRenderWindow_drawText(v->win, v->shop->node[i]->var_niv_a, NULL);
        sfRenderWindow_drawText(v->win, v->shop->node[i]->var_niv_b, NULL);
        sfRenderWindow_drawText(v->win, v->shop->node[i]->price, NULL);
        if (v->shop->node[i]->state == HOVER) {
            sfRectangleShape_setSize(v->shop->node[i]->buy, (sfVector2f){60, 60});
        } else {
            sfRectangleShape_setSize(v->shop->node[i]->buy, (sfVector2f){50, 50});
        }
        sfRenderWindow_drawRectangleShape(v->win, v->shop->node[i]->buy, NULL);
    }
    if (v->shop->bool_error == 1) {
        sfRenderWindow_drawText(v->win, v->shop->error, NULL);
    }
    sfRenderWindow_setView(v->win, v->view);
}

void draw_shop(glob_t *v)
{
    //printf("%d\n", v->shop->state);
    sfRenderWindow_drawSprite(v->win, v->shop->vendeur, NULL);
    if (v->shop->state == HOVER) {
        sfRenderWindow_drawSprite(v->win, v->shop->letter, NULL);
    }
    if (v->shop->state == PRESSED) {
        draw_shop_menu(v);
    }
}
