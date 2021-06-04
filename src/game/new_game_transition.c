/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** new_game_transition.c
*/

#include "rpg.h"
#include "lib.h"
#include "menu.h"
#include "structure.h"
#include <stdlib.h>

static const char *STEPS = "assets/font/Steps.ttf";

static void manage_string(t_text *text, char *new_str, char const *talk,
    int pos_in_str)
{
    if (pos_in_str == my_strlen(talk))
        return;
    sfText_setString(text->text, new_str);
    new_str[pos_in_str] = talk[pos_in_str];
    new_str[pos_in_str + 1] = '\0';
}

void new_game_transition(t_window *game)
{
    sfUint8 shade = 255;
    char const *talk = "who am i ?";
    char *new_str = malloc(my_strlen(talk) + 1);
    float pos_in_str = 0;
    t_text *text = create_text("", (sfVector2f){800, 400}, (sfVector2f)
        {1.3, 1.3}, STEPS);
    sfClock *timer = sfClock_create();
    sfMusic_stop(game->sfx.menu_theme);

    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            if (game->event.type == sfEvtClosed)
                close_window(game);
        manage_string(text, new_str, talk, (int)pos_in_str);
        if (sfTime_asSeconds(sfClock_getElapsedTime(timer)) - pos_in_str / 10 >=
                0 && (int)pos_in_str < my_strlen(talk)) {
            sfSound_play(game->sfx.typing_sound);
            ++pos_in_str;
        }
        else if (pos_in_str == my_strlen(talk)) {
            if (sfTime_asMicroseconds(sfClock_getElapsedTime(timer)) >= 1 && shade > 0) {
                sfText_setColor(text->text, (sfColor) {255, 255, 255, shade--});
                sfClock_restart(timer);
            } else
                return;
        }
        sfRenderWindow_clear(game->window, sfBlack);
        draw_text(game, text);
        sfRenderWindow_display(game->window);
    }
}