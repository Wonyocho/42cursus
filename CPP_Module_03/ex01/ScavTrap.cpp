#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) // ClapTrap 생성자 호출
{
    std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) // ClapTrap 복사 생성자 호출
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() // ClapTrap 소멸자 호출
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy) // ClapTrap 복사 대입 연산자 호출
{
    if (this != &copy)
    {
        ClapTrap::operator=(copy); // ClapTrap의 복사 대입 연산자 호출
        std::cout << "ScavTrap assignment operator called" << std::endl;
    }
    return (*this);
}




void ScavTrap::attack(const std::string& target)
{
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " 
              << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode." << std::endl;
}
