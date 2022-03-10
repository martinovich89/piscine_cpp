#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap Unnamed;
	ClapTrap JeanJacques("Jean-Jacques");
	ClapTrap Unnamed2(Unnamed);
	ClapTrap JeanJacquesClone;
	ScavTrap JeanPierre;
	
	std::cout << std::endl;
	JeanJacquesClone = JeanJacques;
	std::cout << std::endl;
	JeanJacques.attack(Unnamed.get_name());
	Unnamed.takeDamage(JeanJacques.get_ad());
	std::cout << "It's not very effective ..." << std::endl;
	std::cout << std::endl;
	for (int i = JeanJacques.get_ep(); i > 1; i--)
	{
		JeanJacques.attack(Unnamed2.get_name());
		Unnamed2.takeDamage(JeanJacques.get_ad());
		std::cout << "It's not very effective ..." << std::endl;
		std::cout << std::endl;
	}
	std::cout << Unnamed.get_name() << " decides to let his Pikachu attack for him." << std::endl;
	std::cout << Unnamed.get_name() << "'s Pikachu attacks " << JeanJacques.get_name() << ", causing 5 points of damage!" << std::endl;
	JeanJacques.takeDamage(5);
	std::cout << std::endl;
	JeanJacques.beRepaired(1);
	std::cout << std::endl;
	JeanJacques.attack(JeanJacquesClone.get_name());
	std::cout << std::endl;
	JeanJacques.beRepaired(3);
	std::cout << std::endl;
/*	std::cout << "Fake " << JeanJacquesClone.get_name() << " says : \"ImmA FirinG Ma LaseR !!\", and attacks Jean-Jacques, causing 452 points of damage!" << std::endl;
	JeanJacques.takeDamage(452);*/
	JeanPierre.attack("JeanJacques");
	JeanJacques.takeDamage(JeanPierre.get_ad());
	std::cout << std::endl;
	JeanJacques.beRepaired(3);
	std::cout << std::endl;
	std::cout << std::endl << "---->Game Over<----" << std::endl;
	std::cout << std::endl;
	return (0);
}