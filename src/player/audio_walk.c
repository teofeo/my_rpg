/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** audio_walk
*/

#include "../../include/my.h"

static int key_move_pressed(void)
{
    if (key_down() || key_left() || key_up() || key_right()) return (1);
    return (0);
}

void audio_walk(glob_t *v)
{
    sfSoundStatus status = sfMusic_getStatus(v->audios->walk);
    if (key_move_pressed() && status == sfStopped)
        sfMusic_play(v->audios->walk);
    if (!key_move_pressed() && status == sfPlaying)
        sfMusic_stop(v->audios->walk);
}
