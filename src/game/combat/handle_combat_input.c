/*
** EPITECH PROJECT, 2021
** handle_combat_input.c
** File description:
** void
*/

#include <stdio.h>
#include "rpg.h"

int change_turn(t_infoGame *info)
{
    if (info->combat.turn == 1) {
        info->combat.turn = 0;
        return (0);
    }
    if (info->combat.turn == 0) {
        info->combat.turn = 1;
        return (1);
    }
    return (0);
}

void reset_defense(t_infoFighter *striked)
{
    if (striked->last_move == 3)
        striked->defense /= 3;
}

void handle_attack(t_window *game, t_infoGame *info,
            t_infoFighter *striker, t_infoFighter *striked)
{
    float atk_power = striker->atk_power;
    float dfs = striked->defense;
    float atk = striker->attack;
    float damages = atk_power * 0.5 * (atk / dfs);
    
    striked->current_health -= damages;
    if (striked->current_health <= 0)
        striked->current_health = 0;
    reset_defense(striked);
    change_turn(info);
    sfClock_restart(info->combat.clock_turn);
}

void handle_guard(t_infoGame *info, t_infoFighter *striker, 
                            t_infoFighter *striked)
{
    striker->defense *= 3;
    striker->last_move = 3;
    reset_defense(striked);
    change_turn(info);
    sfClock_restart(info->combat.clock_turn);
}

void handle_combat_input(t_window *game, t_infoGame *info)
{
    if (game->event.type == sfEvtMouseButtonReleased) {
        if (combat_button_hovered(info->combat.attack, game->window)) {
            info->player.atk_power = 50;
            handle_attack(game, info, &info->player, &info->enemy);
            info->player.last_move = 1;
        }
        if (combat_button_hovered(info->combat.guard, game->window) &&
        info->player.last_move != 3)
            handle_guard(info, &info->player, &info->enemy);
        if (combat_button_hovered(info->combat.big_attack, game->window) &&
        info->player.big_atk_pp > 0 && info->player.last_move != 2) {
            info->player.atk_power = 100;
            info->player.big_atk_pp -= 1;
            info->player.last_move = 2;
            handle_attack(game, info, &info->player, &info->enemy);
        }
    }
}