/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** XorComponent
*/

#ifndef XORCOMPONE1NT_HPP_
#define XORCOMPONE1NT_HPP_
#include "../../../include/nanotekspice.hpp"

namespace nts {
    class XorComponent : public nts::AComponent {
        public:
            XorComponent(std::string name);
            ~XorComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);

        protected:
        private:
            nts::Tristate state = nts::Undefined;
    };
}

#endif /* !XORCOMPONE1NT_HPP_ */
