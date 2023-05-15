#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <stdlib.h>

#define red "\033[1;31m"
#define orange "\033[1;33m"
#define white "\033[0;37m"
#define reset "\033[0;0m"

class BitcoinExchange
{
private:
	std::map<int, float> _database;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &src);
	~BitcoinExchange();

	void SetDatabase();
	void ReadDatabase(std::string path);

	int InputChecker(std::string line);
	void PrintRate(int numdate, std::string date, float bitcoin);
};

class DBNotFound : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return (red "Error: " white "Database not found." reset);
	}
};

class IFNotFound : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return (red "Error: " white "Input file not found." reset);
	}
};

class BadUsage : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return (orange "Usage: " white "./btc <inputfile>" reset);
	}
};