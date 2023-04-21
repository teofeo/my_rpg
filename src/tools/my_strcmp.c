/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** my_strcmp
*/

#include "../../include/my.h"

int my_strcmp(const char *s1, const char *s2)
{
    if (my_strlen(s1) != my_strlen(s2)) return 84;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i]) return 84;
    }
    return 0;
}
