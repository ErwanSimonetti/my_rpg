/*
** EPITECH PROJECT, 2021
** draw_combat.c
** File description:
** made to draw sprites in combat
*/

#include "structure.h"
#include "rpg.h"

static void draw_fighter(sfRenderWindow *window, t_infoGame *info, t_infoFighter
        fighter)
{
    sfVector2f name_pos = {fighter.position.x + ((fighter.name_len * 11) *
        (-1) + 100), fighter.position.y - 50};
    sfVector2f health_pos = {name_pos.x, name_pos.y - 10};
    sfVector2f health_size = {fighter.current_health * 1.5, 3};
    sfVector2f max_health_size = {fighter.max_health * 1.5, 3};

    (void)info;
    sfText_setPosition(fighter.name, name_pos);
    sfSprite_setPosition(fighter.sprite, fighter.position);
    sfRectangleShape_setSize(fighter.health_bar, health_size);
    sfRectangleShape_setSize(fighter.max_health_bar, max_health_size);
    sfRectangleShape_setPosition(fighter.health_bar, health_pos);
    sfRectangleShape_setPosition(fighter.max_health_bar, health_pos);
    sfRenderWindow_drawSprite(window, fighter.sprite, NULL);
    sfRenderWindow_drawText(window, fighter.name, NULL);
    sfRenderWindow_drawRectangleShape(window, fighter.max_health_bar, NULL);
    sfRenderWindow_drawRectangleShape(window, fighter.health_bar, NULL);
}

sfBool combat_button_hovered(sfText *text, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    int x = mouse_pos.x;
    int y = mouse_pos.y;

    sfFloatRect button = sfText_getGlobalBounds(text);
    return (sfFloatRect_contains(&button, x, y));
}

static int animate_combat_button(sfText *text, sfRenderWindow *window,
                                    const int turn)
{
    sfColor mauve = sfColor_fromRGB(135, 85, 150);
    sfColor pink = sfColor_fromRGB(215, 150, 235);
    sfColor grey = sfColor_fromRGB(144, 144, 144);

    if (turn != 1) {
        sfText_setOutlineColor(text, grey);
        return (0);
    }
    if (combat_button_hovered(text, window) == sfTrue &&
    sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        sfText_setOutlineColor(text, pink);
    else if (combat_button_hovered(text, window) == sfTrue)
        sfText_setOutlineColor(text, mauve);
    else
        sfText_setOutlineColor(text, sfBlack);
    return (1);
}

static void animate_buttons(t_infoGame *info, sfRenderWindow *window)
{
    animate_combat_button(info->combat.attack, window, info->combat.turn);
    animate_combat_button(info->combat.guard, window, info->combat.turn);
    animate_combat_button(info->combat.big_attack, window, info->combat.turn);
}

void draw_combat_scene(t_window *game, t_infoGame *info)
{
    sfRenderWindow_drawSprite(game->window, info->combat.floor, NULL);
    sfRenderWindow_drawSprite(game->window, info->combat.wall, NULL);
    draw_fighter(game->window, info, info->player);
    draw_fighter(game->window, info, info->enemy);
    sfRenderWindow_drawRectangleShape(game->window, info->combat.box, NULL);
    sfRenderWindow_drawText(game->window, info->combat.attack, NULL);
    sfRenderWindow_drawText(game->window, info->combat.guard, NULL);
    sfRenderWindow_drawText(game->window, info->combat.big_attack, NULL);
    animate_buttons(info, game->window);
}
