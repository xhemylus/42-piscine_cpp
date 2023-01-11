#include "fixed.hpp"

std::ostream& operator<<(std::ostream& out, const Fixed& src)
{
	out << src.toFloat();
	return out;
}

// Constructors
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = n << this->_bits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(n * (1 << this->_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Operators
	// Comparaison operators

bool Fixed::operator<(const Fixed& src)
{
	if (this->value < src.value)
		return true;
	return false;
}

bool Fixed::operator>(const Fixed& src)
{
	if (this->value > src.value)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed& src)
{
	if (this->value >= src.value)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed& src)
{
	if (this->value <= src.value)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed& src)
{
	if (this->value == src.value)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed& src)
{
	if (this->value != src.value)
		return true;
	return false;
}

	// Arithmetic operators

Fixed Fixed::operator+(const Fixed& src)
{
	Fixed tmp(*this);

	tmp.setRawBits(this->value + src.value);
	return tmp;
}

Fixed Fixed::operator-(const Fixed& src)
{
	Fixed tmp(*this);

	tmp.setRawBits(this->value - src.value);
	return tmp;
}

Fixed Fixed::operator*(const Fixed& src)
{
	Fixed tmp(*this);

	tmp.setRawBits(this->toFloat() * src.toFloat());
	return tmp;
}

Fixed Fixed::operator/(const Fixed& src)
{
	Fixed tmp(*this);

	tmp.setRawBits(value / src.value);
	return tmp;
}

	// Increment operators

Fixed Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->value++;
	return tmp;
}

Fixed Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->value--;
	return tmp;
}

	// Assignment operators

Fixed &Fixed::operator=(const Fixed& src)
{
	this->value = src.value;
	return *this;
}


int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->value / (1 << this->_bits);
}

int Fixed::toInt(void) const
{
	return this->value >> this->_bits;
}

Fixed Fixed::min(const Fixed& src1, const Fixed& src2)
{
	if (src1.getRawBits() < src2.getRawBits())
		return src1;
	return src2;
}

Fixed Fixed::max(const Fixed& src1, const Fixed& src2)
{
	if (src1.getRawBits() > src2.getRawBits())
		return src1;
	return src2;
}
