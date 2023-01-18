#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <typeinfo>
#include <time.h>

class Base
{
public:
	virtual ~Base(){};
};

class A : public Base
{
public:
	A()
	{
		std::cout << "A" << std::endl;
	}
};

class B : public Base
{
public:
	B()
	{
		std::cout << "B" << std::endl;
	}

};

class C : public Base
{
public:
	C()
	{
		std::cout << "C" << std::endl;
	}
};
#endif