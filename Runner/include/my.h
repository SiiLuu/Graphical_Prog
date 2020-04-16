/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** my.h
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <stdlib.h>

#ifndef _MY_H_
# define _MY_H_

typedef struct set_s
{
    sfTexture *sky;
    sfTexture *enemi;
    sfTexture *candy;
    sfTexture *tree;
    sfTexture *enemi2;
    sfTexture *player;
    sfTexture *mountain;
    sfTexture *cloud;
    sfTexture *cake;
    sfTexture *ground;
    sfSprite *sky1;
    sfSprite *enemi1;
    sfSprite *enemi12;
    sfSprite *candy1;
    sfSprite *tree1;
    sfSprite *player1;
    sfSprite *cloud1;
    sfSprite *mountain1;
    sfSprite *cake1;
    sfSprite *ground1;

    sfTexture *tree2;
    sfTexture *mountain2;
    sfTexture *cloud2;
    sfTexture *cake2;
    sfTexture *ground2;
    sfSprite *tree12;
    sfSprite *cloud12;
    sfSprite *mountain12;
    sfSprite *cake12;
    sfSprite *ground12;
    sfMusic *sound;

    sfFont *fon;
    sfText *score;
    sfText *score_i;
    char *str;
    int i;
} set_t;

typedef struct anim_s
{
    sfVector2f of_player;
    sfVector2f of_enemi2;
    sfVector2f of_cane;
    sfVector2f of_enemi;
    sfVector2f of_ground;
    sfVector2f of_cake;
    sfVector2f of_tree;
    sfVector2f of_mountain;
    sfVector2f of_cloud;
    sfVector2f of_man;

    sfVector2f of_ground2;
    sfVector2f of_cake2;
    sfVector2f of_tree2;
    sfVector2f of_mountain2;
    sfVector2f of_cloud2;
    int frame;
} anim_t;

typedef struct menu_s
{
    sfText *menu_p;
    char *txt;
    sfVector2f pos;
} menu_t;

void analyse_event(sfRenderWindow *window, sfEvent event,
    set_t *set, anim_t *duck);
sfSprite *position(sfSprite *target, sfRenderWindow *window);
anim_t *init_man(anim_t *duck);
sfIntRect frame(int frame, sfIntRect rectangle);
void use_clock(sfClock *clock, set_t *set, anim_t *duck);
void my_putchar(char c);
void my_putstr(char *s);
void usage_func(int ac, char **av);
anim_t *init_ground(anim_t *duck);
anim_t *init_cake(anim_t *duck);
anim_t *init_tree(anim_t *duck);
anim_t *init_mountain(anim_t *duck);
anim_t *init_cloud(anim_t *duck);
void load_doublon(sfRenderWindow *window, set_t *set);
void destroy_doublon(sfRenderWindow *window, set_t *set);
void display_doublon(sfRenderWindow *window, set_t *set, anim_t *duck);
sfSprite *position_sprites(sfSprite *target);
sfSprite *position_sprites2(sfSprite *target);
void display(sfRenderWindow *window, set_t *set, anim_t *anim);
void display2(sfRenderWindow *window, set_t *set, anim_t *anim);
void use_clock_sprite(sfRenderWindow *window, set_t *set,
    sfClock *clock, anim_t *duck);
void sound_destroy(sfMusic *sound);
sfMusic *add_music(sfMusic* ala);
void use_clock2(sfRenderWindow *window, set_t *set, sfClock *clock,
    anim_t *duck);
sfText *position_text(sfText *target);
void text_init(sfRenderWindow *window, set_t *set);
sfText *position_text2(sfText *target);
char *int_to_str(int i);
char *int_to_char(int i);
sfSprite *position_obstacle(sfSprite *target);
sfSprite *position_ob(sfSprite *target);
void load_obstacle(sfRenderWindow *window, set_t *set);
sfSprite *position_enemi(sfSprite *target);
sfSprite *position_enemi2(sfSprite *target);
void display3(sfRenderWindow *window, set_t *set, anim_t *anim);
sfSprite *position_man(sfSprite *target, anim_t *anim);
void jump_start(anim_t *anim);
sfSprite *position_p(sfSprite *target);
sfSprite *position_pl(sfSprite *target);
void jump_end(anim_t *anim);
int hitbox(set_t *set, anim_t *anim);

#endif