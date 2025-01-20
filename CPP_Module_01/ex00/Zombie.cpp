#include "Zombie.hpp"

// 기본 생성자
Zombie::Zombie() {}

// 생성자
Zombie::Zombie(std::string name)
{
	this->_name = name;
}

// 소멸자
Zombie::~Zombie(void)
{
	std::cout << this->_name << " is dead." << std::endl;
}

// announce 함수
void Zombie::announce(void) const
{
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
