/*
** EPITECH PROJECT, 2023
** supp
** File description:
** event_on_settings
*/

#include "../include/my.h"

void change_volume(glob_t *v, sfFloatRect rect_ligne)
{
    sfVector2f new_pos = {v->pos_mouse.x, 500};
    if (sfFloatRect_contains(&rect_ligne, new_pos.x, new_pos.y))
        sfRectangleShape_setPosition(v->settings_menu.volume.barre, new_pos);
    sfFloatRect rect_barre = sfRectangleShape_getGlobalBounds(v->
    settings_menu.volume.barre);
    double new_volume = rect_barre.left + rect_barre.width / 2 - 500;
    int volume = round(new_volume);
    sfSound_setVolume(v->audios->son_fond, new_volume);
    sfText_setString(v->settings_menu.volume.text, int_to_str(volume));
}

void change_color_back(glob_t *v)
{
    sfColor color = sfText_getOutlineColor(v->settings_menu.bout_back.text);
    if (v->evt.type == sfEvtMouseButtonReleased &&
    mouseisinrect(v->settings_menu.bout_back.rect, v->pos_mouse))
        v->stage = START_M;
    if (v->evt.type == sfEvtMouseButtonPressed && mouseisinrect(v->
    settings_menu.bout_back.rect, v->pos_mouse) && colorcmp(color, sfBlue) == 0)
        sfText_setOutlineColor(v->settings_menu.bout_back.text, sfGreen);
    if (mouseisinrect(v->settings_menu.bout_back.rect, v->pos_mouse)
    && (colorcmp(color, sfRed) == 0))
        sfText_setOutlineColor(v->settings_menu.bout_back.text, sfBlue);
    if (mouseisinrect(v->settings_menu.bout_back.rect, v->pos_mouse)
    == 0 && (colorcmp(color, sfBlue) == 0 || colorcmp(color, sfGreen) == 0))
        sfText_setOutlineColor(v->settings_menu.bout_back.text, sfRed);
}

void event_on_settings(glob_t *v, sfEvent event)
{
    (void) event;
    sfFloatRect rect_ligne = sfRectangleShape_getGlobalBounds
    (v->settings_menu.volume.ligne);
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
    mouseisinrect(rect_ligne, v->pos_mouse)) {
        change_volume(v, rect_ligne);
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        v->stage = START_M;
    change_color_back(v);
    update_buttons_res(v);
}
