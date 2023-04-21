/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** mouse_is_in_rect
*/

#include "../include/my.h"

int mouseisinrect(sfFloatRect rect, sfVector2f MousePo)
{
    if ((MousePo.x >= rect.left && MousePo.x <= rect.left + rect.width) &&
    (MousePo.y >= rect.top && MousePo.y <= rect.top + rect.height)) {
        return 1;
    }
    return 0;
}
