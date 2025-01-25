#include "ClapTrap.hpp"

// ********************** OCCF **********************
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "ClapTrap assignation operator called" << std::endl;
    if (this == &copy)
    {
        return *this;
    }
    _name = copy._name;
    _hitPoints = copy._hitPoints;
    _energyPoints = copy._energyPoints;
    _attackDamage = copy._attackDamage;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl; // 소멸자 호출 시 메시지 출력
}





// ********************** getter **********************
std::string ClapTrap::getName() const
{
    return this->_name;
}

int ClapTrap::getHitPoints() const
{
    return this->_hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
    return this->_energyPoints;
}

int ClapTrap::getAttackDamage() const
{
    return this->_attackDamage;
}





// attack 멤버 함수
void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0) // 이미 죽어있는 경우
    {
        std::cout << "ClapTrap " << _name << " 은 이미 쓰러져있다..." << std::endl;
        return ;
    }
    if (_energyPoints <= 0) // 행동할 수 없는 경우(에너지 부족)
    {
        std::cout << "ClapTrap" << _name << " 은 지쳐서 아무것도 할 수 없다!" << std::endl;
        return ;
    }
    _energyPoints--; // 공격 성공, energyPoints 1 감소
    std::cout << "ClapTrap " << _name << " 은 " << target << " 에게 " << _attackDamage << " 의 피해를 입혔다!" << std::endl; // 메시지 출력
}

// takeDamage 멤버 함수
void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0) // 이미 죽어있는 경우
    {
        std::cout << "ClapTrap " << _name << " 은 이미 쓰러져있다..." << std::endl; // 메시지 출력
        return;
    }

    if (_hitPoints < amount) // 받은 데미지가 남은 HP보다 클경우 혹시 몰라서 처리
    {
        amount = _hitPoints;
    }

    _hitPoints -= amount; // 공격 받았으니 HP에서 amount만큼 감소

    if (_hitPoints <= 0) // 공격받고 죽은경우
    {
        std::cout << "ClapTrap " << _name << " 은 쓰러졌다..." << std::endl; // 메시지 출력
    }
    else // 공격받고 살아남은 경우
    {
        std::cout << "ClapTrap " << _name << " 은 " << amount << " 의 피해를 입었다!" << std::endl; // 메시지 출력
    }
}

// beRepaired 멤버 함수
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0) // 이미 죽어있는 경우
    {
        std::cout << "ClapTrap " << _name << " 은 이미 쓰러져있다..." << std::endl; // 메시지 출력
        return;
    }
    if (_energyPoints <= 0) // 행동할 수 없을 때
    {
        std::cout << "ClapTrap " << _name << " 은 지쳐서 아무것도 할 수 없다!" << std::endl;
    }
    _energyPoints--; // energyPoints 1 감소
    _hitPoints += amount; // hitPoints에서 amount만큼 증가
    std::cout << "ClapTrap " << _name << " 은 " << amount << " 만큼 회복헸다!" << std::endl; // 메시지 출력
}
