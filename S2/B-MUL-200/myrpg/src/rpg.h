/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

//include
    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <fcntl.h>
    #include <time.h>
    #include <stdbool.h>

//define
    #define NPC3 " J'ai cru vous voir au nord...\
        \n Mais vous sembliez plus... froid ?\nC'est tres etrange..."

    #define TUTO "  Appuyez sur -ZQSD- / -fleches- au clavier \
        \n  ou le joystick a la manette. \
        \n\n Appuyez sur -I- pour ouvrir \n  l'inventaire comprenant : \
        \n  \t-Vos competences.\
        \n  \t-Vos trophees de boss.\
        \n  \t-Vos quetes en cours.\
        \n\n  Appuyez sur -F- proche \n  d'un ennemi pour lancer un combat."

    #define flower "Nous sommes des fleurs, de tres jolies fleurs.\
        \nIl consomme 6 points de magie."

    #define soleil "Le soleil dans le creux de sa main se reveille\n\
en endommageant l'ennemi.\nIl consomme 9 points de magie."

    #define leaf "Envoie une brise de feuille d'automne sur l'ennemi.\n\
Il consomme 7 points de magie"

    #define sprite_flower "utilities/sprites/flower.png"

    #define sprite_soleil "utilities/sprites/soleil.png"

    #define sprite_feuille "utilities/sprites/feuille_automne.png"

    #define hair "Vous avez battu Sommar\ntransforme en cendres apres sa \
defaite.\nSeul sa chevelure restait."

    #define sprite_hair "utilities/sprites/hair.png"

    #define pumpkin "Vous avez battu Host\nretourne dans la terre apres \
sa defaite.\nLa citrouille etant trop grosse, resta a decouvert."

    #define sprite_citrou "utilities/sprites/citrouille.png"

    #define king "Vous avez battu Vinter, aneanti a tout jamais, on l'espere."

    #define sprite_king "utilities/sprites/crown.png"

    #define FOND "utilities/images/tom_bg.png"

    #define FLOCON "utilities/sprites/flocon.png"

    #define Q1 "Vaincre Sommar"

    #define Q2 "Vaincre Host"

    #define Q3 "Aneantir Vinter"

    #define CHECK "utilities/sprites/check.png"

    #define WRONG "utilities/sprites/wrong.png"

    #define CS_SVP "Attaque\t\t\t\t\t\t  Magie\t\t\t\t\t\t\t  Fuite"

    #define CINE_T "Le royaume etait florissant et le roi etait aime de tous. \
        \n            Les habitants y menaient une vie heureuse."

    #define CINE_T2 " Un jour, apres une bataille feroce et glorieuse, \
        \n            le roi ouvrit un tresor de guerre."

    #define CINE_T3 "             A l'interieur se trouvait un miroir \
        \n    qui ne sembla pas attirer l'attention du roi."

    #define CINE_T4 "            Il leva le miroir pour s'y regarder, \
        \n           mais en voyant son reflet malefique, \
        \n                             il le fit tomber. \
        \n                Le miroir se brisa en mille morceaux, \
        \n        laissant ainsi echapper son ame demoniaque."

    #define CINE_T5 "Cette ame etait froide, \
depourvue de vie et animee uniquement \
        \n                            par une soif de pouvoir."

    #define CINE_T6 "La famille royale fut expulsee du chateau \
apres un coup d'Etat \
        \n          sans difficulte orchestre par ce nouveau demon."

//enum

    //button
    enum button_status {
        IDLE,
        HOVER,
        PRESSED
    };

    //editor
    enum draw_status {
        HANDS_UP,
        DRAWING
    };

    enum layers_selected {
        BG,
        MID,
        FG
    };

