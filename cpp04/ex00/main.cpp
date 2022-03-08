#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	Animal JeanClaude;
	std::cout << "---------------------------------\n";
	Dog JeanPierre;
	std::cout << "---------------------------------\n";
	Cat JeanMichel;
	std::cout << "---------------------------------\n";
	Animal JeanMarc(JeanPierre);
	std::cout << "---------------------------------\n";
	Cat JeanKevin(JeanMichel);

	std::cout << "=================================\n";

	std::cout << JeanClaude.get_type() << std::endl;
	JeanClaude.makeSound();
	std::cout << "---------------------------------\n";
	std::cout << JeanPierre.get_type() << std::endl;
	JeanPierre.makeSound();
	std::cout << "---------------------------------\n";
	std::cout << JeanMichel.get_type() << std::endl;
	JeanMichel.makeSound();
	std::cout << "---------------------------------\n";
	std::cout << JeanMarc.get_type() << std::endl;
	JeanMarc.makeSound();
	std::cout << "---------------------------------\n";
	std::cout << JeanKevin.get_type() << std::endl;
	JeanKevin.makeSound();
	std::cout << "---------------------------------\n";

	JeanMarc = JeanMichel;
	std::cout << "---------------------------------\n";

	std::cout << JeanMarc.get_type() << std::endl;
	JeanMarc.makeSound();

	std::cout << "=================================\n";

	return (0);
}