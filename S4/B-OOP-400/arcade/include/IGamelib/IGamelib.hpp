/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGamelib
*/

#ifndef IGAMELIB_HPP_
    #define IGAMELIB_HPP_
    #include "../Arcade.hpp"



    class IGamelib {
        public:
            virtual ~IGamelib() = default;

            virtual std::vector<std::vector<std::string>>getStaticDecor() const = 0;
            virtual std::vector<IObject>getObject() = 0;
            virtual void setObject(std::vector<IObject> layer) = 0;
            virtual int getScore() const = 0;
            virtual std::string getName() const = 0;
            virtual bool isGameOver() const = 0;
            // virtual std::vector<IObject>moove_charac(int moove) = 0;

            virtual void sendCommand(int commande) = 0;

        protected:
        private:
    };

#endif /* !IGAMELIB_HPP_ */