//struct

    //core
    typedef struct system_data {
        sfRenderWindow* window;
        sfView* view;
        sfFloatRect rect_view;
        sfEvent event;
        sfMusic* music;
        int fight;
        sfVector2f pos_music_volume;
        int music_volume;
        sfText **quest;
    } sys_data;

    //menu
    typedef struct menu_t {
        int choice;
        sfSprite* background;
        struct button_t* buttons_menu;
        sfClock* joystick_clock;
    } menu_s;

    //map
    typedef struct ftile_t {
        char* file;
        int tile_size;
        int l;
        int x;
        int y;
    } ftile_s;

    typedef struct used_tiles {
        sfSprite* tile;
        int id;
        struct used_tiles* next;
    } used_t;

    typedef struct num_list {
        int n;
        struct num_list* next;
    } nlist;

    typedef struct tile_t {
        sfSprite* tile;
        int collide_type;
        struct tile_t* next;
    } tile_s;

    typedef struct tp_loc {
        sfRectangleShape* rect;
        int dest;
        sfVector2f pos;
        struct tp_loc* next;
    } tp_s;

    typedef struct map_t {
        struct tile_t* bg;
        struct tile_t* mid;
        struct tile_t* fg;
        struct tp_loc* tp;
        struct npc_list* npc;
        struct champ_t* boss;
        int id;
    } map_s;

    //characters & stats
    typedef struct stats_t {
        int hp;
        int max_hp;
        int mp;
        int max_mp;
        int attack;
        int defense;
        int magie;
    } stats_s;

    typedef struct spells_t {
        int id;
        int heal;
        char* name;
        char* desc;
        sfSprite* icon;
        sfText *texte;
        struct stats_t* stats;
        struct spells_t* next;
    } spells_s;

    //inv
    typedef struct inv_t {
        int id;
        char* name;
        char* desc;
        sfSprite* icon;
        struct stats_t* stats;
        struct inv_t* next;
    } inv_s;

    typedef struct trophee_t {
        int id;
        sfSprite *icon;
        sfText *titre;
        struct trophee_t *next;
    } trophee_s;

    typedef struct giu_t {
        sfRenderWindow *window;
        sfRectangleShape *place_input;
        sfRectangleShape *button_open;
        sfRectangleShape *button_hasard;
        sfText *titre_open;
        sfText *titre_hasard;
        sfText *texte_open;
        sfText *texte_to_open;
        sfText *maj;
        sfText *end;
        sfText *end_name;
        int affiche;
    } giu_s;

    typedef struct perso_t {
        int affiche;
        int maj;
        int fini;
        int touch;
        int taille;
    } perso_s;

    typedef struct elemnt_inv {
        sfSprite *icon;
        sfText *text;
        struct elemnt_inv *next;
    } elemnt_inv_s;

    typedef struct wind_inv {
        sfRenderWindow *wind_inv;
        sfRectangleShape *button_trophee;
        sfRectangleShape *button_spells;
        sfRectangleShape *quete;
        sfRectangleShape *cadre;
        sfSprite *fond;
        sfSprite *ice;
        sfText *texte_trophee;
        sfText *texte_spells;
        sfText *texte_quete;
        struct elemnt_inv *co;
        struct elemnt_inv *tr;
        struct elemnt_inv *qu;
        bool trophee;
        bool spells;
        bool w_quete;
    } wind_inv_s;

    //fight
    typedef struct level_t {
        int lvl;
        int exp;
    } level_s;

    typedef struct champ_t {
        sfSprite *battle;
        struct level_t *level;
        sfSprite* sprite;
        char* sheet;
        sfIntRect* rect;
        sfClock* clock_move;
        sfClock* clock_spri;
        char* name;
        struct stats_t* stats;
        struct spells_t* spells;
        struct inv_t* inv;
        struct trophee_t* trophee;
        bool q1;
        bool q2;
        bool q3;
        int map;
    } champ_s;

    typedef struct fight_t {
        struct champ_t *player;
        struct champ_t *enemie;
        sfClock *clock;
        sfSprite *bg;
        sfSprite *trans;
        sfSprite *s_box;
        sfSprite *box;
        sfSprite *opt_box;
        sfSprite *cursor;
        sfFont *font;
        sfText *chos_act;
        sfText *upper_msg;
        sfText *hp;
        sfText *name;
        sfText *mp;
        sfSound *cur_s;
        sfSoundBuffer *buf_sound;
        sfVector2f s;
        sfMusic *gm;
    sfMusic *vic;
        int down_status;
        int move_cursor;
        int nbr_spells;
        int no_mana;
        int changemenu;
    } fight_s;

    typedef struct npc_list {
        struct champ_t* mod;
        sfRectangleShape* area;
        struct dialogues_t* dial;
        struct npc_list* next;
    } lnpc_s;

    //button
    typedef struct button_t {
        enum button_status status;
        sfText* text;
        sfRectangleShape* rect;
        struct button_t* next;
        char* file;
    } button_s;

    //dialogues
    typedef struct dialogues_t {
        sfText *text;
        sfRectangleShape* rect;
        sfBool show;
    } dial_s;

    //editor
    typedef struct palette_t {
        sfSprite* tile;
        int id;
        enum button_status status;
        struct palette_t* next;
    } palette_s;

    typedef struct selection_t {
        sfRectangleShape* rect;
        enum draw_status status;
        sfSprite* tile;
        struct button_t* save;
        struct button_t* layers_selected;
        int id;
    } selec_s;

    typedef struct ed_layers_t {
        char* name;
        int x;
        int y;
        sfSprite*** s_bg;
        sfSprite*** s_mid;
        sfSprite*** s_fg;
        int** i_bg;
        int** i_mid;
        int** i_fg;
        sfBool v_bg;
        sfBool v_mid;
        sfBool v_fg;
        enum layers_selected current;
    } ed_layers;

    typedef struct var_editor_t {
        struct palette_t* pal;
        struct selection_t* sel;
        sfRectangleShape* bg_pal;
        sfRectangleShape* bg_map;
    } var_editor;

