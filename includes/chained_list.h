/*
** EPITECH PROJECT, 2021
** chained_list.h
** File description:
** chained_list's prototype
*/

#include "structure.h"

#ifndef CHAINED_LIST
#define CHAINED_LIST

int len_list_text(t_text *list);
int len_list_rect(t_rect *list);
int len_list_sprite(t_sprite *list);
t_text *create_text(char *str, sfVector2f pos, sfVector2f scale,
                const char *filepath);
t_text *add_text_inlist(t_text *buttons, t_text *element, int pos);
t_sprite *create_sprite(char *filepath, sfVector2f pos, sfVector2f scale);
t_sprite *add_sprite_inlist(t_sprite *gui, t_sprite *element,
                            int pos);
t_sprite *free_sprite_in_list(t_sprite *list, int pos);
t_rect *create_rect(sfVector2f pos, sfVector2f size,
        sfColor colorFill, sfColor colorOutline);
t_rect *add_rectangle_inlist(t_rect *rect, t_rect *element,
                int pos);
void draw_text(t_window *game, t_text *buttons);
void draw_text_animated(t_window *game, t_text *buttons);
void draw_sprite(sfRenderWindow **window, t_sprite *gui);
void draw_rectangle(sfRenderWindow **window, t_rect *rect);
void draw_rectangle_animated(t_window *game, t_rect *rect);
t_rect *free_rect_in_list(t_rect *list, int pos);

#endif /* !CHAINED_LIST */
