#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public :

	FragTrap();
	~FragTrap();
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);

	FragTrap(std::string name);

	void attack(std::string target);
	void highFivesGuys(void);
};