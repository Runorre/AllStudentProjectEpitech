/*
** EPITECH PROJECT, 2024
** Bootstrap - NanotekSpice
** File description:
** FalseComponent
*/

#ifndef FalseComponent_HPP_
#define FalseComponent_HPP_

#include "../../../include/nanotekspice.hpp"

namespace nts {
    class FalseComponent : public nts::AComponent {
        public:

            FalseComponent(std::string name);
            ~FalseComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);
        protected:
        private:
            nts::Tristate state = nts::False;
    };
}


#endif /* !FalseComponent_HPP_ */
