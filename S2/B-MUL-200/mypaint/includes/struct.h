/*
** EPITECH PROJECT, 2023
** struct
** File description:
** struct
*/

#ifndef _Struct
    #define _Struct

    enum buttonstate {
        NONE = 0,
        HOVER,
        PRESSED,
        RELEASED
    };

    enum menustate {
        FILEMENU,
        EDIT,
        HELP
    };

    typedef struct button_systeme {
        enum buttonstate state;
        sfVector2f pos_button;
        sfVector2u size_button;
        sfRectangleShape *shape;
        sfText *txt;
    } but;

    typedef struct list_button {
        but *select;
        struct list_button *next;
    }l_button;
    typedef struct button {
        sfRectangleShape **shape;
        sfBool is_active;
        sfVector2f pos_button;
        sfVector2u size_button;
        sfText *open;
        sfVector2f open_pos;
        sfVector2u open_size;
        sfBool open_active;
        sfText *save;
        sfVector2f save_pos;
        sfVector2u save_size;
        sfBool save_active;
        sfText *new;
        sfVector2f new_pos;
        sfVector2u new_size;
        sfBool new_active;
    } button_shape;

    typedef struct canva {
        sfImage *canva_image;
        int mousepress;
        sfTexture *canva_text;
        sfSprite *canva;
        sfVector2i mouse;
        sfVector2f pos_canva;
        sfVector2u size_canva;
    } canva_shape;

    typedef struct sprite {
        sfVector2f pos_pen;
        sfSprite *pen;
        sfVector2u size_pen;
        sfBool pen_active;
        sfVector2f pos_erase;
        sfSprite *eraser;
        sfVector2u size_erase;
        sfBool erase_active;
        sfVector2f pos_up;
        sfSprite *up;
        sfVector2u size_up;
        sfBool up_active;
        sfVector2f pos_down;
        sfSprite *down;
        sfVector2u size_down;
        sfBool down_active;
    } glob_sprites;

    typedef struct pen {
        sfColor color_pen;
        int size;
        sfText *text_size;
        sfVector2f size_pos;
        char *st_size;
    } pen_conf;

    typedef struct save {
        sfVector2f pos_save;
        char *char_save;
        sfText *save_text;
        // sfRectangleShape;
    } save_conf;

    typedef struct system_data {
        sfRenderWindow *window;
        sfEvent *event;
        canva_shape *canva;
        l_button *but_menu;
        l_button *file_menu;
        l_button *help_menu;
        button_shape *button;
        sfColor last_color;
        glob_sprites *sprites;
        sfVector2i mouse;
        sfVector2f tmp;
        pen_conf *pen;
        enum menustate m_s;
        sfColor c_hover;
        sfColor c_press;
        save_conf *save;
    } sys_data;

#endif /* !struct */
