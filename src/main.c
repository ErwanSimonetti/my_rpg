/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** main.c
*/

#include <stdio.h>
#include "rpg.h"

int main(int ac, char const *const av[], char **env)
{
    (void)av;
    if (ac != 1)
        return (84);
    else if (env[46] == NULL)
        return (84);
    else
        window();
    return (0);
}
