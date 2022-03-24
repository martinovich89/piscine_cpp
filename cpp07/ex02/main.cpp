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

		intArray[4];
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}