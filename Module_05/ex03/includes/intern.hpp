#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	/* data */
public:
	Intern();
	Intern(const Intern &src);
	~Intern();

	Intern &operator=(const Intern &src);

	Form *makeForm(const std::string form, const std::string target);

	class InvalidForm : public std::exception
		{
			public:
				const char *what() const throw();
		};

	
};

#endif