#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		// Constructors and destructor
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed& src);
		~Fixed();

		// Comparaison operators
		bool operator<(const Fixed& src) const;
		bool operator>(const Fixed& src) const;
		bool operator>=(const Fixed& src);
		bool operator<=(const Fixed& src);
		bool operator==(const Fixed& src);
		bool operator!=(const Fixed& src);

		// Arithmetic operators
		Fixed operator+(const Fixed& src);
		Fixed operator-(const Fixed& src);
		Fixed operator*(const Fixed& src);
		Fixed operator/(const Fixed& src);

		// Increment operators
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);

		// Assignment operators
		Fixed& operator=(const Fixed& src);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

		static Fixed &min(Fixed& a, Fixed& b);
		static Fixed &max(Fixed& a, Fixed& b);
		static Fixed const &min(const Fixed& a, const Fixed& b);
		static Fixed const &max(const Fixed& a, const Fixed& b);
	private:
		int value;
		static const int _bits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& src);

#endif