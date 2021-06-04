/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** poll_event_menu.c
*/

#include "rpg.h"
#include "menu.h"
#include "structure.h"

int poll_event_click_menu_text(t_window *game)
{
    if (game->mousePos.y >= 401 && game->mousePos.y <= 431) {
        sfSound_play(game->sfx.launch_game);
        game->status = NEW_GAME;
        return 1;
    }
    if (game->mousePos.y >= 600 && game->mousePos.y <= 632) {
        game->status = SETTINGS_MENU;
        return 1;
    }
    if (game->mousePos.y >= 700 && game->mousePos.y <= 732) {
        game->status = HELP_MENU;
        return 1;
    }
    if (game->mousePos.y >= 802 && game->mousePos.y <= 832)
        close_window(game);
    return 0;
}

int poll_event_click_menu(t_window *game, t_text *buttons)
{
    for (; buttons; buttons = buttons->next)
        if (button_hovered(buttons->text, game) == sfTrue) {
            if (poll_event_click_menu_text(game) == 1)
                return 1;
        }
    return 0;
}

int poll_event_click_settings_rect(t_window *game)
{
    if (game->mousePos.x >= 948 && game->mousePos.x <= 986
        && game->mousePos.y >= 468 && game->mousePos.y <= 506) {
        if (game->fpslimit == 144) {
            game->fpslimit = 120;
            return 1;
        } else if (game->fpslimit == 120) {
            game->fpslimit = 60;
            return 1;
        } else
            return 1;
    }
    if (game->mousePos.x >= 1148 && game->mousePos.x <= 1186
        && game->mousePos.y >= 468 && game->mousePos.y <= 506) {
        if (game->fpslimit == 60) {
            game->fpslimit = 120;
            return 1;
        } else if (game->fpslimit == 120) {
            game->fpslimit = 144;
            return 1;
        } else
            return 1;
    }
    if (game->mousePos.x >= 1048 && game->mousePos.x <= 1086
        && game->mousePos.y >= 528 && game->mousePos.y <= 566) {
            if (game->VSync == sfFalse)
                game->VSync = sfTrue;
            else
                game->VSync = sfFalse;
            return 1;
        }
    return 0;
}

int poll_event_click_settings_text(t_window *game)
{
    if (game->mousePos.y >= 825 && game->mousePos.y <= 858) {
        game->status = MAIN_MENU;
        return 1;
    }
    return 0;
}

int poll_event_click_settings(t_window *game, t_text *buttons,
    t_rect *rect_option)
{
    for (; buttons; buttons = buttons->next)
        if (button_hovered(buttons->text, game) == sfTrue) {
            if (poll_event_click_settings_text(game) == 1)
                return 1;
        }
    for (; rect_option; rect_option = rect_option->next)
        if (rectangle_hovered(rect_option->rectangle, game) == sfTrue) {
            if (poll_event_click_settings_rect(game) == 1)
                return 1;
        }
    return 0;
}

int poll_event_click_help_text(t_window *game)
{
    if (game->mousePos.y >= 825 && game->mousePos.y <= 858) {
        game->status = MAIN_MENU;
        return 1;
    }
    return 0;
}

int poll_event_press_buttons(t_window *game, t_text *buttons)
{
    sfColor mauve = sfColor_fromRGB(135, 85, 150);

    for (int i = 0; buttons != NULL; buttons = buttons->next, ++i)
        if (game->event.type == sfEvtKeyPressed && game->event.key.code ==
            sfKeyEnter && sfColor_toInteger(sfText_getOutlineColor(
            buttons->text)) == sfColor_toInteger(mauve)) {
            if (i == NEW_GAME)
                sfSound_play(game->sfx.launch_game);
            game->status = i;
            return 1;
        }
    return 0;
}

int poll_event_press_escape(t_window *game)
{
    if (game->event.type == sfEvtKeyPressed && game->event.key.code ==
        sfKeyEscape && game->status == HELP_MENU) {
        game->status = MAIN_MENU;
        return 1;
    }
    return 0;
}

int poll_event_press_escape2(t_window *game)
{
    if (game->event.type == sfEvtKeyPressed && game->event.key.code ==
        sfKeyEscape && game->status == SETTINGS_MENU) {
        game->status = MAIN_MENU;
        return 1;
    }
    return 0;
}

int poll_event_click_help(t_window *game, t_text *buttons)
{
    for (; buttons; buttons = buttons->next)
        if (button_hovered(buttons->text, game) == sfTrue) {
            if (poll_event_click_help_text(game) == 1)
                return 1;
        }
    return 0;
}

int poll_event_click(t_window *game, t_text *buttons, t_rect *rect_option)
{
    if (buttons == NULL)
        return 0;
    switch (game->status) {
    case (MAIN_MENU):
        if (poll_event_click_menu(game, buttons) == 1)
            return 1;
        else
            return 0;
    case (SETTINGS_MENU):
        if (poll_event_click_settings(game, buttons, rect_option) == 1)
            return 1;
        else
            return 0;
    case (HELP_MENU):
        if (poll_event_click_help(game, buttons) == 1)
            return 1;
        else
            return 0;
    default:
        return 0;
    }
}

int poll_event_menu(t_window *game, t_text *buttons, t_rect *rect_option)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            close_window(game);
        if (game->event.type == sfEvtMouseButtonReleased
                && game->event.mouseButton.button == sfMouseLeft)
            if (poll_event_click(game, buttons, rect_option) == 1)
                return 1;
        if (game->event.type == sfEvtKeyPressed)
            check_arrow_for_button(game, buttons);
        if (game->status == MAIN_MENU)
            if (poll_event_press_buttons(game, buttons) == 1)
                return 1;
        if (game->status == SETTINGS_MENU)
            if (poll_event_press_escape2(game) == 1)
                return 1;
        if (game->status == HELP_MENU)
            if (poll_event_press_escape(game) == 1)
                return 1;
    }
    return 0;
}
