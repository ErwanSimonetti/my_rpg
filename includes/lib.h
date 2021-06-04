/*
** EPITECH PROJECT, 2021
** lib.h
** File description:
** lib's prototype
*/

#ifndef LIB
#define LIB

void free_array(char **array);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char *str1, char *str2);
char *my_itoc(int nb);
char *open_read(char const *filename);
char *my_strdup(char *dest, char *src);
char *concat_str(char *str1, char *str2, char concat);
char **fopen_getline(char **buffer, char *filename);

#endif /* !LIB */
