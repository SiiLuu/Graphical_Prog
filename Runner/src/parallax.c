/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** animation duck function.
*/

#include "../include/my.h"

sfSprite *position_sprites2(sfSprite *target)
{
    sfVector2f new_pos;

    new_pos.x = 1920;
    new_pos.y = 0;
    sfSprite_setPosition(target, new_pos);
    return (target);
}

sfText *position_text(sfText *target)
{
    sfVector2f pos;

    pos.x = 25;
    pos.y = 0;
    sfText_setPosition(target, pos);
    return (target);
}

sfText *position_text2(sfText *target)
{
    sfVector2f pos;

    pos.x = 325;
    pos.y = 0;
    sfText_setPosition(target, pos);
    return (target);
}

sfSprite *position_sprites(sfSprite *target)
{
    sfVector2f size;

    size = sfSprite_getPosition(target);
    if (size.x == -1920) {
        size.x = 1920;
        sfSprite_setPosition(target, size);
    }
    return (target);
}