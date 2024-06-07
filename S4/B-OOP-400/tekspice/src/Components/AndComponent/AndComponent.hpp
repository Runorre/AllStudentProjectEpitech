/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** AndComponent
*/

#ifndef ANDCOMPONE1NT_HPP_
#define ANDCOMPONENT_HPP_
#pragma once
#include "../../../include/nanotekspice.hpp"

namespace nts {
    class AndComponent : public nts::AComponent {
        public:
            AndComponent(std::string name);
            ~AndComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);

        protected:
        private:
            nts::Tristate state = nts::Undefined;
    };
}

#endif /* !ANDCOMPONENT_HPP_ */
