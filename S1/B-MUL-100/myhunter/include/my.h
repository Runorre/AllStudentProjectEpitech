/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <time.h>
    #include "sprite.h"
    #include "system.h"
    #include "sfx.h"
    #include "text.h"
    void event_menu(struct system_data *sys);
    void menuevent(sfRenderWindow *window, sfEvent event, sfSprite *lo_sp);
    struct sprite create_sp(char const *path);
    struct system_data create_sys(void);
    struct sprite create_sp_duck(char const *path, struct system_data *sys);
    void animation(struct sprite *sp, struct system_data *sys);
    void randomduck(struct sprite *sp,struct system_data *sys);
    void my_putchar(char c);
    int my_put_nbr(int nb);
    void my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_compute_power_rec(int nb, int power);
    char *my_revstr(char *str);
    int my_nbrlen(int n);
    int my_unnbrlen(unsigned int n);
    int my_put_unnbr(unsigned int nb);
    int my_put_longnbr(long nb);
    int my_longnbrlen(long n);
    int my_unlongnbrlen(unsigned long n);
    int my_put_unlongnbr(unsigned long nb);
    int my_putfloat(double nb, int dec);
    int my_compute_power_rec(int nb, int p);
    int my_getnbr(char *str);
    int my_printf(const char *format, ...);
    void event_game(struct system_data *sys, struct sprite *sp);
    int game(struct system_data *sys);
    struct text create_txt_1(char const *str, struct system_data *sys);
    struct text create_txt_score(char const *str, struct system_data *sys);
    void textanime(struct text *txt, struct system_data *sys);
    struct HUD create_sp_hud(char const *path, struct system_data *sys);
    struct BG create_bg(struct system_data *sys);
    void show_bg(struct BG *bg, struct system_data *sys);
    void show_hud(struct HUD *hud, struct system_data *sys);
    void mousecsm(struct system_data *s, sfSprite *sp);
#endif /* !MY_H_ */
