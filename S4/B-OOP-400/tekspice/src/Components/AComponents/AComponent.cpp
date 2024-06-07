/*
** EPITECH PROJECT, 2024
** Bootstrap - NanotekSpice
** File description:
** AComponent
*/

#include "../../../include/nanotekspice.hpp"

nts::AComponent::AComponent(std::string name) {
    this->_name = name;
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) {
    this->modifyLinks(pin, &other, otherPin);
    other.modifyLinks(otherPin, this, pin);
    other.addInputLink(this->getName());
}

void nts::AComponent::modifyLinks(std::size_t pin, nts::IComponent *content, std::size_t otherPin) {
    this->_links[pin] = content;
    this->_linksOtherSide[pin] = otherPin;
}

std::vector<std::string> nts::AComponent::getAllInputs() const {
    return this->_inputName;
}

nts::Tristate nts::AComponent::getLinkCompute(std::size_t pin) const {
    if (_links.find(pin) != _links.end())
        return this->_links.at(pin)->compute(_linksOtherSide.at(pin));
    return nts::Tristate::Undefined;
}

nts::IComponent *nts::AComponent::getLink(std::size_t pin) const {
    if (_links.find(pin) != _links.end())
        return this->_links.at(pin);
    return nullptr;
}

void nts::AComponent::addInputLink(std::string name) {
    this->_inputName.push_back(name);
}

std::map<std::size_t, nts::IComponent*> nts::AComponent::getLinks() const {
    return _links;
}

std::string nts::AComponent::getName() const {
    return this->_name;
}
