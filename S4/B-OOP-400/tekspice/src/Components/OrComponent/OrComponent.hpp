/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** OrComponent
*/

#ifndef ORCOMPONE1NT_HPP_
#define ORCOMPONE1NT_HPP_
#include "../../../include/nanotekspice.hpp"

namespace nts {
    class OrComponent : public nts::AComponent {
        public:
            OrComponent(std::string name);
            ~OrComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);

        protected:
        private:
            nts::Tristate state = nts::Undefined;
    };
}

#endif /* !ORCOMPONE1NT_HPP_ */
