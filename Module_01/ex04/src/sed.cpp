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
    std::string::size_type pos;

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
        std::cout << line << std::endl;
        pos = line.find(s1);
        while(pos != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);

            pos = line.find(s1, pos + s2.length());
        }
        newfile << line << std::endl;
    }
}
