/*
** EPITECH PROJECT, 2021
** create_help_menu_buttons.c
** File description:
** create the help's menu buttons
*/

#include "structure.h"
#include "chained_list.h"
#include "lib.h"
#include <stddef.h>

static const char *ARTYPA = "assets/font/Artypa.ttf";

static t_text *create_help_menu_button_second_part(t_text *buttons_help,
    char **str)
{
    buttons_help = add_text_inlist(buttons_help, create_text(str[3],
        (sfVector2f) {480, 650}, (sfVector2f) {0.6, 0.6}, ARTYPA),
        len_list_text(buttons_help));
    buttons_help = add_text_inlist(buttons_help, create_text(str[4],
        (sfVector2f) {480, 700}, (sfVector2f) {0.6, 0.6}, ARTYPA),
        len_list_text(buttons_help));
    buttons_help = add_text_inlist(buttons_help, create_text(str[5],
        (sfVector2f) {480, 750}, (sfVector2f) {0.6, 0.6}, ARTYPA),
        len_list_text(buttons_help));
    return buttons_help;
}

t_text *create_help_menu_button(void)
{
    char **str = NULL;
    t_text *buttons_help = NULL;

    str = fopen_getline(str, "assets/txt/Info.txt");
    buttons_help = add_text_inlist(buttons_help, create_text(str[0],
        (sfVector2f) {480, 500}, (sfVector2f) {0.6, 0.6}, ARTYPA),
        len_list_text(buttons_help));
    buttons_help = add_text_inlist(buttons_help, create_text(str[1],
        (sfVector2f) {480, 550}, (sfVector2f) {0.6, 0.6}, ARTYPA),
        len_list_text(buttons_help));
    buttons_help = add_text_inlist(buttons_help, create_text(str[2],
        (sfVector2f) {480, 600}, (sfVector2f) {0.6, 0.6}, ARTYPA),
        len_list_text(buttons_help));
    buttons_help = create_help_menu_button_second_part(buttons_help, str);
    return buttons_help;
}
