#include "Array.hpp"

int main(void)
{
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