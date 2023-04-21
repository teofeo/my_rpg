/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** event_buttons_settings
*/

#include "../include/my.h"

void click_on_button(button_t *list_buttons, int i, glob_t *b)
{
    if (my_strcmp(sfText_getString(list_buttons[i].text), "EXIT") == 0) {
        sfRenderWindow_close(b->win);
    }
    if (my_strcmp(sfText_getString(list_buttons[i].text), "Jouer") == 0) {
        b->stage = LOADING_GAME;
    }
}

void change_pressed_button(glob_t *v, int i, sfColor color_clic)
{
    sfText_setOutlineColor(v->list_buttons[i].text, color_clic);
}

void update_buttons(glob_t *v, sfColor color_base, sfColor new_color,
sfColor color_clic)
{
    (void) color_base;
    (void) new_color;
    (void) color_clic;
    for (int i = 0; i != 2; i++) {
        if (v->evt.type == sfEvtMouseButtonReleased && mouseisinrect
        (v->list_buttons[i].rect, v->pos_mouse)) {
            sfText_setOutlineColor(v->list_buttons[i].text,
            sfRed); click_on_button(v->list_buttons, i, v);
        }
        sfColor color = sfText_getOutlineColor
        (v->list_buttons[i].text);
        if (v->evt.type == sfEvtMouseButtonPressed && mouseisinrect(v->
        list_buttons[i].rect, v->pos_mouse) && colorcmp(color, sfBlue) == 0)
            change_pressed_button(v, i, sfGreen);
        if (mouseisinrect(v->list_buttons[i].rect, v->pos_mouse) && (colorcmp
        (color, sfRed) == 0))
            sfText_setOutlineColor(v->list_buttons[i].text,
            sfBlue);
        if (mouseisinrect(v->list_buttons[i].rect, v->pos_mouse) == 0 &&
        (colorcmp(color, sfBlue) == 0 || colorcmp(color, sfGreen) == 0))
            sfText_setOutlineColor(v->list_buttons[i].text,
            sfRed);
    }
}

void update_event_sett(glob_t *v, sfColor color_clic, sfColor new_color,
sfColor color_base)
{
    sfColor color = sfRectangleShape_getFillColor(v->start->sett.rectangle);
    if (v->evt.type == sfEvtMouseButtonReleased &&
    mouseisinrect(v->start->sett.rect, v->pos_mouse))
        v->stage = SETTINGS;
    if (v->evt.type == sfEvtMouseButtonPressed && mouseisinrect
    (v->start->sett.rect, v->pos_mouse) && colorcmp(color, new_color) == 0)
        sfRectangleShape_setFillColor(v->start->sett.rectangle, color_clic);
    if (mouseisinrect(v->start->sett.rect, v->pos_mouse) && (colorcmp(color,
    color_base) == 0))
        sfRectangleShape_setFillColor(v->start->sett.rectangle, new_color);
    if (mouseisinrect(v->start->sett.rect, v->pos_mouse) == 0 && (colorcmp
    (color, new_color) == 0 || colorcmp(color, color_clic) == 0))
        sfRectangleShape_setFillColor(v->start->sett.rectangle, color_base);
}

void event_on_buttons(glob_t *v, sfEvent event)
{
    sfColor color_base = sfColor_fromRGBA(164, 169, 255, 200);
    sfColor new_color = sfColor_fromRGB(110, 118, 255);
    sfColor color_clic = sfColor_fromRGB(25, 38, 255);
    sfVector2i posi = sfMouse_getPositionRenderWindow(v->win);
    sfVector2f popo = sfRenderWindow_mapPixelToCoords(v->win, posi, v->view);
    if (event.type == sfEvtMouseButtonReleased && mouseisinrect
    (v->start->sett.rect, popo)) {
        sfRectangleShape_setFillColor(v->start->sett.rectangle, color_base);
    }
    update_buttons(v, color_base, new_color, color_clic);
    update_event_sett(v, color_clic, new_color, color_base);
}
