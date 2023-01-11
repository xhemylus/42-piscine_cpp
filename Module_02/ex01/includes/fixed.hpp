#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed& src);
		~Fixed();

		Fixed& operator=(const Fixed& src);
		Fixed& operator<<(const Fixed& src);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

	private:
		int value;
		static const int _bits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& src);

#endif