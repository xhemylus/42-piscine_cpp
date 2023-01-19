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
	Form *(*Forms[])(const std::string target) = {makePres, makeShrub, makeRob};
	std::string tabs[] = {"Presidential", "Shrubbery" ,"Robotomy"};

	for (int i = 0 ; i < 3 ; i++)
		if (form == tabs[i])
			return (Forms[i](target));
	throw Intern::InvalidForm();
	return (NULL);
}

Form* Intern::makePres(const std::string target)
{
	return (new PresidentialPardonForm(target));
}
Form* Intern::makeShrub(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}
Form* Intern::makeRob(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

const char *Intern::InvalidForm::what() const throw()
{
	return "Cannot create this form.";
}