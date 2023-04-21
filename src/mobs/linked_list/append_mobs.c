/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** append
*/

#include "../../../include/my.h"

static mob_t *create_node_mob(char **item)
{
    char *path = my_strcat("img/mobs/", item[6]);
    mob_t *node = malloc(sizeof(mob_t));
    sfVector2f position = {(float)my_atoi(item[0]), (float) my_atoi(item[1])};
    printf("X = %f | Y = %f\n", position.x, position.y);
    sfVector2f scale = {0, 0};
    sfVector2u size = {0, 0};
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();
    sfIntRect rect = {0, 0, 64, 64};

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
    size = sfTexture_getSize(texture);
    scale = (sfVector2f){150.0f / size.x, 150.0f / size.y};
    //sfSprite_setOrigin(sprite, (sfVector2f) {size.x / 2, size.y / 2});
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, position);
    node->sprite = sprite;
    node->id = my_strcpy(item[2]);
    node->hitbox = circle_fake(node, (sfVector2f) {0, 0});
    return (node);
}

void append_mobs(glob_t *v, char **item, places stage)
{
    mob_t *node = create_node_mob(item);
    node->next = NULL;
    node->stage = stage;
    node->dammage = my_atoi(item[2]);
    node->life = my_atoi(item[3]);
    node->delay = my_atoi(item[4]);
    node->speed = my_atoi(item[5]);
    mob_t *tmp = NULL;

    if (v->mobs == NULL)
        v->mobs = node;
    else {
        tmp = v->mobs;
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = node;
    }
}
