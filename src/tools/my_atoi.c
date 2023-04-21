/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** my_atoi
*/

#include "../../include/my.h"

int my_atoi(const char *str)
{
    int num = 0;
    for (int i = 0; str[i]; i++) {
        num *= 10;
        num += str[i] - 48;
    }
    return (num);
}
