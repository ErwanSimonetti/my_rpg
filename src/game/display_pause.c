/*
** EPITECH PROJECT, 2021
** display_pause.c
** File description:
** display input on pause menu
*/

#include "rpg.h"
#include "chained_list.h"
#include "structure.h"
#include "game.h"

void display_pause_menu(t_window *game, t_clock *clock, t_infoGame *info)
{
    (void)clock;
    sfSprite *gui_pause = create_background_from_game(info);
    t_rect *rect_pause = create_pause_menu_rectangle();
    t_text *buttons_pause = create_pause_menu_button_animated();
    t_sprite *logo = create_sprite("assets/img/Xeno.png", (sfVector2f)
                {675, 150}, (sfVector2f) {1, 1});

    sfView_reset(info->camera, (sfFloatRect) {0, 0, 1920, 1031});
    while (sfRenderWindow_isOpen(game->window)) {
        if (poll_event_pause(game, buttons_pause, NULL))
            return;
        game->mousePos = sfMouse_getPositionRenderWindow(game->window);
        sfRenderWindow_setFramerateLimit(game->window, game->fpslimit);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_setView(game->window, info->camera);
        sfRenderWindow_drawSprite(game->window, gui_pause, NULL);
        draw_rectangle(&game->window, rect_pause);
        draw_sprite(&game->window, logo);
        draw_text_animated(game, buttons_pause);
        sfRenderWindow_display(game->window);
    }
}
