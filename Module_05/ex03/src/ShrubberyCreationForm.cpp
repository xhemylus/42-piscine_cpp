#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : Form(other), _target(other._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	(void)other;
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::Formexecute() const
{
	std::ofstream NewFile(this->getTarget().append("_shrubbery").c_str());
	for (int i = 0; i < 3; i++)
		NewFile <<

"          &&& &&  & &&" << std::endl <<
"      && &//&/|& ()|/ @, &&" << std::endl <<
"      &//(/&/&||/& /_/)_&/_&" << std::endl <<
"   &() &/&|()|/&// % /  & ()" << std::endl <<
"  &__&&_ |& |&&/&__%_/_& &&" << std::endl <<
"&&   && & &| &| /& & % ()& /&&" << std::endl <<
" ()&_---()&&&-&&--%---()~" << std::endl <<
"     &&      |||" << std::endl <<
"             |||" << std::endl <<
"             |||" << std::endl <<
"             |||" << std::endl <<
"       , -=-~  .-^- _" << std::endl <<
"            " << std::endl;
	NewFile.close();
}

std::ostream& operator<<(std::ostream &outputStream, const ShrubberyCreationForm &ref)
{
	outputStream << "Form name: " << ref.getName() << std::endl;
	outputStream << "Form is signed: " << ref.getIsSigned() << std::endl;
	outputStream << "Form grade to sign: " << ref.getGradeToSign() << std::endl;
	outputStream << "Form grade to execute: " << ref.getGradeToExecute() << std::endl;
	return (outputStream);
}

