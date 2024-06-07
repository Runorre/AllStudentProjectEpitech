/*
** EPITECH PROJECT, 2024
** Bootstrap - NanotekSpice
** File description:
** TrueComponent
*/

#ifndef TRUECOMPONENT_HPP_
#define TRUECOMPONENT_HPP_

#include "../../../include/nanotekspice.hpp"

namespace nts {
    class TrueComponent : public nts::AComponent {
        public:

            TrueComponent(std::string name);
            ~TrueComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);
        protected:
        private:
            nts::Tristate state = nts::True;
    };
}


#endif /* !TRUECOMPONENT_HPP_ */
