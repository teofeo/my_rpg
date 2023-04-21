/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "../../../include/my.h"

sfCircleShape *create_circle_hitbox(char **pnj, sfSprite *sprite)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfCircleShape_setRadius(circle, (float)my_atoi(pnj[3]));
    sfVector2f center = {(my_atoi(pnj[3])), (my_atoi(pnj[3]))};
    sfVector2f pos_circle = {sfSprite_getPosition(sprite).x,
    sfSprite_getPosition(sprite).y};
    sfCircleShape_setOrigin(circle, center);
    sfCircleShape_setPosition(circle, pos_circle);
    return circle;
}

sfSprite *create_letter_sprite(sfSprite *character)
{
    sfSprite *r = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile
    ("img/letter/r_letter.png", NULL);
    sfVector2f pos = {sfSprite_getPosition(character).x,
    sfSprite_getPosition(character).y - 30};
    sfSprite_setTexture(r, text, sfFalse);
    sfSprite_setPosition(r, pos);
    sfSprite_setOrigin(r, (sfVector2f){256, 256});
    sfSprite_setScale(r, (sfVector2f){0.03, 0.03});
    return r;
}

static sfText *create_dialogue(void)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("font/test.otf");
    sfText_setCharacterSize(text, 20);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    return text;
}

static pnj_t *create_node_pnj(char **pnj)
{
    char *path = my_strcat("img/pnj/", pnj[2]);
    pnj_t *node = malloc(sizeof(pnj_t));
    sfVector2f position = {(float)my_atoi(pnj[0]), (float) my_atoi(pnj[1])};
    sfVector2f scale;
    sfVector2u size = {0, 0};
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfFalse);
    size = sfTexture_getSize(texture);
    scale = (sfVector2f){25.f / size.x, 30.f / size.y};
    sfSprite_setOrigin(sprite, (sfVector2f) {size.x / 2, size.y / 2});
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, position);
    node->hitbox = sfCircleShape_getGlobalBounds
    (create_circle_hitbox(pnj, sprite));
    node->sprite = sprite;
    node->pnj_dialogue = my_strdup(pnj[4]);
    node->letter = create_letter_sprite(sprite);
    node->dialogue = create_dialogue();
    node->next = NULL; return (node);
}

void append_pnj(glob_t *v, char **pnj, places stage)
{
    pnj_t *node = create_node_pnj(pnj);
    node->stage = stage;
    pnj_t *tmp = NULL;

    if (v->pnj == NULL)
        v->pnj = node;
    else {
        tmp = v->pnj;
        tmp->state = NONE;
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = node;
    }
}
