#include "Array.hpp"

int main(void)
{
	std::string strtab[] = {"Alexandre", "Benoit", "Charlotte", "David", "Eleonore", "Francois", "Gauthier", "Helene", "Igor", "Jeanne"};

	try
	{
		Array<char> charArray;
		std::cout << "size of charArray : " << charArray.size() << std::endl;
		std::cout << charArray[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		unsigned size = 4;
		Array<int> intArray(size);

		for (unsigned i = 0; i < size; i++)
			intArray[i] = i;

		Array<int> intArrayCopy(intArray);
		Array<int> intArrayAssignment;
		std::cout << "size of intArrayAssignment before copy assignment	: " << intArrayAssignment.size() << std::endl;
		intArrayAssignment = intArrayCopy;
		std::cout << "size of intArrayAssignment after copy assignment	: " << intArrayAssignment.size() << std::endl;
		std::cout << std::endl;

		for (unsigned i = 0; i < size; i++)
		{
			std::cout << "OG intArray[" << i << "]		: " << intArray[i] << std::endl;
			std::cout << "intArrayCopy[" << i << "]		: " << intArrayCopy[i] << std::endl;
			std::cout << "intArrayAssignment[" << i << "]	: " << intArrayAssignment[i] << std::endl;
		}

		intArray[size];
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		unsigned size = 10;
		Array<std::string> strArray(size);

		for (unsigned i = 0; i < size; i++)
		{
			strArray[i] = strtab[i];
		}

		Array<std::string> strArrayCopy(strArray);
		Array<std::string> strArrayAssignment;
		std::cout << "size of strArrayAssignment before copy assignment	: " << strArrayAssignment.size() << std::endl;
		strArrayAssignment = strArrayCopy;
		std::cout << "size of strArrayAssignment after copy assignment	: " << strArrayAssignment.size() << std::endl;

		std::cout << std::endl;

		for (unsigned i = 0; i < size; i++)
		{
			std::cout << "OG strArray[" << i << "]		: |" << strArray[i] << "|" << std::endl;
			std::cout << "strArrayCopy[" << i << "]		: |" << strArrayCopy[i] << "|" << std::endl;
			std::cout << "strArrayAssignment[" << i << "]	: |" << strArrayAssignment[i] << "|" << std::endl;
		}

		strArray[size];
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

/*
#include "Array.hpp"
#include <iostream>
#include <Array.hpp>
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/