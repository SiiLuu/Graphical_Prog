/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** animation duck function.
*/

#include <stdlib.h>
#include <SFML/System.h>
#include <time.h>
#include "../include/my.h"

sfSprite *position(sfSprite *target, sfRenderWindow *window)
{
    srand(time(NULL));
    int r = rand() % 450 + 0;
    sfVector2f new_pos;

    new_pos.x = 0;
    new_pos.y = r;
    sfSprite_setPosition(target, new_pos);
    return (target);
}

duck_t *init_duck(duck_t *duck)
{
    srand(time(NULL));
    int r = rand() % 20 + 10;
    duck->offset.x = r;
    duck->offset.y = 0;
    duck->frame = 0;
    return (duck);
}

sfIntRect frame(int frame, sfIntRect rectangle)
{
    rectangle.left = 110 * frame;
    rectangle.top = 0;
    rectangle.width = 110;
    rectangle.height = 110;
    return (rectangle);
}

int manage_mouse(sfEvent event, sfSprite *target)
{
    sfVector2f target_pos;
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    target_pos = sfSprite_getPosition(target);
    if (x >= target_pos.x &&
        x <= target_pos.x + 110 &&
        y >= target_pos.y &&
        y <= target_pos.y + 110) {
        return (1);
    }
    else if (target_pos.x >= 1122)
        return (2);
    return (0);
}

void use_clock(sfClock *clock, duck_t *duck)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.17) {
        sfClock_restart(clock);
        duck->frame++;
    }
    if (duck->frame == 3)
        duck->frame = 0;
}