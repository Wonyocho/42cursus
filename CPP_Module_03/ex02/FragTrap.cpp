#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    std::cout << "FragTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "FragTrap assignation operator called" << std::endl;
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy.getHitPoints();
		this->_energyPoints = copy.getEnergyPoints();
		this->_attackDamage = copy.getAttackDamage();
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}



void FragTrap::highFivesGuys()
{
	if (this->_hitPoints <= 0)
	{
        std::cout << "FragTrap " << _name << " 은 이미 쓰러져있다..." << std::endl;
		return ;
	}
	
	std::cout << "FragTrap " << this->getName() << " high fives guys!" << std::endl;
}
