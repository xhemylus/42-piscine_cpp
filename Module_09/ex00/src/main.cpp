#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange btc;
		try
		{
			if (argc != 2)
				throw BadUsage();
			btc.SetDatabase();
			btc.ReadDatabase(argv[1]);
			return (0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		

	return (1);
}