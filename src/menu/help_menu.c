/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** option_menu.c
*/

#include "chained_list.h"
#include "structure.h"

static const char *ARTYPA = "assets/font/Artypa.ttf";

t_sprite *create_help_menu_sprite1(void)
{
    t_sprite *gui_help = NULL;

    gui_help = add_sprite_inlist(gui_help,
        create_sprite("assets/img/Bckgrd_menu.jpg", (sfVector2f)
                {0, 0}, (sfVector2f) {0.5, 0.48}), len_list_sprite(gui_help));
    return gui_help;
}

t_sprite *create_help_menu_sprite2(void)
{
    t_sprite *gui_help = NULL;

    gui_help = add_sprite_inlist(gui_help,
        create_sprite("assets/img/Keyboard.png", (sfVector2f)
                {570, 150}, (sfVector2f) {1, 1}), len_list_sprite(gui_help));
    return gui_help;
}

t_rect *create_help_menu_rectangle(void)
{
    t_rect *rect_help = NULL;

    rect_help = add_rectangle_inlist(rect_help,
        create_rect((sfVector2f) {460, 100}, (sfVector2f) {1000, 800},
        sfColor_fromRGBA(20, 20, 20, 220), sfWhite), len_list_rect(rect_help));
    return rect_help;
}

t_text *create_help_menu_button_animated(void)
{
    t_text *buttons_help = NULL;

    buttons_help = create_text("Back", (sfVector2f) {900, 825},
                    (sfVector2f) {1, 1}, ARTYPA);
    return buttons_help;
}
