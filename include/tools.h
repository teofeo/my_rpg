/*
** EPITECH PROJECT, 2023
** anim_csfml
** File description:
** tools
*/

#pragma once

int key_down(void);
int key_up(void);
int key_left(void);
int key_right(void);

char **str_to_word_array(char *str, char *delimiters);
void free_str_word_array(char **str_w);
int my_atoi(const char *str);
int my_strlen(const char *str);
char *my_strcat(const char *dest, const char *from);
char *int_to_string(int num);
char *my_strdup(char const *src);
