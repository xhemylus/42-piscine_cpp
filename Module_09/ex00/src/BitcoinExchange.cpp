#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
};

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	this->_database = src._database;
	return *this;
};

BitcoinExchange::~BitcoinExchange()
{
};

void BitcoinExchange::SetDatabase()
{
	std::ifstream Exchangefile;
	std::string line;
	float pricefloat = 0.0;

	Exchangefile.open("./data.csv");
	if (!Exchangefile.is_open())
		throw std::runtime_error("Error: file not found");
	while (std::getline(Exchangefile, line))
	{
		std::string date = line.substr(0, line.find(','));
		std::string price = line.substr(line.find(',') + 1, line.length());
		std::stringstream tofloat;
		tofloat << price;
		tofloat >> pricefloat;
		_database[date] = pricefloat;
	}
	Exchangefile.close();
}

void BitcoinExchange::ReadDatabase(std::string path)
{
	std::ifstream Inputfile;
	std::string line;

	std::cout << "Reading database: " << path << std::endl;
	Inputfile.open(path.c_str());
	if (!Inputfile.is_open())
		throw std::runtime_error("Error: file not found");
	std::getline(Inputfile, line);
	while (std::getline(Inputfile, line))
	{
		std::string date = line.substr(0, line.find('|'));
		int year = atoi(date.substr(0, 4).c_str());
		int month = atoi(date.substr(5, 2).c_str());
		int day = atoi(date.substr(8, 2).c_str());

		std::string number = line.substr(line.find('|') + 1, line.length());
		
		float bitcoin = 0.0;
		std::stringstream tofloat;
		tofloat << number;
		tofloat >> bitcoin;

		if (InputChecker(year, month, day, number, bitcoin, line) == 0)
			PrintRate(date, bitcoin);
		
	}
	Inputfile.close();
}

int BitcoinExchange::InputChecker(int year, int month, int day, std::string number, float bitcoin, std::string line)
{
	size_t pos = line.find('|');
	if (pos == std::string::npos || line[pos - 1] != ' ' || line[pos + 1] != ' ')
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (1);
	}

	if (year < 2009 || year > 2019)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (1);
	}
	if (month < 1 || month > 12)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (1);
	}
	if (day < 1 || day > 31)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return (1);
	}
	if (bitcoin < 0.0)
	{
		std::cout << "Error: not a positive number " << line << std::endl;
		return (1);
	}
	if (bitcoin > 1000.0)
	{
		std::cout << "Error: too large a number " << line << std::endl;
		return (1);
	}
	return (0);
}

void BitcoinExchange::PrintRate(std::string date, float bitcoin)
{
	std::map<std::string, float>::const_iterator it = _database.begin();
	for (; it != _database.end(); ++it)
	{
		if (it->first == date)
		{
			std::cout << date << " => " << bitcoin << " = " << it->second * bitcoin << std::endl;
			return ;
		}
	}
	it = _database.lower_bound(date);
	std::cout << date << " => " << bitcoin << " = " << it->second * bitcoin << std::endl;
}