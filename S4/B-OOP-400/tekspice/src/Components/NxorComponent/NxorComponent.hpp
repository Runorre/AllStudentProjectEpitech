/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** NxorComponent
*/

#ifndef NXORCOMPONE1NT_HPP_
#define NXORCOMPONE1NT_HPP_
#include "../../../include/nanotekspice.hpp"

namespace nts {
    class NxorComponent : public nts::AComponent {
        public:
            NxorComponent(std::string name);
            ~NxorComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);

        protected:
        private:
            nts::Tristate state = nts::Undefined;
    };
}

#endif /* !XORCOMPONE1NT_HPP_ */
