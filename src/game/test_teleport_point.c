/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** test_teleport_point.c
*/

#include "game.h"
#include "structure.h"

int test_teleport_points_zone(t_window *game, t_infoGame *info, t_rect *box)
{
    sfColor color = sfRectangleShape_getFillColor(box->rectangle);
    sfUint32 colorRGB = sfColor_toInteger(color);

    if (colorRGB == sfColor_toInteger(sfRed)
            && game->status == MAIN_GAME_TOWN) {
        info->character_move.x = 490;
        info->character_move.y = 426;
        game->oldstatus = game->status;
        game->status = MAIN_GAME_SHOP;
        return 1;
    }
    if (colorRGB == sfColor_toInteger(sfRed)
            && game->status == MAIN_GAME_SHOP) {
        info->character_move.x = 196;
        info->character_move.y = 366;
        game->oldstatus = game->status;
        game->status = MAIN_GAME_TOWN;
        return 1;
    }
    if (colorRGB == sfColor_toInteger(sfBlue)
            && game->status == MAIN_GAME_TOWN &&
            info->statushistory >= 4) {
        info->character_move.x = 338;
        info->character_move.y = 850;
        game->oldstatus = game->status;
        game->status = MAIN_GAME_SWAMP;
        return 1;
    }
    if (colorRGB == sfColor_toInteger(sfBlue)
            && game->status == MAIN_GAME_SWAMP) {
        info->character_move.x = 20;
        info->character_move.y = 446;
        game->oldstatus = game->status;
        game->status = MAIN_GAME_TOWN;
        return 1;
    }
    if (colorRGB == sfColor_toInteger(sfGreen)
            && game->status == MAIN_GAME_TOWN &&
            info->statushistory >= 1) {
        info->character_move.x = 580;
        info->character_move.y = 885;
        game->oldstatus = game->status;
        game->status = MAIN_GAME_MINES;
        return 1;
    }
    if (colorRGB == sfColor_toInteger(sfGreen)
            && game->status == MAIN_GAME_MINES) {
        info->character_move.x = 800;
        info->character_move.y = 446;
        game->oldstatus = game->status;
        game->status = MAIN_GAME_TOWN;
        return 1;
    }
    return 0;
}

int test_interaction_points(t_window *game, t_infoGame *info, t_rect *box, sfVector2f character_hitbox)
{
    for (; box; box = box->next)
        if  (character_hitbox.x + (47 * 0.4) - 2 >= box->pos.x
            && character_hitbox.x <= box->pos.x + box->size.x
            && character_hitbox.y + (47 * 0.4) >= box->pos.y
            && character_hitbox.y <= box->pos.y + box->size.y
            && test_teleport_points_zone(game, info, box) == 1)
        return 1;
    return 0;
}
