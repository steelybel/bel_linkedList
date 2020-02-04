#include <iostream>
#include "tLinkedList.h"
int main()
{
	tForwardList<int> list;
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}

	//bool go = true;
	//int input = 0;
	//int step = 0;
	//while (go)
	//{
	//	std::cin >> input;
	//	std::cout << std::endl;
	//	list.push_front(input);
	//	step++;
	//	if (step == 5) go = false;
	//	std::cin.ignore();
	//}
	//list.remove(23);
	//list.remove(24);
	//list.pop_front();
	//list.pop_front();
	//list.pop_front();
	//if (list.empty())
	//{
	//	std::cout << "yooo wtf" << std::endl;
	//}
	//list.resize(13);
	//std::cin >> input;
	//std::cout << std::endl;
	//return 0;
}