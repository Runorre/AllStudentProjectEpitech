/*
** EPITECH PROJECT, 2024
** Day07AM
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_
#include <string>
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Borg {
    class Ship {
            protected:
                int _side;
                short _maxWarp;
                Destination _home;
            private:
                Destination _location;
                WarpSystem::Core *_coreShip;
            public:
                Ship();
                ~Ship();

                void setupCore(WarpSystem::Core *core);
                void checkCore();

                bool move(int warp, Destination d);
                bool move(int warp );
                bool move(Destination d);
                bool move();
        };
}

#endif /* !BORG_HPP_ */
