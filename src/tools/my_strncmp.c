/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** my_strncmp
*/

#include "../../include/my.h"

int my_strncmp(const char *model, const char *comp, int start, char end)
{
    int len_comp = my_strlen(comp);
    int len_model = my_strlen(model);
    int neutral = 0;

    if (len_comp > len_model - start) return (-2);
    for (int i = start; model[i] != end; i++, neutral++) {
        if (model[i] != comp[neutral])
            return (-1);
    }
    return (0);
}
