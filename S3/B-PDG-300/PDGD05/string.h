/*
** EPITECH PROJECT, 2024
** Day05
** File description:
** string
*/


#ifndef STRING_H_
    #define STRING_H_
    #include <stddef.h>

typedef struct string_s {
    char *str;
    void (*assign_c)(struct string_s *this, const char *s);
    void (*assign_s)(struct string_s *this, const struct string_s *str);
    void (*append_s)(struct string_s *this, const struct string_s *ap);
    void (*append_c)(struct string_s *this, const char *ap);
    char (*at)(const struct string_s *this, size_t pos);
    void (*clear)(struct string_s *this);
    int (*length)(const struct string_s *this);


} string_t;

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);

void assign_c(string_t *this, const char *s);
void assign_s(string_t *this, const string_t *str);

void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);

char at(const string_t *this, size_t pos);

void clear(string_t *this);

int length(const string_t *this);

char *my_strdup(const char *copy);

#endif /* !STRING_H_ */
