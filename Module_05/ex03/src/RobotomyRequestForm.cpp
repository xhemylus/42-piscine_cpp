#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : Form(other), _target(other._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	(void)other;
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::Formexecute() const
{
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << "*bip* *boop*" << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}

std::ostream& operator<<(std::ostream &outputStream, const RobotomyRequestForm &ref)
{
	outputStream << "Form name: " << ref.getName() << std::endl;
	outputStream << "Form is signed: " << ref.getIsSigned() << std::endl;
	outputStream << "Form grade to sign: " << ref.getGradeToSign() << std::endl;
	outputStream << "Form grade to execute: " << ref.getGradeToExecute() << std::endl;
	return (outputStream);
}