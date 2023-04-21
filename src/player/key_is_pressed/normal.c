/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** normal
*/

#include "../../../include/my.h"

int key_down(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) ||
    sfKeyboard_isKeyPressed(sfKeyS))
        return (1);
    return (0);
}

int key_up(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) ||
    sfKeyboard_isKeyPressed(sfKeyZ))
        return (1);
    return (0);
}

int key_left(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) ||
    sfKeyboard_isKeyPressed(sfKeyQ))
        return (1);
    return (0);
}

int key_right(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) ||
    sfKeyboard_isKeyPressed(sfKeyD))
        return (1);
    return (0);
}
