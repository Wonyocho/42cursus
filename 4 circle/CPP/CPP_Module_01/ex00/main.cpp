#include "Zombie.hpp"

int main(void)
{
	// Zombie 객체를 생성하여 출력한다.
	// Zombie 객체는 생성자에서 이름을 받아 멤버 변수에 저장하고, 소멸자에서 이름을 출력한다.
	// announce 함수는 멤버 변수에 저장된 이름을 출력한다.
	Zombie stackZombie1("Stack Zombie");
	Zombie stackZombie2("Stack Zombie");
	Zombie stackZombie3("Stack Zombie");

	// newZombie 함수는 Zombie 객체를 생성하여 반환한다.
	// newZombie 함수는 생성자를 호출하여 Zombie 객체를 생성하고, 생성된 객체의 주소를 반환한다.
	Zombie *heapZombie1 = newZombie("Heap Zombie");

	// ramdomChump 함수는 newZombie 함수를 호출하여 Zombie 객체를 생성하고, announce 함수를 호출하여 출력한 후, delete를 호출하여 메모리를 해제한다.
	// 따라서, randomChump 함수를 호출하면, Zombie 객체가 생성되고, 출력된 후, 메모리가 해제된다.
	randomChump("randomChump Zombie");

	// stackZombie1, stackZombie2, stackZombie3, heapZombie1 객체를 출력한다.
	stackZombie1.announce();
	stackZombie2.announce();
	stackZombie3.announce();
	heapZombie1->announce();

	// heapZombie1 객체를 메모리에서 해제한다.
	delete heapZombie1;

	return (0);
}
