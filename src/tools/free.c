/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** free
*/

#include "../../include/my.h"

void free_str_word_array(char **str_w)
{
    for (int i = 0; str_w[i]; i++)
        free(str_w[i]);
    free(str_w);
}