//functions

    //main
    int main(void);

    //sys
    sys_data* init_sys(void);

    //buttons.c
    button_s* init_button(char* str, char* file,
        sfVector2f pos, sfVector2f size);
    button_s* init_buttons_list(char** tab, char* file,
    sfVector2f pos, sfVector2f size);
    button_s* add_button(button_s* head, button_s* button);
    void display_buttons(sfRenderWindow* window, button_s* buttons);
    void adapt_buttons_menu(button_s** buttons, int choice);

    //buttons2
    button_s* reverse_buttons_list(button_s* buttons);

    //menu
    menu_s* init_menu(void);
    int menu(sys_data* sys);
    void events_menu(sys_data* sys, int* choice, sfClock** joystick_clock,
    menu_s *menu);
    void key_pressed(sys_data* sys, int* choice, menu_s *menu);
    void check_choice(sys_data* sys, int *choice, menu_s *menu);

    //game
    int game(sys_data* sys, map_s* map, champ_s* mc);
    void events_game(sys_data* sys, champ_s** mc, tile_s* collisions,
        map_s *map);

    //maps.c
    map_s* init_map_from_file(ftile_s ftile, char* bg, char* mid, char* fg);
    void draw_map(sfRenderWindow* window, map_s* map, champ_s* mc);
    void draw_layer(sfRenderWindow* window, tile_s* layer);

    //joystick
    void joystick_menu(sys_data* sys, int* choice, sfClock** joystick_clock,
    menu_s *menu);
    int joystick_set(sys_data *sys, int pos, sfClock* joystick_clock);
    int move_volume_contr(sys_data *sys, sfSprite *volume_spri, int button,
    sfClock *joystick_clock);

    //nlist.c
    nlist* init_nlist(char* file);
    nlist* reverse_nlist(nlist* list);
    nlist* add_num(nlist* head, int n);
    int count_until_limit(char* str, char lim);
    char* open_file(char* file);

    //tiles
    tile_s* add_tile(tile_s* tiles, sfSprite* sprite);
    tile_s* get_tiles(nlist* num, ftile_s ftile);
    used_t* add_used_tile(used_t* used, sfSprite* tile, int id);
    sfSprite* is_used(used_t* used, int id);
    sfSprite* get_sprite_tile(int n, sfVector2f pos, ftile_s ftile);

    //my_str_to_word_array
    int num_words(char* str);
    int word_len_in_str(char* str, int i);
    char** my_str_to_word_array(char* str);
    int tab_len(char** tab);

    //my_strcat
    char* my_strcat(char *str1, char *str2);
    int my_strlen(char const* str);

    //mc.c
    champ_s* init_mc(sfVector2f pos);
    void move_player(sfKeyCode key, champ_s** mc, tile_s* collisions);
    sfVector2f move_offset(sfKeyCode key, champ_s** mc);
    void set_view(sys_data* sys, sfSprite* sprite);

    //collisions.c
    int player_collide(champ_s* mc, tile_s* collisions);
    int player_collide2(tile_s* tmp, champ_s* mc);
    int sprite_collisions(sfSprite* a, sfVector2f size_a,
        sfSprite* b, sfVector2f size_b);
    int set_collision(ftile_s ftile, int id);

    //cinematique
    void cinematique(sys_data *sys);
    int cine_events(sys_data* sys, sfSound* voice);

    //menu_settings
    void change_rez(sys_data *sys, int pos);
    int move_volume(sys_data *sys, sfSprite *volume_spri, int button);
    int move_button_set(sys_data *sys, int pos);
    sfBool events_set(sys_data *sys);
    sfSprite **change_rect_set(sfSprite **tab_sprite, int pos);
    sfSprite **init_sprite_set(sys_data *sys);
    sfText *create_text_set(char *str, sfVector2f pos, int scale);
    sfText **init_text_set(void);

    //3
    void menu_settings(sys_data *sys, menu_s *menu);

    //editor.c
    void ed_pressed_cases(sys_data* sys, var_editor** v_ed,
        ed_layers** layers);
    void editor(int x, int y, sys_data* sys, char* name);
    var_editor* init_var_editor(int x, int y);
    void events_editor(sys_data* sys, var_editor** v_ed, ed_layers** layers);

    //editor_sel.c
    selec_s* init_sel_buttons(selec_s* sel);
    void update_sel_buttons(selec_s** sel, int i);
    selec_s* init_selection(void);
    void draw_sel(sfRenderWindow* window, selec_s* sel);
    int sel_buttons_clicked(sfMouseButtonEvent mouse, selec_s** sel,
        ed_layers* layers);

    //editor_status.c
    sfRectangleShape* init_rect(sfVector2f pos, sfVector2f size,
        sfColor color);
    sfBool is_tile_clicked(sfSprite* tile, sfVector2f mouse);
    sfSprite* tile_layer_clicked(sfSprite* tile, sfVector2f mouse,
        selec_s* sel, int* id);
    void layer_clicked(sfSprite*** layer, sfVector2f mouse,
        selec_s* sel, int** ltab);
    sfBool is_rect_clicked(sfRectangleShape* rect, sfVector2f mouse);

    //editor_layer.c
    ed_layers* init_layers(int x, int y, char* name);
    int** init_void_itab(int x, int y, int void_id);
    void draw_layers_editor(sfRenderWindow* window, ed_layers* layers);
    void draw_layer_editor(sfRenderWindow* window, sfSprite*** layer);
    sfSprite*** init_void_layer(int x, int y, int size);

    //editor_layer2.c
    void update_current_layer(selec_s* sel, ed_layers** layer);
    void check_current_layer(selec_s* sel, ed_layers** layers,
        sfVector2f mouse);
    void save_map(ed_layers* layers);

    //editor_pal.c
    void pal_clicked(palette_s** pal, sfMouseButtonEvent* mouse,
        selec_s** sel);
    sfSprite* init_palette_sprite(int i, int j, int size);
    palette_s* add_paltile(palette_s* pal, int i, int j, int size);
    void draw_palette(sfRenderWindow* window, palette_s* pal);
    palette_s* init_palette(void);
    void save_layer(int** layer, char* layername, int x, int y);

    //init.c
    sfSprite* init_sprite(char* file);

    //cinematique.c
    sfText **create_text(void);
    sfText *init_subtitle(char *text);

    //pause.c
    void pause_game(sys_data *sys, champ_s* mc);
    sfText **init_text_pause(void);
    sfSprite **init_sprite_pause(void);
    int move_button_pause(sys_data *sys, int pos);

    //int_to_str.c
    char* int_to_str(int n, char *str);
    int len_nb(int n);
    int str_to_int(char* str);

    //map_templates.c
    map_s* map1(void);
    map_s* map2(void);
    map_s* map3(void);
    map_s* map4(void);
    map_s* map5(void);

    //map_templates2.c
    map_s* map4_npc(map_s* map);

    //tp.c
    tp_s* add_tp(tp_s* head, sfRectangleShape* rect, int id, sfVector2f pos);
    void draw_tp(sfRenderWindow* window, tp_s* tp);
    void tp_map(tp_s* tp, champ_s* mc, sys_data* sys);
    int tp_collision(sfSprite* sprite, sfVector2f size_a,
        sfRectangleShape* rect);
    map_s* map(int id);

    //npc.c
    champ_s* init_npc(char* sheet, char* name, sfVector2f pos);
    lnpc_s* add_npc(lnpc_s* head, champ_s* mod, sfRectangleShape* area,
        dial_s* dial);
    void draw_npcs(sfRenderWindow* win, map_s* map, champ_s* mc);
    void draw_npc_dial(sfRenderWindow* win, lnpc_s* npc, champ_s* mc);

    //dial.c
    void adjust_dial_pos(lnpc_s** npc);
    dial_s *create_dialogues(char *text);
    int n_lines(char* str);
    sfText *init_dtext(char *str, int scale);
    void draw_dial(dial_s* dial, sfRenderWindow* win);

    //init_fight.c
    int init_fight(champ_s *player, champ_s *enemie, sys_data* sys, map_s* map);
    champ_s *init_enemy(char *texture, char *name);
    fight_s *init_struct2(fight_s *fight, sfVector2f s,
                            champ_s *player, sys_data *sys);
    //event_fight.c
    void down_menu_event(fight_s *fight, sys_data *sys, sfKeyCode key);

    //fight.c
    void draw_upper(fight_s *fight, sys_data *sys);
    int draw_life(fight_s *fight, sys_data *sys);
    int draw_aera(fight_s *fight, sys_data *sys);
    int draw_hud(fight_s *fight, sys_data *sys);
    int fight_scene(fight_s *fight, sys_data *sys);
    //fight3.c
    int end_action(sfMusic *battle, fight_s *fight, sys_data *sys);
    //attack.c
    void attack_enemy(fight_s *fight, sys_data *sys);
    void enemy_attack(fight_s *fight, sys_data *sys);
    void magic_attack(fight_s *f, sys_data *sys);
    //cursor_f.c
    void move_l_cursor(fight_s *fight, sys_data *sys);
    void move_r_cursor(fight_s *fight, sys_data *sys);
    void move_l_cursor_m(fight_s *fight, sys_data *sys);
    void move_r_cursor_m(fight_s *fight, sys_data *sys);

    //putnbr.c
    char* putnbr(int num);

    //quest.c
    sfText **init_quest(void);

    //crédit.c
    void place_credit(sys_data *sys);
    //magie.c
    void show_list_spell(fight_s *fight, sys_data *sys);
    void pos_spell(fight_s *fight, sys_data *sys);
    spells_s *get_spring(champ_s *mc);
    spells_s *get_automne(champ_s *mc);
    spells_s *get_ete(champ_s *mc);
    //inv1
    void inventaire(sys_data* sys, champ_s *champion);
    void hover_inv(wind_inv_s *inv);
    void affichage_inv(wind_inv_s inv);
    void affichage_inv_spell(wind_inv_s inv, elemnt_inv_s *elm);
    bool event_moment_inv(wind_inv_s *inv, sfClock* clock);

    //inv2
    elemnt_inv_s *create_head_inv(char *file, char *description,
        sfVector2f scale);
    elemnt_inv_s *add_node_inv(char *file, char *description, int i,
        sfVector2f scale);
    sfRenderWindow *create_window_inv(char *name);
    sfText *create_text_inv(int posx, int posy, int taille, char *string);
    sfRectangleShape *create_button(int t_rec_x, int t_rec_y, int posx,
        int posy);

    //inv3
    sfSprite *create_invsprite(char *titre, sfVector2f pos, sfVector2f scale);
    elemnt_inv_s *init_ll_inv_tr(trophee_s *trophee);
    void add_node_tr(trophee_s *trophee, elemnt_inv_s *tr, int i);
    elemnt_inv_s *init_ll_inv_co(spells_s *spell);
    void add_node_co(spells_s *spell, elemnt_inv_s *co, int i);

    //inv4
    void check_click(wind_inv_s *inv);
    wind_inv_s init_struct_inv(sfRenderWindow* window, champ_s *champion);
    elemnt_inv_s *init_struct_qu(champ_s *champion);
    void add_node_qu(elemnt_inv_s *qu, champ_s *champion, int i);
    elemnt_inv_s *create_head_qu(champ_s *champion);

    //inv5
    void free_all_inv(wind_inv_s inv);
    void free_ll(elemnt_inv_s *elm);
    trophee_s *get_trophhe_from_champ(champ_s *champion);

    //keyboard1
    char* get_name_champion(sys_data *sys);
    void affichage_end(giu_s perso, char *name);
    void free_all(giu_s perso);
    bool events_kb(giu_s perso, sfEvent event);

    //keyboard2
    char *remplir_char(char *texte, int key, perso_s *fichier);
    int no_change(int key, perso_s *fichier);
    char *enleve_char(char *texte, perso_s *fichier);
    char *my_realloc(int key, char *texte, perso_s *fichier);
    int mauvaise_key(int key);

    //keyboard3
    sfText *create_kbtext(int posx, int posy, int taille, char *string);
    sfRenderWindow *create_window(void);
    sfRectangleShape *create_save(int t_rec_x, int t_rec_y, int posx,
        int posy);
    perso_s init_struct_perso(void);
    void clik_button(sfRectangleShape *open, sfRectangleShape *annul,
        perso_s *fichier, sfRenderWindow *window);

    //keyboard4
    void pos_deux(giu_s perso, sfRenderWindow *window,
        sfVector2i position_two);
    void pos_apres(giu_s perso, sfRenderWindow *window, sfVector2i position);
    void pos_debut(giu_s perso, sfRenderWindow *window, sfVector2i
        position_one);
    void affichage(giu_s open, perso_s fichier, char *name, sys_data *sys);
    giu_s init_struct_giu(void);

    //keyboard5
    void free_part(giu_s perso);
    char *check_witch_end(perso_s add, char *name);
    char *generate_aleatoire(void);
