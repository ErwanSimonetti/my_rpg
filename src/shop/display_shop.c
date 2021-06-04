/*
** EPITECH PROJECT, 2021
** display_shop.c
** File description:
** display the shop
*/

#include "structure.h"
#include "rpg.h"
#include "lib.h"
#include "game.h"
#include "chained_list.h"
#include <stdlib.h>

static void init_box_and_sprites(t_rect **box, t_sprite **sprites,
    char **config_character, t_infoGame *info)
{
    char **config_rectangle = NULL;

    config_rectangle = fopen_getline(config_rectangle,
            "assets/config_file/shop.txt");
    if (config_rectangle == NULL)
        return;
    config_rectangle = remove_jump_line_at_end(config_rectangle);
    create_box_from_config(&config_rectangle[1], box);
    *box = add_rectangle_inlist(*box, create_rect((sfVector2f){490, 280},
        (sfVector2f){20, 20}, sfBlack, sfBlack), len_list_rect(*box));
    *sprites = create_sprite(config_rectangle[0],
        (sfVector2f) {295, 120}, (sfVector2f) {0.5, 0.5});
    info->statusMove = UP;
    change_texture(&(*sprites)->next, config_character[1], 1, info);
    *sprites = add_sprite_inlist(*sprites, create_sprite(
        "assets/img/shop_man_sprite.png", (sfVector2f){486, 235},
        (sfVector2f){0.6, 0.6}), len_list_sprite(*sprites));
}

static char **init_shop_window(char **config_character, t_infoGame *info,
    t_window *game)
{
    config_character = fopen_getline(config_character,
            "assets/save/player_info.txt");
    if (*config_character == NULL)
        return NULL;
    config_character = remove_jump_line_at_end(config_character);
    sfView_setSize(info->camera, (sfVector2f){1920 / 3, 1080 / 3});
    sfView_setCenter(info->camera, (sfVector2f){1920 / 3.825, 1080 / 3.6});
    sfRenderWindow_setView(game->window, info->camera);
    return config_character;
}

void manage_window_info(t_window *game)
{
    game->mousePos = sfMouse_getPositionRenderWindow(game->window);
    sfRenderWindow_setFramerateLimit(game->window, game->fpslimit);
}

static void do_shop_loop(t_window *game, t_sprite *sprites, t_infoGame *info)
{
    sfRenderWindow_clear(game->window, sfBlack);
    draw_sprite(&game->window, sprites);
    sfSprite_setPosition(sprites->next->sprite, info->character_move);
    sfRenderWindow_display(game->window);
}

void display_shop(t_window *game, t_clock *clock, t_infoGame *info)
{
    char **config_character = NULL;
    int event = 0;
    t_rect *box = NULL;
    t_sprite *sprites = NULL;

    config_character = init_shop_window(config_character, info, game);
    init_box_and_sprites(&box, &sprites, config_character, info);
    while (sfRenderWindow_isOpen(game->window)) {
        event = poll_event_game(game, info, clock, box);
        if (event == 1) {
            return;
        } else if (event == 2)
            change_texture(&sprites->next, config_character[1],
                clock->spriteStatus - 1, info);
        do_shop_loop(game, sprites, info);
        manage_window_info(game);
        if (is_in_color_rect(sprites->next, box, sfBlack) && info->statusMove == UP) {
            let_shop_man_talk(game, sprites);
            info->statusMove = DOWN;
            change_texture(&sprites->next, config_character[1],
                clock->spriteStatus - 1, info);
        }
    }
}
