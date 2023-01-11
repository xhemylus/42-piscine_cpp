#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& src);
		~Fixed();

		Fixed& operator=(const Fixed& src);

		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int value;
		static const int _bits = 8;
};

#endif