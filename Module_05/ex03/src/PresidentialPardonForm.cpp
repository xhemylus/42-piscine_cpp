#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : Form(other), _target(other._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	(void)other;
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}	

void	PresidentialPardonForm::Formexecute() const
{
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::ostream& operator<<(std::ostream &outputStream, const PresidentialPardonForm &ref)
{
	outputStream << "Form name: " << ref.getName() << std::endl;
	outputStream << "Form is signed: " << ref.getIsSigned() << std::endl;
	outputStream << "Form grade to sign: " << ref.getGradeToSign() << std::endl;
	outputStream << "Form grade to execute: " << ref.getGradeToExecute() << std::endl;
	return (outputStream);
}