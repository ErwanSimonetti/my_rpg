/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** window_init.c
*/

#include <SFML/Window.h>
#include "rpg.h"

void window_init(t_window *game)
{
    sfImage *icon_img = sfImage_createFromFile("assets/img/X.png");
    const sfUint8* icon_ptr = sfImage_getPixelsPtr(icon_img);

    game->oldstatus = MAIN_MENU;
    game->status = MAIN_MENU;
    game->VSync = sfFalse;
    game->fpslimit = 60;
    game->sfx.game_theme = sfMusic_createFromFile("assets/sfx/game_theme.ogg");
    game->sfx.menu_theme = sfMusic_createFromFile("assets/sfx/menu_theme.ogg");
    game->sfx.combat_theme = sfMusic_createFromFile(
        "assets/sfx/combat_theme.ogg");
    game->sfx.launch_game_buffer = sfSoundBuffer_createFromFile(
        "assets/sfx/new_game.ogg");
    game->sfx.typing_sound_buffer = sfSoundBuffer_createFromFile(
        "assets/sfx/typing.ogg");
    game->sfx.success_sound_buffer = sfSoundBuffer_createFromFile(
        "assets/sfx/success.ogg");
    game->sfx.game_over_buffer = sfSoundBuffer_createFromFile(
        "assets/sfx/game_over.ogg");
    game->sfx.launch_game = sfSound_create();
    game->sfx.typing_sound = sfSound_create();
    game->sfx.success_sound = sfSound_create();
    game->sfx.game_over = sfSound_create();
    sfSound_setBuffer(game->sfx.launch_game,
        game->sfx.launch_game_buffer);
    sfSound_setBuffer(game->sfx.typing_sound,
        game->sfx.typing_sound_buffer);
    sfSound_setBuffer(game->sfx.success_sound,
        game->sfx.success_sound_buffer);
    sfSound_setBuffer(game->sfx.game_over,
    game->sfx.game_over_buffer);
    game->musicVolume = 50;
    game->soundVolume = 70;
    game->videoMode = (sfVideoMode){1920, 1080, 32};
    game->window = sfRenderWindow_create(game->videoMode,
        "XenoQuest", sfClose | sfResize, NULL);
    game->windowSize = sfRenderWindow_getSize(game->window);
    sfRenderWindow_setIcon(game->window, 221, 202, icon_ptr);
    sfMusic_setLoop(game->sfx.menu_theme, sfTrue);
    sfMusic_setLoop(game->sfx.game_theme, sfTrue);
    sfMusic_setVolume(game->sfx.menu_theme, game->musicVolume);
    sfMusic_play(game->sfx.menu_theme);
}
