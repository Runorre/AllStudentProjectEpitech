/*
** EPITECH PROJECT, 2024
** Bootstrap - NanotekSpice
** File description:
** OutputComponent
*/

#ifndef OUTPUTCOMPONENT_HPP_
#define OUTPUTCOMPONENT_HPP_

#include "../../../include/nanotekspice.hpp"

namespace nts {
    class OutputComponent : public nts::AComponent {
        public:

            OutputComponent(std::string name);
            ~OutputComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);
        protected:
        private:
            nts::Tristate state = nts::Undefined;
            nts::Tristate tmpState = nts::Undefined;
    };
}


#endif /* !OUTPUTCOMPONENT_HPP_ */
