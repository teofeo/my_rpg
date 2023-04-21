/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include "../include/my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    int count = my_strlen(src);
    char *new = malloc(sizeof(char) * (count + 1));
    for (; i < count; i++)
        new[i] = src[i];
    new[i] = '\0';
    return (new);
}
