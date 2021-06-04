/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** clock_init.c
*/

#include "structure.h"

void clock_init(t_clock *clock)
{
    clock->fpsClock = sfClock_create();
    clock->fps = 0;
    clock->spriteClock = sfClock_create();
    clock->spriteStatus = 1;
    clock->vectorClock = sfClock_create();
}