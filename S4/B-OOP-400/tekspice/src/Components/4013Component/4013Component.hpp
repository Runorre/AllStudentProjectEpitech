/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-angelo.anselmet
** File description:
** 4013Component
*/

#ifndef QUATRE_MILLE_TREIZE_HPP_
#define QUATRE_MILLE_TREIZE_HPP_
#include "../../../include/nanotekspice.hpp"


namespace nts {
    class quatreMilleTreizeComponent : public nts::AComponent {
        public:
            quatreMilleTreizeComponent(std::string name);
            ~quatreMilleTreizeComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);

        protected:
        private:
            std::vector<nts::Tristate> state;
    };
}

#endif /* QUATRE_MILLE_TREIZE_HPP_ */
