/*
** EPITECH PROJECT, 2023
** test
** File description:
** etes
*/

#include "../../../include/my.h"

void change_item(glob_t *v)
{
    if (v->evt.mouseWheelScroll.delta == 1) {
        v->inventory->item_index++;
        if (v->inventory->item_index == 5)
            v->inventory->item_index = 0;
    }
    if (v->evt.mouseWheelScroll.delta == -1) {
        v->inventory->item_index--;
        if (v->inventory->item_index == -1)
            v->inventory->item_index = 4;
    }
}
