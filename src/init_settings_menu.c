/*
** EPITECH PROJECT, 2023
** supp
** File description:
** init_settings_menu
*/

#include "../include/my.h"

sfRectangleShape *create_ligne_vol(sfVector2f pos)
{
    sfRectangleShape *ligne = sfRectangleShape_create();
    sfRectangleShape_setFillColor(ligne, sfColor_fromRGB(107, 107, 107));
    sfRectangleShape_setSize(ligne, (sfVector2f) {100, 20});
    sfRectangleShape_setOutlineColor(ligne, sfBlack);
    sfRectangleShape_setOutlineThickness(ligne, 1);
    sfRectangleShape_setPosition(ligne, pos);
    return ligne;
}

sfRectangleShape *create_barre_vol(sfVector2f pos)
{
    sfRectangleShape *barre = sfRectangleShape_create();
    sfVector2f size_barre = {5, 20};
    sfRectangleShape_setFillColor(barre, sfWhite);
    sfRectangleShape_setSize(barre, size_barre);
    sfRectangleShape_setOrigin(barre, (sfVector2f) {size_barre.x / 2,
    size_barre.y / 2 - 10});
    sfRectangleShape_setPosition(barre, pos);
    return barre;
}

sfText *create_text_volume(sfVector2f pos, sfRectangleShape *bouton)
{
    (void) pos;
    sfText *text_volume = sfText_create();
    sfText_setFont(text_volume, sfFont_createFromFile("font/slkscr.ttf"));
    sfText_setString(text_volume, "100");
    sfFloatRect rect_text = sfText_getGlobalBounds(text_volume);
    sfVector2f good_pos = {sfRectangleShape_getPosition(bouton).x + 10,
    sfRectangleShape_getPosition(bouton).y};
    sfText_setPosition(text_volume, good_pos);
    sfText_setOrigin(text_volume, (sfVector2f) {0, rect_text.height / 2});
    return text_volume;
}

void init_settings_menu(glob_t *v)
{
    sfVector2f pos = {500, 500};
    sfVector2f pos_barre = {600, 500};
    sfVector2f pos_text = {400, 500};
    v->settings_menu.volume.ligne = create_ligne_vol(pos);
    v->settings_menu.volume.barre = create_barre_vol(pos_barre);
    v->settings_menu.volume.text = create_text_volume(pos_text, v->
    settings_menu.volume.barre);
    v->settings_menu.bout_back = create_button("RETOUR", (sfVector2f) {0, 0});
    sfFloatRect rect_back = sfText_getGlobalBounds
    (v->settings_menu.bout_back.text);
    sfVector2f pos_back = {rect_back.width / 2, rect_back.height / 2};
    sfText_setPosition(v->settings_menu.bout_back.text, pos_back);
    rect_back = sfText_getGlobalBounds(v->settings_menu.bout_back.text);
    v->settings_menu.bout_back.rect = rect_back;
}
