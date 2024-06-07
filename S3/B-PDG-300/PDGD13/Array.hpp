/*
** EPITECH PROJECT, 2024
** Day13
** File description:
** Array
*/

#ifndef ARRAY_HPP_
#define ARRAY_HPP_
#include <vector>
#include <exception>
#include <ostream>
#include <functional>


template <typename type, std::size_t s>
class Array {
    public:
        class ErrorOutofRange : public std::exception {
            public:
                ~ErrorOutofRange() override = default;
                const char* what() const noexcept override {
                    return ("Out of range");
                };
        };

        Array() : _array_(s) {}

        type &operator[](std::size_t index) {
            if (index < s)
                return _array_[index];
            else
                throw ErrorOutofRange();
        }

        const type &operator[](std::size_t index) const {
            if (index < s)
                return _array_[index];
            else
                throw ErrorOutofRange();
        }

        std::size_t size() const {
            return s;
        }

        void forEach(const std::function <void (const type &)> &task) const {
            for (std::size_t i = 0; i != s; i++) {
                task(_array_[i]);
            }
        }

        template<typename U>
        Array<U, s> convert(const std::function <U(const type &)>& converter) const {
            Array<U, s> newArray;
            for (std::size_t i = 0; i != s; i++) {
                newArray[i] = converter(_array_[i]);
            }
            return newArray;
        }
        std::vector<type> _array_;
    private:
        
};

template <typename type, std::size_t s>
std::ostream &operator<<(std::ostream &os, const Array<type, s> &a) {
    os << "[";
    for (std::size_t i = 0; i != s; i++) {
        os << a._array_[i];
        if ((i + 1) < s)
            os << ", ";
    }
    os << "]";
    return os;
}


#endif /* !ARRAY_HPP_ */
