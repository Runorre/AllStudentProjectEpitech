/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** 4081Component AND
*/

#ifndef QUATRE_MILLE_QUATRE_VINGTUN_COMPONENT_HPP_
#define QUATRE_MILLE_QUATRE_VINGTUN_COMPONENT_HPP_
#include "../../../include/nanotekspice.hpp"

namespace nts {
    class quatreMilleQutreVingtUnComponent : public nts::AComponent {
        public:
            quatreMilleQutreVingtUnComponent(std::string name);
            ~quatreMilleQutreVingtUnComponent();

            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void changeState(std::size_t pin, nts::Tristate newState);

        protected:
        private:
            std::vector<nts::Tristate> state;
    };
}

#endif /* !QUATRE_MILLE_QUATRE_VINGTUN_COMPONENT_HPP_ */
