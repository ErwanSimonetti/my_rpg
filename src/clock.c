/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** get_fps.c
*/

#include "lib.h"
#include "game.h"
#include "structure.h"

void get_fps(t_clock *clock, t_text *fps)
{
    sfTime time = sfClock_getElapsedTime(clock->fpsClock);
    float time_to_seconds = sfTime_asSeconds(time);

    clock->fps++;
    if (time_to_seconds <= 1.0)
        return;
    else {
        sfText_setString(fps->text, my_itoc(clock->fps));
        clock->fps = 0;
        sfClock_restart(clock->fpsClock);
    }
}

void get_sprite(t_clock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock->spriteClock);
    float time_to_seconds = sfTime_asSeconds(time);

    if (time_to_seconds <= 0.15)
        return;
    else {
        clock->spriteStatus++;
        if (clock->spriteStatus == 5)
            clock->spriteStatus = 1;
        sfClock_restart(clock->spriteClock);
    }
}

void get_vector(t_clock *clock, t_infoGame *info)
{
    sfTime time = sfClock_getElapsedTime(clock->vectorClock);
    float time_to_seconds = sfTime_asSeconds(time);

    if (time_to_seconds <= 0.034)
        return;
    else {
        if (info->statusMove == 1)
            info->character_move.y -= 2;
        if (info->statusMove == 4)
            info->character_move.x -= 2;
        if (info->statusMove == 3)
            info->character_move.y += 2;
        if (info->statusMove == 2)
            info->character_move.x += 2;
    }
    sfClock_restart(clock->vectorClock);
}
