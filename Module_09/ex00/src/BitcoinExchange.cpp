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

int toNumDate(std::string date)
{

	while (date.find("-") != std::string::npos)
	{
		date.erase(date.find("-"), 1);
	}
	return (atoi(date.c_str()));
}

void BitcoinExchange::SetDatabase()
{
	std::ifstream datafile;
	std::string line;
	float pricefloat = 0.0;

	datafile.open("./data.csv");
	if (!datafile.is_open())
		throw DBNotFound();
	std::getline(datafile, line);
	while (std::getline(datafile, line))
	{
		std::string date = line.substr(0, line.find(','));
		int numdate = toNumDate(date);
		std::string price = line.substr(line.find(',') + 1, line.length());
		std::stringstream tofloat;
		tofloat << price;
		tofloat >> pricefloat;
		_database[numdate] = pricefloat;
	}
	datafile.close();
}

void BitcoinExchange::ReadDatabase(std::string path)
{
	std::ifstream Inputfile;
	std::string line;

	Inputfile.open(path.c_str());
	if (!Inputfile.is_open())
		throw IFNotFound();
	std::cout << reset << "Reading input from: " << path << reset << std::endl;
	std::getline(Inputfile, line);
	while (std::getline(Inputfile, line))
	{
		std::string date = line.substr(0, line.find('|') - 1);

		InputChecker(line);
	}
	Inputfile.close();
}

int BitcoinExchange::InputChecker(std::string line)
{
	size_t pos = line.find('|');
	if (pos == std::string::npos || line[pos - 1] != ' ' || line[pos + 1] != ' ')
	{
		std::cout << red << "Error: " << white << "bad input => " << reset << line << std::endl;
		return (1);
	}
	std::string date = line.substr(0, line.find('|') - 1);

	int dash = 0;

	for (size_t i = 0; i < date.length(); i++)
	{
		if (date[i] == '-')
			dash++;
	}

	if (dash != 2)
	{
		std::cout << red << "Error: " << white << "bad input => " << reset << line << std::endl;
		return (1);
	}

	std::string strmonth = date.substr(date.find_first_of("-") + 1, date.find_last_of("-") - date.find_first_of("-") - 1);
	int month = atoi(strmonth.c_str());
	if (month < 1 || month > 12)
	{
		std::cout << red << "Error: " << white << "not a valid month => " << reset << line << std::endl;
		return (1);
	}
	std::string strday = date.substr(date.find_last_of("-") + 1);
	int day = atoi(strday.c_str());
	if (day < 1 || day > 31)
	{
		std::cout << red << "Error: " << white << "not a valid day => " << reset << line << std::endl;
		return (1);
	}
	std::string number = line.substr(line.find('|') + 1, line.length());
		
	float bitcoin = 0.0;
	std::stringstream tofloat;
	tofloat << number;
	tofloat >> bitcoin;

	if (bitcoin < 0.0)
	{
		std::cout << red << "Error: " << white << "value to low => " << reset << line << std::endl;
		return (1);
	}
	if (bitcoin > 1000.0)
	{
		std::cout << red << "Error: " << white << "value too high => " << reset << line << std::endl;
		return (1);
	}
	int numdate = toNumDate(date);
	PrintRate(numdate, date, bitcoin);
	return (0);
}

void BitcoinExchange::PrintRate(int numdate, std::string date, float bitcoin)
{
	std::map<int, float>::const_iterator it = _database.begin();
	for (; it != _database.end(); ++it)
	{
		if (it->first == numdate)
		{
			std::cout << date << " => " << bitcoin << " = " << it->second * bitcoin << std::endl;
			return ;
		}
	}
	it = _database.lower_bound(numdate);
	if (it == _database.begin())
		{
			std::cout << red << "Error: " << white << "date too early => " << reset << date << std::endl;
			return ;
		}
	it++;
	std::cout << date << " => " << bitcoin << " = " << it->second * bitcoin << std::endl;
}