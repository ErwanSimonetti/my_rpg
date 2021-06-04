/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** get_player_name.c
*/

#include "structure.h"
#include "chained_list.h"
#include "menu.h"
#include "rpg.h"
#include "lib.h"
#include <stdlib.h>

static const int DEL = -100;
static const int ENTER = -101;
static const int SIZE_LIMIT = 15;
static const char *ARTYPA = "assets/font/Artypa.ttf";

char *add_in_name(char *dest, char const src)
{
    char *new = malloc(my_strlen(dest) + 2);
    int i = 0;

    for (; dest[i] != '\0'; i += 1)
        new[i] = dest[i];
    new[i++] = src;
    new[i] = '\0';
    return new;
}

int draw_player_name(t_window *game, t_text **name)
{
    char to_add = game->event.text.unicode + 'a';

    if (to_add == DEL && my_strlen((*name)->str))
        (*name)->str[my_strlen((*name)->str) - 1] = '\0';
    else if (to_add == ENTER && my_strlen((*name)->str) > 0)
        return 1;
    else if (to_add != DEL && my_strlen((*name)->str) < SIZE_LIMIT && to_add >=
        'a' && to_add <= 'z')
        (*name)->str = add_in_name((*name)->str, to_add);
    sfText_setString((*name)->text, (*name)->str);
    return 0;
}

static int manage_poll_event(t_window *game, t_text *name)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtKeyPressed)
            if (draw_player_name(game, &name) == 1)
                return 1;
        if (game->event.type == sfEvtClosed)
            close_window(game);
    }
    return 0;
}

char *get_player_name(t_window *game)
{
    t_text *name = create_text("\0", (sfVector2f) {650, 505}, (sfVector2f)
            {1, 1}, ARTYPA);
    t_rect *box = create_rect((sfVector2f) {645, 500},
            (sfVector2f) {620, 45}, sfTransparent, sfWhite);

    name = add_text_inlist(name, create_text("What is your name ?",
    (sfVector2f) {700, 350}, (sfVector2f) {1, 1}, ARTYPA), len_list_text(name));
    while (sfRenderWindow_isOpen(game->window)) {
        if (manage_poll_event(game, name) == 1)
            return name->str;
        sfRenderWindow_clear(game->window, sfBlack);
        manage_window_info(game);
        draw_rectangle(&game->window, box);
        draw_text(game, name);
        sfRenderWindow_display(game->window);
    }
    return NULL;
}
