/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** transition.c
*/

#include "rpg.h"

void do_transition(t_window *game, sfUint8 *shade,
    sfClock *timer, t_rect *new_game)
{
    if (game->oldstatus != PAUSE_MENU && game->oldstatus != INVENTORY_MENU) {
        if (sfTime_asMicroseconds(sfClock_getElapsedTime(timer)) >= 10 && *shade > 0) {
            sfRectangleShape_setFillColor
                (new_game->rectangle, (sfColor) {0, 0, 0, (*shade)--});
            sfClock_restart(timer);
        }
        sfRenderWindow_drawRectangleShape(game->window, new_game->rectangle, NULL);
    }
}