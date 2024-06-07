/*
** EPITECH PROJECT, 2024
** Day13
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_

template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(const T a, const T b) {
    return a < b ? a : b;
};

template <typename T>
T max(const T a, const T b) {
    return b < a ? a : b;
};

template <typename T>
T clamp(const T value, const T min, const  T max) {
    if (value < min)
        return min;
    else if (!(value < max))
        return max;
    else
        return value;
};


#endif /* !ALGORITHM_HPP_ */
