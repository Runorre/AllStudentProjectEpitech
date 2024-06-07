/*
** EPITECH PROJECT, 2024
** Bootstrap - NanotekSpice
** File description:
** InputComponent
*/

#ifndef INPUTCOMPONENT_HPP_
#define INPUTCOMPONENT_HPP_

#include "../../../include/nanotekspice.hpp"

namespace nts {
    class InputComponent : public nts::AComponent {
        public:

            InputComponent(std::string name);
            ~InputComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);
        protected:
        private:
            nts::Tristate state = nts::Undefined;
            nts::Tristate tmpState = nts::Undefined;
    };
}


#endif /* !INPUTCOMPONENT_HPP_ */
