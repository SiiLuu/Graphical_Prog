/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** game runner.
*/

#include "../include/my.h"

void load_obstacle(sfRenderWindow *window, set_t *set)
{
    sfSprite_setTexture(set->tree12, set->tree2, sfTrue);
    sfSprite_setTexture(set->cloud12, set->cloud2, sfTrue);
    sfSprite_setTexture(set->mountain12, set->mountain2, sfTrue);
    sfSprite_setTexture(set->cake12, set->cake2, sfTrue);
    sfSprite_setTexture(set->ground12, set->ground2, sfTrue);
    sfSprite_setTexture(set->candy1, set->candy, sfTrue);
    sfSprite_setTexture(set->enemi1, set->enemi, sfTrue);
    sfSprite_setTexture(set->enemi12, set->enemi2, sfTrue);
}

sfSprite *position_obstacle(sfSprite *target)
{
    sfVector2f new_pos;

    new_pos.x = 2500;
    new_pos.y = 740;
    sfSprite_setPosition(target, new_pos);
    return (target);
}

sfSprite *position_enemi(sfSprite *target)
{
    sfVector2f new_pos;

    new_pos.x = 3250;
    new_pos.y = 550;
    sfSprite_setPosition(target, new_pos);
    return (target);
}

sfSprite *position_enemi2(sfSprite *target)
{
    sfVector2f new_pos;

    new_pos.x = 4000;
    new_pos.y = 740;
    sfSprite_setPosition(target, new_pos);
    return (target);
}

sfSprite *position_ob(sfSprite *target)
{
    sfVector2f size;

    size = sfSprite_getPosition(target);
    if (size.x == -500) {
        size.x = 1950;
        sfSprite_setPosition(target, size);
    }
    return (target);
}