/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** game runner.
*/

#include "../include/my.h"

void load_doublon(sfRenderWindow *window, set_t *set)
{
    set->candy = sfTexture_createFromFile("sprites/cane.png", NULL);
    set->enemi2 = sfTexture_createFromFile("sprites/enemi2.png", NULL);
    set->enemi = sfTexture_createFromFile("sprites/enemi.png", NULL);
    set->tree2 = sfTexture_createFromFile("sprites/layer03_trees.png", NULL);
    set->cloud2 = sfTexture_createFromFile("sprites/layer04_clouds.png", NULL);
    set->mountain2 = sfTexture_createFromFile("sprites/layer05_rocks.png",
        NULL);
    set->cake2 = sfTexture_createFromFile("sprites/layer02_cake.png", NULL);
    set->ground2 = sfTexture_createFromFile("sprites/layer01_ground.png", NULL);
    set->tree12 = sfSprite_create();
    set->enemi12 = sfSprite_create();
    set->enemi1 = sfSprite_create();
    set->candy1 = sfSprite_create();
    set->cloud12 = sfSprite_create();
    set->mountain12 = sfSprite_create();
    set->cake12 = sfSprite_create();
    set->cake12 = sfSprite_create();
    set->ground12 = sfSprite_create();
    text_init(window, set);
    load_obstacle(window, set);
}

void destroy_doublon(sfRenderWindow *window, set_t *set)
{
    sfSprite_destroy(set->ground12);
    sfSprite_destroy(set->enemi1);
    sfSprite_destroy(set->enemi12);
    sfSprite_destroy(set->candy1);
    sfSprite_destroy(set->cake12);
    sfSprite_destroy(set->tree12);
    sfSprite_destroy(set->mountain12);
    sfSprite_destroy(set->cloud12);
    sfTexture_destroy(set->ground2);
    sfTexture_destroy(set->enemi2);
    sfTexture_destroy(set->enemi);
    sfTexture_destroy(set->candy);
    sfTexture_destroy(set->cake2);
    sfTexture_destroy(set->tree2);
    sfTexture_destroy(set->mountain2);
    sfTexture_destroy(set->cloud2);
    sfText_destroy(set->score);
    sfText_destroy(set->score_i);
}

void display_doublon(sfRenderWindow *window, set_t *set, anim_t *duck)
{
    sfIntRect rect;

    rect = frame(duck->frame, rect);
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setTextureRect(set->player1, rect);
    sfSprite_move(set->ground1, duck->of_ground);
    sfSprite_move(set->cake1, duck->of_cake);
    sfSprite_move(set->tree1, duck->of_tree);
    sfSprite_move(set->mountain1, duck->of_mountain);
    sfSprite_move(set->cloud1, duck->of_cloud);
    sfSprite_move(set->ground12, duck->of_ground2);
    sfSprite_move(set->cake12, duck->of_cake2);
    sfSprite_move(set->tree12, duck->of_tree2);
    sfSprite_move(set->mountain12, duck->of_mountain2);
    sfSprite_move(set->cloud12, duck->of_cloud2);
    sfSprite_move(set->candy1, duck->of_cane);
    sfSprite_move(set->enemi1, duck->of_enemi);
    sfSprite_move(set->enemi12, duck->of_enemi2);
    sfSprite_move(set->player1, duck->of_man);
}

void text_init(sfRenderWindow *window, set_t *set)
{
    set->i = 0;
    set->score = sfText_create();
    set->score_i = sfText_create();
    set->fon = sfFont_createFromFile("sprites/orange juice 2.0.ttf");
    sfText_setString(set->score, "Score :");
    sfText_setFont(set->score, set->fon);
    sfText_setFont(set->score_i, set->fon);
    sfText_setCharacterSize(set->score, 100);
    sfText_setCharacterSize(set->score_i, 100);
    sfText_setColor(set->score, sfMagenta);
    sfText_setColor(set->score_i, sfMagenta);
}