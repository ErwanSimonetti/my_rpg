/*
** EPITECH PROJECT, 2021
** handle_enemy_turn
** File description:
** made to handle enemy turn
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "rpg.h"

void set_random_seed(void)
{
    time_t timer = time(NULL);

    srand(timer);
}

int rand_generator(int minimum, int maximum)
{
    int rand_nb = rand() % maximum + minimum;

    return (rand_nb);
}

static void handle_current_move(t_window *game, t_infoGame *info)
{
    int move = 0;

    move = rand_generator(1, 10);
    if (info->enemy.last_move == 3)
        move = rand_generator(6, 10);
    if (info->enemy.last_move == 2)
        move = 1;
    switch (move) {
        case 1: case 2: case 3: case 4: case 5:
            handle_guard(info, &info->enemy, &info->player);
            break;
        case 7: case 8: case 9: case 10:
            info->enemy.atk_power = 50;
            handle_attack(game, info, &info->enemy, &info->player);
            info->enemy.last_move = 1;
            break;
        case 6:
            info->enemy.atk_power = 100;
            handle_attack(game, info, &info->enemy, &info->player);
            info->enemy.last_move = 2;
            break;
    }
}

void handle_enemy_turn(t_window *game, t_infoGame *info)
{
    sfTime time = sfClock_getElapsedTime(info->combat.clock_turn);
    float seconds = sfTime_asSeconds(time);

    set_random_seed();
    if (seconds >= 1.5) {
        handle_current_move(game, info);
        info->combat.turn = 1;
    }
}