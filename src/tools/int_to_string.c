/*
** EPITECH PROJECT, 2023
** test
** File description:
** tets
*/

#include <stdlib.h>

char *int_to_string(int num)
{
    int i;
    int rem;
    int len = 0;
    int n;
    n = num;
    if (n == 0) n = 1;
    for (; n > 1; n /= 10) {
        len++;
    } len++;
    char *str = malloc(sizeof(char) * (len + 1));
    for (i = 0; i < len; i++) {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
    return str;
}
