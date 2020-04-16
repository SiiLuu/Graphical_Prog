/*
** EPITECH PROJECT, 2018
** use_func
** File description:
** tools.
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *s)
{
    for (int i = 0 ; s[i] != 0 ; i++)
        my_putchar(s[i]);
}

void usage_func(int ac, char **av)
{
    if ((ac == 2) && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("USAGE\n");
        my_putstr("\t.Launch with : /my_hunter\n\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("\t- The goal of this game is to reach a maximum ");
        my_putstr("of ducks.\n");
        my_putstr("\t- Whenever you touch a duck a cross is added to\n");
        my_putstr("\t  your score on the terminal.\n");
        my_putstr("\t- When you miss the duck the game stops ");
        my_putstr("(Game Over !).\n");
        my_putstr("\t- Plus the speed of the duck is random :)\n\n");
    }
}