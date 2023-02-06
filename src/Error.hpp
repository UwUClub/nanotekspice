/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <string>

namespace nts
{
    class Error : public std::exception
    {
        public:
            Error(const std::string &message) : _message(message) {}
            ~Error() = default;
            const char *what() const noexcept override { return _message.c_str(); }
        private:
            std::string _message;
    };
} // namespace nts

#endif /* !ERROR_HPP_ */
