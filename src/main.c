/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** main
*/

#include "../include/my.h"

static void change_size_view(glob_t *v)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(v->win);
    sfVector2f center = sfView_getCenter(v->view);
    sfVector2u win_size = sfRenderWindow_getSize(v->win);
    if (v->evt.mouseWheelScroll.delta == 1) {
        v->view_s.x -= 50;
        v->view_s.y -= 50;
        center.x -= (((float) win_size.x / 2) - mouse.x) / 15;
        center.y -= (((float) win_size.y / 2) - mouse.y) / 15;
    }
    if (v->evt.mouseWheelScroll.delta == -1) {
        v->view_s.x += 50;
        v->view_s.y += 50;
        center.x += (((float) win_size.x / 2) - mouse.x) / 15;
        center.y += (((float) win_size.y / 2) - mouse.y) / 15;
    }
}

static void my_event(glob_t *v)
{
    while (sfRenderWindow_pollEvent(v->win, &v->evt)) {
        sfVector2i posi = sfMouse_getPositionRenderWindow(v->win);
        v->pos_mouse = sfRenderWindow_mapPixelToCoords(v->win, posi, v->view);
        if (v->evt.type == sfEvtClosed)
            sfRenderWindow_close(v->win);
        if (v->evt.type == sfEvtMouseWheelScrolled) {
            change_size_view(v);
            change_item(v);
        }
        display_hitbox_event(v);
        resize_window_change_view(v, 0);
        if (v->stage == START_M)
            event_on_buttons(v, v->evt);
        if (v->stage == SETTINGS)
            event_on_settings(v, v->evt);
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            go_to_menu_start(v);
        event_full_screen(v, 0);
    }
}

void malloc_struct(glob_t *v)
{
    v->inventory = malloc(sizeof(inventory_t));
    v->inventory->inventory_button = malloc(sizeof(inventory_button_t*) * 5);
    for (int i = 0; i != 5; i++) {
        v->inventory->inventory_button[i] = malloc(sizeof(inventory_button_t));
    }
    v->cara = malloc(sizeof(caracteristique_t));
    v->cara->node = malloc(sizeof(node_t*) * 3);
    for (int i = 0; i != 3; i++) {
        v->cara->node[i] = malloc(sizeof(node_t));
    }
    v->shop = malloc(sizeof(shop_t));
    v->shop->node = malloc(sizeof(node_shop_t*) * 3);
    for (int i = 0; i != 3; i++) {
        v->shop->node[i] = malloc(sizeof(node_shop_t));
    }
}

static void run_in_game(glob_t *v)
{
    if (v->stage != START_M && v->stage != LOADING_GAME
    && v->stage != SETTINGS) {
        player_event(v);
        pnj_event(v);
        move_bot(v);
        attaque_bot(v);
    }
    if (v->enti_player.life <= 0)
        v->stage = START_M;
}

int main(void)
{
    glob_t *v = malloc(sizeof(glob_t));

    malloc_struct(v);
    init_main(v);
    entity_t enemy = create_fake_mob(v);
    v->list_afk = push_back(v->list_afk, enemy);
    if (load_items(v) < 0 || load_pnj(v) < 0 || load_mobs(v) < 0)
        return (84);
    while (sfRenderWindow_isOpen(v->win)) {
        v->delta = sfClock_restart(v->clock).microseconds / 1000000.0;
        my_event(v);
        run_in_game(v);
        displays(v);
        sfRenderWindow_display(v->win);
        sfRenderWindow_clear(v->win, sfBlack);
    }
    return (0);
}
