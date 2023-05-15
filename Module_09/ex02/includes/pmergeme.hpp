#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <algorithm>

#define red "\033[1;31m"
#define orange "\033[1;33m"
#define white "\033[0;37m"
#define reset "\033[0;0m"

class PMergeMe
{
public:
	PMergeMe();
	PMergeMe(PMergeMe const &src);
	PMergeMe &operator=(PMergeMe const &rhs);
	~PMergeMe();

	void holder(int argc, char **argv);
	void isUnsigned(char *str1, char *str2);

private:
	std::vector<std::pair<unsigned int, unsigned int> > vect;
	std::deque<std::pair<unsigned int, unsigned int> > list;
	unsigned int tmp;
	bool odd;
};

template <typename T, typename U, typename V> 
void vecsort(int argc, T &vect, U &a, V &b, unsigned int tmp, bool odd, int opt)
{
	struct timeval start, end;
	long sec, usec;
	gettimeofday(&start, NULL);
	for (size_t i = 0; i < vect.size(); i++)
	{
		if (vect[i].first > vect[i].second)
			std::swap(vect[i].first, vect[i].second);
	}

	for (size_t i = 0; i < vect.size(); i++)
	{
		a.push_back(vect[i].first);
		b.push_back(vect[i].second);
	}

	std::sort(a.begin(), a.end());

	for (size_t i = 0; i < b.size(); i++)
	{
		a.insert(std::lower_bound(a.begin(), a.end(), b[i]), b[i]);
	}
	if (odd)
		a.insert(std::lower_bound(a.begin(), a.end(), tmp), tmp);

	std::cout << "After : ";
	if (a.size() < 6)
	{
		for (size_t i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
	}
	else
	{
		for (size_t i = 0; i < 6; i++)
			std::cout << a[i] << " ";
		std::cout << "[...]";
	}
	std::cout << std::endl;
	gettimeofday(&end, NULL);
	sec = end.tv_sec - start.tv_sec;
	usec = end.tv_usec - start.tv_usec;
	long duration = (sec / 1000000) + usec;
	if (opt)
		std::cout << "Time to process a range of " << argc << " elements with [std::vector] " << duration << " us" << std::endl;
	else
		std::cout << "Time to process a range of " << argc << " elements with [std::deque] " << duration << " us" << std::endl;
	
	std::ofstream outputfile;
	outputfile.open("output.txt", std::ios_base::app);
	if (outputfile.is_open())
	{
		if (opt)
			outputfile << "std::vector: " << duration << " us" << std::endl;
		else
			outputfile << "std::deque: " << duration << " us" << std::endl;
		for (size_t i = 0; i < a.size(); i++)
			outputfile << a[i] << " ";
		outputfile << std::endl;
		outputfile.close();
	}
	else
		std::cout << "Unable to open outputfile" << std::endl;

}

class BadUsage : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return (orange "Usage: " white "./ex02 \"<int1>\" \"<int2>\" [...]" reset);
	}
};

class InvalidInput : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return (red "Error: " white "Invalid input" reset);
	}
};

class NegativeNumber : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return (red "Error: " white "Negative number" reset);
	}
};