/*
** EPITECH PROJECT, 2018
** runner
** File description:
** my_runner.
*/

#include "../include/my.h"

void jump_start(anim_t *anim)
{
    anim->of_man.y = -15;
}

void jump_end(anim_t *anim)
{
    anim->of_man.y = +15;
}

sfSprite *position_p(sfSprite *target)
{
    sfVector2f size;

    size = sfSprite_getPosition(target);
    if (size.y <= 550) {
        size.y += +15;
        sfSprite_setPosition(target, size);
    }
    return (target);
}

sfSprite *position_pl(sfSprite *target)
{
    sfVector2f size;

    size = sfSprite_getPosition(target);
    if (size.y >= 780) {
        size.y -= 15;
        sfSprite_setPosition(target, size);
    }
    return (target);
}