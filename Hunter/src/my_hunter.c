/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** game hunter.
*/

#include "../include/my.h"
#include <stdlib.h>

elem_t *load_elem(elem_t *elem, char *file)
{
    elem->texture = sfTexture_createFromFile(file, NULL);
    elem->sprite = sfSprite_create();
    sfSprite_setTexture(elem->sprite, elem->texture, sfTrue);
    return (elem);
}

void destroy(elem_t *elem)
{
    sfSprite_destroy(elem->sprite);
    sfTexture_destroy(elem->texture);
}

void display(sfRenderWindow *window, sfSprite *background,
    elem_t *target, duck_t *duck)
{
    sfIntRect rect;

    rect = frame(duck->frame, rect);
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setTextureRect(target->sprite, rect);
    sfSprite_move(target->sprite, duck->offset);
    sfRenderWindow_drawSprite(window, background, NULL);
    sfRenderWindow_drawSprite(window, target->sprite, NULL);
    sfRenderWindow_display(window);
}

void load_window(sfRenderWindow *window, sfSprite *background)
{
    sfEvent event;
    sfClock *clock = sfClock_create();
    elem_t *target = malloc(sizeof(target));
    duck_t *duck = malloc(sizeof(duck));

    target = load_elem(target, "B-MUL-100_Bootstrap_my_hunter_spritesheet.png");
    target->sprite = position(target->sprite, window);
    duck = init_duck(duck);
    while (sfRenderWindow_isOpen(window)) {
        if (manage_mouse(event, target->sprite) == 2)
            position(target->sprite, window);
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_event(window, event, target->sprite, duck);
        display(window, background, target, duck);
        use_clock(clock, duck);
    }
    sfClock_destroy(clock);
    destroy(target);
    free(target);
}

int main(int ac, char **av)
{
    sfVideoMode mode = {1123, 595, 32};
    sfRenderWindow *window;
    elem_t *background = malloc(sizeof(background));

    usage_func(ac, av);
    if (ac == 1) {
        window = sfRenderWindow_create(mode, "My Hunter",
            sfResize | sfClose, NULL);
        background = load_elem(background, "non.jpg");
        sfRenderWindow_setFramerateLimit(window, 30);
        load_window(window, background->sprite);
        destroy(background);
        free(background);
        sfRenderWindow_destroy(window);
        return (0);
    }
}