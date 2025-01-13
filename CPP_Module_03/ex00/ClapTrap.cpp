// 1. When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
// 2. When ClapTrap repairs itself, it gets <amount> hit points back.
// 3. Attacking and repairing cost 1 energy point each.
// 4. ClapTrap can’t do anything if it has no hit points or energy points left.

// In all of these member functions, you have to print a message to describe what happens. 
// For example, the attack() function may display something like (of course, without the angle brackets):
// ClapTrap <name> attacks <target>, causing <damage> points of damage!

// The constructors and destructor must also display a message, so your peer-evaluators can easily see they have been called.
// Implement and turn in your own tests to ensure your code works as expected.

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "ClapTrap assignation operator called" << std::endl;
    if (this == &copy) {
        return *this;
    }
    name = copy.name;
    hitPoints = copy.hitPoints;
    energyPoints = copy.energyPoints;
    attackDamage = copy.attackDamage;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " can't attack because it has no hit points or energy points left" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " can't take damage because it has no hit points left" << std::endl;
        return;
    }
    hitPoints -= amount;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " can't be repaired because it has no hit points left" << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired by " << amount << " points!" << std::endl;
}
