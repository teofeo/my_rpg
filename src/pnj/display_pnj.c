/*
** EPITECH PROJECT, 2023
** ts
** File description:
** tes
*/

#include "../../include/my.h"

sfText *text_create(char *str)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("font/test.otf");
    sfText_setCharacterSize(text, 40);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setString(text, str);
    sfVector2f center = {sfText_getGlobalBounds(text).width / 2,
    sfText_getGlobalBounds(text).height / 2};
    sfText_setOrigin(text, center);
    sfText_setPosition(text, (sfVector2f){500, 900});
    return text;
}

int fill_string(glob_t *v, pnj_t **tmp)
{
    int i = 0;
    int j = 0;
    for (; j < v->dialogue_pos_pnj; j++);
    char *temp = malloc(sizeof(char) * (j + 1));
    for (; i < v->dialogue_pos_pnj; i++) {
        temp[i] = (*tmp)->pnj_dialogue[i];
    } temp[i] = '\0';
    ((*tmp)->dialogue) = text_create(temp);
    if ((*tmp)->pnj_dialogue[v->dialogue_pos_pnj] == '\0') {
        return 1;
    }
    return 0;
}

int clock_pnj(glob_t *v, pnj_t **tmp)
{
    v->delta_pnj = sfClock_restart(v->clock).microseconds / 1000000.0;
    v->time_pnj += v->delta_pnj;
    while (v->time_pnj > 0.1) {
        if (fill_string(v, &(*tmp)) == 1) {
            return 1;
        }
        v->dialogue_pos_pnj++;
        v->time_pnj -= 0.005;
    }
    return 0;
}

void verif_area(glob_t *v, pnj_t **tmp)
{
    if ((*tmp)->state == HOVER) {
        sfRenderWindow_drawSprite(v->win, (*tmp)->letter, NULL);
        sfRenderWindow_setView(v->win, v->inventory->view);
        sfRenderWindow_drawText(v->win, (*tmp)->dialogue, NULL);
        sfRenderWindow_setView(v->win, v->view);
    }
    if ((*tmp)->state == PRESSED) {
        if (clock_pnj(v, &(*tmp)) == 1) {
            (*tmp)->state = PASSED;
            v->dialogue_pos_pnj = 0;
        }
        sfRenderWindow_setView(v->win, v->inventory->view);
        sfRenderWindow_drawText(v->win, (*tmp)->dialogue, NULL);
        sfRenderWindow_setView(v->win, v->view);
    }
    sfRenderWindow_drawSprite(v->win, (*tmp)->sprite, NULL);
}

void display_pnj(glob_t *v)
{
    pnj_t *tmp = v->pnj;
    for (; tmp; tmp = tmp->next) {
        if (tmp->stage == v->stage)
            verif_area(v, &tmp);
    }
    if (v->stage == SHOP) {
        draw_shop(v);
    }
}
