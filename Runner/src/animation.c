/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** my_runner.
*/

#include "../include/my.h"

sfSprite *position(sfSprite *target, sfRenderWindow *window)
{
    sfVector2f new_pos;

    new_pos.x = 100;
    new_pos.y = 770;
    sfSprite_setPosition(target, new_pos);
    return (target);
}

anim_t *init_man(anim_t *duck)
{
    duck->of_ground.x = -10;
    duck->of_ground2.x = -10;
    duck->of_cane.x = -10;
    duck->of_enemi.x = -10;
    duck->of_enemi2.x = -10;
    duck->of_tree.x = -8;
    duck->of_tree2.x = -8;
    duck->of_cake.x = -8;
    duck->of_cake2.x = -8;
    duck->of_mountain.x = -5;
    duck->of_mountain2.x = -5;
    duck->of_cloud.x = -3;
    duck->of_cloud2.x = -3;
    duck->of_cloud2.x = -3;
    duck->frame = 0;
    return (duck);
}

sfIntRect frame(int frame, sfIntRect rectangle)
{
    rectangle.left = 107.75 * frame;
    rectangle.top = 0;
    rectangle.width = 108;
    rectangle.height = 130;
    return (rectangle);
}

void use_clock(sfClock *clock, set_t *set, anim_t *duck)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.125) {
        sfClock_restart(clock);
        duck->frame++;
        set->i++;
    }
    if (duck->frame == 8)
        duck->frame = 0;
}

void use_clock2(sfRenderWindow *window, set_t *set, sfClock *clock,
    anim_t *duck)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.1) {
        sfClock_restart(clock);
        duck = init_man(duck);
    }
}