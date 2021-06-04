/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** window.c
*/

#include "rpg.h"
#include "menu.h"
#include "lib.h"
#include <stdio.h>

void close_window(t_window *game)
{
    sfRenderWindow_close(game->window);
    sfMusic_destroy(game->sfx.menu_theme);
    sfMusic_destroy(game->sfx.game_theme);
    sfMusic_destroy(game->sfx.combat_theme);
    sfSound_destroy(game->sfx.launch_game);
    sfSoundBuffer_destroy(game->sfx.launch_game_buffer);
    sfSound_destroy(game->sfx.typing_sound);
    sfSoundBuffer_destroy(game->sfx.typing_sound_buffer);
    sfSound_destroy(game->sfx.success_sound);
    sfSoundBuffer_destroy(game->sfx.success_sound_buffer);
    sfSound_destroy(game->sfx.game_over);
    sfSoundBuffer_destroy(game->sfx.game_over_buffer);
}

void window(void)
{
    t_window game;
    t_clock clock;
    t_infoGame info;

    window_init(&game);
    clock_init(&clock);
    info_init(&info);
    while (sfRenderWindow_isOpen(game.window)) {
        test_display(&game, &clock, &info);
    }
    sfRenderWindow_destroy(game.window);
}
