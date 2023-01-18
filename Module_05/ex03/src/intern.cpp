#include "intern.hpp"

Intern::Intern(/* args */)
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern constructor called" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	if (this == &src)
		return *this;
	return *this;
}

Form* Intern::makeForm(const std::string form, const std::string target)
{
	if (form == "Presidential")
		return (new PresidentialPardonForm(target));
	else if (form == "Robotomy")
		return (new RobotomyRequestForm(target));
	else if (form == "Shrubbery")
		return (new ShrubberyCreationForm(target));
	else 
		throw Intern::InvalidForm();
	return (NULL);
}

const char *Intern::InvalidForm::what() const throw()
{
	return "Cannot create this form.";
}