/*
** EPITECH PROJECT, 2023
** test
** File description:
** shop_event
*/

#include "../../include/my.h"

void add_stat(glob_t *v, int index, int stat)
{
    int thune = (stat - 1) * 10;
    sfText_setString(v->shop->node[index]->var_niv_b, int_to_string(stat));
    sfText_setString(v->shop->node[index]->var_niv_a, int_to_string(stat + 1));
    sfText_setString(v->shop->node[index]->price, my_strcat(int_to_string
    (stat * 10), "$"));
    v->cara->var_money -= thune; 
    sfText_setString(v->inventory->money_nbr,
    int_to_string(v->cara->var_money));
}

int reload_stat(glob_t *v, int index)
{
    if (index == 0) {
        if (v->cara->var_money - (v->cara->poing_lvl * 10) < 0) {
            v->shop->bool_error = 1;
            return 1;
        } v->cara->poing_lvl++;
        add_stat(v, index, v->cara->poing_lvl);
    } if (index == 1) {
        if (v->cara->var_money - (v->cara->baton_lvl * 10) < 0) {
            v->shop->bool_error = 1;
            return 1;
        } v->cara->baton_lvl++;
        add_stat(v, index, v->cara->baton_lvl);
    } if (index == 2) {
        if (v->cara->var_money - (v->cara->couteau_lvl * 10) < 0) {
            v->shop->bool_error = 1;
            return 1;
        } v->cara->couteau_lvl++;
        add_stat(v, index, v->cara->couteau_lvl);
    } v->shop->node[index]->state = HOVER;
    v->shop->bool_error = 0;
    return 0;
}

void shop_menu_event(glob_t *v)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(v->win);
    sfVector2f test = sfRenderWindow_mapPixelToCoords(v->win, pos, v->inventory->view);
    for (int i = 0; i != 3; i++) {
        if (sfFloatRect_contains(&(v->shop->node[i]->buy_hitbox), test.x, test.y)) {
            if (sfMouse_isButtonPressed(sfMouseLeft))
                v->shop->node[i]->state = PRESSED;
            if (v->shop->node[i]->state != PRESSED)
                v->shop->node[i]->state = HOVER;
            if (v->shop->node[i]->state == PRESSED && v->evt.type == sfEvtMouseButtonReleased) {
                reload_stat(v, i);
                v->shop->node[i]->state = HOVER;
            }
        }
        else {
            v->shop->node[i]->state = NONE;
        }
    }
}

void shop_event(glob_t *v)
{
    if (sfFloatRect_intersects(&(v->hitbox_hero), &(v->shop->hitbox), NULL)) {
        if (sfKeyboard_isKeyPressed(sfKeyR)) {
            v->shop->state = PRESSED;
        }
        if ((v->shop->state != PRESSED)) {
            v->shop->state = HOVER;
        }
    } else {
        v->shop->state = NONE;
    }
    if (v->shop->state == PRESSED) {
        shop_menu_event(v);
    }
}
