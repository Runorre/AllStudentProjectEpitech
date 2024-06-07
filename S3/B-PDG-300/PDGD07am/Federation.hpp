/*
** EPITECH PROJECT, 2024
** Day07AM
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_
#include <string>
#include "WarpSystem.hpp"
#include "Destination.hpp"

namespace Federation {

    namespace Starfleet {
        class Captain {
            protected:
                std::string _name;
                int _age;
            public:
                Captain(std::string name);
                ~Captain();

                std::string getName();
                int getAge();
                void setAge(int age);
        };

        class Ensign {
        protected:
            std::string _name;
        public:
            Ensign(std::string name);
            ~Ensign();
        };

        class Ship {
            protected:
                int _length;
                int _width;
                std::string _name;
                short _maxWarp;
                Destination _home;
            private:
                Destination _location;
                WarpSystem::Core *_coreShip;
                Federation::Starfleet::Captain *_ledShip;
            public:
                Ship(int length, int width, std::string name, short maxWarp);
                ~Ship();

                void setupCore(WarpSystem::Core *core);
                void checkCore();
                void promote(Federation::Starfleet::Captain *captain);

                bool move(int warp, Destination d);
                bool move(int warp );
                bool move(Destination d);
                bool move();
        };
    }

    class Ship {
    protected:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        Destination _home;
    private:
        Destination _location;
        WarpSystem::Core *_coreShip;
    public:
        Ship(int length, int width, std::string name);
        ~Ship();

        void setupCore(WarpSystem::Core *core);
        void checkCore();

        bool move(int warp, Destination d);
        bool move(int warp );
        bool move(Destination d);
        bool move();
};
}

#endif /* !FEDERATION_HPP_ */
