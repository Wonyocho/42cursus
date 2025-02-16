#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
		ScavTrap();									// 디폴트 생성자
    
    public:
        ScavTrap(std::string name);					// 생성자
        ScavTrap(const ScavTrap &copy);				// 복사 생성자
        ScavTrap &operator=(const ScavTrap &copy);	// 복사 대입 연산자
        ~ScavTrap();								// 소멸자

        void attack(const std::string& target);
        void guardGate();
};

#endif
