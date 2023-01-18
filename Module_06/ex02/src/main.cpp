#include "base.hpp"

Base *generate()
{
	int r = rand() % 3;

	switch (r)
	{
	case 0:
		return (new A);
		break;
	case 1:
		return (new B);
		break;
	case 2:
		return (new C);
		break;
	default:
		return (new A);
		break;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "It's A (ptr)" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "It's B (ptr)" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "It's C (ptr)" << std::endl;
	else
		std::cout << "It's undefined (ptr)!" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A& aref = dynamic_cast<A &>(p);
		(void)aref;
		std::cout << "It's A (ref)" << std::endl;
	}
	catch (std::bad_cast)
	{
		try
		{
			B& bref = dynamic_cast<B &>(p);
			(void)bref;
			std::cout << "It's B (ref)" << std::endl;
		}
		catch (std::bad_cast)
		{
			try
			{
				C& cref = dynamic_cast<C &>(p);
				(void)cref;
				std::cout << "It's C (ref)" << std::endl;
			}
			catch (std::bad_cast)
			{
				std::cerr << "It's undefined (ref)!" << std::endl;
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	std::cout << "- - - GENERATING - - -" << std::endl;
	Base *id1 = generate();
	Base &ref1 = (*id1);

	Base *id2 = generate();
	Base &ref2 = (*id2);

	Base *id3 = generate();
	Base &ref3 = (*id3);
	std::cout << "- - - - - - - - - - -" << std::endl;

	identify(id1);
	identify(ref1);
	std::cout << std::endl;

	identify(id2);
	identify(ref2);
	std::cout << std::endl;

	identify(id3);
	identify(ref3);
	std::cout << std::endl;

}