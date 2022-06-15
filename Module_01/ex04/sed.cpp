#include "sed.hpp"

Sed::Sed()
{

}

Sed::~Sed()
{

}

void Sed::replace(std::string filename, std::string s1, std::string s2)
{
    std::ifstream oldfile;
    std::ofstream newfile;
    std::string line;

    if (filename.empty())
    {
        std::cout << "No Filename." << std::endl;
        return;
    }
    else if (s1.empty() || s2.empty())
    {
        std::cout << "Empty strings." << std::endl;
        return;
    }
    oldfile.open(filename.c_str());
    newfile.open(filename.append(".replace").c_str());
    if (oldfile.fail() || newfile.fail())
        {
            std::cout << "couldn't open file" << std::endl;
            return ;
        };
    
    while (std::getline(oldfile, line))
    {
        if (line[line.length() - 1] == '\r')
            line.erase(line.end()-1);
        if (line.compare(s1) == 0)
            newfile << s2 << std::endl;
        else
            newfile << line << std::endl;
    }
}
