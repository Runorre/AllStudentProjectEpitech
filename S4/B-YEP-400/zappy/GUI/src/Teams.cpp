/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Teams
*/

#include "../includes/Teams.hpp"

Teams::Teams(const string &teamName) : mTeamName(teamName)
{
    if (::colors.empty()) {
        return;
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dis(0, static_cast<int>(::colors.size() - 1));
    const int randomNumber = dis(gen);
    auto it = ::colors.begin();
    advance(it, randomNumber);
    mColor = get<0>(get<1>(*it));
    pathColor = get<1>(get<1>(*it));
}

void Teams::addCharacter(const Characters &character)
{
    mCharacters.push_back(character);
}

vector<Characters> Teams::getCharacters() const
{
    return mCharacters;
}
