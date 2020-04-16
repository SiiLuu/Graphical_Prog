/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** my.h
*/

#include <SFML/Graphics.h>

#ifndef _MY_H_
# define _MY_H_

typedef struct elem_s
{
    sfTexture *texture;
    sfSprite *sprite;
} elem_t;

typedef struct duck_s
{
    sfVector2f offset;
    int frame;
} duck_t;

void check_shot(duck_t *duck, sfEvent event, sfSprite *target,
    sfRenderWindow *window);
void analyse_event(sfRenderWindow *window, sfEvent event,
    sfSprite *target, duck_t *duck);
sfSprite *position(sfSprite *target, sfRenderWindow *window);
duck_t *init_duck(duck_t *duck);
sfIntRect frame(int frame, sfIntRect rectangle);
int manage_mouse(sfEvent event, sfSprite *target);
void use_clock(sfClock *clock, duck_t *duck);
void my_putchar(char c);
void my_putstr(char *s);
void usage_func(int ac, char **av);

#endif