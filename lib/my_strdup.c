/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** duplicate a string
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strdup(char *dest, char *src)
{
    dest = malloc(my_strlen(src) + 1);
    for (int i = 0; src[i] != '\0'; i += 1) {
        dest[i] = src[i];
        dest[i + 1] = '\0';
    }
    return (dest);
}