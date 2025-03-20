#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> v;
	std::list<int> l;

	for (int i = 0; i < 20; i++)
	{
		v.push_back(i);
		l.push_back(i);
	}
	
	std::cout << *easyfind(v, 3) << std::endl;
	std::cout << *easyfind(l, 9) << std::endl;
	
	try	
	{
		std::cout << *easyfind(v, 21) << std::endl;
	}
	catch (std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}
	
	try	
	{
		std::cout << *easyfind(l, 21) << std::endl;
	}
	catch (std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}
}