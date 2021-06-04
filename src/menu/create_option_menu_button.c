/*
** EPITECH PROJECT, 2021
** create_option_menu_button.c
** File description:
** create_option_menu_button
*/

#include "structure.h"
#include "chained_list.h"
#include "lib.h"

static const char *STEPS = "assets/font/Steps.ttf";
static const char *ARTYPA = "assets/font/Artypa.ttf";

static t_text *create_option_menu_button_second_part(t_window *game, t_text
    *buttons_option)
{
    buttons_option = add_text_inlist(buttons_option, create_text("Sounds Effect"
            , (sfVector2f) {650, 755}, (sfVector2f) {0.8, 0.8}, ARTYPA),
                len_list_text(buttons_option));
    buttons_option = add_text_inlist(buttons_option, create_text("-",
                (sfVector2f) {963, 465}, (sfVector2f) {1.2, 1.2}, STEPS),
                len_list_text(buttons_option));
    buttons_option = add_text_inlist(buttons_option, create_text("+",
                (sfVector2f) {1160, 465}, (sfVector2f) {1.2, 1.2}, STEPS),
                len_list_text(buttons_option));
    buttons_option = add_text_inlist(buttons_option, create_text("0",
                (sfVector2f) {1850, 10}, (sfVector2f) {0.7, 0.7}, STEPS),
                                    len_list_text(buttons_option));
    buttons_option = add_text_inlist(buttons_option,
                create_text(my_itoc(game->fpslimit), (sfVector2f)
                {1040, 470}, (sfVector2f) {0.9, 0.9}, STEPS),
                                    len_list_text(buttons_option));
    return buttons_option;
}

t_text *create_option_menu_button(t_window *game)
{
    t_text *buttons_option = NULL;

    buttons_option = add_text_inlist(buttons_option, create_text("Display",
                (sfVector2f) {870, 400}, (sfVector2f) {1, 1}, ARTYPA),
                len_list_text(buttons_option));
    buttons_option = add_text_inlist(buttons_option, create_text("FPS Limit",
                (sfVector2f) {705, 470}, (sfVector2f) {0.8, 0.8}, ARTYPA),
                len_list_text(buttons_option));
    buttons_option = add_text_inlist(buttons_option, create_text("VSYNC",
                (sfVector2f) {735, 530}, (sfVector2f) {0.8, 0.8}, ARTYPA),
                len_list_text(buttons_option));
    buttons_option = add_text_inlist(buttons_option, create_text("Audio",
                (sfVector2f) {895, 625}, (sfVector2f) {1, 1}, ARTYPA),
                len_list_text(buttons_option));
    buttons_option = add_text_inlist(buttons_option, create_text("Music Volume",
                (sfVector2f) {660, 695}, (sfVector2f) {0.8, 0.8}, ARTYPA),
                len_list_text(buttons_option));
    buttons_option = create_option_menu_button_second_part(game,
        buttons_option);
    return buttons_option;
}
