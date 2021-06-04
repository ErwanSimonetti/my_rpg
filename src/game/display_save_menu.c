/*
** EPITECH PROJECT, 2021
** display_pause.c
** File description:
** display_save_menu.c
*/

#include "rpg.h"
#include "chained_list.h"
#include "game.h"
#include "structure.h"

static const char *ARTYPA = "assets/font/Artypa.ttf";

static void draw_in_loop(t_window *game, t_rect *rect_pause, t_text
    *buttons_pause, t_text *buttons_pause_animated)
{
    draw_rectangle(&game->window, rect_pause);
    draw_text(game, buttons_pause);
    draw_text_animated(game, buttons_pause_animated);
}

void display_save_menu(t_window *game, t_clock *clock, t_infoGame *info)
{
    (void)clock;
    sfSprite *gui_pause = create_background_from_game(info);
    t_rect *rect_pause = create_save_menu_rectangle();
    t_text *buttons_pause = buttons_pause = create_text
            ("Would you like to save your game", (sfVector2f) {662, 400},
            (sfVector2f) {0.7, 0.7}, ARTYPA);
    t_text *buttons_pause_animated = create_save_menu_button_animated();
    t_sprite *logo = create_sprite("assets/img/Xeno.png", (sfVector2f)
                {675, 150}, (sfVector2f) {1, 1});

    while (sfRenderWindow_isOpen(game->window)) {
        if (poll_event_pause(game, buttons_pause_animated, NULL))
            return;
        game->mousePos = sfMouse_getPositionRenderWindow(game->window);
        sfRenderWindow_setFramerateLimit(game->window, game->fpslimit);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, gui_pause, NULL);
        draw_in_loop(game, rect_pause, buttons_pause, buttons_pause_animated);
        draw_sprite(&game->window, logo);
        sfRenderWindow_display(game->window);
    }
}
