/*
** EPITECH PROJECT, 2021
** combat.c
** File description:
** functions related to combat
*/

#include <stdio.h>
#include "rpg.h"
#include "structure.h"

static void init_combat(t_window *game, t_infoGame *info)
{
    sfMusic_setLoop(game->sfx.combat_theme, sfTrue);
    if (sfMusic_getStatus(game->sfx.game_theme) == sfPlaying) {
        sfMusic_stop(game->sfx.game_theme);
        sfMusic_play(game->sfx.combat_theme);
    }
    info->combat.clock = sfClock_create();
    info->combat.white_fade = sfRectangleShape_create();
    info->combat.clock_turn = sfClock_create();
}

static void do_transition(t_window *game, t_infoGame *info)
{
    sfTime time = sfClock_getElapsedTime(info->combat.clock);
    float seconds = sfTime_asMilliseconds(time);
    int alpha_rect = 0;
    sfColor fade_rect = sfColor_fromRGBA(255, 255, 255, 0);

    if (seconds >= 2000)
        alpha_rect = (seconds -2000) * 1.25;
    if (seconds > 2000 && seconds < 2500)
        alpha_rect = 255;
    if (seconds > 2500)
        alpha_rect = 255 - (seconds - 2500) * 1.25;
    if (alpha_rect <= 0)
        alpha_rect = 0;
    if (seconds >= 2000)
        sfView_reset(info->camera, (sfFloatRect) {0, 0, 1920, 1031});
    fade_rect = sfColor_fromRGBA(255, 255, 255, alpha_rect);
    sfRectangleShape_setFillColor(info->combat.white_fade, fade_rect);
}

static void enter_combat(t_window *game, t_infoGame *info)
{
    sfTime time = sfClock_getElapsedTime(info->combat.clock);
    float seconds = sfTime_asMilliseconds(time);

    do_transition(game, info);
    if (seconds >= 2400) {
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
        draw_combat_scene(game, info);
    }
    sfRenderWindow_drawRectangleShape(game->window, info->combat.white_fade,
    NULL);
}

int display_combat(t_window *game, t_infoGame *info)
{
    sfSprite *game_screenshot = setup_background(game, info);
    sfTime time;
    float seconds = 0;
    int win = 0;

    init_combat(game, info);
    while (sfRenderWindow_isOpen(game->window)) {
        win = handle_combat_outcome(game, info);
        if (win != 0) {
            sfSprite_destroy(game_screenshot);
            break;
        }
        time = sfClock_getElapsedTime(info->combat.clock);
        seconds = sfTime_asMilliseconds(time);
        if (info->combat.turn == 0)
            handle_enemy_turn(game, info);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_setView(game->window, info->camera);
        if (seconds < 2000)
            animate_entry(game, info, game_screenshot);
        enter_combat(game, info);
        sfRenderWindow_display(game->window);
        while (sfRenderWindow_pollEvent(game->window, &game->event)) {
            if (game->event.type == sfEvtClosed)
                close_window(game);
            if (info->combat.turn == 1)
                handle_combat_input(game, info);
        }
        if (sfKeyboard_isKeyPressed(sfKeyDelete)) {
            sfSprite_destroy(game_screenshot);
            break;
        }
    }
    return win;
}
