#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange btc;
	if (argc == 2)
	{
		try
		{
			btc.SetDatabase();
			btc.ReadDatabase(argv[1]);
			return (0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	std::cout << "Usage: ./bitcoinexchange <database1>" << std::endl;
	return (1);
}