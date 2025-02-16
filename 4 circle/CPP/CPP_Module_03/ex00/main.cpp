#include <iostream>
#include "ClapTrap.hpp"

int main()
{
    ClapTrap claptrap1("피카츄");
    ClapTrap claptrap2("디그다");
    ClapTrap claptrap3(claptrap2);

    claptrap1.attack(claptrap2.getName());
    claptrap2.takeDamage(5);
    claptrap2.beRepaired(3);

    return 0;
}
