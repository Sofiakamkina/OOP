#pragma once
#include <exception>
namespace exceptions
{
    class WrongNumberOfParamter: public std::exception
    {
    public:
        const char *what() const noexcept;
    };
    class OpenFile: public std::exception
    {
    public:
        const char *what()  const noexcept;
    };

class WrongNameOfOperation:public std::exception
    {
    public:
        const char *what()  const noexcept;
    };

    class StackIsEmpty:public std::exception
    {
    public:
        const char *what()  const noexcept;
    };

    class notEnoughParameters:public std::exception
    {
    public:
        const char *what()  const noexcept;
    };
    class DivizionByZero:public std::exception
    {
    public:
        const char *what()  const noexcept;
    };

    class InvalidOperands: public std::exception
    {
    public:
        const char *what()  const noexcept;
    };
}
