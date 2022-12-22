#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <deque>

template<class Type>

void PrintWithDel(const Type& container, const std::string& sepator)
{
	for (auto iter = container.begin(); iter != container.end();)
	{
		std::cout << *iter;
		if (++iter != container.end())
			std::cout << sepator;
	}
	std::cout << std::endl;
}

void MakeTrain()
{
	std::deque<int> train;

	std::string command;

	int number = 0;

	int amount = 0;

	while (std::cin >> command >> number)
	{
		if (command == "+left")
			train.push_front(number);

		if (command == "+right")
			train.push_back(number);

		if (command == "-left")
		{
			auto begin = train.begin();
			auto end = train.end();
			amount = number;

			if (amount >= train.size())
				train.clear();
			else
			{
				amount = train.size() - amount;

				train.erase(begin, end - amount);
			}
		}
		if (command == "-right")
		{
			auto begin = train.begin();
			auto end = train.end();
			amount = number;

			if (amount >= train.size())
				train.clear();
			else
			{
				amount = train.size() - amount;

				train.erase(begin + amount, end);
			}
		}
	}
	for (auto iter = train.begin(); iter != train.end();)
	{
		std::cout << *iter;
		if (++iter != train.end())
			std::cout << ' ';
	}
	std::cout << std::endl;
}

int main()
{
/*
	std::vector<int> v = { 1, 2, 3 };
	char c = '||';

	PrintWithDel(v, c);

	std::list<char> l = {'p', 'i', 'p', 'l'};
	c = '-';

	PrintWithDel(l, c);

	std::string s = "Hello? My friend!";
	c = ' ';

	PrintWithDel(s, c);
*/

	MakeTrain();

	return 0;
}

