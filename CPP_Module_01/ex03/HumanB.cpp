#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack()
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " attacks with a hand" << std::endl;
	else
		std::cout << this->_name << " attacks with a " << this->_weapon->getType() << std::endl;
}
