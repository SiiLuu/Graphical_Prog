/*
** EPITECH PROJECT, 2018
** runner
** File description:
** my_runner.
*/

#include "../include/my.h"

void analyse_event(sfRenderWindow *window, sfEvent event,
    set_t *set, anim_t *duck)
{
    set->sound = sfMusic_createFromFile("sprites/jump.wav");
    if (event.key.code == sfKeySpace || event.key.code == sfKeyUp) {
        sfMusic_play(set->sound);
        jump_start(duck);
    }
    if (event.key.code == sfKeyDown) {
        sfMusic_play(set->sound);
        jump_end(duck);
    }
    if (event.key.code == sfKeyEscape) {
        sfRenderWindow_close(window);
    }
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

int hitbox(set_t *set, anim_t *anim)
{
    sfVector2f target_pos;
    sfVector2f target_pos2;
    sfVector2f target_pos3;
    sfVector2f target_pos4;
    target_pos = sfSprite_getPosition(set->player1);
    target_pos2 = sfSprite_getPosition(set->candy1);
    target_pos3 = sfSprite_getPosition(set->enemi1);
    target_pos4 = sfSprite_getPosition(set->enemi12);
    if ((target_pos.x >= target_pos2.x && target_pos.x <= target_pos2.x + 110 &&
        target_pos.y >= target_pos2.y && target_pos.y <= target_pos2.y + 110) ||
        (target_pos.x >= target_pos3.x && target_pos.x <= target_pos3.x + 110 &&
        target_pos.y >= target_pos3.y && target_pos.y <= target_pos3.y + 110) ||
        (target_pos.x >= target_pos4.x && target_pos.x <= target_pos4.x + 110 &&
        target_pos.y >= target_pos4.y && target_pos.y <= target_pos4.y + 110)) {
        my_putstr("GAME OVER\n");
        return (1);
    }
    return (0);
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

sfMusic *add_music(sfMusic* sound)
{
    const char *music = "sprites/musik.ogg";

    sound = sfMusic_createFromFile(music);
    sfMusic_play(sound);
    sfMusic_setLoop(sound, sfTrue);
    return (sound);
}

void sound_destroy(sfMusic *sound)
{
    sfMusic_stop(sound);
    sfMusic_destroy(sound);
}