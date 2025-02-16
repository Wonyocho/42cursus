#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
        ClapTrap();

    public:
        ClapTrap(std::string name);					// 생성자
        ClapTrap(const ClapTrap &copy);				// 복사 생성자
        ClapTrap &operator=(const ClapTrap &copy); 	// 복사 대입 연산자
        ~ClapTrap();								// 소멸자

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        // getter
        std::string getName() const;
        int getHitPoints() const;
        int getEnergyPoints() const;
        int getAttackDamage() const;
};

#endif
