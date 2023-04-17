/*
** EPITECH PROJECT, 2023
** nts/Exception.hpp
** File description:
** Used for error handling
*/

#pragma once
#include <iostream>

namespace nts
{
    /// @brief Displays an exception on std::cerr (error output).
    /// @brief Uses an additional string for content
    /// @return Always false
    bool drawException(char const *what, std::string const &content);
    /// @brief Displays an exception on std::cerr (error output)
    /// @return Always false
    bool drawException(char const *what);

    namespace exception
    {
        class Base : public std::exception
        {
        protected:
            std::string _content = "";
        public:
            Base(std::string const &ct) { _content = ct; }
            Base(void) {}
            std::string content(void) const { return _content; }
        };

        class InvalidId : public nts::exception::Base
        {
        public:
            InvalidId(std::string const &ct) { _content = ct; }
            InvalidId(void) { }
            char *what(void) { return (char *)"Invalid id"; }
        };

        class InvalidKey : public nts::exception::Base
        {
        public:
            InvalidKey(std::string const &ct) { _content = ct; }
            InvalidKey(void) { }
            char *what(void) { return (char *)"Invalid key"; }
        };

        class InvalidPin : public nts::exception::Base
        {
        public:
            InvalidPin(std::string const &ct) { _content = ct; }
            InvalidPin(void) { }
            char *what(void) { return (char *)"Pin out of range"; }
        };

        class ComponentNotInput : public nts::exception::Base
        {
        public:
            ComponentNotInput(std::string const &ct) { _content = ct; }
            ComponentNotInput(void) { }
            char *what(void) { return (char *)"Component not an input"; }
        };

        class UnknownCommand : public nts::exception::Base
        {
        public:
            UnknownCommand(std::string const &ct) { _content = ct; }
            UnknownCommand(void) { }
            char *what(void) { return (char *)"Unknown command"; }
        };

        namespace parsing {
            class CantOpenFile : public nts::exception::Base
            {
            public:
                CantOpenFile(std::string const &ct) { _content = ct; }
                CantOpenFile(void) { }
                char *what(void) { return (char *)"Cannot open file"; }
            };
            class UnknownLineFormating : public nts::exception::Base
            {
            public:
                UnknownLineFormating(std::string const &ct) { _content = ct; }
                UnknownLineFormating(void) { }
                char *what(void) { return (char *)"Unknown line formating"; }
            };
            class UnknownStatement : public nts::exception::Base
            {
            public:
                UnknownStatement(std::string const &ct) { _content = ct; }
                UnknownStatement(void) { }
                char *what(void) { return (char *)"Unknown statement"; }
            };
            class UnknownComponentName : public nts::exception::Base
            {
            public:
                UnknownComponentName(std::string const &ct) { _content = ct; }
                UnknownComponentName(void) { }
                char *what(void) { return (char *)"Unknown component name"; }
            };
            class UnknownComponentType : public nts::exception::Base
            {
            public:
                UnknownComponentType(std::string const &ct) { _content = ct; }
                UnknownComponentType(void) { }
                char *what(void) { return (char *)"Unknown component type"; }
            };
            class ShareSameName : public nts::exception::Base
            {
            public:
                ShareSameName(std::string const &ct) { _content = ct; }
                ShareSameName(void) { }
                char *what(void) { return \
                    (char *)"Several components share the same name"; }
            };
            class ChipsetOutside : public nts::exception::Base
            {
            public:
                ChipsetOutside(std::string const &ct) { _content = ct; }
                ChipsetOutside(void) { }
                char *what(void) { return \
                    (char *)"Chipset outside of statement .chipsets"; }
            };
            class LinkOutside : public nts::exception::Base
            {
            public:
                LinkOutside(std::string const &ct) { _content = ct; }
                LinkOutside(void) { }
                char *what(void) { return \
                    (char *)"Link outside of statement .links"; }
            };
            class LinkToItself : public nts::exception::Base
            {
            public:
                LinkToItself(std::string const &ct) { _content = ct; }
                LinkToItself(void) { }
                char *what(void) { return \
                    (char *)"Pin linked to itself"; }
            };
        }

        namespace usage
        {
            class InvalidAmountArguments : public nts::exception::Base
            {
            public:
                char *what(void) \
                    { return (char *)"Invalid amount of arguments"; }
            };
            class EmptyFileName : public nts::exception::Base
            {
            public:
                char *what(void) \
                    { return (char *)"Empty file name"; }
            };
        }
    }
}
