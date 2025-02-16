#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	*this = copy;
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    if (this != &copy)
    {
        this->_name = copy._name;
		this->_hitPoints = copy.getHitPoints();
		this->_energyPoints = copy.getEnergyPoints();
		this->_attackDamage = copy.getAttackDamage();
        std::cout << "ScavTrap assignment operator called" << std::endl;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}




void ScavTrap::guardGate()
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " 은 이미 쓰러져있다..." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << "은 Gate keeper 모드에 돌입했다!" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	if (this->_hitPoints <= 0) // 이미 죽어있는 경우
	{
		std::cout << "ScavTrap " << this->getName() << " 은 이미 쓰러져있다..." << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " 은 지쳐서 아무것도 할 수 없다..." << std::endl;
		return ;
	}

	this->_energyPoints--;
		std::cout << "ScavTrap " << this->getName() << " 은 " << target << " 에게 " << this->_attackDamage << "의 피해를 입혔다!" << std::endl;
}