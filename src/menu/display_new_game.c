/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** display_new_game.c
*/

#include "rpg.h"
#include "structure.h"
#include "config_file.h"

void display_new_game(t_window *game, t_clock *clock, t_infoGame *info)
{
    (void)clock;
    (void)info;
    char *player_name = NULL;
    char *player_sprite = NULL;

    player_name = get_player_name(game);
    player_sprite = get_player_sprite(game);
    new_game_transition(game);
    game->status = MAIN_GAME_TOWN;
    write_in_config_file("assets/save/player_info.txt", (char *[]) {player_name,
            player_sprite, get_face_name(player_sprite),NULL});
}
