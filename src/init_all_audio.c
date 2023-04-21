/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** walk
*/

#include "../include/my.h"

sfSound *create_sound(const char *path)
{
    sfSound *son = sfSound_create();
    sfSoundBuffer *buff = sfSoundBuffer_createFromFile(path);
    sfSound_setBuffer(son, buff);
    return son;
}

void init_all_audio(glob_t *v)
{
    v->audios = malloc(sizeof(audio_t));
    v->audios->walk = sfMusic_createFromFile("audio/walk.ogg");
    sfMusic_setLoop(v->audios->walk, 1);
    v->audios->sword_hit = create_sound("audio/hit_swoosh.ogg");
    v->audios->sword_miss = create_sound("audio/miss_swoosh.ogg");
    v->audios->die_sword = create_sound("audio/die_sword.ogg");
    v->audios->son_fond = create_sound("audio/music.ogg");
    //sfSound_play(v->audios->son_fond);
    sfSound_setLoop(v->audios->son_fond, sfTrue);
}
