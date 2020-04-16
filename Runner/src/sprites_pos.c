/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** my_runner.
*/

#include "../include/my.h"

void display(sfRenderWindow *window, set_t *set, anim_t *anim)
{
    display_doublon(window, set, anim);
    sfRenderWindow_drawSprite(window, set->sky1, NULL);
    set->cloud1 = position_sprites(set->cloud1);
    set->cloud12 = position_sprites(set->cloud12);
    sfRenderWindow_drawSprite(window, set->cloud1, NULL);
    sfRenderWindow_drawSprite(window, set->cloud12, NULL);
    set->mountain1 = position_sprites(set->mountain1);
    set->mountain12 = position_sprites(set->mountain12);
    sfRenderWindow_drawSprite(window, set->mountain1, NULL);
    sfRenderWindow_drawSprite(window, set->mountain12, NULL);
    set->cake1 = position_sprites(set->cake1);
    set->cake12 = position_sprites(set->cake12);
    sfRenderWindow_drawSprite(window, set->cake1, NULL);
    sfRenderWindow_drawSprite(window, set->cake12, NULL);
}

void display2(sfRenderWindow *window, set_t *set, anim_t *anim)
{
    display(window, set, anim);
    set->tree1 = position_sprites(set->tree1);
    set->tree12 = position_sprites(set->tree12);
    sfRenderWindow_drawSprite(window, set->tree1, NULL);
    sfRenderWindow_drawSprite(window, set->tree12, NULL);
    set->ground1 = position_sprites(set->ground1);
    set->ground12 = position_sprites(set->ground12);
    sfRenderWindow_drawSprite(window, set->ground1, NULL);
    sfRenderWindow_drawSprite(window, set->ground12, NULL);
    set->player1 = position_p(set->player1);
    set->player1 = position_pl(set->player1);
    sfRenderWindow_drawSprite(window, set->player1, NULL);
    set->candy1 = position_ob(set->candy1);
    sfRenderWindow_drawSprite(window, set->candy1, NULL);
    set->enemi1 = position_ob(set->enemi1);
    sfRenderWindow_drawSprite(window, set->enemi1, NULL);
    set->enemi12 = position_ob(set->enemi12);
    sfRenderWindow_drawSprite(window, set->enemi12, NULL);
}

void display3(sfRenderWindow *window, set_t *set, anim_t *anim)
{
    display2(window, set, anim);
    set->score = position_text(set->score);
    set->score_i = position_text2(set->score_i);
    sfRenderWindow_drawText(window, set->score, NULL);
    set->str = int_to_char(set->i);
    sfText_setString(set->score_i, set->str);
    sfRenderWindow_drawText(window, set->score_i, NULL);
    sfRenderWindow_display(window);
}