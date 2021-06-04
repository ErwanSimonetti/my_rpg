/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** give the size of a string
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i += 1;
    return (i);
}
