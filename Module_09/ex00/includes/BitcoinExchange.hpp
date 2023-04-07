#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, float> _database;
public:
	BitcoinExchange(/* args */);
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &src);
	~BitcoinExchange();

	void SetDatabase();
	void ReadDatabase(std::string path);

	int InputChecker(int year, int month, int day, std::string number, float bitcoin, std::string line);
	void PrintRate(std::string date, float bitcoin);
};