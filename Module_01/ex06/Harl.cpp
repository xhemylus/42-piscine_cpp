#include <iostream>
#include "Harl.hpp"

Harl::Harl()
{

}

void Harl::complain(std::string level)
{
    
    void (Harl::*complain[])(void) = 
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string levels[] =
    {
        "debug",
        "info",
        "warning",
        "error",
    }


    while (levels[i] && levels[i] != level)
        i++;

    switch (i)
    {
    case (0):
        void Harl::debug(void)
        void Harl::info(void)
        void Harl::warning(void)
        void Harl::error(void)
    case (1):
        void Harl::info(void)
        void Harl::warning(void)
        void Harl::error(void)
    case (2):
        void Harl::warning(void)
        void Harl::error(void)
    case (3):
        void Harl::error(void)

    }
};

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}