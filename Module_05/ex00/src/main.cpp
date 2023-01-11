#include "bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat John("John", 1);
		std::cout << John << std::endl;
		John.incrementGrade();

		// Bureaucrat Jane("Jane", 150);
		// std::cout << Jane << std::endl;
		// Jane.decrementGrade();
	}
	catch (std::exception &error)
	{
		std::cout << error.what() << std::endl;
	}
}
