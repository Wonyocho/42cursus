#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): clapTrap(name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
}



ScavTrap::ScavTrap() : name("ScavTrap"), hitpoints(100), energyPoints(50), attackDamage(20), isGuardGate(false)
{
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : name(name), hitpoints(100), energyPoints(50), attackDamage(20), isGuardGate(false)
{
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = copy;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "ScavTrap assignation operator called" << std::endl;
    if (this == &copy)
        return *this;
    name = copy.name;
    hitpoints = copy.hitpoints;
    energyPoints = copy.energyPoints;
    attackDamage = copy.attackDamage;
    isGuardGate = copy.isGuardGate;
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (hitpoints == 0 || energyPoints == 0)
    {
        std::cout << "ScavTrap " << name << " can't attack because it has no hit points or energy points left" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    isGuardGate = !isGuardGate;
    std::cout << "ScavTrap " << name << " is " << (isGuardGate ? "" : "not ") << "guarding the gate" << std::endl;
}



/*
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_maxHitPoints = 100;
	std::cout << "ScavTrap " << this->getName() << " is created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src) {
	*this = src;
	std::cout << "ScavTrap " << this->getName() << " copy constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src) {
	if (this != &src) {
		this->_name = src._name;
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->getName() << " is destroyed" << std::endl;
}

void ScavTrap::guardGate(void) {
	if (this->_hitPoints <= 0) {
		std::cout << "ScavTrap " << this->getName() << " is already dead!" << std::endl;
		return;
	}
	
	std::cout << "ScavTrap " << this->getName() << " has entered in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(std::string const &target) {
	if (this->_hitPoints <= 0) {
		std::cout << "ScavTrap " << this->getName() << " is already dead!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ScavTrap " << this->getName() << " has no energy points left!" << std::endl;
		return;
	}
	
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", " << "causing " << this->_attackDamage << " points of damage!" << std::endl;
}
*/