/*
** EPITECH PROJECT, 2021
** handle_volume_cursor.c
** File description:
** handle volume
*/

#include "rpg.h"
#include "structure.h"

static void set_volume(t_window *window, sfVector2f mouse_pos)
{
    if (mouse_pos.y <= 750)
        window->musicVolume = (mouse_pos.x - 936) * 0.345;
    else
        window->soundVolume = (mouse_pos.x - 936) * 0.345;
    sfMusic_setVolume(window->sfx.menu_theme, window->musicVolume);
    sfMusic_setVolume(window->sfx.game_theme, window->musicVolume);
    sfMusic_setVolume(window->sfx.combat_theme, window->musicVolume);
    sfSound_setVolume(window->sfx.launch_game, window->soundVolume);
    sfSound_setVolume(window->sfx.typing_sound, window->soundVolume);
    sfSound_setVolume(window->sfx.success_sound, window->soundVolume);
    sfSound_setVolume(window->sfx.game_over, window->soundVolume);
}

void handle_volume_cursor(sfRectangleShape *rect, sfText *cursor,
        t_window *window)
{
    sfVector2f cursor_pos = sfText_getPosition(cursor);
    sfVector2f mouse_pos = {window->mousePos.x - 12, cursor_pos.y};
    sfVector2f music_pos = {(window->musicVolume / 0.345) + 936, cursor_pos.y};
    sfVector2f sound_pos = {(window->soundVolume / 0.345) + 936, cursor_pos.y};
    sfFloatRect bar = sfRectangleShape_getGlobalBounds(rect);

    if (cursor_pos.y <=  750)
        sfText_setPosition(cursor, music_pos);
    else
        sfText_setPosition(cursor, sound_pos);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        if (sfFloatRect_contains(&bar, window->mousePos.x, window->mousePos.y)
                || sfFloatRect_contains(&bar, window->mousePos.x,
                window->mousePos.y - 10) || sfFloatRect_contains(&bar,
                window->mousePos.x, window->mousePos.y + 10)) {
            set_volume(window, mouse_pos);
            sfText_setPosition(cursor, mouse_pos);
        }
}
