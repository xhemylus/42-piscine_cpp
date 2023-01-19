#include <iostream>
#include <stdlib.h>

#include "intern.hpp"
#include "bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define BREAKLINE std::cout << "###" << std::endl;

int main(void)
{
	srand(time(NULL));
	Intern someIntern;

	Bureaucrat supervisor("Supervisor", 1);
	std::cout << supervisor << std::endl;
	Bureaucrat jack("Jack", 25);
	std::cout << jack << std::endl;
	std::cout << "- - - - - - - - - -" << std::endl;
	Form *shrub = someIntern.makeForm("Shrubbery", "home");
	std::cout << *shrub << std::endl;
	supervisor.signForm(*shrub);
	jack.executeForm(*shrub);
	std::cout << "- - - - - - - - - -" << std::endl;

	Form *pres = someIntern.makeForm("Presidential", "Jack");
	std::cout << *pres << std::endl;
	supervisor.signForm(*pres);
	supervisor.executeForm(*pres);
	jack.executeForm(*pres);
	std::cout << "- - - - - - - - - -" << std::endl;


	Form *robot = someIntern.makeForm("Robotomy", "Bender");
	std::cout << *robot << std::endl;
	robot->beSigned(supervisor);
	robot->execute(jack);
	jack.executeForm(*robot);
	jack.executeForm(*robot);
	BREAKLINE

	try
	{
		Form *ran = someIntern.makeForm("Random Form", "nobody");
		std::cout << ran << std::endl;
	}
	catch(std::exception const &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	BREAKLINE

	try
	{
		jack.executeForm(*pres);
	}
	catch(std::exception const &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	BREAKLINE

	try
	{
		RobotomyRequestForm robot = RobotomyRequestForm("Bender");
		std::cout << robot << std::endl;
		robot.execute(supervisor);
	}
	catch(std::exception const &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	BREAKLINE

	try
	{
		PresidentialPardonForm pres = PresidentialPardonForm("Jack");
		std::cout << pres << std::endl;
		supervisor.signForm(pres);
		pres.execute(jack);
	}
	catch(std::exception const &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	BREAKLINE

	try
	{
		PresidentialPardonForm pres = PresidentialPardonForm("Jack");
		std::cout << pres << std::endl;
		supervisor.signForm(pres);
		jack.executeForm(pres);
	}
	catch(std::exception const &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	delete shrub;
	delete pres;
	delete robot;

	return (0);
}