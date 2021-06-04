/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** display_inventory.c
*/

#include "rpg.h"
#include "chained_list.h"
#include "game.h"
#include "lib.h"
#include "structure.h"

void quest_inventory(t_window *game, t_infoGame *info, t_sprite *sprites)
{
    if (info->statushistory == 2)
        for (t_sprite *tmp = sprites; tmp; tmp = tmp->next)
            if (tmp->filepath[11] == 'C')
                sfRenderWindow_drawSprite(game->window,
                    tmp->sprite, NULL);
    if (info->statushistory >= 5)
        for (t_sprite *tmp = sprites; tmp; tmp = tmp->next)
            if (tmp->filepath[11] == 'R')
                sfRenderWindow_drawSprite(game->window,
                    tmp->sprite, NULL);
}

void display_inventory(t_window *game, t_clock *clock, t_infoGame *info)
{
    (void)clock;
    t_sprite *quest = create_inventory_quest_sprites();
    t_sprite *sprites = create_inventory_menu_sprites();
    t_rect *rect_inventory = create_inventory_menu_rectangle();
    t_text *buttons_inventory = create_inventory_menu_button_animated();
    t_text *text = create_inventory_menu_button(info);
    sfSprite *back = create_background_from_game(info);

    sfView_reset(info->camera, (sfFloatRect) {0, 0, 1920, 1031});
    while (sfRenderWindow_isOpen(game->window)) {
        if (poll_event_inventory(game, buttons_inventory, NULL) == 1)
            return;
        game->mousePos = sfMouse_getPositionRenderWindow(game->window);
        sfRenderWindow_setFramerateLimit(game->window, game->fpslimit);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_setView(game->window, info->camera);
        sfRenderWindow_drawSprite(game->window, back, NULL);
        draw_rectangle(&game->window, rect_inventory);
        draw_sprite(&game->window, sprites);
        draw_text_animated(game, buttons_inventory);
        draw_text(game, text);
        quest_inventory(game, info, quest);
        sfRenderWindow_display(game->window);
    }
}
