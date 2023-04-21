/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "../../../include/my.h"

void display_caracteristique(glob_t *v)
{
    sfRenderWindow_setView(v->win, v->inventory->view);
    sfRenderWindow_drawRectangleShape(v->win, v->cara->background, NULL);
    sfRenderWindow_drawSprite(v->win, v->cara->sprite, NULL);
    sfRenderWindow_drawText(v->win, v->cara->name, NULL);
    sfRenderWindow_drawText(v->win, v->cara->life, NULL);
    sfRenderWindow_drawText(v->win, v->cara->money, NULL);
    for (int i = 0; i != 3; i++) {
        sfRenderWindow_drawSprite(v->win, v->cara->node[i]->img, NULL);
        sfRenderWindow_drawText(v->win, v->cara->node[i]->title, NULL);
        sfRenderWindow_drawText(v->win, v->cara->node[i]->niveau_txt, NULL);
        sfRenderWindow_drawText(v->win, v->cara->node[i]->degat_txt, NULL);
    }
    sfRenderWindow_setView(v->win, v->view);
}
