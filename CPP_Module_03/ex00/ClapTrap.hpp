#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;

    public:
        ClapTrap(std::string name);					// 생성자
        ClapTrap(const ClapTrap &copy);				// 복사 생성자
        ClapTrap &operator=(const ClapTrap &copy); 	// 복사 대입 연산자
        ~ClapTrap();								// 소멸자

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
