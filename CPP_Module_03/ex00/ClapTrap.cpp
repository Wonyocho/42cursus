// 1. When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
// 2. When ClapTrap repairs itself, it gets <amount> hit points back.
// 3. Attacking and repairing cost 1 energy point each.
// 4. ClapTrap can’t do anything if it has no hit points or energy points left.

// In all of these member functions, you have to print a message to describe what happens. 
// For example, the attack() function may display something like (of course, without the angle brackets):
// ClapTrap <name> attacks <target>, causing <damage> points of damage!

// The constructors and destructor must also display a message, so your peer-evaluators can easily see they have been called.
// Implement and turn in your own tests to ensure your code works as expected.

#include "ClapTrap.hpp"

// 생성자
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl; // 생성자 호출 시 메시지 출력
}

// 복사 생성자
ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap copy constructor called" << std::endl; // 복사 생성자 호출 시 메시지 출력
    *this = copy; // 대입 연산자 호출
}

// 복사 대입 연산자
ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "ClapTrap assignation operator called" << std::endl; // 대입 연산자 호출 시 메시지 출력
    if (this == &copy) // 자기 자신과 대입 연산 시 아무것도 하지 않음
    {
        return *this;
    }
    // name, hitPoints, energyPoints, attackDamage 모두 복사
    name = copy.name; // 깊은 복사
    hitPoints = copy.hitPoints; // 깊은 복사
    energyPoints = copy.energyPoints; // 깊은 복사
    attackDamage = copy.attackDamage; // 깊은 복사
    return *this; // 대입 연산자는 *this를 반환
}

// 소멸자
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl; // 소멸자 호출 시 메시지 출력
}




// attack 멤버 함수
void ClapTrap::attack(const std::string& target)
{
    if (hitPoints == 0 || energyPoints == 0) // hitPoints 또는 energyPoints가 0이면 아무것도 하지 않음
    {
        std::cout << "ClapTrap " << name << " can't attack because it has no hit points or energy points left" << std::endl; // 메시지 출력
        return;
    }
    energyPoints--; // energyPoints 1 감소
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl; // 메시지 출력
}

// takeDamage 멤버 함수
void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0) // hitPoints가 0이면 아무것도 하지 않음
    {
        std::cout << "ClapTrap " << name << " can't take damage because it has no hit points left" << std::endl; // 메시지 출력
        return;
    }
    hitPoints -= amount; // hitPoints에서 amount만큼 감소
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl; // 메시지 출력
}

// beRepaired 멤버 함수
void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0) // hitPoints가 0이면 아무것도 하지 않음
    {
        std::cout << "ClapTrap " << name << " can't be repaired because it has no hit points left" << std::endl; // 메시지 출력
        return;
    }
    energyPoints--; // energyPoints 1 감소
    hitPoints += amount; // hitPoints에서 amount만큼 증가
    std::cout << "ClapTrap " << name << " is repaired by " << amount << " points!" << std::endl; // 메시지 출력
}
