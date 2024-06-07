/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** NandComponent
*/

#ifndef NandComponent_HPP_
#define NandComponent_HPP_
#pragma once
#include "../../../include/nanotekspice.hpp"

namespace nts {
    class NandComponent : public nts::AComponent {
        public:
            NandComponent(std::string name);
            ~NandComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);

        protected:
        private:
            nts::Tristate state = nts::Undefined;
    };
}

#endif /* !NandComponent_HPP_ */
