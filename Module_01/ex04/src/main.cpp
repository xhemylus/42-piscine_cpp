#include <iostream>
#include "sed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
        std::cout << "Invalid Arguments.";
    else
        Sed::replace(argv[1], argv[2], argv[3]);
    return (0);
}
