/*
	ScavTrap 생성

	ClapTrap은 충분하지 않기 때문에 이제 파생 로봇을 하나 더 만들어야 합니다.
	이 로봇의 이름은 ScavTrap이며, ClapTrap으로부터 생성자와 소멸자를 상속받습니다.
	그러나 ScavTrap의 생성자, 소멸자, 그리고 attack() 메서드는 각각 다른 메시지를 출력해야 합니다.
	결국 ClapTrap은 자신만의 개성을 가지고 있기 때문입니다.

	생성 및 소멸 체인 테스트
	테스트에서 올바른 생성/소멸 체인이 표시되어야 합니다.
	ScavTrap이 생성되면 프로그램은 ClapTrap을 먼저 생성하는 방식으로 시작합니다.
	소멸은 반대 순서로 이루어집니다. 왜 그런지 생각해 보세요.

	ScavTrap 초기화
	ScavTrap은 ClapTrap의 속성을 사용하고 (ClapTrap 클래스를 수정해야 할 수 있습니다) 아래 값으로 초기화해야 합니다:

	이름(name): 생성자에 전달되는 매개변수로 설정
	체력(hit points): 100, ClapTrap의 건강을 나타냄
	에너지 포인트(energy points): 50
	공격력(attack damage): 20
*/

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	*this = copy;
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    if (this != &copy)
    {
        this->_name = copy._name;
		this->_hitPoints = copy.getHitPoints();
		this->_energyPoints = copy.getEnergyPoints();
		this->_attackDamage = copy.getAttackDamage();
        std::cout << "ScavTrap assignment operator called" << std::endl;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}




void ScavTrap::guardGate()
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " 은 이미 쓰러져있다..." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << "은 Gate keeper 모드에 돌입했다!" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	if (this->_hitPoints <= 0) // 이미 죽어있는 경우
	{
		std::cout << "ScavTrap " << this->getName() << " 은 이미 쓰러져있다..." << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " 은 지쳐서 아무것도 할 수 없다..." << std::endl;
		return ;
	}

	this->_energyPoints--;
		std::cout << "ScavTrap " << this->getName() << " 은 " << target << " 에게 " << this->_attackDamage << "의 피해를 입혔다!" << std::endl;
}