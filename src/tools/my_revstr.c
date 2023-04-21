/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** day 6 / task03
*/

int my_strlen2(char const *str)
{
    int compteur = 0;
    for (int index = 0; str[index] != '\0'; index++) {
        compteur++;
    }
    return compteur;
}

char *my_revstr(char *str)
{
    char arr[my_strlen2(str) + 1];
    int omy = 0;
    arr[my_strlen2(str)] = '\0';
    for (int index2 = 0; str[index2] != '\0'; index2++) {
        arr[index2] = str[index2];
    }
    for (int index = my_strlen2(str) - 1 ; index >= 0; index--) {
        str[index] = arr[omy];
        omy++;
    }
    return (str);
}
