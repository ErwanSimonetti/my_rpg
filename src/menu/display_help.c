/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** display_menu.c
*/

#include "chained_list.h"
#include "rpg.h"
#include "menu.h"
#include "structure.h"

static void set_buttons_color(t_text *buttons_help)
{
    setTextColor_Blue(buttons_help);
    setTextColor_Yellow(buttons_help);
    setTextColor_Green(buttons_help);
    setTextColor_Orange(buttons_help);
    setTextColor_Red(buttons_help);
}

static void draw_in_loop(t_window *game, t_sprite *gui_help2, t_text
    *buttons_help, t_text *buttons_help_animated)
{
    draw_sprite(&game->window, gui_help2);
    draw_text(game, buttons_help);
    draw_text_animated(game, buttons_help_animated);
}

void display_help_menu(t_window *game, t_clock *clock, t_infoGame *info)
{
    t_sprite *gui_help1 = create_help_menu_sprite1();
    t_sprite *gui_help2 = create_help_menu_sprite2();
    t_text *buttons_help = create_help_menu_button();
    t_text *buttons_help_animated = create_help_menu_button_animated();
    t_rect *rect_help_animated = create_help_menu_rectangle();

    (void)clock;
    (void)info;
    set_buttons_color(buttons_help);
    while (sfRenderWindow_isOpen(game->window)) {
        if (poll_event_menu(game, buttons_help_animated, NULL))
            return;
        game->mousePos = sfMouse_getPositionRenderWindow(game->window);
        sfRenderWindow_setFramerateLimit(game->window, game->fpslimit);
        sfRenderWindow_clear(game->window, sfTransparent);
        draw_sprite(&game->window, gui_help1);
        draw_rectangle(&game->window, rect_help_animated);
        draw_in_loop(game, gui_help2, buttons_help, buttons_help_animated);
        sfRenderWindow_display(game->window);
    }
}
