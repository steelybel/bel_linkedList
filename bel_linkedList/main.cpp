#include <iostream>
#include "tLinkedList.h"
int main()
{
	tForwardList<int> list;
	for (int a = 0; a < 6; a++)
	{
		list.push_front(4);
	}
	for (auto it = list.cbegin(); it != list.cend(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
	list.clear();
	bool go = true;
	int input = 0;
	int step = 0;
	/*while (go)
	{
		std::cin >> input;
		std::cout << std::endl;
		list.push_front(input);
		step++;
		if (step == 5) go = false;
		std::cin.ignore();
	}
	list.remove(23);
	list.remove(24);
	list.pop_front();
	list.pop_front();
	list.pop_front();*/
	if (list.empty())
	{
		std::cout << "yooo wtf" << std::endl;
	}
	for (int a = 0; a < 6; a++)
	{
		list.push_front(4);
	}
	std::cin >> input;
	std::cout << std::endl;
	list.clear();
	std::cin >> input;
	std::cout << std::endl;
	return 0;
}