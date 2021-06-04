/*
** EPITECH PROJECT, 2021
** display_menu_option.c
** File description:
** manage display_menu_option
*/

#include "rpg.h"
#include "lib.h"
#include "menu.h"
#include "game.h"
#include "structure.h"

static int manage_window_pause(t_window *game, t_rect *rect_option_animated,
    t_text *buttons_option_animated)
{
    if (poll_event_pause(game, buttons_option_animated,
                        rect_option_animated))
        return -1;
    game->mousePos = sfMouse_getPositionRenderWindow(game->window);
    sfRenderWindow_setFramerateLimit(game->window, game->fpslimit);
    sfRenderWindow_clear(game->window, sfTransparent);
    return 0;
}

void display_settings_pause(t_window *game, t_clock *clock, t_infoGame *info)
{
    sfSprite *gui_pause = create_background_from_game(info);
    t_rect *rect_option = create_option_menu_rectangle();
    t_rect *rect_option_animated = create_option_menu_rectangle_animated();
    t_text *buttons_option = create_option_menu_button(game);
    t_text *buttons_option_animated = create_option_menu_button_animated();
    t_sprite *logo = create_sprite("assets/img/Xeno.png", (sfVector2f)
                {675, 150}, (sfVector2f) {1, 1});

    while (sfRenderWindow_isOpen(game->window)) {
        if (manage_window_pause(game, rect_option_animated,
            buttons_option_animated) == -1)
            return;
        get_fps(clock, find_fps_counter(buttons_option));
        sfText_setString(find_fps_settings(buttons_option)->text,
                        my_itoc(game->fpslimit));
        sfRenderWindow_drawSprite(game->window, gui_pause, NULL);
        manage_volume(game, rect_option, buttons_option_animated);
        manage_fps(game, buttons_option, rect_option_animated, rect_option);
        draw_sprite(&game->window, logo);
        sfRenderWindow_display(game->window);
    }
}
