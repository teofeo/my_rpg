/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** my
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <fcntl.h>

#include "tools.h"
#include "items.h"
#include "stage.h"
#include "caracteristique.h"
#include "inventory.h"
#include "pnj.h"
#include "shop.h"
#include "mobs.h"

typedef struct audio_s {
    sfMusic *walk;
    sfSound *sword_hit;
    sfSound *sword_miss;
    sfSound *die_sword;
    sfSound *cocaine;
    sfSound *son_fond;
} audio_t;

typedef struct button_s {
    sfRectangleShape *rectangle;
    sfFloatRect rect;
    sfText *text;
    sfVector2f position;
} button_t;

typedef struct menu_s {
    sfSprite *sprite_fond;
} menu_t;

typedef struct volume_s {
    sfRectangleShape *ligne;
    sfRectangleShape *barre;
    sfText *text;
} volume_t;

typedef struct reso_s {
    button_t *list_res;
} reso_t;

typedef struct settings_s {
    volume_t volume;
    button_t bout_back;
    button_t *list_res;
    sfText *text_resolution;
    sfText *text_volume;
}settings_t;

typedef struct dead_s {
    sfSprite *sprite;
}dead_t;


typedef struct engrenage_s {
    sfRectangleShape *rectangle;
    sfFloatRect rect;
    sfClock *clock;
    sfSprite *sprite;
}engrenange_t;

typedef struct start_stage_s {
    sfSprite *background;
    sfSprite *loading_sprite;
    sfRectangleShape *loading_rect;
    sfRectangleShape *loading_bar;
    engrenange_t sett;
} start_stage_t;

typedef struct entity_s {
    sfCircleShape *hitbox;
    float delay;
    int life;
    int dammage;
    sfSprite *sprite;
    sfClock *clock_attack;
    places stage;
    int speed;
    int id;
} entity_t;

typedef struct linked_list_enemy_s  {
    entity_t entite;
    struct linked_list_enemy_s *next;
} linked_list_enemy_t;

typedef struct linked_list_afk_s {
    entity_t entite;
    struct linked_list_afk *next;
} linked_list_afk_t;

typedef struct glob_s {
    sfRenderWindow *win;
    sfEvent evt;
    sfSprite *map;
    sfSprite *map_sprite_hit;
    sfImage *map_h;
    sfView *view;
    sfVector2f view_s;
    sfClock *clock;
    sfSprite *player;
    settings_t settings_menu;
    entity_t enti_player;
    sfVector2u player_s;
    sfRectangleShape *player_b;
    linked_list_enemy_t *list_enemy;
    linked_list_enemy_t *list_afk;
    sfVector2f pos_mouse;
    item_t *items;
    places stage;
    audio_t *audios;
    dead_t dead;
    menu_t menu;
    button_t *list_buttons;
    int dialogue_pos_pnj;
    sfFloatRect hitbox_hero;
    sfRectangleShape *player_square;
    pnj_t *pnj;
    float delta_pnj;
    float time_pnj;

    shop_t *shop;
    start_stage_t *start;
    float delta;
    float time;

    caracteristique_t *cara;
    inventory_t *inventory;
    sfBool full_screen;
    mob_t *mobs;
} glob_t;

typedef struct new_position_player_door {
    sfVector2f position;
    places from;
    places dest;
} posi_player_door;

typedef struct door_position_s {
    sfFloatRect dim;
    places from;
    places dest;
} door_position_t;

void player_event(glob_t *v);
void init_player(glob_t *v);

char **read_file(const char *path);
int open_file(const char *path);

int load_items(glob_t *v);
void append_item(glob_t *v, char **item, places stage);
void display_items(glob_t *v);

void init_inventory(glob_t *v);
void display_inventory(glob_t *v);
sfRectangleShape *create_square(sfVector2f pos,
sfVector2f size, sfColor color);
sfRectangleShape *create_img(sfVector2f pos, sfVector2f size, char *file);
void change_item(glob_t *v);
void init_gui(glob_t *v);
void display_gui(glob_t *v);

void init_caracteristique(glob_t *v);
void display_caracteristique(glob_t *v);

void weapons_text(glob_t *v);
void weapons_img(glob_t *v);

int load_pnj(glob_t *v);
int load_pnj(glob_t *v);
char **read_file_pnj(const char *path);
void append_pnj(glob_t *v, char **pnj, places stage);
void display_pnj(glob_t *v);
void pnj_event(glob_t *v);
linked_list_enemy_t *push_back(linked_list_enemy_t *list, entity_t val);

void attaque(glob_t *v);
void move_bot(glob_t *v);
void go_in_fight(glob_t *v);
/* csfml help tools*/
sfText *create_text(char *string, int size, sfVector2f pos);

/* Tool for get position player/view and size view */
void get_position(glob_t *v);

int possible_to_move_check(glob_t *v, sfVector2f rect_p);

void resize_window_change_view(glob_t *v, int manual);

void verification_in_door(glob_t *v);
void change_stage(glob_t *v);

void init_shop(glob_t *v);
void draw_shop(glob_t *v);
void shop_event(glob_t *v);
sfSprite *create_letter_sprite(sfSprite *character);

void init_all_audio(glob_t *v);
void audio_walk(glob_t *v);
void init_main(glob_t *v);
int my_strncmp(const char *model, const char *comp, int start, char end);

void displays(glob_t *v);
void init_loading_game(glob_t *v);
void skipentity(linked_list_enemy_t** head_ref, entity_t entite);
entity_t create_fake_mob(glob_t *v);
void menu(glob_t *v);
void init_menu(glob_t *v);
int mouseisinrect(sfFloatRect rect, sfVector2f MousePo);
void event_on_buttons(glob_t *v, sfEvent event);
int colorcmp(sfColor c1, sfColor c2);
button_t *create_list_buttons(sfFloatRect rect_fond_flou);
void show_all_buttons(glob_t *v);
int my_strcmp(const char *s1, const char *s2);
void settings(glob_t *v);
void init_music_cocaine(glob_t *v);
char *my_strcpy(const char *str);
void event_items(glob_t *v);
void init_settings_menu(glob_t *v);
void event_on_settings(glob_t *v, sfEvent event);
char *int_to_str(int nb);
button_t create_button(const char *string, sfVector2f pos);
void show_button(button_t bouton, glob_t *v);
void create_list_buttons_res(glob_t *v, sfFloatRect rect_fond_flou);
void update_buttons_res(glob_t *v);
void change_pressed_button(glob_t *v, int i, sfColor color_clic);
void attaque_bot(glob_t *v);
void change_window(glob_t *v);
void go_to_menu_start(glob_t *v);
void init_default_win(glob_t *v);
void change_full_screen(glob_t *v);
void event_full_screen(glob_t *v, int manual);
void display_hitbox_event(glob_t *v);
void append_mobs(glob_t *v, char **item, places stage);
void loading_bar(glob_t *v);
int load_mobs(glob_t *v);
void display_mobs(glob_t *v);
sfCircleShape *circle_fake(mob_t *enemy, sfVector2f ori);
