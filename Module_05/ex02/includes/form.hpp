#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		Form(Form const &other);
		virtual ~Form();

		Form &operator=(Form const &other);

		std::string const &getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		virtual void Formexecute() const = 0;

		void execute(Bureaucrat const &executor) const;

		void beSigned(Bureaucrat const &bureaucrat);

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

		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		std::string const   _name;
		bool                _isSigned;
		int                 _gradeToSign;
		int                 _gradeToExecute;
};

std::ostream& operator<<(std::ostream &outputStream, const Form &ref);

#endif