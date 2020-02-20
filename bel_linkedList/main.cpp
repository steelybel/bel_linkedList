#include <iostream>
#include "tLinkedList.h"
int main()
{
	tList<int> list;
	int input = 0;
	std::cout << "How many values to insert from the front? >";
	std::cin >> input;
	for (int a = 0; a < input; a++)
	{
		list.push_front(a);
	}
	std::cout << "How many values to insert from the back? >";
	std::cin >> input;
	for (int a = 0; a < input; a++)
	{
		list.push_back(a);
	}
	std::cout << "Resulting list:" << std::endl;
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
	std::cin.ignore();
	std::cout << std::endl;
	std::cout << "The front of this list is " << (list.front()) << std::endl;
	std::cout << "The back of this list is " << (list.back()) << std::endl;
	std::cin.ignore();
	std::cout << "How many values to remove from the front? >";
	std::cin >> input;
	for (int a = 0; a < input; a++)
	{
		list.pop_front();
	}
	std::cout << "Resulting list:" << std::endl;
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
	std::cin.ignore();
	std::cout << std::endl;
	std::cout << "The front of this list is " << (list.front()) << std::endl;
	std::cout << "The back of this list is " << (list.back()) << std::endl;
	std::cin.ignore();
	std::cout << std::endl;
	return 0;
}