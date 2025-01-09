#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

class FragTrap
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
        unsigned int hitpoints; // HP
        unsigned int energyPoints;
        unsigned int attackDamage;
};

#endif