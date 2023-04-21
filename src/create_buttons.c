/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** create_buttons
*/

#include "../include/my.h"

sfText *create_text_button(const char *string, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfText_setColor(text, sfWhite);
    sfText_setString(text, string);
    sfText_setCharacterSize(text, 40);
    sfText_setFont(text, sfFont_createFromFile("font/slkscr.ttf"));
    sfText_setOutlineColor(text, sfRed);
    sfText_setOutlineThickness(text, 7);
    sfFloatRect prop_text = sfText_getGlobalBounds(text);
    sfText_setOrigin(text, (sfVector2f) {prop_text.width / 2,
    prop_text.height / 2});
    sfText_setPosition(text, pos);
    return text;
}

sfRectangleShape *create_rectangle_button(sfVector2f pos, button_t bouton)
{
    sfFloatRect prop_text = sfText_getGlobalBounds(bouton.text);
    sfColor color = sfColor_fromRGBA(164, 169, 255, 200);
    sfRectangleShape *rectangle = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rectangle, color);
    sfRectangleShape_setPosition(rectangle, pos);
    sfRectangleShape_setSize(rectangle, (sfVector2f)
    {prop_text.width + 50, prop_text.height + 50});
    return rectangle;
}

button_t create_button(const char *string, sfVector2f pos)
{
    button_t bouton;
    bouton.text = create_text_button(string, pos);
    bouton.rectangle = create_rectangle_button(pos, bouton);
    sfVector2f rect_size = sfRectangleShape_getSize(bouton.rectangle);
    sfRectangleShape_setOrigin(bouton.rectangle, (sfVector2f)
    {rect_size.x / 2, rect_size.y / 2});
    bouton.rect = sfText_getGlobalBounds(bouton.text);
    return bouton;
}

button_t *create_list_buttons(sfFloatRect rect_fond_flou)
{
    button_t *list_buttons = malloc(sizeof(button_t) * 2);
    list_buttons[0] = create_button("Jouer", (sfVector2f)
    {rect_fond_flou.width / 2, rect_fond_flou.height / 2});
    list_buttons[1] = create_button("EXIT", (sfVector2f)
    {rect_fond_flou.width / 2, rect_fond_flou.height / 2 + 100});
    return list_buttons;
}

void create_list_buttons_res(glob_t *v, sfFloatRect rect_fond_flou)
{
    button_t *list_buttons = malloc(sizeof(button_t) * 3);
    list_buttons[0] = create_button("800x600", (sfVector2f)
    {rect_fond_flou.width / 2 - 300, rect_fond_flou.height / 2 - 100});
    list_buttons[1] = create_button("Plein ecran", (sfVector2f)
    {rect_fond_flou.width / 2, rect_fond_flou.height / 2 - 100});
    list_buttons[2] = create_button("900x900", (sfVector2f)
    {rect_fond_flou.width / 2 + 300, rect_fond_flou.height / 2 - 100});
    v->settings_menu.list_res = list_buttons;
    v->settings_menu.text_resolution = create_text_button("Resolution:",
    (sfVector2f) {rect_fond_flou.width / 2, rect_fond_flou.height / 2 - 200});
    v->settings_menu.text_volume = create_text_button("Volume:",
    (sfVector2f) {rect_fond_flou.width / 2, rect_fond_flou.height / 2 + 25});
}
