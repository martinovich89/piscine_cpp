#include "iter.hpp"
#include "number.hpp"
#include "print.hpp"
#include "printeven.hpp"

#define ARRAY_SIZE 6

int main(void)
{
	Number tab[ARRAY_SIZE];
	int array[] = {1, 42, 19, 69, 7, 32};

	std::cout << "use of print() on array{1, 42, 19, 69, 7, 32} :" << std::endl;
	iter(array, ARRAY_SIZE, print);
	std::cout << std::endl;
	
	std::cout << "use of printeven() on array{1, 42, 19, 69, 7, 32} :" << std::endl;
	iter(array, ARRAY_SIZE, printeven);
	std::cout << std::endl;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		tab[i].setNumber(array[i]);
	}

	std::cout << "use of print() on Number tab[6] containing copies of each array element" << std::endl;
	iter(tab, ARRAY_SIZE, print);
	std::cout << std::endl;
}
