#include <iostream>
#include "Harl.hpp"

Harl::Harl()
{

}

void Harl::complain(std::string level)
{
    
    enum SC { debug, info, warning, error};
    
    void (Harl::complain[])
    {
        Harl::debug,
        Harl::info,
        Harl::warning,
        Harl::error
    }

    for (int i; i < 4 ; i++)
    {
        SC switchcase
        if (level == switchcase[i])
            ()

        // Link the index of SC to the function in complain[]. Idk how to do it but I must sleep so... tomorrow.

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