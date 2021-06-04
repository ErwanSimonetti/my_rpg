/*
** EPITECH PROJECT, 2021
** combat_outcome.c
** File description:
** handle victory & defeat
*/

#include <stdio.h>
#include "rpg.h"

static void reset_fight(t_infoFighter *enemy, t_infoGame *info)
{
    enemy->current_health = enemy->max_health;
    reset_defense(enemy);
    reset_defense(&info->player);
    enemy->last_move = -1;
    enemy->big_atk_pp = 3;
    info->combat.turn = 1;
    info->player.last_move = -1;
}

static void animate_loose(t_window *game, t_infoGame *info)
{
    sfTime time = sfClock_getElapsedTime(info->combat.clock_turn);
}

static void animate_win(t_window *game, t_infoGame *info)
{
    sfTime time = sfClock_getElapsedTime(info->combat.clock_turn);
    float seconds = sfTime_asSeconds(time);
    int alpha_text = 0;
    sfColor shade = sfColor_fromRGBA(255, 255, 255, 0);
    sfColor shade_blue = sfColor_fromRGBA(0, 81, 255, 0);

    while (seconds <= 5) {
        sfRenderWindow_clear(game->window, sfBlack);
        draw_combat_scene(game, info);
        alpha_text = seconds * 150;
        if (alpha_text >= 255)
            alpha_text = 255;
        shade = sfColor_fromRGBA(255, 255, 255, alpha_text);
        shade_blue = sfColor_fromRGBA(0, 81, 255, alpha_text);
        sfText_setColor(info->combat.you_win, shade);
        sfText_setOutlineColor(info->combat.you_win, shade_blue);
        sfRenderWindow_drawRectangleShape(game->window, info->combat.box_middle, NULL);
        sfRenderWindow_drawText(game->window, info->combat.you_win, NULL);
        sfRenderWindow_display(game->window);
        time = sfClock_getElapsedTime(info->combat.clock_turn);
        seconds = sfTime_asSeconds(time);
    }
}

int handle_combat_outcome(t_window *game, t_infoGame *info)
{
    if (info->enemy.current_health == 0) {
        sfMusic_stop(game->sfx.combat_theme);
        animate_win(game, info);
        reset_fight(&info->enemy, info);
        sfMusic_play(game->sfx.game_theme);
        return (1);
    }
    if (info->player.current_health == 0) {
        sfClock_restart(info->combat.clock_turn);
        reset_fight(&info->enemy, info);
        info->player.current_health = info->player.max_health;
        sfSound_play(game->sfx.game_over);
        sfMusic_stop(game->sfx.combat_theme);
        sfMusic_play(game->sfx.menu_theme);
        game->status = MAIN_MENU;
        return (2);
    }
    return (0);
}
