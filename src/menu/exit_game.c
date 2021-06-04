/*
** EPITECH PROJECT, 2021
** exit
** File description:
** game
*/

#include "rpg.h"
#include "lib.h"
#include "menu.h"
#include "structure.h"
#include <stdio.h>

void exit_game(t_window *game, t_clock *clock, t_infoGame *info)
{
    (void)clock;
    (void)info;
    close_window(game);
}