#include "easyfind.hpp"


int main(void)
{
	std::list<int>	lst;
	int array[5] = {4, 42, 69, 19, 8};

	for (unsigned i = 0; i < 5; i++)
	{
		lst.push_back(array[i]);
	}

	std::cout << "=====>TESTS WITH A LIST<=====" << std::endl;

	try
	{
		easyfind(lst, 42);
		easyfind(lst, 19);
		easyfind(lst, 80);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::vector<int>	vector;
	for (unsigned i = 0; i < 5; i++)
	{
		vector.push_back(array[i]);
	}

	std::cout << "=====>TESTS WITH A VECTOR<=====" << std::endl;

	try
	{
		easyfind(lst, 4);
		easyfind(lst, 69);
		easyfind(lst, 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}