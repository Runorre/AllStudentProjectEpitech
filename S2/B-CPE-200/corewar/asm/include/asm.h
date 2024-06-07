/*
** EPITECH PROJECT, 2023
** CoreWar
** File description:
** asm
*/

#ifndef ASM_H_
    #define ASM_H_

    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>

    typedef struct champion champion;
    struct champion {
        char *name, *comment;
    };

    typedef struct labels labels;
    struct labels {
        char *name;
        int abs_pos;
        labels *next;
    };

    typedef struct labels_l labels_l;
    struct labels_l {
        labels *first;
        int ac_pos;
    };

    // * str_related.c
    int my_strlen(char *str);
    int my_strcmp(char *str_o, char *str_t);
    int *len_words(char *str, char c, int *size);
    char **str_to_word_array(char *str, char c);
    char *my_strcat(char *str1, char *str2);

    // * more_str_related.c
    char *my_strncpy(char *dest, char *source, int num);
    char *hexa_to_str(char *hex_string);
    int my_pow(int nb, int power);
    char i_love_c_one(int remainder, char *hex, int i);
    char *int_to_hex(int number);

    // * main.c
    int return_error(int err, char *message);
    int main(int ac, char **av);

    // * parsing.c
    int is_one_in_two(char *str_one, char *str_two);
    char *find_name(char **champ_env);
    char *find_comment(char **champ_env);
    champion *create_champion(char **champ_env);

    // * output.c
    int header_output(champion *champ, int fd, char **line_by_line,
                        labels_l *list);
    char *name_to_cor(char *name);
    void reverse_str(char *str);
    int array_len(char **array);
    int str_to_int(char *str);

    // * functions.c
    void parse_command(char *line, int fd, labels_l *list);

    // * functions_sec.c
    int print_reg_value(char *command, int fd);
    int print_direct_value(char *command, int fd);
    int print_indirect_value(char *command, int fd, labels_l *list);

    // * prog_size.c
    int count_hexa_values(char **commands_params, int fd, char *command);
    int count_hexa_params(char **command, int fd, char *c_name);
    int count_command_index(char *command, int fd);
    int count_bytes(char *line, int fd, int count_bits, labels_l *list);
    char *chars_test(char *str, int i);
    int i_love_c_one_so_much(labels *temp, char *label);

    #define MEM_SIZE (6 * 1024)
    #define IDX_MOD 512
    #define MAX_ARGS_NUMBER 4

    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','

    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

    #define REG_NUMBER 16

    typedef char args_type_t;

    #define T_REG 1
    #define T_DIR 2
    #define T_IND 4
    #define T_LAB 8

    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE DIR_SIZE

    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC "ea83f3"

    struct op_s {
        char *mnemonique;
        char nbr_args;
        args_type_t type[MAX_ARGS_NUMBER];
        char *code;
        int nbr_cycles;
        char *comment;
    };

    typedef struct op_s op_t;

#endif
