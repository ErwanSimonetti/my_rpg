/*
** EPITECH PROJECT, 2021
** display_menu_option.c
** File description:
** manage display_menu_option
*/

#include "structure.h"
#include "chained_list.h"
#include "menu.h"
#include "rpg.h"
#include "lib.h"

void manage_fps(t_window *game, t_text *buttons_option, t_rect
                    *rect_option_animated, t_rect *rect_option)
{
    if (game->fpslimit >= 100)
        sfText_setPosition(find_fps_settings(buttons_option)->text,
                        (sfVector2f) {1025, 470});
    if (game->VSync == sfTrue && find_vsync(rect_option_animated) == NULL)
        rect_option = add_rectangle_inlist(rect_option,
            create_rect((sfVector2f) {1052.7, 532.7}, (sfVector2f) {30, 30},
                            sfWhite, sfBlack), len_list_rect(rect_option));
    draw_rectangle_animated(game, rect_option_animated);
    draw_text(game, buttons_option);
}

static int manage_window(t_window *game, t_rect *rect_option_animated, t_text
*buttons_option_animated)
{
    if (poll_event_menu(game, buttons_option_animated,
                        rect_option_animated))
        return -1;
    game->mousePos = sfMouse_getPositionRenderWindow(game->window);
    sfRenderWindow_setFramerateLimit(game->window, game->fpslimit);
    sfRenderWindow_clear(game->window, sfTransparent);
    return 0;
}

void manage_volume(t_window *game, t_rect *rect_option, t_text
*buttons_option_animated)
{
    handle_volume_cursor(find_sound_bar(rect_option)->rectangle,
                        find_cursor(buttons_option_animated)->text, game);
    handle_volume_cursor(find_sound_bar(rect_option)->next->rectangle,
            find_cursor(buttons_option_animated)->next->text, game);
    draw_rectangle(&game->window, rect_option);
    draw_text_animated(game, buttons_option_animated);
}

void display_settings_menu(t_window *game, t_clock *clock, t_infoGame *info)
{
    t_rect *rect_option = create_option_menu_rectangle();
    t_rect *rect_option_animated = create_option_menu_rectangle_animated();
    t_text *buttons_option = create_option_menu_button(game);
    t_text *buttons_option_animated = create_option_menu_button_animated();
    t_sprite *gui_option = create_option_menu_sprite();
    t_sprite *logo = create_sprite("assets/img/Xeno.png", (sfVector2f)
                {675, 150}, (sfVector2f) {1, 1});

    (void)info;
    while (sfRenderWindow_isOpen(game->window)) {
        if (manage_window(game, rect_option_animated,
            buttons_option_animated) == -1)
            return;
        get_fps(clock, find_fps_counter(buttons_option));
        sfText_setString(find_fps_settings(buttons_option)->text,
                        my_itoc(game->fpslimit));
        draw_sprite(&game->window, gui_option);
        manage_volume(game, rect_option, buttons_option_animated);
        manage_fps(game, buttons_option, rect_option_animated, rect_option);
        draw_sprite(&game->window, logo);
        sfRenderWindow_display(game->window);
    }
}
