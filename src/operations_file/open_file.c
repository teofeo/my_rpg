/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** open_file
*/

#include "../../include/my.h"

int open_file(const char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return (-1);
    return (fd);
}
