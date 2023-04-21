/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** read_file
*/

#include "../../include/my.h"

static int get_size_of_file(const char *path)
{
    struct stat sb;

    if (stat(path, &sb) < 0)
        return (-1);
    return (sb.st_size);
}

char **read_file(const char *path)
{
    int fd = 0;
    int sz_file = 0;
    char *buf = NULL;
    char **buffer = NULL;
    int sz = 0;

    fd = open_file(path);
    if (fd == -1) return (NULL);
    sz_file = get_size_of_file(path);
    if (sz_file == -1) return (NULL);
    buf = malloc(sizeof(char) * (sz_file + 1));
    if (buf == NULL) return (NULL);
    sz = read(fd, buf, sz_file);
    if (sz < 0) return (NULL);
    buf[sz] = '\0';
    buffer = str_to_word_array(buf, "\n");
    if (buffer == NULL) return (NULL);
    return (buffer);
}
