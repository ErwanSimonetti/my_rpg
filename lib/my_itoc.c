/*
** EPITECH PROJECT, 2021
** My_RPG
** File description:
** my_itoc.c
*/

#include "stdlib.h"

char *my_itoc(int nb)
{
    char *str;
    int len;
    int count;

    if (nb == 0) {
        str = malloc((sizeof(char)) * 2);
        str[0] = '0';
        str[1] = '\0';
    } else {
        len = 0;
        count = nb;
        while (count > 0) {
            count /= 10;
            len++;
        }
        str = malloc((sizeof(char)) * (len + 1));
        str[len] = '\0';
        while (len--) {
            str[len] = nb % 10 + '0';
            nb /= 10;
        }
    }
    return (str);
}