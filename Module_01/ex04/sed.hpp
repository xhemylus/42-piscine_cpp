#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
public:
    Sed();
    ~Sed();
    static void replace(std::string filename, std::string s1, std::string s2);
};
#endif