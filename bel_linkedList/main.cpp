#include <iostream>
#include "tLinkedList.h"
int main()
{
	tList<int> list;
	for (int a = 0; a < 6; a++)
	{
		list.push_front(a);
	}
	// list.clear();
	bool go = true;
	int input = 0;
	for (int a = 0; a < 6; a++)
	{
		list.push_back(a);
	}
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
	std::cin >> input;
	std::cout << std::endl;
	std::cout << (list.back()) << std::endl;
	std::cin >> input;
	std::cout << std::endl;
	for (int a = 0; a < 4; a++)
	{
		list.pop_front();
	}
	std::cin >> input;
	std::cout << std::endl;
	return 0;
}