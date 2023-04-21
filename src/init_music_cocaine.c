/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** init_sound
*/

#include "../include/my.h"

void init_music_cocaine(glob_t *v)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile("audio/cocaine.ogg");
    sfSound_setBuffer(sound, buffer);
    v->audios->cocaine = sound;
}
