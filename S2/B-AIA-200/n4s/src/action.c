/*
** EPITECH PROJECT, 2023
** B-AIA-200-MAR-2-1-n4s-sonny.rameaux
** File description:
** action
*/

#include "../include/my.h"

void fontcinq(values *val)
{
    sendintrustion("WHEELS_DIR:0.0\n", 0);
    if (val->middle >= 1200.0)
        sendintrustion("CAR_FORWARD:0.8\n", 0);
    if (val->middle < 1200.0 && val->middle >= 800.0)
        sendintrustion("CAR_FORWARD:0.6\n", 0);
    if (val->middle < 800.0 && val->middle >= 400.0)
        sendintrustion("CAR_FORWARD:0.45\n", 0);
}

void rotateright2(values *val)
{
    if (val->right < 250.0 && val->right >= 200.0) {
        sendintrustion("WHEELS_DIR:0.3\n", 0);
        sendintrustion("CAR_FORWARD:0.3\n", 0);
    }
    if (val->right < 200.0 && val->right >= 150.0) {
        sendintrustion("WHEELS_DIR:0.35\n", 0);
        sendintrustion("CAR_FORWARD:0.25\n", 0);
    }
    if (val->right < 150.0 && val->right >= 100.0) {
        sendintrustion("WHEELS_DIR:0.4\n", 0);
        sendintrustion("CAR_FORWARD:0.2\n", 0);
    }
    if (val->right < 100.0 && val->right >= 0.0) {
        sendintrustion("WHEELS_DIR:1\n", 0);
        sendintrustion("CAR_FORWARD:0.15\n", 0);
    }
}

void rotateright(values *val)
{
    if (val->right >= 350.0) {
        sendintrustion("WHEELS_DIR:0.1\n", 0);
        sendintrustion("CAR_FORWARD:0.5\n", 0);
        return;
    }
    if (val->right < 350.0 && val->right >= 300.0) {
        sendintrustion("WHEELS_DIR:0.2\n", 0);
        sendintrustion("CAR_FORWARD:0.4\n", 0);
        return;
    }
    if (val->right < 300.0 && val->right >= 250.0) {
        sendintrustion("WHEELS_DIR:0.25\n", 0);
        sendintrustion("CAR_FORWARD:0.35\n", 0);
        return;
    }
    rotateright2(val);
}

void rotateleft2(values *val)
{
    if (val->left < 250.0 && val->left >= 200.0) {
        sendintrustion("WHEELS_DIR:-0.3\n", 0);
        sendintrustion("CAR_FORWARD:0.3\n", 0);
    }
    if (val->left < 200.0 && val->left >= 150.0) {
        sendintrustion("WHEELS_DIR:-0.35\n", 0);
        sendintrustion("CAR_FORWARD:0.25\n", 0);
    }
    if (val->left < 150.0 && val->left >= 100.0) {
        sendintrustion("WHEELS_DIR:-0.4\n", 0);
        sendintrustion("CAR_FORWARD:0.2\n", 0);
    }
    if (val->left < 100.0 && val->left >= 0.0) {
        sendintrustion("WHEELS_DIR:-1\n", 0);
        sendintrustion("CAR_FORWARD:0.15\n", 0);
    }
}

void rotateleft(values *val)
{
    if (val->left >= 350.0) {
        sendintrustion("WHEELS_DIR:-0.1\n", 0);
        sendintrustion("CAR_FORWARD:0.5\n", 0);
        return;
    }
    if (val->left < 350.0 && val->left >= 300.0) {
        sendintrustion("WHEELS_DIR:-0.2\n", 0);
        sendintrustion("CAR_FORWARD:0.4\n", 0);
        return;
    }
    if (val->left < 300.0 && val->left >= 250.0) {
        sendintrustion("WHEELS_DIR:-0.25\n", 0);
        sendintrustion("CAR_FORWARD:0.35\n", 0);
        return;
    }
    rotateleft2(val);
}
