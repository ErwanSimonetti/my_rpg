/*
** EPITECH PROJECT, 2021
** check_save.c
** File description:
** check if a save exist or not
*/

#include "lib.h"
#include <stddef.h>

int is_there_a_save(void)
{
    char *buffer = open_read("assets/save/last_save.txt");

    if (buffer == NULL)
        return -1;
    if (buffer[0] == '\0')
        return -1;
    return 0;
}
