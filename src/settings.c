/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** settings
*/

#include "../include/my.h"

void click_on_button_res(button_t *list_buttons, int i, glob_t *v)
{
    if (my_strcmp(sfText_getString(list_buttons[i].text), "Plein ecran") == 0) {
        event_full_screen(v, 1);
    }
    if (my_strcmp(sfText_getString(list_buttons[i].text), "900x900") == 0) {
        sfRenderWindow_setSize(v->win, (sfVector2u) {720, 480});
    }
}

void update_buttons_res(glob_t *v)
{
    for (int i = 0; i != 3; i++) {
        if (v->evt.type == sfEvtMouseButtonReleased && mouseisinrect
        (v->settings_menu.list_res[i].rect, v->pos_mouse)) {
            sfText_setOutlineColor(v->settings_menu.list_res[i].text,
            sfRed); click_on_button_res(v->settings_menu.list_res, i, v);
        }
        sfColor color = sfText_getOutlineColor
        (v->settings_menu.list_res[i].text);
        if (v->evt.type == sfEvtMouseButtonPressed && mouseisinrect(v->
        settings_menu.list_res[i].rect, v->pos_mouse) && colorcmp
        (color, sfBlue) == 0)
            change_pressed_button(v, i, sfGreen);
        if (mouseisinrect(v->settings_menu.list_res[i].rect, v->pos_mouse) &&
        (colorcmp(color, sfRed) == 0))
            sfText_setOutlineColor(v->settings_menu.list_res[i].text,
            sfBlue);
        if (mouseisinrect(v->settings_menu.list_res[i].rect, v->pos_mouse) == 0
        && (colorcmp(color, sfBlue) == 0 || colorcmp(color, sfGreen) == 0))
            sfText_setOutlineColor(v->settings_menu.list_res[i].text,
            sfRed);
    }
}

void settings(glob_t *v)
{
    (void) v;
    sfRenderWindow_drawSprite(v->win, v->start->background, NULL);
    sfRenderWindow_drawRectangleShape(v->win,
    v->settings_menu.volume.ligne, NULL);
    sfRenderWindow_drawRectangleShape(v->win,
    v->settings_menu.volume.barre, NULL);
    sfRenderWindow_drawText(v->win, v->settings_menu.volume.text, NULL);
    show_button(v->settings_menu.bout_back, v);
    for (int i = 0; i != 3; i++)
        show_button(v->settings_menu.list_res[i], v);
    sfRenderWindow_drawText(v->win,
    v->settings_menu.text_resolution, NULL);
    sfRenderWindow_drawText(v->win,
    v->settings_menu.text_volume, NULL);
}
