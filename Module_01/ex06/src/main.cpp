#include "Harl.hpp"
#include <iostream>

int main()
{
    Harl harl;

    harl.complain("debug");
    std::cout << "-----" << std::endl;
    harl.complain("info");
    std::cout << "-----" << std::endl;
    harl.complain("warning");
    std::cout << "-----" << std::endl;
    harl.complain("error");
    std::cout << "-----" << std::endl;
    harl.complain("Travaldo");
}