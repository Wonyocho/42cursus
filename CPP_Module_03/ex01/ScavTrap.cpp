#include "ScavTrap.hpp"

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
