/*
** EPITECH PROJECT, 2024
** Bootstrap - NanotekSpice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_
#include "../../../include/nanotekspice.hpp"

namespace nts {
    class AComponent : public nts::IComponent {
        public:

            AComponent(std::string name);
            virtual ~AComponent() = default;

            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void simulate(std::size_t tick) = 0;
            virtual void changeState(std::size_t pin, nts::Tristate state) = 0;

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            nts::Tristate getLinkCompute(std::size_t pin) const; // getter du precedent recupere True False ou Undefined
            nts::IComponent *getLink(std::size_t pin) const;
            
            void modifyLinks(std::size_t pin, nts::IComponent *content, std::size_t otherPin);
            void addInputLink(std::string name);
            std::vector<std::string> getAllInputs() const;
            std::map<std::size_t, nts::IComponent*> getLinks() const;

            std::string getName() const;
        protected:
            std::string _name;
        private:
            std::map<std::size_t, nts::IComponent*> _links;
            std::vector<std::string> _inputName;
            std::map<std::size_t, std::size_t> _linksOtherSide;

    };
}

#endif /* !ACOMPONENT_HPP_ */
