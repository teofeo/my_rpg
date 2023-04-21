/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** my_strlen
*/

#include "../../include/my.h"

int my_strlen(const char *str)
{
    int i = 0;
    for (; str[i]; i++);
    return (i);
}
