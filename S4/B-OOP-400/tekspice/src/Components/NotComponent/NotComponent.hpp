/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** NotComponent
*/

#ifndef NOTCOMPONE1NT_HPP_
#define NOTCOMPONE1NT_HPP_
#include "../../../include/nanotekspice.hpp"

namespace nts {
    class NotComponent : public nts::AComponent {
        public:
            NotComponent(std::string name);
            ~NotComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);

        protected:
        private:
            nts::Tristate state = nts::Undefined;
    };
}

#endif /* !NOTCOMPONE1NT_HPP_ */
