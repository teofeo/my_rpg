/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** go_in_fight
*/

#include "../../include/my.h"

void skipentity(linked_list_enemy_t **head_ref, entity_t entite)
{
    linked_list_enemy_t* temp = *head_ref, *prev;
    if (temp != NULL && temp->entite.id == entite.id) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->entite.id != entite.id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void move_it(glob_t *v, sfFloatRect rect_p, linked_list_enemy_t *tmp)
{
    sfFloatRect rect_e = sfSprite_getGlobalBounds(tmp->entite.sprite);
    if (sfFloatRect_intersects(&rect_p, &rect_e, NULL)) {
        v->list_enemy = push_back(v->list_enemy, tmp->entite);
        skipentity(&v->list_afk, tmp->entite);
    }
}

void go_in_fight(glob_t *v)
{
    sfFloatRect rect_p = sfSprite_getGlobalBounds(v->player);
    linked_list_enemy_t *tmp = v->list_afk;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->entite.stage == v->stage) {
            move_it(v, rect_p, tmp);
        }
    }
}