char *event_moment(char *input, perso_s *fichier, giu_s perso, sys_data *sys);
    void shake_screen(giu_s perso, perso_s fichier, char *name, sys_data *sys);

    //save
    void save(champ_s *champion);
    void write_spells(sfBool b, FILE *save);
    void write_lvl(level_s* level, FILE* save);
    void write_stat(stats_s* stats, FILE *save);

    //my_int_to_char
    char *my_int_to_char(int nb);
    int compt_size(int nb);
    char *put_nb_in_char(int nb, char *nb_char, int i, int size);

    //get_save
    champ_s *recup_sauvegarde(map_s **map);
    char *recup_fichier(int fd);
    int malloc_size_buffer(int fd, int *taille);
    char *my_strdup(char *src);

    //2
    map_s* recup_map(char* id, char* x, char* y, champ_s** mc);
    champ_s* get_inv(champ_s* mc, char* line);
    stats_s *recup_stats_ll(char *dest, int *i);

    //3
    void add_node_spell(char *line, int *i, spells_s *spell);
    spells_s *create_head_spell(char *line, int *i);
    inv_s *create_head(char *line, int *i);
    void add_node(char *line, int *i, inv_s *inv);
    char *recup_chare(char *line, int *i);

    //4
    stats_s *recup_stats(char *dest);
    inv_s *recup_inv(char *line);

    //mygetnbrtom
    int my_getnbnbr(char *dest, int *i);
    int malloc_size_buffer_getnbr(char *dest, int y);
    bool numerique(char c);
    int transform_to_int(char *temp, bool moin, int size);

    //cencd
    char **char_en_char_double(char *buffer);

    //gameover.c
    void gameover(fight_s *f, sys_data *sys);

    //victory.c
    void victory(fight_s *fight, sys_data *sys);

    //gameover.c
    void gameover(fight_s *f, sys_data *sys);

    //victory.c
    void victory(fight_s *fight, sys_data *sys);

    //boss.c
    void draw_boss(sfRenderWindow* win, map_s* map, champ_s* mc);
    champ_s* init_boss(int id);
    champ_s *boss_summer(void);
    champ_s *boss_autumn(void);
    champ_s *boss_alter(void);
    void fight_a_boss(champ_s** mc, map_s** map, sys_data* sys);

#endif
