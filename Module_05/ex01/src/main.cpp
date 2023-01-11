#include "bureaucrat.hpp"
#include "form.hpp"

int main(void)
{
	try
	{
		Bureaucrat John("John", 10);
		std::cout << John << std::endl;

		// Bureaucrat Jane("Jane", 150);
		// std::cout << Jane << std::endl;
		// Jane.decrementGrade();

		Form Form1("Form1", 1, 1);
		std::cout << Form1 << std::endl;

		John.signForm(Form1);
		
		std::cout << Form1 << std::endl;

	}
	catch (std::exception &error)
	{
		std::cout << error.what() << std::endl;
	}
}
