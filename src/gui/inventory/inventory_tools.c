/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "../../../include/my.h"

sfRectangleShape *create_square(sfVector2f pos,
sfVector2f size, sfColor color)
{
    sfRectangleShape *square = sfRectangleShape_create();
    sfRectangleShape_setSize(square, size);
    sfRectangleShape_setOrigin(square, (sfVector2f){size.x / 2,
    size.y / 2});
    sfRectangleShape_setFillColor(square, color);
    sfRectangleShape_setPosition(square, pos);
    sfRectangleShape_setOutlineThickness(square, 2);
    sfRectangleShape_setOutlineColor(square, sfTransparent);
    return square;
}

sfRectangleShape *create_img(sfVector2f pos, sfVector2f size, char *file)
{
    sfRectangleShape *square = sfRectangleShape_create();
    sfTexture *text = sfTexture_createFromFile(file, NULL);
    sfRectangleShape_setSize(square, size);
    sfRectangleShape_setOrigin(square, (sfVector2f){size.x / 2, size.y / 2});
    sfRectangleShape_setTexture(square, text, sfFalse);
    sfRectangleShape_setPosition(square, pos);
    return square;
}
