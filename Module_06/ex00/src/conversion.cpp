#include "conversion.hpp"

Conversion::Conversion()
{
	std::cout << "Conversion Default Constructor called" << std::endl;
}

Conversion::Conversion(const std::string input) : _input(input)
{
	this->_double = atof(input.c_str());
	this->convert();
	this->printAll();
}

Conversion::Conversion(const Conversion &src) : _input(src.getInput())
{
	*this = src;
	this->printAll();
}

Conversion::~Conversion()
{

}

Conversion &Conversion::operator=(const Conversion &src)
{
	if (this == &src)
		return *this;

	this->_type = src.getType();
	this->_char = src.getChar();
	this->_int = src.getInt();
	this->_float = src.getFloat();
	this->_double = src.getDouble();
	return *this;
}

int Conversion::parse(std::string input)
{
	if (input == "nan" || input == "+inf" || input == "-inf"|| input == "+inff" || input == "-inff")
	{
		return (NAN_INF);
	}
	else if (input.length() == 1 && (input[0] == '+' || input[0] == '-' || input[0] == 'f' || input[0] == '.'))
	{
		return (CHAR);
	}
	else if (input.find_first_of("+-") != input.find_last_of("+-"))
		return (ERROR);
	else if (input.find_first_not_of("+-0123456789") == std::string::npos)
		return (INT);
	else if (input.find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if (input.find_first_of(".") != input.find_last_of(".") || isdigit(input[input.find_first_of(".") + 1]) == false || input.find_first_of(".") == 0)
			return (ERROR);
		else
			return (DOUBLE);
	}
	else if (input.find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (input.find_first_of("f") != input.find_last_of("f") || input.find_first_of(".") != input.find_last_of(".") ||
			input.find_first_of("f") - input.find_first_of(".") == 1 || input.find_first_of(".") == 0 || input[input.find_first_of("f") + 1] != '\0')
			return (ERROR);
		else
			return (FLOAT);
	}
	else if ((input.length() == 1 && std::isprint(input[0])) ||
			 (input.length() == 1 && std::isalpha(input[0])))
	{
		return (CHAR);
	}
	else
		return (ERROR);
}

void Conversion::fromChar(void)
{
	this->_char = static_cast<unsigned char>(_input[0]);
	this->_int = static_cast<int>(this->getChar());
	this->_float = static_cast<float>(this->getChar());
	this->_double = static_cast<double>(this->getChar());
}
void Conversion::fromInt(void)
{
	this->_int = static_cast<int>(this->getDouble());
	this->_char = static_cast<unsigned char>(this->getDouble());
	this->_float = static_cast<float>(this->getDouble());
}
void Conversion::fromFloat(void)
{
	this->_float = static_cast<float>(this->getDouble());
	this->_char = static_cast<char>(this->getFloat());
	this->_int = static_cast<int>(this->getFloat());
}
void Conversion::fromDouble(void)
{
	this->_char = static_cast<char>(this->getDouble());
	this->_int = static_cast<int>(this->getDouble());
	this->_float = static_cast<float>(this->getDouble());
}

void Conversion::convert(void)
{
	void (Conversion::*converts[])(void) = {&Conversion::fromChar, &Conversion::fromInt, &Conversion::fromFloat, &Conversion::fromDouble};
	int types[] = {CHAR, INT, FLOAT, DOUBLE};

	this->_type = parse(this->_input);

	if (this->getType() == NAN_INF)
		return;
	int i;
	for (i = 0; i < 4; i++)
	{
		if (this->getType() == types[i])
		{
			(this->*converts[i])();
			break;
		}
	}
	if (i == 4)
		throw Conversion::ErrorException();
}

void Conversion::printChar() const
{
	if (this->getType() != NAN_INF && this->getDouble() >= 0 && this->getDouble() <= UCHAR_MAX)
	{
		if (isprint(this->getChar()))
			std::cout << "char: '" << this->getChar() << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
}

void Conversion::printInt() const
{
if (this->getType() != NAN_INF && this->getDouble() >= INT_MIN && this->getDouble() <= INT_MAX)
	{
		std::cout << "int: " << this->getInt() << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;
}

void Conversion::printFloat() const
{
	if (this->getType() != NAN_INF)
	{
		std::cout << "float: " << this->getFloat();
		if (this->getFloat() < INT_MIN || this->getFloat() > INT_MAX || this->getFloat() - this->getInt() == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
	else
	{
		if (_input == "nan" || _input == "nanf")
			std::cout << "float: nanf" << std::endl;
		else if (_input[0] == '+')
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}
}

void Conversion::printDouble() const
{
	if (this->getType() != NAN_INF)
	{
		std::cout << "double: " << this->getDouble();
		if (this->getDouble() < INT_MIN || this->getDouble() > INT_MAX || this->getDouble() - this->getInt() == 0)
		{
			std::cout << ".0" << std::endl;
		}
		else
			std::cout << std::endl;
	}
	else
	{
		if (_input == "nan" || _input == "nanf")
			std::cout << "double: nan" << std::endl;
		else if (_input[0] == '+')
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
}

void Conversion::printAll(void) const
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

const char *Conversion::ErrorException::what(void) const throw()
{
	return ("Error: Unprintable");
};

std::string Conversion::getInput(void) const
{
	return (this->_input);
}

int Conversion::getType(void) const
{
	return (this->_type);
}

char Conversion::getChar(void) const
{
	return (this->_char);
}

int Conversion::getInt(void) const
{
	return (this->_int);
}

float Conversion::getFloat(void) const
{
	return (this->_float);
}

double Conversion::getDouble(void) const
{
	return (this->_double);
}

// Setter
