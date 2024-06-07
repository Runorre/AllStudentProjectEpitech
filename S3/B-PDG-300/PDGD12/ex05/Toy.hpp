/*
** EPITECH PROJECT, 2024
** Day12
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_
#include <string>
#include <iostream>
#include "Picture.hpp"

class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY
        };

        Toy(ToyType type, std::string name, std::string fileName);
        Toy(const Toy &t);
        Toy();
        ~Toy();

        ToyType getType() const;
        std::string getName() const;
        void setName(std::string name);
        bool setAscii(std::string fileName);
        std::string getAscii() const;

        virtual void speak(std::string text) const;
        virtual bool speak_es(std::string text);

        

        Toy &operator<<(const std::string &ascii);
        Toy &operator=(const Toy &source);

        class Error {
            public:
                enum ErrorType {
                    UNKNOWN,
                    PICTURE,
                    SPEAK
                };

                explicit Error(std::string msg, Error::ErrorType type1, std::string whereErr);

                const std::string what();
                const std::string where();
                ErrorType type;
            private:
                std::string msgError;
                
                std::string whereError;
        };

        Error getLastError() const;

    protected:
    private:
        ToyType _type_;
        std::string _name_;
        Picture *_ascii_;
        Error *err;
};

std::ostream &operator<<(std::ostream &os, const Toy &t);

#endif /* !TOY_HPP_ */
