#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>

class PMergeMe
{
public:
	PMergeMe();
	PMergeMe(PMergeMe const &src);
	PMergeMe &operator=(PMergeMe const &rhs);
	~PMergeMe();

	void holder(int argc, char **argv);
	void isUnsigned(char *str1, char *str2);

	// void vecsort(int argc, char **argv, T &vect, U &a, V &b);
private:
	std::vector<std::pair<unsigned int, unsigned int> > vect;
	std::deque<std::pair<unsigned int, unsigned int> > list;
	unsigned int tmp;
	bool odd;
};

template <typename T, typename U, typename V> 
void vecsort(int argc, char **argv, T &vect, U &a, V &b, unsigned int tmp, bool odd, int opt)
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
	if (argc < 6)
	{
		for (int i = 0; i < a.size(); i++)
			std::cout << a[i] << " ";
	}
	else
	{
		for (int i = 0; i < 5; i++)
			std::cout << a[i] << " ";
		std::cout << "[...]";
	}
	std::cout << std::endl;
	gettimeofday(&end, NULL);
	sec = end.tv_sec - start.tv_sec;
	usec = end.tv_usec - start.tv_usec;
	long duration = (sec / 1000000) + usec;
	if (opt)
		std::cout << "Time to process a range of " << argc << " elements with [std::vector:] " << duration << " us" << std::endl;
	else
		std::cout << "Time to process a range of " << argc << " elements with [std::deque:] " << duration << " us" << std::endl;

}