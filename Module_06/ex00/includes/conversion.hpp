
#include <string>
#include <iostream>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define ERROR 5
#define NAN_INF 6

class Conversion
{
	public:
		Conversion();

		Conversion(const std::string input);
		Conversion(const Conversion &src);

		~Conversion();

		Conversion &operator=(const Conversion &src);

	class ErrorException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	private:
		const std::string _input;
		int _type;
		char _char;
		int _int;
		float _float;
		double _double;

		int parse(std::string input);
		void convert(void);

		void fromChar(void);
		void fromInt(void);
		void fromFloat(void);
		void fromDouble(void);

		void printAll(void)const;
		void printChar(void)const;
		void printInt(void)const;
		void printFloat(void)const;
		void printDouble(void)const;


		std::string getInput(void)const;
		int getType(void)const;
		char getChar(void)const;
		int getInt(void)const;
		float getFloat(void)const;
		double getDouble(void)const;
};