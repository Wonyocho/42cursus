#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(std::string name);					// 생성자
        ScavTrap(const ScavTrap &copy);				// 복사 생성자
        ~ScavTrap();								// 소멸자
        ScavTrap &operator=(const ScavTrap &copy);	// 복사 대입 연산자

        void attack(const std::string& target);
        void guardGate();
    
    private:
		ScavTrap(); // 디폴트 생성자
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;
};

#endif


// #ifndef SCAVTRAP_HPP
// # define SCAVTRAP_HPP
// # include <iostream>
// # include "ClapTrap.hpp"

// class ScavTrap: public ClapTrap {
// private:
// 	ScavTrap(void);
// public:
// 	ScavTrap(std::string name);
// 	ScavTrap(const ScavTrap &src);
// 	ScavTrap &operator=(const ScavTrap &src);
// 	~ScavTrap();
	
// 	void attack(std::string const &target);
// 	void guardGate(void);
// };

// #endif
