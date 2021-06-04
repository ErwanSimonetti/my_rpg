/*
** EPITECH PROJECT, 2021
** free.c
** File description:
** free different things
*/

#include <stdlib.h>

void free_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; ++i)
        free(array[i]);
    free(array);
}
