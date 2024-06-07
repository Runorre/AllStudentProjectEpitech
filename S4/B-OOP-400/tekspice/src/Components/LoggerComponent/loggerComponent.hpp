/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-angelo.anselmet
** File description:
** logger
*/

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include "../../../include/nanotekspice.hpp"

namespace nts {
    class loggerComponent : public nts::AComponent {
        public:
            loggerComponent(std::string name);
            ~loggerComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(size_t pin, nts::Tristate newState);

        protected:
        private:
            std::vector<nts::Tristate> state;
    };
}


#endif /* !LOGGER_HPP_ */

