/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** show_buttons_menu
*/

#include "../include/my.h"

void show_button(button_t bouton, glob_t *v)
{
    sfRenderWindow_drawText(v->win, bouton.text, NULL);
}

void show_all_buttons(glob_t *v)
{
    sfRenderWindow_drawSprite(v->win, v->start->background, NULL);
    if (v->stage == START_M) {
        sfRenderWindow_drawSprite(v->win, v->start->sett.sprite, NULL);
        for (int i = 0; i != 2; i++)
            show_button(v->list_buttons[i], v);
    }
}
