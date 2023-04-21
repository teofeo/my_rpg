/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** colorcmp
*/

#include "../../include/my.h"

int colorcmp(sfColor c1, sfColor c2)
{
    if (c1.a != c2.a) return 84;
    if (c1.b != c2.b) return 84;
    if (c1.g != c2.g) return 84;
    if (c1.r != c2.r) return 84;
    return 0;
}
