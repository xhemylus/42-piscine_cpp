#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <stdlib.h>

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

	int InputChecker(int year, int month, int day, float bitcoin, std::string line);
	void PrintRate(int date, std::string numdate, float bitcoin);
};