#include "iter.hpp"
#include "number.hpp"
#include "print.hpp"
#include "printeven.hpp"

int main(void)
{
	Number tab[6];
	int array[] = {1, 42, 19, 69, 7, 32};

	std::cout << "use of print() on array{1, 42, 19, 69, 7, 32} :" << std::endl;
	iter(array, 6, print);
	std::cout << std::endl;
	
	std::cout << "use of printeven() on array{1, 42, 19, 69, 7, 32} :" << std::endl;
	iter(array, 6, printeven);
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
	{
		tab[i].setNumber(array[i]);
	}

	std::cout << "use of print() on Number tab[6] containing copies of each array element" << std::endl;
	iter(tab, 6, print);
	std::cout << std::endl;
}
