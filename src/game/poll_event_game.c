/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** poll_event_game.c
*/

#include "rpg.h"
#include "menu.h"
#include "game.h"
#include "structure.h"
#include <stdbool.h>
#include <stdio.h>

bool is_in_rect(t_window *game, t_rect *box, sfVector2f character_hitbox)
{
    (void)game;
    for (; box; box = box->next)
        if (sfColor_toInteger(sfBlack) ==
            sfColor_toInteger(sfRectangleShape_getFillColor(box->rectangle)) ||
            sfColor_toInteger(sfRed) ==
            sfColor_toInteger(sfRectangleShape_getFillColor(box->rectangle)) ||
            sfColor_toInteger(sfBlue) ==
            sfColor_toInteger(sfRectangleShape_getFillColor(box->rectangle)) ||
            sfColor_toInteger(sfGreen) ==
            sfColor_toInteger(sfRectangleShape_getFillColor(box->rectangle)) ||
            sfColor_toInteger(sfYellow) ==
            sfColor_toInteger(sfRectangleShape_getFillColor(box->rectangle)) ||
            sfColor_toInteger(sfWhite) ==
            sfColor_toInteger(sfRectangleShape_getFillColor(box->rectangle)))
            continue;
        else if (character_hitbox.x + (47 * 0.4) - 1 >= box->pos.x
                && character_hitbox.x <= box->pos.x + box->size.x
                && character_hitbox.y + (47 * 0.4) >= box->pos.y
                && character_hitbox.y + 8 <= box->pos.y + box->size.y)
            return true;
    return false;
}

static void get_info_from_sprite(t_clock *clock, t_infoGame *info, int dir)
{
    info->statusMove = dir;
    get_vector(clock, info);
    get_sprite(clock);
}

static int manage_key_move_second_part(t_window *game, t_infoGame *info, t_clock
    *clock, t_rect *box)
{
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        get_info_from_sprite(clock, info, DOWN);
        if (is_in_rect(game, box, info->character_move))
            info->character_move.y -= 2;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        get_info_from_sprite(clock, info, RIGHT);
        if (is_in_rect(game, box, info->character_move))
            info->character_move.x -= 2;
        return 1;
    }
    return 0;
}

int manage_key_move(t_window *game, t_infoGame *info, t_clock *clock,
    t_rect *box)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        get_info_from_sprite(clock, info, UP);
        if (is_in_rect(game, box, info->character_move))
            info->character_move.y += 2;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        get_info_from_sprite(clock, info, LEFT);
        if (is_in_rect(game, box, info->character_move))
            info->character_move.x += 2;
        return 1;
    }
    return manage_key_move_second_part(game, info, clock, box);
}

int poll_key_menu(t_window *game, t_infoGame *info, t_clock *clock)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        info->background_pause = sfRenderWindow_capture(game->window);
        game->oldstatus = game->status;
        game->status = PAUSE_MENU;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        info->background_pause = sfRenderWindow_capture(game->window);
        game->oldstatus = game->status;
        display_inventory(game, clock, info);
        sfView_setSize(info->camera, (sfVector2f){1920 / 4, 1080 / 4});
        return 0;
    }
    return 0;
}

int poll_event_game(t_window *game, t_infoGame *info, t_clock *clock,
    t_rect *box)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            close_window(game);
        if (game->event.type == sfEvtKeyPressed) {
            if (test_interaction_points(game, info, box, info->character_move) == 1)
                return 1;
            if (poll_key_menu(game, info, clock) == 1)
                return 1;
            if (manage_key_move(game, info, clock, box) == 1)
                return 2;
        }
    }
    return 0;
}
