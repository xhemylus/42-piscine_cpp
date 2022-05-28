#include <iostream>

int main()
{
   std::string str1 = "HI THIS IS BRAIN";
   std::string * stringPTR = &str1;
   std::string & stringREF = str1;


   std::cout << "MEMORY ADRESS OF STR: " << &str1 << std::endl;
   std::cout << "MEMORY ADRESS OF PTR: " << stringPTR << std::endl;
   std::cout << "MEMORY ADRESS OF REF: " << &stringREF << std::endl;
   std::cout << std::endl;
   std::cout << "VALUE OF STR: " << str1 << std::endl; 
   std::cout << "VALUE POINTED BY PTR: " << *stringPTR  << std::endl;
   std::cout << "VALUE POINTED BY REF: " << stringREF << std::endl;
}