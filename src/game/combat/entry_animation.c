/*
** EPITECH PROJECT, 2021
** entry_animation.c
** File description:
** made to animate entry
*/

#include "rpg.h"
#include "structure.h"

sfSprite *setup_background(t_window *game, t_infoGame *info)
{
    sfVector2u window_size = sfRenderWindow_getSize(game->window);
    sfSprite *game_screenshot = sfSprite_create();
    sfTexture *screenshot_texture = sfTexture_create(window_size.x, window_size.y);

    (void)game;
    info->background_pause = sfRenderWindow_capture(game->window);
    screenshot_texture = sfTexture_createFromImage(info->background_pause, NULL);
    sfSprite_setPosition(game_screenshot, (sfVector2f) {0, 0});
    sfSprite_setScale(game_screenshot, (sfVector2f) {1, 1});
    sfSprite_setTexture(game_screenshot, screenshot_texture, 1);
    sfView_reset(info->camera, (sfFloatRect) {0, 0, 1920, 1031});
    return (game_screenshot);
}

static void fade_black(t_window *game, t_infoGame *info, sfSprite *screenshot)
{
    sfTime time = sfClock_getElapsedTime(info->combat.clock);
    float seconds = sfTime_asMilliseconds(time);
    sfColor fade = sfColor_fromRGBA(255, 255, 255, 0);
    int alpha_screenshot = seconds;

    if (seconds >= 255)
        alpha_screenshot = 255;
    fade = sfColor_fromRGBA(255, 255, 255, alpha_screenshot);
    sfSprite_setColor(screenshot, fade);
    sfRenderWindow_drawSprite(game->window, screenshot, NULL);
}

static void fade_white(t_infoGame *info)
{
    sfTime time = sfClock_getElapsedTime(info->combat.clock);
    float seconds = sfTime_asMilliseconds(time);
    int alpha_rect = 0;
    sfColor fade_rect = sfColor_fromRGBA(255, 255, 255, 0);

    if (seconds >= 650)
        alpha_rect = (seconds -650) * 2;
    if (seconds > 650 && seconds < 800)
        alpha_rect = 255;
    if (seconds > 800)
        alpha_rect = 255 - (seconds - 800) * 2;
    if (alpha_rect <= 0)
        alpha_rect = 0;
    fade_rect = sfColor_fromRGBA(255, 255, 255, alpha_rect);
    sfRectangleShape_setFillColor(info->combat.white_fade, fade_rect);
    sfRectangleShape_setSize(info->combat.white_fade, (sfVector2f) {100000,
            100000});
}

void animate_entry(t_window *game, t_infoGame *info, sfSprite *screenshot)
{
    sfTime time = sfClock_getElapsedTime(info->combat.clock);
    float seconds = sfTime_asMilliseconds(time);
    sfVector2f size_view = sfView_getSize(info->camera);

    if (seconds > 1450 && size_view.x > 650)
        sfView_zoom(info->camera, 0.93);
    fade_black(game, info, screenshot);
    fade_white(info);
    sfRenderWindow_drawRectangleShape(game->window, info->combat.white_fade,
            NULL);
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
}
