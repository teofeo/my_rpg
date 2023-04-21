/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** push_back
*/

#include "../../include/my.h"

linked_list_enemy_t *push_back(linked_list_enemy_t *list, entity_t val)
{
    linked_list_enemy_t *a = malloc(sizeof(linked_list_enemy_t));
    a->entite = val;
    a->next = NULL;
    linked_list_enemy_t *tmp = list;
    if (list == NULL) return a;
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = a;
    return list;
}
