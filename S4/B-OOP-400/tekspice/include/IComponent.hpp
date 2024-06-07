/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

    #include "nanotekspice.hpp"
    #include <cstddef>
    #include <exception>
    #include <string>
    #include <iostream>
    #include <map>
    #include <vector>


namespace nts {
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };
    class IComponent {
    public :
        virtual ~IComponent() = default;
        virtual void simulate (std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin ) = 0;
        virtual void modifyLinks(std::size_t pin, nts::IComponent *content, std::size_t otherPin) = 0;
        virtual std::map<std::size_t, nts::IComponent*> getLinks() const = 0;
        virtual void changeState(std::size_t pin, nts::Tristate newState) = 0;
        virtual std::string getName() const = 0;
        virtual void addInputLink(std::string name) = 0;
        virtual std::vector<std::string> getAllInputs() const = 0;
    };

    enum class ErrorType {
        FileOpenFailed,
        MissingSection,
        MalformedLine,
        UnknownError,
        UnknownComponent,
        IncorrectFile,
        NameAlreadyUse,
        WrongTypeError,
        EmptySection
    };

    class ParsingError : public std::exception {
        private:
            ErrorType errorType;

        public:
            ParsingError(ErrorType type) : errorType(type) {}
            ParsingError() {};

            const char* what() const noexcept override {return "There is an error.";}

            ErrorType getErrorType() const noexcept {
                return errorType;
            }
    };

    class FileOpenFailed : public ParsingError {
        public:
            FileOpenFailed() : ParsingError(ErrorType::FileOpenFailed) {}

            const char* what() const noexcept override {return "Can't open the file.";}
    };

    class MissingSection : public ParsingError {
        public:
            MissingSection() : ParsingError(ErrorType::MissingSection) {}

            const char* what() const noexcept override {return ".chipsets and/or .links are missed.";}
    };

    class MalformedLine : public ParsingError {
        public:
            MalformedLine() : ParsingError(ErrorType::MalformedLine) {}

            const char* what() const noexcept override {return "Inccorect .chipsets format.";}
    };

    class UnknownComponentError : public ParsingError {
        private:
            std::string message;

        public:
           UnknownComponentError(const std::string& name) : ParsingError() {
            message = "Unknown component '" + name + "'.";
            }

            const char* what() const noexcept override {
                return message.c_str();
            }
    };

    class IncorrectFile : public ParsingError {
        public:
            IncorrectFile() : ParsingError(ErrorType::IncorrectFile) {}

            const char* what() const noexcept override {return "File must ended with .nts.";}
    };

    class NameAlreadyUse : public ParsingError {
        public:
            NameAlreadyUse() : ParsingError(ErrorType:: NameAlreadyUse) {}

            const char* what() const noexcept override {return "Chipset name must be unique.";}
    };

    class EmptySection : public ParsingError {
        public:
            EmptySection() : ParsingError(ErrorType:: EmptySection) {}

            const char* what() const noexcept override {return "Empty section chipets or links.";}
    };

    class WrongTypeError : public ParsingError {
        private:
            std::string message;

        public:
           WrongTypeError(const std::string& type) : ParsingError() {
            message = "type '" + type + "' don't exist.";
            }

            const char* what() const noexcept override {
                return message.c_str();
            }
    };
}

#endif /* !ICOMPONENT_HPP_ */
