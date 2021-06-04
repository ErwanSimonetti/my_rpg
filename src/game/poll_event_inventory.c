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

int poll_event_click_inventory_rect(t_window *game)
{
    (void)game;
    return 0;
}

int poll_event_click_inventory_text(t_window *game)
{
    (void)game;
    return 0;
}

int poll_event_click_inventory(t_window *game, t_text *buttons,
    t_rect *rect_option)
{
    if (game->mousePos.y >= 825 && game->mousePos.y <= 858) {
        game->status = game->oldstatus;
        game->oldstatus = INVENTORY_MENU;
        return 1;
    }
    return 0;
}

int poll_event_inventory(t_window *game, t_text *buttons, t_rect *box)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            close_window(game);
        if (game->event.type == sfEvtMouseButtonReleased
                && game->event.mouseButton.button == sfMouseLeft)
            if (poll_event_click_inventory(game, buttons, box) == 1)
                return 1;
        if (game->event.type == sfEvtKeyPressed)
            check_arrow_for_button(game, buttons);
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            game->status = game->oldstatus;
            game->oldstatus = INVENTORY_MENU;
            return 1;
        }
    }
    return 0;
}
