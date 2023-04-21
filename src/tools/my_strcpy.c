/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** my_strcpy
*/

#include "../../include/my.h"

char *my_strcpy(const char *str)
{
    int len = my_strlen(str);
    char *new = malloc(sizeof(char) * (len + 1));

    for (int i = 0; str[i]; i++)
        new[i] = str[i];
    new[len] = '\0';
    return (new);
}
