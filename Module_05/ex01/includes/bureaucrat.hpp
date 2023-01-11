#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &other);
		virtual ~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &other);

		std::string const &getName() const;
		int getGrade() const;
		void signForm(Form &form);

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

private:
	std::string const   _name;
	int                 _grade;
};

std::ostream& operator<<(std::ostream &outputStream, const Bureaucrat &ref);

#endif