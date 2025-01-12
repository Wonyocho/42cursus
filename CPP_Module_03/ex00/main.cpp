#include <iostream>

int main()
{
    ClapTrap claptrap("ClapTrap");
    ClapTrap claptrap2(claptrap);
    claptrap2.attack("enemy");
    claptrap2.takeDamage(5);
    claptrap2.beRepaired(3);
    return 0;
}