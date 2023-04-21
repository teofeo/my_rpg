/*
** EPITECH PROJECT, 2023
** test
** File description:
** tets
*/

#include "../../../include/my.h"

static void background_inventory_init(glob_t *v)
{
    v->inventory->background = sfRectangleShape_create();
    sfRectangleShape_setSize(v->inventory->background, (sfVector2f){300, 70});
    sfRectangleShape_setOrigin(v->inventory->background, (sfVector2f){150, 25});
    sfRectangleShape_setFillColor(v->inventory->background,
    sfColor_fromRGB(38, 49, 84));
    sfRectangleShape_setPosition(v->inventory->background,
    (sfVector2f){sfView_getSize(v->view).x / 2,
    sfView_getSize(v->view).y - 20});
    v->inventory->view = sfView_create();
    sfView_setSize(v->inventory->view, (sfVector2f){1920, 1080});
}

static void inventory_img_init(glob_t *v, sfVector2f pos)
{
    sfVector2f size = {32, 32};
    v->inventory->inventory_button[0]->img =
    create_img((sfVector2f){pos.x - 294, pos.y}, size,
    "img/inventory/poing.png");
    v->inventory->inventory_button[1]->img =
    create_img((sfVector2f){pos.x - 235, pos.y}, size,
    "img/inventory/batte-de-baseball.png");
    v->inventory->inventory_button[2]->img =
    create_img((sfVector2f){pos.x - 176, pos.y}, size,
    "img/inventory/couteau.png");
    v->inventory->inventory_button[3]->img =
    create_img((sfVector2f){pos.x - 117, pos.y}, size,
    "img/inventory/biere.png");
    v->inventory->inventory_button[4]->img =
    create_img((sfVector2f){pos.x - 58, pos.y}, size,
    "img/inventory/?.png");
}

static void inventory_case_init(glob_t *v)
{
    v->inventory->item_index = 0;
    sfVector2f pos = {sfView_getSize(v->view).x / 2 - 117,
    sfView_getSize(v->view).y - 10};
    for (int i = 0; i != 5; i++) {
        v->inventory->inventory_button[i]->index = i;
        v->inventory->inventory_button[i]->square = create_square(pos,
        (sfVector2f){54, 54}, sfColor_fromRGB(82, 90, 117));
        pos.x += 59;
    } inventory_img_init(v, pos);
}

void init_inventory(glob_t *v)
{
    background_inventory_init(v);
    inventory_case_init(v);
}
