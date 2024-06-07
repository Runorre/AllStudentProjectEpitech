/*
** EPITECH PROJECT, 2022
** B-MUL-100-MAR-1-1-myhunter-angelo.anselmet
** File description:
** main
*/

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window.h>

void randomduck(struct sprite *sp,struct system_data *sys)
{
    srand(time(NULL));
    sys->random = rand() % 1650;
    if (sys->random > 960) {
        sp->inverted = 1;
        sp->status = 2;
    } else {
        sp->inverted = 0;
        sp->status = 1;
    }
    sp->pos.x = sys->random;
    sp->pos.y = 550;
}

int menu(int again)
{
    struct system_data sys = create_sys();
    struct sprite lo = create_sp("./assets/logo.png");
    struct text txt = create_txt_1("Press Enter to start", &sys);
    sfVector2f pos_lo = {360, 30};
    sfVector2f scale2 = {1.7, 1.7};
    sfMusic_play(sys.sound.music);
    sfSprite_setScale(lo.sp, scale2);
    sfSprite_setPosition(lo.sp, pos_lo);
    while (sfRenderWindow_isOpen(sys.window)) {
        event_menu(&sys);
        sfRenderWindow_clear(sys.window, sfBlack);
        sfRenderWindow_drawSprite(sys.window, lo.sp, NULL);
        textanime(&txt, &sys);
        sfRenderWindow_drawText(sys.window, txt.text, NULL);
        sfRenderWindow_display(sys.window);
    }
    return 0;
}

void gameover(struct system_data *sys, struct BG *b, struct HUD *h)
{
    sfMusic *go = sfMusic_createFromFile("./assets/gameover.wav");
    if (sys->live <= 0) {
        sfMusic_play(go);
        menu(1);
    }
}

int game(struct system_data *sys)
{
    struct BG bg = create_bg(&(*sys));
    struct sprite c = create_sp("./assets/cursor.png");
    struct HUD hud = create_sp_hud("./assets/hudblanck.png", &(*sys));
    sfSprite_setScale(c.sp, (sfVector2f) {3, 3});
    while (sfRenderWindow_isOpen(sys->window)) {
        mousecsm(&(*sys), &(*c.sp));
        event_game(&(*sys), &bg.duck);
        sfRenderWindow_clear(sys->window, sfBlack);
        show_bg(&bg, &(*sys));
        show_hud(&hud, &(*sys));
        sfRenderWindow_drawSprite(sys->window, c.sp, NULL);
        sfRenderWindow_display(sys->window);
        gameover(&(*sys), &bg, &hud);
    }
}

int main(int ar, char **av)
{
    if (ar == 2 && av[1][1] == 'h'){
        my_printf("          MyHunter by Angelo\n\n");
        my_printf("DESCRIPTION\n    Jeu du Duckhunt jouable à la base sur NES");
        my_printf(", crée en 1987 par Shigeru Miyamoto.");
        my_printf("Recodé par Angelo en C");
        my_printf(" pour un projet Epitech\n\n");
        my_printf("COMMAND\n    Movement : Souris\n");
        my_printf("     Tire = click souris\n     Quittez = échap\n\n");
        my_printf("BUT DU JEU\n     Eliminez le plus de Canards, ");
        my_printf("vous avez droit que à 3 erreur\n");
        return 0;
    } else {
        return menu(0);
    }
}
