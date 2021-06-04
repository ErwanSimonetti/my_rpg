/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** display_menu.c
*/

#include "rpg.h"
#include "lib.h"
#include "menu.h"
#include "structure.h"
#include "chained_list.h"
#include <stdio.h>

static void draw_object_in_loop(t_window *game, t_text *buttons, t_rect *rect,
    t_sprite *gui)
{
    draw_sprite(&game->window, gui);
    draw_rectangle(&game->window, rect);
    draw_text_animated(game, buttons);
}

void display_main_menu(t_window *game, t_clock *clock, t_infoGame *info)
{
    (void)clock;
    t_sprite *gui = create_main_menu_sprite();
    t_text *buttons = create_main_menu_button();
    t_rect *rect = create_main_menu_rectangle();
    t_sprite *logo = create_sprite("assets/img/Xeno.png", (sfVector2f)
                {675, 150}, (sfVector2f) {1, 1});

    (void)info;
    while (sfRenderWindow_isOpen(game->window)) {
        if (poll_event_menu(game, buttons, rect))
            return;
        game->mousePos = sfMouse_getPositionRenderWindow(game->window);
        sfRenderWindow_setFramerateLimit(game->window, game->fpslimit);
        sfRenderWindow_clear(game->window, sfTransparent);
        draw_object_in_loop(game, buttons, rect, gui);
        draw_sprite(&game->window, logo);
        sfRenderWindow_display(game->window);
    }
}

static const t_status STATUS[] = {
    (t_status) {MAIN_MENU, display_main_menu},
    (t_status) {NEW_GAME, display_new_game},
    (t_status) {SETTINGS_MENU, display_settings_menu},
    (t_status) {HELP_MENU, display_help_menu},
    (t_status) {MAIN_GAME_TOWN, display_game},
    (t_status) {MAIN_GAME_SHOP, display_shop},
    (t_status) {MAIN_GAME_SWAMP, display_swamp},
    (t_status) {MAIN_GAME_MINES, display_mines},
    (t_status) {PAUSE_MENU, display_pause_menu},
    (t_status) {SETTINGS_PAUSE, display_settings_pause},
    (t_status) {SAVE_MENU, display_save_menu},
    (t_status) {INVENTORY_MENU, display_inventory},
    (t_status) {EXIT, exit_game},
};

void test_display(t_window *game, t_clock *clock, t_infoGame *info)
{
    for (long unsigned int i = 0; i < sizeof(STATUS) / sizeof(t_status) &&
            sfRenderWindow_isOpen(game->window); i += 1)
        if (game->status == STATUS[i].status)
            STATUS[i].function(game, clock, info);
}
