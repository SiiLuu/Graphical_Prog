/*
** EPITECH PROJECT, 2018
** hitbox
** File description:
** hitbox and animation functions.
*/

#include "../include/my.h"

void check_shot(duck_t *duck, sfEvent event, sfSprite *target,
    sfRenderWindow *window)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (manage_mouse(event, target) == 1) {
            target = position(target, window);
            my_putchar('X');
        }
        else if (manage_mouse(event, target) == 0) {
            sfRenderWindow_close(window);
            my_putchar('\n');
            my_putstr("Game Over !\n");
        }
    }
}

void analyse_event(sfRenderWindow *window, sfEvent event,
    sfSprite *target, duck_t *duck)
{
    if (event.type == sfEvtMouseButtonPressed) {
        check_shot(duck, event, target, window);
    }
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}