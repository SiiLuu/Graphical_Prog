/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** game runner.
*/

#include "../include/my.h"

void load_texture(set_t *set)
{
    set->tree = sfTexture_createFromFile("sprites/layer03_trees.png", NULL);
    set->sky = sfTexture_createFromFile("sprites/layer06_sky.png", NULL);
    set->cloud = sfTexture_createFromFile("sprites/layer04_clouds.png", NULL);
    set->player = sfTexture_createFromFile("sprites/leyton.png", NULL);
    set->mountain = sfTexture_createFromFile("sprites/layer05_rocks.png", NULL);
    set->cake = sfTexture_createFromFile("sprites/layer02_cake.png", NULL);
    set->ground = sfTexture_createFromFile("sprites/layer01_ground.png", NULL);
    set->sky1 = sfSprite_create();
    set->tree1 = sfSprite_create();
    set->cloud1 = sfSprite_create();
    set->player1 = sfSprite_create();
    set->mountain1 = sfSprite_create();
    set->cake1 = sfSprite_create();
    set->ground1 = sfSprite_create();
    sfSprite_setTexture(set->sky1, set->sky, sfTrue);
    sfSprite_setTexture(set->tree1, set->tree, sfTrue);
    sfSprite_setTexture(set->cloud1, set->cloud, sfTrue);
    sfSprite_setTexture(set->mountain1, set->mountain, sfTrue);
    sfSprite_setTexture(set->cake1, set->cake, sfTrue);
    sfSprite_setTexture(set->ground1, set->ground, sfTrue);
    sfSprite_setTexture(set->player1, set->player, sfTrue);
}

void destroy(sfRenderWindow *window, set_t *set)
{
    sfSprite_destroy(set->player1);
    sfSprite_destroy(set->ground1);
    sfSprite_destroy(set->cake1);
    sfSprite_destroy(set->tree1);
    sfSprite_destroy(set->mountain1);
    sfSprite_destroy(set->cloud1);
    sfSprite_destroy(set->sky1);
    sfTexture_destroy(set->player);
    sfTexture_destroy(set->ground);
    sfTexture_destroy(set->cake);
    sfTexture_destroy(set->tree);
    sfTexture_destroy(set->mountain);
    sfTexture_destroy(set->cloud);
    sfTexture_destroy(set->sky);
    destroy_doublon(window, set);
    sfRenderWindow_destroy(window);
}

void position_spritee(sfRenderWindow *window, set_t *set)
{
    set->ground12 = position_sprites2(set->ground12);
    set->cake12 = position_sprites2(set->cake12);
    set->tree12 = position_sprites2(set->tree12);
    set->mountain12 = position_sprites2(set->mountain12);
    set->cloud12 = position_sprites2(set->cloud12);
    set->candy1 = position_obstacle(set->candy1);
    set->enemi1 = position_enemi(set->enemi1);
    set->enemi12 = position_enemi2(set->enemi12);
    set->player1 = position(set->player1, window);
}

void load_window(sfRenderWindow *window)
{
    sfEvent event;
    sfClock *clock = sfClock_create();
    set_t *set = malloc(sizeof(set_t));
    anim_t *anim = malloc(sizeof(anim_t));

    load_texture(set);
    load_doublon(window, set);
    position_spritee(window, set);
    use_clock2(window, set, clock, anim);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_event(window, event, set, anim);
        if (hitbox(set, anim) == 1)
            sfRenderWindow_close(window);
        display3(window, set, anim);
        use_clock(clock, set, anim);
    }
    sfClock_destroy(clock);
    destroy(window, set);
    free(set);
    free(anim);
}

int main(int ac, char **av)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfMusic* sound = NULL;

    usage_func(ac, av);
    if (ac == 1) {
        window = sfRenderWindow_create(mode, "My Runner",
            sfResize | sfClose, NULL);
        sfRenderWindow_setFramerateLimit(window, 30);
        sound = add_music(sound);
        load_window(window);
        sound_destroy(sound);
    }
    return (0);
}