#include "fixed.hpp"

std::ostream& operator<<(std::ostream& out, const Fixed& src)
{
	out << src.toFloat();
	return out;
}

// Constructors
Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed& src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int n)
{
	//std::cout << "Int constructor called" << std::endl;
	this->value = n << Fixed::_bits;
}

Fixed::Fixed(const float n)
{
	//std::cout << "Float constructor called" << std::endl;
	this->value = roundf(n * (1 << Fixed::_bits));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

// Operators
	// Comparaison operators

bool Fixed::operator<(const Fixed& src) const
{
	return (this->getRawBits() < src.getRawBits());

}

bool Fixed::operator>(const Fixed& src) const
{
	return (this->getRawBits() > src.getRawBits());
}

bool Fixed::operator>=(const Fixed& src)
{
	return (this->getRawBits() >= src.getRawBits());
}

bool Fixed::operator<=(const Fixed& src)
{
	return (this->getRawBits() <= src.getRawBits());

}

bool Fixed::operator==(const Fixed& src)
{
	return (this->getRawBits() == src.getRawBits());

}

bool Fixed::operator!=(const Fixed& src)
{
	return (this->getRawBits() != src.getRawBits());
}

	// Arithmetic operators

Fixed Fixed::operator+(const Fixed& src)
{
	Fixed tmp(*this);

	tmp.setRawBits(this->getRawBits() + src.getRawBits());
	return tmp;
}

Fixed Fixed::operator-(const Fixed& src)
{
	Fixed tmp(*this);

	tmp.setRawBits(this->getRawBits() - src.getRawBits());
	return tmp;
}

Fixed Fixed::operator*(const Fixed& src)
{
	Fixed tmp(*this);
	long var1, var2;

	var1 = ((long)this->getRawBits());
	var2 = ((long)src.getRawBits());
	tmp.setRawBits((var1 * var2) / (1 << Fixed::_bits));
	return tmp;
}

Fixed Fixed::operator/(const Fixed& src)
{
	Fixed tmp(*this);
	long var1, var2;

	var1 = ((long)this->getRawBits());
	var2 = ((long)src.getRawBits());
	tmp.setRawBits((var1 * (1 << Fixed::_bits)) / var2);
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
	//std::cout << "getRawBits member function called" << std::endl;
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

Fixed &Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed const &Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &min(Fixed& a, Fixed& b)
{
	return (Fixed::min(a, b));
}

Fixed const &min(const Fixed& a, const Fixed& b)
{
	return (Fixed::min(a, b));
}

Fixed &Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

Fixed const &Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

Fixed const &max(Fixed const &a, Fixed const &b)
{
	return (Fixed::max(a, b));
}

Fixed &max(Fixed& a, Fixed& b)
{
	return (Fixed::max(a, b));
}