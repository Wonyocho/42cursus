#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class ScavTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &copy);

        void attack(const std::string& target);
        void guardGate();
    
    private:
        std::string name;
        unsigned int hitpoints; // HP
        unsigned int energyPoints;
        unsigned int attackDamage;
        bool isGuardGate;
};

#endif