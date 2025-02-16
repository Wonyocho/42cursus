#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap clapTrap("ClapTrap");
    ScavTrap scavTrap("ScavTrap");

    clapTrap.attack("enemy");
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(5);

    scavTrap.attack("enemy");
    scavTrap.takeDamage(10);
    scavTrap.beRepaired(5);
    scavTrap.guardGate();

    return 0;
}