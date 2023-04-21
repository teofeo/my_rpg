/*
** EPITECH PROJECT, 2023
** test
** File description:
** node
*/

#include "../../../include/my.h"

static void create_weapons_cara(node_t **node, char *filename, sfVector2f pos)
{
    (*node)->img = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);
    sfSprite_setTexture((*node)->img, texture, sfFalse);
    sfSprite_setPosition((*node)->img, pos);
    sfSprite_setScale((*node)->img, (sfVector2f){0.11, 0.11});
}

void weapons_text(glob_t *v)
{
    v->cara->node[0]->title = create_text("Poing", 20,
    (sfVector2f){320, 585});
    v->cara->node[1]->title = create_text("Batton", 20,
    (sfVector2f){460, 585});
    v->cara->node[2]->title = create_text("Couteau", 20,
    (sfVector2f){600, 585});
    v->cara->node[0]->niveau_txt = create_text("Niv :", 15,
    (sfVector2f){300, 615});
    v->cara->node[1]->niveau_txt = create_text("Niv :", 15,
    (sfVector2f){440, 615});
    v->cara->node[2]->niveau_txt = create_text("Niv :", 15,
    (sfVector2f){580, 615});
    v->cara->node[0]->degat_txt = create_text("Degat :", 15,
    (sfVector2f){300, 635});
    v->cara->node[1]->degat_txt = create_text("Degat :", 15,
    (sfVector2f){440, 635});
    v->cara->node[2]->degat_txt = create_text("Degat :", 15,
    (sfVector2f){580, 635});
}

void weapons_img(glob_t *v)
{
    create_weapons_cara(&(v->cara->node[0]),
    "img/inventory/poing.png",
    (sfVector2f){315, 525});
    create_weapons_cara(&(v->cara->node[1]),
    "img/inventory/batte-de-baseball.png",
    (sfVector2f){475, 525});
    create_weapons_cara(&(v->cara->node[2]),
    "img/inventory/couteau.png",
    (sfVector2f){615, 525});
}
