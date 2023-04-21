/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** load
*/

#include "../../include/my.h"

static const load_file_stage_t corespond_stage[] = {
    {"spawn", SPAWN},
    {"cellar", CELLAR},
    {"bedroom", BEDROOM},
    {"map", MAP},
    {"basic-fit", BASIC_FIT},
    {"docks", DOCKS},
    {"night-club", NIGHT_CLUB},
    {"zara", ZARA},
    {NULL, ZERO}
};

static void extract_associate_stage_items(glob_t *v, char **file, int index)
{
    places stage_select = ZERO;
    const char *error = "Wrong stage give\n";
    char **each = NULL;

    for (int i = 0; corespond_stage[i].str; i++) {
        if (my_strncmp(file[index - 1], corespond_stage[i].str, 1, '\0') == 0)
            stage_select = corespond_stage[i].stage;
    }
    if (stage_select == ZERO) {
        write(2, error, my_strlen(error));
        return;
    }
    while (file[index][0] != '#') {
        each = str_to_word_array(file[index], " \t");
        append_item(v, each, stage_select);
        free_str_word_array(each);
        index += 1;
    }
}

int load_items(glob_t *v)
{
    char **file = read_file("txt/items.txt");
    v->items = NULL;

    for (int i = 0; file[i]; i++)
        if (file[i][0] == '#' && file[i + 1])
            extract_associate_stage_items(v, file, i + 1);
    free_str_word_array(file);
    return (0);
}
