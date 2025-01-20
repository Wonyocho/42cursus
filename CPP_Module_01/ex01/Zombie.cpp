#include "Zombie.hpp"

// 기본 생성자
Zombie::Zombie() {}

// 소멸자
Zombie::~Zombie()
{
    std::cout << this->_name << " is dead." << std::endl;
}

// announce 함수
void Zombie::announce(void) const
{
    std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

// 이름 설정 함수
void Zombie::getName(std::string name)
{
    this->_name = name;
}
