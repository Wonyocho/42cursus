#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap: public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &copy);
        ~FragTrap();
        FragTrap &operator=(const FragTrap &copy);

        void attack(const std::string& target);
        void highFivesGuys(void);
    
    private:
        std::string name;
        unsigned int hitPoints; // HP
        unsigned int energyPoints;
        unsigned int attackDamage;
};

#endif