/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** poll_event_menu.c
*/

#include "rpg.h"
#include "menu.h"
#include "structure.h"
#include <stdio.h>

int poll_event_click_pause_text(t_window *game)
{
    if (game->mousePos.y >= 401 && game->mousePos.y <= 431) {
        game->status = game->oldstatus;
        game->oldstatus = PAUSE_MENU;
        return 1;
    }
    if (game->mousePos.y >= 500 && game->mousePos.y <= 532) {
        game->status = SETTINGS_PAUSE;
        return 1;
    }
    if (game->mousePos.y >= 600 && game->mousePos.y <= 632) {
        game->status = SAVE_MENU;
        return 1;
    }
    if (game->mousePos.y >= 702 && game->mousePos.y <= 732)
        close_window(game);
    return 0;
}

int poll_event_click_pause_buttons(t_window *game, t_text *buttons)
{
    for (; buttons; buttons = buttons->next)
        if (button_hovered(buttons->text, game) == sfTrue) {
            if (poll_event_click_pause_text(game) == 1)
                return 1;
        }
    return 0;
}

int poll_event_click_settings_pause_rect(t_window *game)
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

int poll_event_click_settings_pause_text(t_window *game)
{
    if (game->mousePos.y >= 825 && game->mousePos.y <= 858) {
        game->status = PAUSE_MENU;
        return 1;
    }
    return 0;
}

int poll_event_click_settings_pause(t_window *game, t_text *buttons,
    t_rect *box)
{
    for (; buttons; buttons = buttons->next)
        if (button_hovered(buttons->text, game) == sfTrue) {
            if (poll_event_click_settings_pause_text(game) == 1)
                return 1;
        }
    for (; box; box = box->next)
        if (rectangle_hovered(box->rectangle, game) == sfTrue) {
            if (poll_event_click_settings_pause_rect(game) == 1)
                return 1;
        }
    return 0;
}

int poll_event_click_save_menu_text(t_window *game)
{
    if (game->mousePos.y >= 500 && game->mousePos.y <= 532
        && game->mousePos.x >= 799 && game->mousePos.x <= 880) {
        sfMusic_stop(game->sfx.game_theme);
        sfMusic_play(game->sfx.menu_theme);
        game->status = MAIN_MENU;
        return 1;
    }
    if (game->mousePos.y >= 500 && game->mousePos.y <= 532
        && game->mousePos.x >= 1041 && game->mousePos.x <= 1097) {
        game->status = MAIN_MENU;
        return 1;
    }
    if (game->mousePos.y >= 825 && game->mousePos.y <= 858) {
        game->status = PAUSE_MENU;
        return 1;
    }
    return 0;
}

int poll_event_click_save_menu(t_window *game, t_text *buttons)
{
    for (; buttons; buttons = buttons->next)
        if (button_hovered(buttons->text, game) == sfTrue) {
            if (poll_event_click_save_menu_text(game) == 1)
                return 1;
        }
    return 0;
}

int poll_event_click_pause(t_window *game, t_text *buttons, t_rect *box)
{
    if (buttons == NULL)
        return 0;
    switch(game->status) {
    case (PAUSE_MENU):
        if (poll_event_click_pause_buttons(game, buttons) == 1) {
            return 1;
        } else
            return 0;
    case (SETTINGS_PAUSE):
        if (poll_event_click_settings_pause(game, buttons, box) == 1)
            return 1;
        else
            return 0;
    case (SAVE_MENU):
        if (poll_event_click_save_menu(game, buttons) == 1)
            return 1;
        else
            return 0;
    default:
        return 0;
    }
}

int poll_event_pause(t_window *game, t_text *buttons, t_rect *box)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            close_window(game);
        if (game->event.type == sfEvtMouseButtonReleased
                && game->event.mouseButton.button == sfMouseLeft)
            if (poll_event_click_pause(game, buttons, box) == 1)
                return 1;
        if (game->event.type == sfEvtKeyPressed)
            check_arrow_for_button(game, buttons);
    }
    return 0;
}
