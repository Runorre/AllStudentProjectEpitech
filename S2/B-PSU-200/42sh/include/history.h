/*
** EPITECH PROJECT, 2023
** B-PSU-200-MAR-2-1-42sh-theo.berget
** File description:
** history
*/

#ifndef HISTORY_H_
    #define HISTORY_H_
    typedef struct history_d {
        struct history_d *prev;
        int id;
        char *command;
        int hour;
        int minute;
        struct history_d *next;
    }history;

#endif /* !HISTORY_H_ */
