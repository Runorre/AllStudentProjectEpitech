/*
** EPITECH PROJECT, 2023
** B-MUL-200-MAR-2-1-myrpg-angelo.anselmet
** File description:
** joystick
*/

#include "rpg.h"

void joystick_menu(sys_data* sys, int* choice, sfClock** joystick_clock,
    menu_s *menu)
{
    float val;
    switch (sys->event.type) {
        case sfEvtJoystickMoved:
            if (sfTime_asSeconds(
                sfClock_getElapsedTime(*joystick_clock)) > 0.1
                && sfJoystick_isConnected(0) == sfTrue) {
                sfClock_restart(*joystick_clock);
                val = sfJoystick_getAxisPosition(0, sfJoystickY);
                if (val <= -10)
                    *choice = (*choice == 0) ? 3 : *choice - 1;
                if (val <= -10)
                    *choice = (*choice == 3) ? 0 : *choice + 1;
                break;
            }
        case sfEvtJoystickButtonPressed:
            if (sfJoystick_isButtonPressed(0, sfJoystickX))
                check_choice(sys, choice, menu);
        default:
            break;
    }
}

int joystick_set(sys_data *sys, int pos, sfClock* joystick_clock)
{
    float val;
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(joystick_clock)) > 0.1 &&
        sfJoystick_isConnected(0) == sfTrue) {
        val = sfJoystick_getAxisPosition(0, sfJoystickY);
        sfClock_restart(joystick_clock);
        if (val <= -10)
            pos--;
        if (val >= 10)
            pos++;
        if (pos > 2)
            pos = 0;
        if (pos < 0)
            pos = 2;
    }
    return pos;
}

int move_volume_contr(sys_data *sys, sfSprite *volume_spri, int button,
sfClock *joystick_clock)
{
    float val;
    if (sfTime_asSeconds(
    sfClock_getElapsedTime(joystick_clock)) > 0.1 &&
    sfJoystick_isConnected(0) == sfTrue) {
        val = sfJoystick_getAxisPosition(0, sfJoystickX);
        sfClock_restart(joystick_clock);
        sfVector2f pos = sfSprite_getPosition(volume_spri);
        if (val <= -10) {
            sys->music_volume -= 2; pos.x -= 10;
            sfSprite_setPosition(volume_spri, pos);
        } if (val >= 10) {
            sys->music_volume += 2; pos.x += 10;
            sfSprite_setPosition(volume_spri, pos);
        } sys->pos_music_volume = pos;
    }
}
