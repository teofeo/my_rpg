/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** append
*/

#include "../../../include/my.h"

static item_t *create_node(char **item)
{
    char *path = my_strcat("img/items/", item[2]);
    item_t *node = malloc(sizeof(item_t));
    sfVector2f position = {(float)my_atoi(item[0]), (float) my_atoi(item[1])};
    sfVector2f scale = {0, 0};
    sfVector2u size = {0, 0};
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    size = sfTexture_getSize(texture);
    scale = (sfVector2f){12.0f / size.x, 12.0f / size.y};
    sfSprite_setOrigin(sprite, (sfVector2f) {size.x / 2, size.y / 2});
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, position);
    node->position = position;
    node->scale = scale;
    node->sprite = sprite;
    node->id = my_strcpy(item[2]);
    return (node);
}

void append_item(glob_t *v, char **item, places stage)
{
    item_t *node = create_node(item);
    node->next = NULL;
    node->active = sfTrue;
    node->up = 1;
    node->down = 0;
    node->stage = stage;
    item_t *tmp = NULL;

    if (v->items == NULL)
        v->items = node;
    else {
        tmp = v->items;
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = node;
    }
}
