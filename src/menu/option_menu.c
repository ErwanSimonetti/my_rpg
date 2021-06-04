/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** option_menu.c
*/

#include "structure.h"
#include "chained_list.h"

static const char *ARTYPA = "assets/font/Artypa.ttf";

t_sprite *create_option_menu_sprite(void)
{
    t_sprite *gui_option = NULL;

    gui_option = add_sprite_inlist(gui_option,
    create_sprite("assets/img/Bckgrd_menu.jpg", (sfVector2f) {0, 0},
    (sfVector2f) {0.5, 0.48}), len_list_sprite(gui_option));
    return gui_option;
}

t_rect *create_option_menu_rectangle(void)
{
    t_rect *rect_base = create_rect((sfVector2f) {630, 100},
        (sfVector2f) {660, 800}, sfColor_fromRGBA(20, 20, 20, 220), sfWhite);

    rect_base = add_rectangle_inlist(rect_base, create_rect((sfVector2f) {950,
        770}, (sfVector2f) {275, 5}, sfWhite, sfBlack),
        len_list_rect(rect_base));
    rect_base = add_rectangle_inlist(rect_base, create_rect((sfVector2f) {950,
        708}, (sfVector2f) {275, 5}, sfWhite, sfBlack),
        len_list_rect(rect_base));
    return rect_base;
}

t_rect *create_option_menu_rectangle_animated(void)
{
    t_rect *rect_option = NULL;

    rect_option = add_rectangle_inlist(rect_option, create_rect((sfVector2f)
            {950, 470}, (sfVector2f) {35, 35}, sfTransparent, sfWhite),
            len_list_rect(rect_option));
    rect_option = add_rectangle_inlist(rect_option, create_rect((sfVector2f)
            {1150, 470}, (sfVector2f) {35, 35}, sfTransparent, sfWhite),
            len_list_rect(rect_option));
    rect_option = add_rectangle_inlist(rect_option, create_rect((sfVector2f)
            {1050, 530}, (sfVector2f) {35, 35}, sfTransparent, sfWhite),
            len_list_rect(rect_option));
    return rect_option;
}

t_text *create_option_menu_button_animated(void)
{
    t_text *buttons_option = NULL;

    buttons_option = add_text_inlist(buttons_option, create_text("Back",
        (sfVector2f) {900, 825}, (sfVector2f) {1, 1}, ARTYPA),
        len_list_text(buttons_option));
    buttons_option = add_text_inlist(buttons_option, create_text("x",
                (sfVector2f) {1210, 755},
        (sfVector2f) {1, 1}, ARTYPA), len_list_text(buttons_option));
    buttons_option = add_text_inlist(buttons_option, create_text("x",
                (sfVector2f) {1210, 693},
        (sfVector2f) {1, 1}, ARTYPA), len_list_text(buttons_option));
    return buttons_option;
}
