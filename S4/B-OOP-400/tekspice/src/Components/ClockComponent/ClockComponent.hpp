/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** NotComponent
*/

#ifndef CLOCKCOMPONENT_HPP_
#define CLOCKCOMPONENT_HPP_
#include "../../../include/nanotekspice.hpp"

namespace nts {
    class ClockComponent : public nts::AComponent {
        public:
            ClockComponent(std::string name);
            ~ClockComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);

        protected:
        private:
            nts::Tristate state = nts::Undefined;
            nts::Tristate tmpState = nts::Undefined;
            bool changing = false;
    };
}

#endif /* !CLOCKCOMPONENT_HPP_ */
