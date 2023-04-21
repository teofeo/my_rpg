/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** my_strcat
*/

#include "../../include/my.h"

char *my_strcat(const char *dest, const char *from)
{
    int total = my_strlen(dest) + my_strlen(from);
    int j = 0;
    char *new = malloc(sizeof(char) * (total + 1));
    for (int i = 0; dest[i]; i++, j++)
        new[j] = dest[i];
    for (int i = 0; from[i]; i++, j++)
        new[j] = from[i];
    new[total] = '\0';
    return (new);
}
