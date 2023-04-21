/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** my_in_to_str
*/
#include <stdlib.h>
#include <stdio.h>
char *my_revstr(char *str);

int len_int(int nb)
{
    int compt = 0;
    for (; nb != 0 ; compt++) {
        nb = nb / 10;
    }
    return compt;
}

char *int_to_str(int nb)
{
    int len_nbr = len_int(nb);
    char *str = malloc(sizeof(char) * len_nbr + 1);
    for (int i = 0; i != len_nbr; i++) {
        str[i] = (nb % 10) + 48;
        nb = nb / 10;
    }
    str[len_nbr] = '\0';
    return my_revstr(str);
}
